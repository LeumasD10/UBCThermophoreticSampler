

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
const int D13 = 13;
boolean wasoff = true;
double t0 = 0;
double timer = 0;
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(D13, OUTPUT);
  pinMode(7,INPUT);
//  pinMode(9,OUTPUT);
//  digitalWrite(9,LOW);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println(F("START"));
  display.display();      // Show initial text
  delay(100);
  
}

void loop() {
  // put your main code here, to run repeatedly
  
  if (digitalRead(7) == HIGH) {
    if (wasoff == true) {
      // start timer
      t0 = millis();
      display.clearDisplay();
      display.setTextSize(2); // Draw 2X-scale text
      display.setTextColor(WHITE);
      display.setCursor(10, 0);
      display.println(F("TIMING..."));
      display.display();      // Show initial text
      wasoff = false;
    }
  } 
  else {
    if (wasoff == false) {
      // stop timer
      timer = millis() - t0;
      t0 = timer;
      // display timer here
      display.clearDisplay();
      display.setTextSize(2); // Draw 2X-scale text
      display.setTextColor(WHITE);
      display.setCursor(10, 0);
      display.print(F("T:"));
      display.println((timer/1000));
      display.display();      // Show initial text
      wasoff = true;
      timer = 0;
    }
  }
}
