//#include <HID.h>
//#include "HX711.h"
#define DOUT  3
#define CLK  2
int strobePin = 4;
//Pin connecte.......................................................d to Data (pin 2) of 4094
int dataPin = 5;
//Pin connected to Clock (pin 3) of 4094
int clockPin = 3;
//code 5x7
byte segChar[] = {0xfc, 0x60, 0xda, 0xf2, 0x66, 0xb6, 0xbe, 0xe0, 0xfe , 0xf6};
byte segChardot[] ={0xfd, 0x61, 0xdb, 0xf3, 0x67, 0xb7, 0xbf, 0xe1, 0xff, 0xf7};
//code 3x4
//byte segChar[] = {0x05, 0x3f, 0x46, 0x16, 0x3c, 0x94, 0x84, 0x37, 0x04, 0x14, 0xfe,0x00,0xff};
//byte segChardot[] ={0x01, 0x3B, 0x42, 0x12, 0x38, 0x90, 0x80, 0x33, 0x00, 0x10, 0xfa};// font 3x4 co dau cham.
int t;

//HX711 scale;

float calibration_factor = 1370;
float units;
float ounces;

void setup()
 {                                           
  pinMode(strobePin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
  //scale.begin(DOUT, CLK);
  Serial.println("HX711 weighing");
  //scale.set_scale(calibration_factor);
  //scale.tare();
  Serial.println("Readings:");
}

void loop()
{
  int i ;
  for(i=0; i< 10; i++)
  { 
    //segChar[i] = t; 
    Serial.print(i);
    hienthit (i);
    //Serial.println("HX711 weighing");
    delay(1000);
  }

for(i=0; i< 10; i++)
  { 
    //segChar[i] = t; 
    Serial.print(i);
    hienthit1 (i);
    //Serial.println("HX711 weighing");
    delay(1000);
  }
    
//}
}
//
void hienthit(float t){
  unsigned char tramnghin =0, chucnghin=0, thousand=0, hundred=0, ten=0, unit=0;
 unsigned int t_in;
 // t_in=t*100;
    t_in=t;
    tramnghin = char(t_in/100000);
    chucnghin=char((t_in- tramnghin*100000)/10000);
    thousand=char((t_in- chucnghin*10000)/1000);
    hundred=char((t_in-thousand*1000)/100);
    ten=char((t_in-thousand*1000-hundred*100)/10);
    unit=char(t_in%10);
    tramnghin=unit;
    chucnghin=unit;
    thousand=unit;
    hundred=unit;
    ten=unit;



//    for( char i = 0; i< 4 ; i++)
//    {
  digitalWrite(strobePin, LOW);

  // hien thi ben trai
  shiftOut(dataPin, clockPin, MSBFIRST,segChar[unit]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChar[ten]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChar[hundred]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChar[thousand]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChar[chucnghin]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChar[tramnghin]);

  digitalWrite(strobePin, HIGH);
      delay(10);
//    }
  }

  void hienthit1(float t){
  unsigned char tramnghin =0, chucnghin=0, thousand=0, hundred=0, ten=0, unit=0;
 unsigned int t_in;
 // t_in=t*100;
    t_in=t;
    tramnghin = char(t_in/100000);
    chucnghin=char((t_in- tramnghin*100000)/10000);
    thousand=char((t_in- chucnghin*10000)/1000);
    hundred=char((t_in-thousand*1000)/100);
    ten=char((t_in-thousand*1000-hundred*100)/10);
    unit=char(t_in%10);
    tramnghin=unit;
    chucnghin=unit;
    thousand=unit;
    hundred=unit;
    ten=unit;

  digitalWrite(strobePin, LOW);

  // hien thi ben trai
  shiftOut(dataPin, clockPin, MSBFIRST,segChardot[unit]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChardot[ten]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChardot[hundred]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChardot[thousand]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChardot[chucnghin]);
  shiftOut(dataPin, clockPin, MSBFIRST,segChardot[tramnghin]);
  

  digitalWrite(strobePin, HIGH);
      delay(10);
//    }
  }
