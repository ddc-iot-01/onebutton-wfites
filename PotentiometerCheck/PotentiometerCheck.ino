/*
 * Project: Potentiometer Check
 * Description: uses potentiometer to show adjustment
 * 
 * Author: Ted Fites
 * Date: 3/3/20
 * Modifications: NOTE: won't work. Potentiometer removed
 * by BA
 */

int inPin=20;
int inputDelay=3000;
int inVal;
float inVolts;

// add program feature to to output to LED
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  pinMode(inPin,INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  inVal=analogRead(inPin);
  Serial.print ("INVAL >");Serial.println(inVal);
  inVolts=in2volt(inVal);
  Serial.print("INVOLTS >"); Serial.println(inVolts);
  delay(inputDelay);
}

float in2volt(float inBits)  //all variabes are float
{
  float volts;
  volts=(inBits/1023)*3.3;
  return volts;  
}
