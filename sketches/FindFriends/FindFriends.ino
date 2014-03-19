/*
* Find attached Fubarino boards
*
*/
#define MAX_INPUT 200
char gBuf[MAX_INPUT];


int gCount = 0;

void setup()
{
	Serial.begin(9600);
	Serial1.begin(9600);
	Serial2.begin(9600);

	Serial.println("Start Up: Finding Friends");
}

void processIncomingByte( const byte inByte) {
  static char buf[MAX_INPUT];
  static unsigned int ii = 0;
  //Serial.print(inByte);
  switch(inByte)
  {
   case '\r': //terminator reached
    buf[ii] = 0; //terminate array
    Serial.println(buf);
    ii = 0;
    Serial.print("> ");
    break;
   case '\n':
    buf[ii] = 0; //terminate array
    Serial.println(buf);
    ii = 0;
    Serial.print("> ");
    break;
   default:
     if (ii < (MAX_INPUT - 1)) {
      buf[ii++] = inByte; 
     }
     break;
  }
}


void loop() 
{
	gCount++;
	Serial0.println("s0:ping: ");
	Serial0.println(gCount);
	while (Serial0.available() > 0) 
	{
   		processIncomingByte(Serial0.read());
  	}
	Serial1.println("s1:ping: ");
	Serial1.println(gCount);
	while (Serial1.available() > 0) 
	{
   		processIncomingByte(Serial1.read());
  	}
    delay(250);
    Serial.print("LOOP: ");
    Serial.println(gCount);

}