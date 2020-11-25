#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);    //ประกาศสร้าง oject ที่ใช้ลองรับชื่อของอุปกรณ์

void setup() 
{
  pinMode(2, INPUT_PULLUP); 
  oled.begin(0x3C); // Address 0x3C for 128x32
}

int i = 0;

void loop() {

  oled.clearDisplay();      //ล้างหน้าจอแสดงผล
  oled.setCursor(0, 0);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)

  oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
  oled.setTextSize(1);                      //กำหนดขนาดของตัวหนังสือ(มีตั้งแต่1-3)
  oled.println("Weather clear");            //แสดงคำบนหน้าจอ

  oled.setTextSize(1);                          //กำหนดขนาดของตัวหนังสือ(มีตั้งแต่1-3)
  oled.println("May be rain is coming");        //แสดงคำบนหน้าจอ

  oled.setTextSize(1);                          //กำหนดขนาดของตัวหนังสือ(มีตั้งแต่1-3)
  oled.println("There is raining");             //แสดงคำบนหน้าจอ
  
  oled.display();           //แสดงการทำงานทั้งหมด
  delay(10);            //หน่วงเวลา
}