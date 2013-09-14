#include <AFMotor.h>
#include <Servo.h> 

/*
This was coded minutes after I learned that my old dog and friend passed away
I'll miss you Brownie
2013-09-13
*/

int posS1 = 0;         // variable to store the servo position
int posS1min = 0;      //initial position
int posS1max = 180;    //final position
int posS1p;            //increment in position value 
int posS1m;            //decrement of position value
int incomingByte = 0;  // for incoming serial data
int currentPosS1;      //current position 1


Servo servo1;  // create servo object to control a servo. A maximum of eight servo objects can be created 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Arduino code starting");

  servo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  servo1.write(posS1min); //set the servos position to 0 degrees


  /* ascii codes for the keys to de used:
   a = 97
   s= 115
   d = 100
   w = 119
   x = 120
   */

}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

  switch(incomingByte){
    case 97: 
      if(posS1 > 180){
        posS1=170;
      }
      posS1 += 10; 
      servo1.write(posS1);
      currentPosS1 = servo1.read();
      Serial.print("Current position: ");
      Serial.println(currentPosS1);
      break;
    case 100:
      if(posS1 < 0){
        posS1=10;
      }
      posS1 -= 10; 
      servo1.write(posS1);
      currentPosS1 = servo1.read();
      Serial.print("Current position: ");
      Serial.println(currentPosS1);
      break;
    case 119:
      servo1.write(180);
      currentPosS1 = servo1.read();
      Serial.print("Current position: ");
      Serial.println(currentPosS1);      
      break;
    case 115:
      servo1.write(0);
      currentPosS1 = servo1.read();
      Serial.print("Current position: ");
      Serial.println(currentPosS1);
      break;
    case 120:
      Serial.println("Quitting!");
      break;
    default:
      incomingByte = 0;
    }
  Serial.print("Current position requested: ");
  Serial.println(posS1);
  incomingByte = 0;
  }  
}

