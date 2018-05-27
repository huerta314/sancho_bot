/*
  Motors.cpp -
  Created by Juan Huerta and Kevin Beher
*/

#include "Arduino.h"
#include "motors.h"

/*
| Author: Juan Huerta
| Param: Digital Pins values on the Teensy used as PWM and
|    motor direction and direction enables
| Remark: This constructor sets the pin numbers given as private
|    variables of the class
*/
motors::motors(int motor_direction_pin1, int motor_direction_pin2) {
    pinMode(motor_direction_pin1, OUTPUT); //motor direction en1
    pinMode(motor_direction_pin2, OUTPUT); //motor direction en2
    m_dir1 = motor_direction_pin1;
    m_dir2 = motor_direction_pin2;
}

/*
| Author: Juan Huerta
| Param:  Positive or negative PWM value
| Remark: Calls motor_forward if motor_speed in positive,
|         calls motor_reverse if motor_speed is negative,
|         calls motor_brake if motor_speed is zero
|         updates last_motor_cmd variable with last past motor_speed.
*/
void motors::motor_cmd(float motor_speed) {
    if (motor_speed > 0) {
        motor_forward();
    } else if (motor_speed < 0) {
        motor_reverse();
    } else {
        motor_brake();
    }
}

/*
| Author: Juan Huerta
| Param: motor_speed, 0-255
| Return: Void
| Remark: This function sets PWM duty cycle of the right
|    motor and sets directions pins to rotate the motor forward
*/
void motors::motor_forward() {
    digitalWrite(m_dir1, HIGH);
    digitalWrite(m_dir2, LOW);
}

/*
| Author: Juan Huerta
| Param: motor_speed, 0-255
| Return: Void
| Remark: This function sets PWM duty cycle of the right
|    motor and sets directions pins to rotate the motor in reverse
*/
void motors::motor_reverse() {
    digitalWrite(m_dir1, LOW);
    digitalWrite(m_dir2, HIGH);
}

/*
| Author: Juan Huerta
| Param: None
| Return: Void
| Remark: This function sets motor direction pins to zero
|    and PWM duty cycle to zero to brake the motor
*/
void motors::motor_brake() {
    digitalWrite(m_dir1, LOW);
    digitalWrite(m_dir2, LOW);
}
