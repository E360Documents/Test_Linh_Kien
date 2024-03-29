
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
LiquidCrystal_I2C lcd(0x3F, 16, 2);
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init(); 
  lcd.init();
  lcd.backlight();  // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
       lcd.setCursor(2, 0);
    lcd.print("PASS LOADING ...");
}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  char letter;
  for (char i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "C1 F6 93 24") //change here the UID of the card/cards that you want to give access
  {
    lcd.setCursor(2, 0);
    lcd.print("Authorized access");
    Serial.println("Authorized access");
    Serial.println();
    delay(3000);
  }
 
 else   {
       lcd.setCursor(2, 0);
    lcd.print("Access denied");
    Serial.println(" Access denied");
    delay(3000);
  }
} 