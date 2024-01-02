/*
 * @Author: Donnie
 * @LastEditors: Donnie
 * @Date: 2023-12-24 18:20:59
 * @LastEditTime: 2024-01-02 23:17:12
 */
/*
OLED
https://wokwi.com/projects/333530915200303699
*/
/*
SW420
DO -> D1-D5
GND -> GND
VCC -> 3V3
*/

#include <U8g2lib.h>
#include <Wire.h>
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void setup()
{
    Serial.begin(115200);
    u8g2.setBusClock(800000); // 设置时钟

    u8g2.begin();
    u8g2.enableUTF8Print(); // 允许UTF8
}

const int sensorPin = 5;
int count = 0;
void loop()
{

    int sensorValue = digitalRead(sensorPin); // Read the sensor value (HIGH or LOW)

    if (sensorValue == HIGH)
    {
        // Serial.println("Vibration detected!"); // Output a message when vibration is detected
        showText();
    }
    else
    {
        // Serial.println("No vibration detected.");
    }

    delay(50); // Delay for one second before checking again
}

void showText()
{
    count += 1;

    u8g2.clearBuffer(); // clear the internal memory
    u8g2.setCursor(10, 15);
    u8g2.setFont(u8g2_font_wqy16_t_gb2312b); // 换成中文字体
    u8g2.print("功德+1");
    u8g2.setCursor(10, 30);
    u8g2.setFont(u8g2_font_wqy12_t_gb2312b); // 换成中文字体
    u8g2.print("累计功德：");
    u8g2.print(count);
    u8g2.sendBuffer(); // transfer internal memory to the display
    delay(500);

    u8g2.clearBuffer(); // clear the internal memory
    u8g2.setCursor(10, 15);
    u8g2.print("");
    u8g2.sendBuffer(); // transfer internal memory to the display
    u8g2.setCursor(10, 30);
    u8g2.setFont(u8g2_font_wqy12_t_gb2312b); // 换成中文字体
    u8g2.print("累计功德：");
    u8g2.print(count);
    u8g2.sendBuffer(); // transfer internal memory to the display
}

// const int sensorPin = 5; // Define the pin to which the SW-420 sensor is connected

// void setup() {
//   Serial.begin(115200); // Initialize serial communication for debugging
//   pinMode(sensorPin, INPUT); // Set the sensor pin as an input
// }

// void loop() {
// int sensorValue = digitalRead(sensorPin); // Read the sensor value (HIGH or LOW)

// if (sensorValue == HIGH) {
//   Serial.println("Vibration detected!"); // Output a message when vibration is detected
// } else {
//   Serial.println("No vibration detected.");
// }

// delay(500); // Delay for one second before checking again
// }
