/* Magic Cup Light Module (KY-027) [D020] : http://rdiot.tistory.com/202 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
int pinLed = 11;
int pinInput = 10;
 
int stateA = 0;
int brightness = 0;
int oldBrightness = 0;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(pinLed, OUTPUT);
  pinMode(pinInput, INPUT);  delay(1000);
  digitalWrite(pinInput, HIGH);
 
  lcd.clear();
}
 
void loop()
{ 
  lcd.setCursor(0,0);
  lcd.print("D020:Magic Cup Light");
 
  stateA = digitalRead(pinInput);
 
  if (stateA == HIGH && brightness < 255)
    brightness++;
  if (stateA == LOW && brightness >0)
    brightness--;
  if (oldBrightness != brightness)
  {
    lcd.setCursor(0,1);
    lcd.print("brightness=" + (String)brightness + "  ");
  }
  oldBrightness = brightness;
  analogWrite(pinLed, brightness);
  delay(10); 
}
