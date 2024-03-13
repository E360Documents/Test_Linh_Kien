#include <hidboot.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

boolean LeftBtn = false; 
boolean RightBtn = false; 
boolean LeftBtnRls = false; 
boolean RightBtnRls = false; 
boolean MouseMoved = false;
int x;
int y;
 

class MouseRptParser : public MouseReportParser
{
protected:
  void OnMouseMove  (MOUSEINFO *mi);
  void OnLeftButtonUp (MOUSEINFO *mi);
  void OnLeftButtonDown (MOUSEINFO *mi);
  void OnRightButtonUp  (MOUSEINFO *mi);
  void OnRightButtonDown  (MOUSEINFO *mi);
};
void MouseRptParser::OnMouseMove(MOUSEINFO *mi)
{
    x = mi->dX;
    y = mi->dY;
    MouseMoved = true; 
};
void MouseRptParser::OnLeftButtonUp (MOUSEINFO *mi)
{
  LeftBtnRls = true; 
};
void MouseRptParser::OnLeftButtonDown (MOUSEINFO *mi)
{
  LeftBtn = true;
};
void MouseRptParser::OnRightButtonUp  (MOUSEINFO *mi)
{
  RightBtnRls = true;
};
void MouseRptParser::OnRightButtonDown  (MOUSEINFO *mi)
{
    RightBtn = true; 
};


USB     Usb;
USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_MOUSE>    HidMouse(&Usb);

MouseRptParser Prs;

void setup()
{
    Serial.begin( 115200 );
#if !defined(__MIPSEL__)
    while (!Serial); 
#endif
    Serial.println("Start");

    if (Usb.Init() == -1)
        Serial.println("OSC did not start.");

    delay( 200 );

    HidMouse.SetReportParser(0, &Prs);
}

void loop()
{
  Usb.Task();
  if(MouseMoved){
    Serial.print("dx = ");
    Serial.print(x); 
    Serial.print(" dy = ");
    Serial.println(y);
    delay(500);
    MouseMoved = false; 
    }
  if(LeftBtn){
    Serial.println("Left Button Pressed");
    LeftBtn = false;
    }
  if(RightBtn){
    Serial.println("Right Button Pressed");
    RightBtn = false;
    }
  if(LeftBtnRls){
    Serial.println("Left Button Released");
    LeftBtnRls = false; 
    }
  if(RightBtnRls){
    Serial.println("Right Button Released");
    RightBtnRls = false;
    }
}
