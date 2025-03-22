/*定义电机控制库
* 电机控制库包含了电机的前进、后退、左转、右转、停止等功能
* 电机控制库的构造函数为MotorControl()
* 电机控制库的成员函数有forward(int speed)、backward(int speed)、turnLeft(int speed)、turnRight(int speed)、stop()  等
* 电机控制库的私有函数有setMotorSpeed(int in1, int in2, int speed)
* 电机控制库的私有变量有AIN1、AIN2、BIN1、BIN2、PWM
* 电机控制库的作者为loong2525
* 电机控制库的版本为V1.0
*/


#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "hardware.h"
#include <Arduino.h>

class MotorControl {
  public:
    MotorControl();
    void forward(int speed);
    void backward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);
    void stop();
  private:
    void setMotorSpeed(int ain1, int ain2, int speed);
};

#endif