# Adafruit SSD1306

## 类概述
Adafruit_SSD1306 类用于与 SSD1306 OLED 显示屏进行交互，它继承自 Adafruit_GFX 类。该类提供了一系列方法，用于初始化显示屏、绘制图形、控制显示效果等。
## 构造函数
推荐使用的构造函数：
* Adafruit_SSD1306(uint8_t w, uint8_t h, TwoWire *twi = &Wire, int8_t rst_pin = -1, uint32_t clkDuring = 400000UL, uint32_t clkAfter = 100000UL);：使用 I2C 接口初始化。
* Adafruit_SSD1306(uint8_t w, uint8_t h, int8_t mosi_pin, int8_t sclk_pin, int8_t dc_pin, int8_t rst_pin, int8_t cs_pin);：使用软件 SPI 接口初始化。
* Adafruit_SSD1306(uint8_t w, uint8_t h, SPIClass *spi, int8_t dc_pin, int8_t rst_pin, int8_t cs_pin, uint32_t bitrate = 8000000UL);：使用硬件 SPI 接口初始化。
不推荐使用的构造函数（用于向后兼容）：
* Adafruit_SSD1306(int8_t mosi_pin, int8_t sclk_pin, int8_t dc_pin, int8_t rst_pin, int8_t cs_pin);
* Adafruit_SSD1306(int8_t dc_pin, int8_t rst_pin, int8_t cs_pin);
* Adafruit_SSD1306(int8_t rst_pin = -1);
## 使用
### 初始化
在使用 OLED 屏幕之前，需要调用 begin 方法进行初始化：

`bool begin(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = 0, bool reset = true, bool periphBegin = true);`
* switchvcc：VCC 选择，通常使用 SSD1306_SWITCHCAPVCC 表示使用内部升压电路。
* i2caddr：I2C 地址，默认值为 0，会根据屏幕高度自动选择合适的地址。
* reset：是否进行硬件复位，默认为 true。
* periphBegin：是否调用外设的 begin 方法，默认为 true。
### 基本显示操作
1. 清屏：
`void clearDisplay(void);`
该方法将显示缓冲区的所有像素设置为黑色，但不会立即更新屏幕，需要调用 display 方法才能生效。
2. 更新显示：
`void display(void);`
将当前显示缓冲区的数据推送到 OLED 屏幕上，使绘制的图形或文字可见。
### 绘制图形
1. **绘制单个像素**：
`void drawPixel(int16_t x, int16_t y, uint16_t color);`
在指定的坐标 (x, y) 处绘制一个像素，颜色可以是 SSD1306_BLACK、SSD1306_WHITE 或 SSD1306_INVERSE。
2. 绘制水平线：
`virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);`
在指定的坐标 (x, y) 处绘制一条宽度为 w 的水平线。
3. 绘制垂直线：
`virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);`
在指定的坐标 (x, y) 处绘制一条高度为 h 的垂直线。
4. 
`drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)`
功能：在屏幕上绘制一条直线。(x0, y0) 是直线的起始坐标，(x1, y1) 是直线的结束坐标，color 是直线的颜色，可以是 SSD1306_BLACK、SSD1306_WHITE 或 SSD1306_INVERSE。

`drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)`
功能：在屏幕上绘制一个圆形。(x0, y0) 是圆心的坐标，r 是圆的半径，color 是圆的颜色。

`fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)`
功能：绘制一个填充的圆形。参数含义与 drawCircle 函数相同。

`drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t radius, uint16_t color)`
功能：绘制一个圆角矩形。(x, y) 是矩形左上角的坐标，w 是矩形的宽度，h 是矩形的高度，radius 是圆角的半径，color 是矩形的颜色。

`fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t radius, uint16_t color)`
功能：绘制一个填充的圆角矩形。参数含义与 drawRoundRect 函数相同。
5. 确定文本的显示位置
`void setCursor(int16_t x, int16_t y);`
(x, y)：文本起始位置的坐标。

### 显示控制
1. 反显模式：
`void invertDisplay(bool i);`
如果 i 为 true，则开启反显模式（黑底白字变为白底黑字）；否则恢复正常模式。
1. 亮度调节：
`void dim(bool dim);`
如果 dim 为 true，则降低屏幕亮度；否则恢复正常亮度。
1. 滚动控制
* 开始向右滚动：
`void startscrollright(uint8_t start, uint8_t stop);`
* 开始向左滚动：
`void startscrollleft(uint8_t start, uint8_t stop);`
* 开始向右对角线滚动：
`void startscrolldiagright(uint8_t start, uint8_t stop);`
* 开始向左对角线滚动：
`void startscrolldiagleft(uint8_t start, uint8_t stop);`
* 停止滚动：
`void stopscroll(void);`
### 其他操作
1. 获取显示缓冲区指针：
`uint8_t *getBuffer(void);`
返回显示缓冲区的指针，可用于直接读写缓冲区数据。
1. 获取像素颜色:
`bool getPixel(int16_t x, int16_t y);`
返回指定坐标 (x, y) 处像素的颜色，true 表示白色，false 表示黑色。
##示例代码
``` cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear the buffer
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  // Print some text
  display.println("Hello, ESP32!");

  // Draw a rectangle
  display.drawRect(10, 20, 50, 30, SSD1306_WHITE);

  // Update the display
  display.display();
}

void loop() {
  // You can add more drawing or control code here
  delay(1000);
}
```