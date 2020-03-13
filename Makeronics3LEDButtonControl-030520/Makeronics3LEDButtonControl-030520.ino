/*
 * Project: Sawtooth 
 * Description: 3rd program
 * Author: Ted Fites
 * Date: 225/20
 * Program gradually brightens up then dims down LED. USES FOR 
 * LOOP. 
 * Uses pin 5,6 & 7.
 * BREADBOARD WORK: WIRING RESISTOR (230 OHMS) AND RED LED INTO 
 * CIRCUIT. CIRCUIT STARTS AT PIN#5 TO SAME ROW AS START OF RESISTOR
 * (ROW 17) FOLLOWED BY ANOTHER SHORT WIRE ON OTHER SIDE OF RESISTOR
 * IN SAME ROW WITH POSITIVE (CATHODE). CURRENT RESUMES THROU NEGATIVE 
 * OF LED, THEN FINAL WIRE STARTS ON SAME ROW AS NEGATIVE LED
 * LED LEAD TO ROW WITH GROUND (ROW ZERO MATCHING GROUND PIN 
 * ON TEENSY)
 */

 // Connect anode of LED to Pin #5
 // Connect cathode of LED to GND using 200 ohm resistor
// define global variables
int LEDPinRed =5;      // Use pin# 5
int LEDPinGreen =6;      // Use pin# 6
int LEDPinBlue =7;      // Use pin# 7
int LEDDelay= 5; // delay value for duration to brighten/dim
int i;  // loop value to change brightness value

void setup() {
  // put your setup code here, to run once:
pinMode(LEDPinRed,OUTPUT);  // set Pin #5 for output mode
pinMode(LEDPinGreen,OUTPUT);  // set Pin #6 for output mode
pinMode(LEDPinBlue,OUTPUT);  // set Pin #7 for output mode
}

void loop() {
  // put your main code here, to run repeatedly:

  for (i=0;i<256;i++)
  {
    analogWrite(LEDPinRed,i);  // RED pin gradually brightens up
    delay(LEDDelay);
  }
  for (i=255;i>=0;i--)
  {
    analogWrite(LEDPinRed,i);  // RED gradually dims down
    delay(LEDDelay);
  }

  for (i=0;i<256;i++)
  {
    analogWrite(LEDPinGreen,i);  // GREEN pin gradually brightens up
    delay(LEDDelay);
  }
  for (i=255;i>=0;i--)
  {
    analogWrite(LEDPinGreen,i);  // GREEN pin gradually dims down
    delay(LEDDelay);
  }

  for (i=0;i<256;i++)
  {
    analogWrite(LEDPinBlue,i);  // BLUE pin gradually brigthens up
    delay(LEDDelay);
  }
  for (i=255;i>=0;i--)
  {
    analogWrite(LEDPinBlue,i);  // BLUE pin gradually dims down
    delay(LEDDelay);
  }

}
