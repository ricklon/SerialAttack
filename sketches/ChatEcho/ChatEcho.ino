void setup()
{
  Serial.begin(9600);
  Serial0.begin(9600);  
  Serial.println("Hi MyBoard");
}

void loop()
{
  char inChar;
  if(Serial.available() > 0) 
  {
    inChar = Serial.read();
    Serial.print(inChar);
    Serial0.print(inChar);
  }
  if(Serial0.available() > 0) 
  {
    inChar = Serial0.read();
    Serial.print(inChar);
  }
}
