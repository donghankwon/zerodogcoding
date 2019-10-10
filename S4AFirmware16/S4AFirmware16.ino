/*
Tiene como adicion la conexion del sensor de ultrasonido HC-SR04
para calcular distancia en centimetros entre 2cm y 400cm Pin3 = Trig, A5 = Echo

ARDUINO		HC-SR04
  5V		Vcc
  3		Trig
  A5		Echo
  GND		Gnd
*/


typedef enum
{ 
  input,
  servomotor,
  pwm,
  digital
} pinType;

typedef struct pin
{
  pinType type;      // Type of pin
  int state;         // State of an output
//  byte value;        // Value of an input. Not used by now. TODO
};

pin arduinoPins[14]; // Array of struct holding 0-13 pins information

#define ULTRASONIC_SENSOR

#if defined (ULTRASONIC_SENSOR)
const int trigPin = 3;
const int echoPin = A5;
#endif

unsigned long lastDataReceivedTime = millis();

void setup()
{
  Serial.begin(38400);
  Serial.flush();
  configurePins();
  resetPins();
}

void loop()
{
  static unsigned long timerCheckUpdate = millis();

  if (millis()-timerCheckUpdate>=20)
  {
    sendUpdateServomotors();
    sendSensorValues();
    
    #if defined (ULTRASONIC_SENSOR)
    calculardistancia(); //////////////////////////// nueva funcion
    #endif
    
    timerCheckUpdate=millis();
  }

  readSerialPort();
}

#if defined (ULTRASONIC_SENSOR)
//// Calculo de distancia en cm  desde 2cm a 400cm hecho por http://elprofegarcia.com/
void calculardistancia()
{
  long duracion, distancia1, distancia0;

  if(distancia1 > 1)
    distancia0=distancia1;
  
  pinMode(trigPin, OUTPUT); 		// ponemos el pin 3 como salida
  pinMode(echoPin, INPUT); 		// cambiamos el pin como entrada
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);                 // give a short LOW pulse beforehand to ensure a clean HIGH pulse
  digitalWrite(trigPin, HIGH); 		// lo activamos
  delayMicroseconds(10);	 	// esperamos 10 microsegundos
  digitalWrite(trigPin, LOW); 		// lo desactivamos

  duracion = pulseIn(echoPin, HIGH, 50000);  // lee el tiempo que tardo el pulso en regresar echo
  distancia1 = duracion / 29 / 2;  // calculo de la distancia en cm

  if (distancia1==0)
    distancia1=distancia0;

  ScratchBoardSensorReport(5, distancia1);   // Envia la distancia a A5
}
#endif


void configurePins()
{
  arduinoPins[0].type=input;
  arduinoPins[1].type=input;
  arduinoPins[2].type=input;

#if defined (ULTRASONIC_SENSOR)
  arduinoPins[3].type=digital;    // triger del sensor de ultrasonido hc-sr04
#else
  arduinoPins[3].type=input;
#endif

  arduinoPins[4].type=servomotor;
  arduinoPins[5].type=pwm;
  arduinoPins[6].type=pwm;
  arduinoPins[7].type=servomotor;
  arduinoPins[8].type=servomotor;
  arduinoPins[9].type=pwm;
  arduinoPins[10].type=digital;
  arduinoPins[11].type=digital;
  arduinoPins[12].type=digital;
  arduinoPins[13].type=digital;
}

void resetPins() {
  for (byte index=0; index <=13; index++) 
  {
    if (arduinoPins[index].type!=input)
    {
      pinMode(index, OUTPUT);
      if (arduinoPins[index].type==servomotor)
      {
        arduinoPins[index].state = 255;
        servo (index, 255);
      }
      else
      {
        arduinoPins[index].state=0;
        digitalWrite(index,LOW);
      }
    }
  }
}

void sendSensorValues()
{
  unsigned int sensorValues[6], readings[5];
  byte sensorIndex;

#if defined (ULTRASONIC_SENSOR)
  for (sensorIndex = 0; sensorIndex < 5; sensorIndex++) // suprimimos la salida A5
#else
  for (sensorIndex = 0; sensorIndex < 6; sensorIndex++) //for analog sensors, calculate the median of 5 sensor readings in order to avoid variability and power surges
#endif
  {
    for (byte p = 0; p < 5; p++)
      readings[p] = analogRead(sensorIndex);
    insertionSort(readings, 5); //sort readings
    sensorValues[sensorIndex] = readings[2]; //select median reading
  }

  //send analog sensor values
#if defined (ULTRASONIC_SENSOR)
  for (sensorIndex = 0; sensorIndex < 5; sensorIndex++)   //  Modificado para no enviar valor A5
#else
  for (sensorIndex = 0; sensorIndex < 6; sensorIndex++)
#endif
    ScratchBoardSensorReport(sensorIndex, sensorValues[sensorIndex]);

  //send digital sensor values
  ScratchBoardSensorReport(6, digitalRead(2)?1023:0);
  ScratchBoardSensorReport(7, digitalRead(3)?1023:0);
}

void insertionSort(unsigned int* array, unsigned int n)
{
  for (int i = 1; i < n; i++)
    for (int j = i; (j > 0) && ( array[j] < array[j-1] ); j--)
      swap( array, j, j-1 );
}

void swap(unsigned int* array, unsigned int a, unsigned int b)
{
  unsigned int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}

void ScratchBoardSensorReport(byte sensor, int value) //PicoBoard protocol, 2 bytes per sensor
{
  Serial.write( B10000000
    | ((sensor & B1111)<<3)
    | ((value>>7) & B111));
  Serial.write( value & B1111111);
}

void readSerialPort()
{
  byte pin;
  int newVal;
  static byte actuatorHighByte, actuatorLowByte;
  static byte readingSM = 0;

  if (Serial.available())
  {
    if (readingSM == 0)
    {
      actuatorHighByte = Serial.read();
      if (actuatorHighByte >= 128)
        readingSM = 1;
    }
    else if (readingSM == 1)
    {
      actuatorLowByte = Serial.read();
      
      if (actuatorLowByte < 128)
        readingSM = 2;
      else
        readingSM = 0;
    }

    if (readingSM == 2)
    {
      lastDataReceivedTime = millis();    
      pin = ((actuatorHighByte >> 3) & 0x0F);
      newVal = ((actuatorHighByte & 0x07) << 7) | (actuatorLowByte & 0x7F); 

      if(arduinoPins[pin].state != newVal)
      {
        arduinoPins[pin].state = newVal;
        updateActuator(pin);
      }
      readingSM = 0;
    }
  }
  else checkScratchDisconnection();
}

// with xbee module,
// we need to simulate the setup execution
// that occurs when a usb connection is opened or closed without this module
void reset()
{
  resetPins();        // reset pins
  sendSensorValues(); // protocol handshaking
  lastDataReceivedTime = millis();
}

void updateActuator(byte pinNumber)
{
  if (arduinoPins[pinNumber].type==digital)
    digitalWrite(pinNumber, arduinoPins[pinNumber].state);
  else if (arduinoPins[pinNumber].type==pwm)
    analogWrite(pinNumber, arduinoPins[pinNumber].state);
}

void sendUpdateServomotors()
{
  for (byte p = 0; p < 10; p++)
    if (arduinoPins[p].type == servomotor)
      servo(p, arduinoPins[p].state);
}

void servo (byte pinNumber, byte angle)
{
  if (angle != 255)
    pulse(pinNumber, (angle * 10) + 600);
}

void pulse (byte pinNumber, unsigned int pulseWidth)
{
  digitalWrite(pinNumber, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(pinNumber, LOW);
}

// the reset is necessary
// when using an wireless arduino board (because we need to ensure that arduino isn't waiting the actuators state from Scratch)
// or when scratch isn't sending information (because is how serial port close is detected)
void checkScratchDisconnection()
{
  //reset state if actuators reception timeout = one second
  if (millis() - lastDataReceivedTime > 1000)
    reset();
}

