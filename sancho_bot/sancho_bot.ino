#define trigPin 9
#define echoPin 10

#include "motors.h"
#include "motors.h"                         


motors left_motor(4,5);


int state = 0;

void setup()                                 // Built in initialization block
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}  
 
void loop()                                  // Main loop auto-repeats
{    
//  left_motor.motor_cmd(1);
//  delay(1000);
//  left_motor.motor_cmd(0);
//  delay(1000);
//  left_motor.motor_cmd(-1);
//  delay(1000);
//  left_motor.motor_cmd(0);
//  delay(1000);

  read_ultra();

   
  
}


long read_ultra(){
  int distance;
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}

void bluetooth_control(){
  if(Serial.available() > 0){
    state = Serial.read();   
  }
  if(state == '1'){ //FORWARD
    left_motor.motor_cmd(1);
    //right_motor.motor_cmd(1);
  }else if(state == '2'){ //REVERSE
    left_motor.motor_cmd(-1);
    //right_motor.motor_cmd(-1);
  }else if(state == '3'){ //LEFT
    left_motor.motor_cmd(-1);
    //right_motor.motor_cmd(1);  
  }else if(state == '4'){ //RIGHT
    left_motor.motor_cmd(1);
    //right_motor.motor_cmd(-1);
  }
}



