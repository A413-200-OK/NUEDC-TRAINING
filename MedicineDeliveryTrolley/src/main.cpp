#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "MotorControl.h"
#include "EncoderInterrupt.h"
#include "PIDController.h"

// 创建电机控制对象
MotorControl motor;
// 创建编码器中断处理对象
EncoderInterrupt encoder;
// 创建左电机的 PID 控制器，设置初始参数
PIDController pidLeft(1, 0.1, 0.01);
// 创建右电机的 PID 控制器，设置初始参数
PIDController pidRight(1, 0.1, 0.01);

// 设定小车的目标速度
const int setSpeed = 100;
// 控制周期，单位为毫秒
const TickType_t pidControlInterval = pdMS_TO_TICKS(100); 
// 其他控制任务执行间隔，单位为毫秒
const TickType_t otherControlInterval = pdMS_TO_TICKS(1000); 

// PID 控制任务
void pidControlTask(void *pvParameters) {
    TickType_t lastWakeTime = xTaskGetTickCount();

    while (1) {
        // 获取左编码器的计数
        long leftCount = encoder.getLeftEncoderCount();
        // 获取右编码器的计数
        long rightCount = encoder.getRoundEncoderCount();

        // 使用左电机的 PID 控制器计算输出值
        int leftOutput = pidLeft.compute(setSpeed, leftCount);
        // 使用右电机的 PID 控制器计算输出值
        int rightOutput = pidRight.compute(setSpeed, rightCount);

        // 设置左电机的速度
        motor.setMotorSpeed(1, leftOutput);
        // 设置右电机的速度
        motor.setMotorSpeed(2, rightOutput);

        // 重置编码器的计数
        encoder.resetCounts();

        // 等待下一个控制周期
        vTaskDelayUntil(&lastWakeTime, pidControlInterval);
    }
}

// 其他控制任务示例
void otherControlTask(void *pvParameters) {
    TickType_t lastWakeTime = xTaskGetTickCount();

    while (1) {
        // 这里可以添加其他控制代码，例如读取传感器数据、通信等
        Serial.println("Other control task is running...");

        // 等待下一次执行
        vTaskDelayUntil(&lastWakeTime, otherControlInterval);
    }
}

void setup() {
    // 初始化串口通信，波特率为 115200
    Serial.begin(115200);

    // 创建 PID 控制任务
    xTaskCreate(pidControlTask, "PID Control Task", 2048, NULL, 1, NULL);
    // 创建其他控制任务
    xTaskCreate(otherControlTask, "Other Control Task", 2048, NULL, 1, NULL);

    // 删除主循环任务，因为所有任务都在后台运行
    vTaskDelete(NULL);
}

void loop() {
    // 主循环为空，所有任务在后台运行
}