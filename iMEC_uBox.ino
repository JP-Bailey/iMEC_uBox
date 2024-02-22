/**
* iMEC_uBox - Simple program to control a useless box
* @Authors - Josiah Bailey & Gabe O'Brien  
* @Version 1.0
*/

#include <Servo.h>
#include <stdio.h>

// create servo object to control a servo
Servo myservo;  

//Variables 
int switchValue = 0; //variable to store the value of the switch 

void setup() 
{
  myservo.attach(9);       // attaches the servo on pin 9 to the servo object
  pinMode(2,INPUT);        // configures pin 2 to be a digital input
  command_zero(myservo);   // Commands servo to its intial position
}

//Start of main loop 
void loop() 
{

  //Reads state of toggle switch 

  // Turns off switch if active
  
  // Reads state of toggle switch

  // Returns home if switch is off
 
  
}

//Start of functions 


//Function command_zero commands the servo to the home position
void command_zero (Servo &theServo)
{
  //Pass the servo the value for home position
}

//Function command_full commands the servo to full position 
void command_full (Servo &theServo)
{
  //Pass the servo the value for full position 
}


