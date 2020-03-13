int ledDelay =1000;
int buttonPin23=23;
int bpI=0;
int ledI=0;
int ledPinRed=5;
int buttonState;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPinRed,OUTPUT);  // set Pin #5 for output mode
pinMode(buttonPin23,INPUT);

Serial.begin (9600);
while(!Serial);  //wait for serial monitor to go on-line
Serial.println();
Serial.println("READY TO GO");
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(buttonState);

if (buttonState==HIGH)
{
  buttonState=digitalRead(buttonPin23);
  bpI= bpI+1;
  Serial.println(bpI);
  if (ledI < bpI)
    {
      for (ledI=0; ledI<bpI; ledI++)
    {
      Serial.println("LED ACTIVATE");
      digitalWrite(ledPinRed,125);  //Turn RED LED pin ON
      delay(ledDelay);
      digitalWrite(ledPinRed,0);   //Turn RED LED pin OFF
      delay(ledDelay);
    }
  }
}
/*   
if (buttonState==LOW)
{
   Serial.println("Button is NOT pressed");
   digitalWrite(ledPinRed,0);   //Turn RED LED pin OFF
}
else
{
  Serial.println("Button is PRESSED");
  digitalWrite(ledPinRed,125);  //Turn RED LED pin ON
}
delay(ledDelay);
*/
}
