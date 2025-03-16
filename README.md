# NUEDC_TRAINING
**For the NUEDC on 2025 , we use the repository to record our experence**

> (https://www.nuedc-training.com.cn/)


## Trainnig texts
1.  [送药小车](https://www.nuedc-training.com.cn/index/news/details/new_id/259)
### 题目分析
整个过程只有两个动作：直走和转弯，因为题目所给时间太短，所以使用编码电机结合PID算法直接固定直走距离和转弯角度。
对于基本要求一，识别到是近端病房后直接行驶到第一个路口再进行识别来确认是左转或右转
对于基本要求二和三识别到不是近端病房就直接行驶到第二个交叉口再进行数字识别，识别不匹配就行驶到第三个交叉口。
整个过程使用串口通信来和单片机进行数据的传输，对于发挥部分可以使用ESP-NOW，让两块ESP32通过蓝牙来进行通讯。
主要问题：
1：循迹
2：数字识别
方案一：使用OPENMV进行循迹和数字识别，但两者同时进行可能帧率较低，尝试将两者分开，当识别到十字路口和T字路口时停止循迹，开始数字识别
方案二：使用OOENMV进行数字识别，使用灰度传感器进行循迹

## Member existing technology stack
1.  loong2525
*  硬件连接，pcb布线
*  arduino框架下开发esp32
*  oled ，lcd的使用

2.  Z-A-ctrl
*  部分基础模块绘制（降压，电机驱动）
*  硬件连接
* 

3.  riverface
*  pcb布线，硬件连接
* 外观设计
*  

## technology stack required the training text

### To MedicineDeliveryTrolley
*  编码电机与PID算法的结合
*  基础python学习和OPENMV学习
*  串口通信
*  ESP-NOW使用（两车通信）
*  基于platformio对ESP32的开发  
### To 
*  
*  
*  
*  
*  

**Absolute sincerity will move a heart of stone !**

****************************************************************************************

## Calendar && show

分支管理
* master 中为训练题目代码所在分支。
* 三个成员各自创建分支提交学习计划以及学习成果展示
* 不确定功能正确实现的代码创建分支提交，禁止直接提交master分支

## For NUEDA （设备清单）

### 硬件材料
* esp32 WROOM 32
* open MV 
* 热风枪，电烙铁
* 编码电机
* OLED屏幕
* 寻迹模块
### 软件工具链
嘉立创EDA 
VScode.platformIO 
OPEN MV IDE   







# THANKS
