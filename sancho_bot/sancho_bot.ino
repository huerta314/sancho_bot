#define trigPin 9
#define echoPin 10
#define GREENLED 12
#define REDLED 11

#define petTime 5

#include "motors.h"
#include "motors.h"                         
<<<<<<< HEAD
=======
#include < Servo.h >
>>>>>>> fa2d646b5dfb5a69d977b627357ca95e355a64c5

motors left_motor(4,5);
motors right_motor(2,3);

<<<<<<< HEAD
int distance;
long duration;
int green_led_flag;
int red_led_flag;
=======
int pos = 0;
>>>>>>> fa2d646b5dfb5a69d977b627357ca95e355a64c5
int state = 0;

void bluetooth_control();
void read_ultra();

void setup()                                 // Built in initialization block
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
}  
 
void loop()                                  // Main loop auto-repeats
{ 
  bluetooth_control();
  read_ultra();
<<<<<<< HEAD
  if(green_led_flag == 1){
    digitalWrite(GREENLED, HIGH);  
  }else{
    digitalWrite(GREENLED, LOW); 
  }
  if(red_led_flag == 1){
    digitalWrite(REDLED, HIGH);  
  }else{
    digitalWrite(REDLED, LOW); 
  }
=======

  servo_test();
  
   
  
>>>>>>> fa2d646b5dfb5a69d977b627357ca95e355a64c5
}


void read_ultra(){
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
   if(distance <= 1){
     red_led_flag = 1;
   }else{
     red_led_flag = 0;
   }
}

void bluetooth_control(){
  if(Serial.available() > 0){
    state = Serial.read();
    Serial.print(state);   
  }
  if(state == '1'){ //FORWARD
    left_motor.motor_cmd(1);
    right_motor.motor_cmd(1);
    green_led_flag = 1;
  }else if(state == '2'){ //REVERSE
    left_motor.motor_cmd(-1);
    right_motor.motor_cmd(-1);
    green_led_flag = 1;
  }else if(state == '3'){ //LEFT
    left_motor.motor_cmd(-1);
    right_motor.motor_cmd(1);
    green_led_flag = 1;
  }else if(state == '4'){ //RIGHT
    left_motor.motor_cmd(1);
    right_motor.motor_cmd(-1);
    green_led_flag = 1;
  }else if(state == '5'){ //STOP
    left_motor.motor_cmd(0);
    right_motor.motor_cmd(0);
    green_led_flag = 0;
  }
}

void servo_test(){
 
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

 
}




