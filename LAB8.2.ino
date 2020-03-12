#include<splash.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include<gfxfont.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height,in pixels
#define OLED_RESET  -1 // Reset pin # (or 1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int rx = 0;
int tx = 1;
int READ;
int VR = A1;
void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  pinMode(rx,OUTPUT);
  pinMode(tx,INPUT);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Welcome");
  display.display();
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  READ = analogRead(VR);
  Serial.print(READ);
  String ar2 = Serial.readString();
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.println(ar2);
  display.display();
  delay(1000);
}
