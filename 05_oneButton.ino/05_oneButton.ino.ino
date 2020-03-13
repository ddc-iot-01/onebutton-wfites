/*
 * Project: Using OneButton library (from open source code library in include statement)
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: Ted Fites
 * Date: 3/3/20
 * Program function:
 * 1st SINGLE click: LED flash 1x
 * 2nd SINGLE click: LED off
 * 1st DOUBLE click: LED flash 2x
 * 2nd DOUBLE click: LED flash off
*/

#include <OneButton.h>  //pre-compiler directive pulls in library referencing OneButton object

// Setup OneButton on pin 23 object instance button1
OneButton button1(23,false);  // SET TO PIN 23, pulldown as false

// Declare global variables
int buttonState = LOW;
int flash=LOW;
int ledDelay=50; // use quick delay (1/20 of a second)
int ledPinRed5 =5;

void setup() {
pinMode(ledPinRed5,OUTPUT);
Serial.begin(9600);
while(!Serial);
Serial.println("STILL WORKING");
  // Setup Serial Monitor
  // Link oneButton library to functions click1, doubleclick1, longPressStart1
  button1.attachClick(click1); // object instance.method.function use in class
  button1.attachDoubleClick(doubleclick1);  //use in class
  //button1.attachLongPressStart(longPressStart1);
  //button1.attachLongPressStop(longPressStop1);
  button1.setClickTicks(250); //ms amount allowed as CLICK
  button1.setPressTicks(2000); //ms amount allowed as PRESS
} 

void loop() 
{
  // keep watching the push buttons:
  button1.tick(); // check behavior of button (click,doubleclick, long press)
if (buttonState==LOW)
    {
//    Serial.println("Button NOT pressed");
    digitalWrite(ledPinRed5, LOW);
    }
else //buttonState is HIGH
{
digitalWrite(ledPinRed5,HIGH); //??
}
  {
  if (flash==LOW)
      {
//      Serial.println("MAIN LOOP: SINGLE button click");
      digitalWrite(ledPinRed5, 1);
      delay(ledDelay);
      }
  else // flash is HIGH     
      {
//      Serial.println("MAIN LOOP: D O U B L E  button click");
      digitalWrite(ledPinRed5, 1);
      delay(ledDelay);
      digitalWrite(ledPinRed5, 1);
      delay(ledDelay);
      buttonState =!buttonState;  
//      Serial.print("MAIN LOOP: buttonState >");Serial.println(buttonState);
      }    
  }  // END first else
} // END loop

// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time. Changes button state
void click1() 
{
//change and print buttonState
Serial.print("Button CLICK1");Serial.print(" buttonState >"); Serial.println(buttonState);
buttonState = !buttonState;
Serial.print("buttonState >"); Serial.println(buttonState);
} // click1
 
// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() 
{
// change state of flash and print
Serial.print("Button DOUBLE1 click");Serial.print(" FLASH >");Serial.println(flash);
flash=!flash;
Serial.print("FLASH >");Serial.println(flash);
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
// print longPress
void longPressStart1() 

{
}
