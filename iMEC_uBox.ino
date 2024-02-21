#include <Servo.h>
#include <stdio.h>
//#include <math.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

#define ZEROSPEED 92
#define MAXRATE  529.4   //529.4

//Variables 
int pos = 0;    // variable to store the servo position
int switchValue = 0; //variable to store the value of the switch 

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(2,INPUT);
  myservo.write(92); 

  
}

void loop() {

switchValue = digitalRead(2);

if (switchValue == HIGH)
{


//120 is a good value for counter clockwise
//60 is a good value for clockwise 

    
   speed_disp_dir(myservo, 1, 360.0);
   delay(1000);

}

switchValue = digitalRead(2);

if (switchValue == LOW)
{
  myservo.write(ZEROSPEED);
}

  
}

//Start of functions 

void quarter_c_turn (Servo &theServo)
{
    theServo.write(60);             
    delay(1400);
    theServo.write(ZEROSPEED);
    delay(1000);  
 
}

void speed_disp_dir (Servo &theServo,int rate, float disp)
{

 // Serial.begin(115200);
  
  float maxSpeed = MAXRATE; // Degrees per second 
  float percentMax = 0;
  float selectSpeed = 0;
  float delayLength = 0;
  int truncDelay = 0;

  //Serial.println(rate);
  
  if (rate > 90)
  {
    percentMax = rate/180.0;
  }
  else
  {
    percentMax = (1.0 - (rate/90.0));
  }


  //calculate new rate 
  selectSpeed = maxSpeed * percentMax; 


  //calculate the time required to complete the selected distance
  
  delayLength = selectSpeed;

  delayLength = delayLength * (1.0/disp);

  delayLength = pow(delayLength,-1.0); 

  //Serial.println(delayLength); 

  //Convert to millie seconds 

  delayLength = delayLength * 1000; 
  truncDelay = (int)delayLength; 

  //Serial.println(truncDelay);

  theServo.write(rate);

  

  delay(truncDelay);

  theServo.write(ZEROSPEED);
  
}
