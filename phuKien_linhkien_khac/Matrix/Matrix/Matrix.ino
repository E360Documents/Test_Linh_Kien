#include <Wire.h>
#include <string.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

//setup lcd
LiquidCrystal_I2C lcd(0x3F, 16, 2);
//setup Keypad
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {8, 9, 10, 11}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
///CONST
char PASS_WORD[4] = {'2', '0', '0', '1'};
char array_pass[4];
char* pass_1 = "2001";
int i = 0;
////void

void lcd_Display();
unsigned char InputPassWord();


//main
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("CLOSE");
  lcd.setCursor(0, 1);
  lcd.print("PASSWORD: ");
}
int lcd_pass_pos = 8;
void loop() {

  //  char key = keypad.getKey();
  //  if (key) {
  //    lcd_pass_pos++;
  //    lcd.setCursor(lcd_pass_pos, 1);
  //    lcd.print(key);
  //    if (key == pass_1)
  //    {
  //      lcd.setCursor(5, 0);
  //      lcd.print("               ");
  //      lcd.setCursor(5, 0);
  //      lcd.print("OPEN");
  //      lcd.setCursor(0, 1);
  //      lcd.print("           ");
  //    }
  //    else
  //    {
  //      lcd.setCursor(5, 0);
  //      lcd.print("     ");
  //      lcd.setCursor(5, 0);
  //      lcd.print("Repeat");
  //      lcd.setCursor(0, 1);
  //      lcd.print("PASSWORD: ");
  //      lcd.setCursor(8,1);
  //      lcd.print("           ");
  //    }
  //  }
  //


  //    while (i < 4)
  //    {
  //      char key = keypad.getKey();
  //      if (key) {
  //        if (key) {
  //        lcd_pass_pos++;
  //        lcd.setCursor(lcd_pass_pos, 1);
  //        lcd.print(key);
  //        array_pass[i] = key;
  //        Serial.println(array_pass);
  //        key = 0;
  //        i++;
  //
  //      }
  //    }
  //    }
  char key = keypad.getKey();
  if (key)
  {
    lcd_pass_pos++;
    lcd.setCursor(lcd_pass_pos, 1);
    lcd.print("*");
    Serial.println(i);
    if (key == pass_1[i]) {
      Serial.println(key);
      Serial.println(pass_1[i]);
      i++;
      if (i == 4) {
        lcd.setCursor(0, 0);
        lcd.print("                 ");
        lcd.setCursor(5, 0);
        lcd.print("OPEN  ");
        lcd.setCursor(0, 1);
        lcd.print("                 ");
        lcd.setCursor(5, 1);
        lcd.print("SuccesFull");
        Serial.println("SuccesFull");
        Serial.println(pass_1); Serial.println(array_pass);
        i = 0;
      }
      Serial.println(i);
    }
    else {
      lcd.setCursor(0, 0);
      lcd.print("                 ");
      lcd.setCursor(5, 0);
      lcd.print("Warring");
      Serial.println("ERROR !");
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("                 ");
      lcd.setCursor(2, 0);
      lcd.print("Enter Again");
      lcd.setCursor(0, 1);
      lcd.print("                 ");
      lcd.setCursor(0, 1);
      lcd.print("PASSWORD: ");
      lcd_pass_pos = 8;
      i = 0;
      Serial.println(key); Serial.println(pass_1[i]);
    }
  }
 
}
