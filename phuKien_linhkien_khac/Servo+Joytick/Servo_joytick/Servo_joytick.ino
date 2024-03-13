#include <Servo.h>
//servo
Servo myServo;
int servoPin=9;
int servoPos=180;
//JoyticK
int Xjoytick=A0;
int Yjoytick=A1;
int Bjoytick=8;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(Xjoytick,INPUT);
  pinMode(Yjoytick,INPUT);
  pinMode(Bjoytick,INPUT);
  myServo.write(0);
  
}

void loop() {
    int XValue=analogRead(Xjoytick);
    int YValue=analogRead(Yjoytick);
    int BValue=digitalRead(Bjoytick);

    //Serial.println(XValue); Serial.println(YValue); Serial.println(BValue);
    int Xservo=map(XValue,0,1023,180,0);
    int Yservo=map(YValue,0,1023,0,180);
    myServo.write(Xservo);
    Serial.println(Xservo);
    //Serial.println(Yservo);
}
