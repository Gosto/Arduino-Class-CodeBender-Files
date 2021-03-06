/***********************************************************************
 * Exp9_SerialDrive -- RedBot Experiment 9
 * 
 * The first step to controlling the RedBot remotely is to first drive it 
 * from the Serial Monitor in a tethered setup. 
 *
 * Hardware setup:
 * After uploading this sketch, keep the RedBot tethered to your computer with 
 * the USB cable. Open up the Seral Monitor to send commands to the RedBot to 
 * drive. 
 * 
 * This sketch was written by SparkFun Electronics, with lots of help from 
 * the Arduino community. This code is completely free for any use.
 * 
 * 15 Dec 2014 B. Huang 
 * 
 * This experiment was inspired by Paul Kassebaum at Mathworks, who made
 * one of the very first non-SparkFun demo projects and brought it to the
 * 2013 Open Hardware Summit in Boston. Thanks Paul!
 ***********************************************************************/

#include <RedBot.h>
#include <SoftwareSerial.h>
// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(A1, A0); // RX, TX

RedBotMotors motors;
int motorPower;  // variable for setting the drive power
int data;  // variable for holding incoming data from PC to Arduino

void setup(void)
{
 // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  XBee.begin(9600);
  Serial.begin(9600);
}

void loop(void)
{
  // if there is data coming in on the Serial monitor, do something with it.
  if(XBee.available() > 0)
  {
    data = Serial.parseInt();
    data = constrain(data, -255, 255);  // constrain the data to -255 to +255
    motors.drive(data);
  }  
}
