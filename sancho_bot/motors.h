/*
  Motors.h - This library is used to set motor speed and direction
  Dependencies : ros.h - This library provides Float32 ROS message type. 
  This data type is passed through to set PWM duty cyle.
  Created by Juan Huerta, Kevin Beher, Kelvin Silva  
*/

#ifndef MOTORS_H
#define MOTORS_H

#include "Arduino.h"
#include <ros.h>
#include <std_msgs/Float32.h>


class motors
{
  private:
    int m_dir1;
    int m_dir2;
    void motor_forward();
    void motor_reverse();
    void motor_brake(); 
  
  public:
    motors(int motor_direction_pin1, int motor_direction_pin2);
    void motor_cmd(float motor_speed);
    void check_motor_stall(float curr_encoder_val);
};

#endif
