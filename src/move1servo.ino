#include <Servo.h> 

/*
This was coded minutes after I learned that my old dog and friend passed away
I'll miss you Brownie
2013-09-13
*/

int posS1 = 0;         // variable to store the servo position
int posS2 = 0;         // variable to store the servo position
int posS1i = 0;        // servo 1 initial position
int posS2i = 0;      // servo 2 initial position
int incomingByte = 0;  // for incoming serial data
int currentPosS1;      //current position servo 1
int currentPosS2;      //current position servo 2


Servo servo1;  // create servo object to control a servo. A maximum of eight servo objects can be created 
Servo servo2;  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Arduino code starting");

  servo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  servo2.attach(10);  // attaches the servo on pin 9 to the servo object 
  servo1.write(posS1i); //set the servo position to 0 degrees
  servo2.write(posS2i); //set the servo position to 0 degrees


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
      Serial.print("S1 Current position: ");
      Serial.println(currentPosS1);
      break;
    case 100:
      if(posS1 < 0){
        posS1=10;
      }
      posS1 -= 10; 
      servo1.write(posS1);
      currentPosS1 = servo1.read();
      Serial.print("S1 Current position: ");
      Serial.println(currentPosS1);
      break;
    case 119:
      if(posS2 > 180){
        posS2=170;
      }
      posS2 += 10; 
      servo2.write(posS2);
      currentPosS2 = servo2.read();
      Serial.print("S2 Current position: ");
      Serial.println(currentPosS2);      
      break;
    case 115:
      if(posS2 < 0){
        posS2=10;
      }
      posS2 -= 10; 
      servo2.write(posS2);
      currentPosS1 = servo2.read();
      Serial.print("S2 Current position: ");
      Serial.println(currentPosS2);
      break;
    case 120:
      Serial.println("Reset servo to default position");
      servo1.write(posS1i);
      servo1.write(posS2i);
      posS1 = 0;
      break;
    default:
      incomingByte = 0;
    }
  Serial.print("S1 Current position requested: ");
  Serial.println(posS1);
  Serial.print("S2 Current position requested: ");
  Serial.println(posS2);
  incomingByte = 0;
  }  
}

