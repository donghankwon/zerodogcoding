void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

int input=0;
int note[5]={2093, 2349, 2637, 2793, 3136};

void loop() { 
  // put your main code here, to run repeatedly:
  input=analogRead(A0);
  Serial.println(input);
  
  if(input<205)
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    if(input<10) tone(3, 0);
    if(input>=10) tone(3, note[0]);  
  }
  else if(input<410)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);  
    tone(3, note[1]);
  }
  else if(input<615)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW); 
    tone(3, note[2]); 
  }
  else if(input<820)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);  
    tone(3, note[3]);
  }
  else if(input<1024)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);  
    tone(3, note[4]);
  }
}
