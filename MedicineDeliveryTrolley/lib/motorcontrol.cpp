#include "MotorControl.h"

MotorControl::MotorControl() {
  // 初始化电机控制引脚为输出模式
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWM, OUTPUT);
}

void MotorControl::setMotorSpeed(int in1, int in2, int speed) {
  if (speed > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(PWM, speed);
  } else if (speed < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(PWM, -speed);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(PWM, 0);
  }
}

void MotorControl::forward(int speed) {
  setMotorSpeed(AIN1, AIN2, speed);
  setMotorSpeed(BIN1, BIN2, speed);
}

void MotorControl::backward(int speed) {
  setMotorSpeed(AIN1, AIN2, -speed);
  setMotorSpeed(BIN1, BIN2, -speed);
}

void MotorControl::turnLeft(int speed) {
  setMotorSpeed(AIN1, AIN2, -speed);
  setMotorSpeed(BIN1, BIN2, speed);
}

void MotorControl::turnRight(int speed) {
  setMotorSpeed(AIN1, AIN2, speed);
  setMotorSpeed(BIN1, BIN2, -speed);
}

void MotorControl::stop() {
  setMotorSpeed(AIN1, AIN2, 0);
  setMotorSpeed(BIN1, BIN2, 0);
}