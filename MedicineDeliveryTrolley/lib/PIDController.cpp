#include "PIDController.h"

// 构造函数，初始化 PID 控制器的参数和积分项、上一次误差
PIDController::PIDController(double kp, double ki, double kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
  integral = 0;
  previousError = 0;
}

// 根据设定值和当前值计算 PID 控制器的输出值
int PIDController::compute(int setpoint, int currentValue) {
  // 计算当前误差
  int error = setpoint - currentValue;
  // 累加误差到积分项
  integral += error;
  // 计算误差的变化率
  int derivative = error - previousError;
  // 计算 PID 输出值
  int output = kp * error + ki * integral + kd * derivative;
  // 更新上一次的误差
  previousError = error;
  return output;
}

// 设置 PID 控制器的参数
void PIDController::setTunings(double kp, double ki, double kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
}