//Green A4 is SDA
//White A5 is SCL


#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

int pPin = 0;
int pRead;

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  //16X2
  //[0,0][][][][][][][][][][][][][][][]
  //[0,1][][][][][][][][][][][][][][][16,2]
  lcd.begin (16,2);   
  
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                   // go home


  //lcd.setCursor(8,0);
  //lcd.print(" YoYo" );
  //lcd.setCursor(0,1); //second row
  //lcd.print("I LOVE YOU <3!");
  
}

void loop()
{
  pRead = analogRead(pPin);
  Serial.print("Analog Reading = ");
  Serial.println(pRead);
  lcd.setCursor(0,0); //first row
  lcd.print("Lumination: ");
  lcd.setCursor(0,1);
  lcd.print(pRead);
  // Backlight on/off every 3 seconds
  //lcd.setBacklight(LOW);      // Backlight off
  delay(3000);
  //lcd.setBacklight(HIGH);     // Backlight on
  //delay(3000);
}
