bool current_B1=LOW;
bool last_B1=LOW;
bool toggle_B1 = false;
bool prevtoggle_B1 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  current_B1=digitalRead(12);
  if(last_B1==LOW && current_B1==HIGH)
  {
    toggle_B1=!toggle_B1;
  }
  last_B1=current_B1;

  if(prevtoggle_B1 != toggle_B1)
  {
      Serial.println(toggle_B1);
      prevtoggle_B1 = toggle_B1;
  }
}
