/// **** Chương Trình LED 7 thanh Chuyên dùng hiển thị số thập phân tối đa 4 CHỮ SỐ *************///
/// ****                                  By MINH TOAN                              *************///
/// ****                                     By E360                                *************///



int strobePin = 4;
int dataPin = 5;
int clockPin = 3;

byte segChar[] = {0x05, 0x3f, 0x46, 0x16, 0x3c, 0x94, 0x84, 0x37, 0x04, 0x14, 0xfe, 0x00, 0xff};
byte segChardot[] = {0x01, 0x3B, 0x42, 0x12, 0x38, 0x90, 0x80, 0x33, 0x00, 0x10, 0xfa}; // font 3x4 co dau cham.

void setup()
{
  pinMode(strobePin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //  displaySegment(segChardot[2]);
  for(float i=0.001 ;i<1.000;i+=0.001)
  {
      displayFloat(i);
      delay(50);
  }



}

void displayFloat(float number) {
  int integerPart = int(number);                  // Phần nguyên của số
  Serial.println(integerPart);




  // Hiển thị phần nguyên trên LED 7 thanh
  if (integerPart == 0) {
    Serial.println("mode0");
    int decimalPart = int(number * 1000) % 1000;     // Phần thập phân của số (lấy ba chữ số thập phân)
    // Hiển thị số 0 nếu phần nguyên là 0
    int digit3 = decimalPart / 100;
    int digit4 = (decimalPart / 10) % 10;
    int digit5 = decimalPart % 10;
    displaySegment(segChar[digit5]);
    displaySegment(segChar[digit4]);
    displaySegment(segChar[digit3]);
    displaySegment(segChardot[0]);
    //    displaySegment(segChar[0]);
  }
  if (integerPart < 10 && integerPart > 0) {
    Serial.println("mode1so");
    int decimalPart = int(number * 1000) % 1000;     // Phần thập phân của số (lấy ba chữ số thập phân)
    int digit3 = decimalPart / 100;
    int digit4 = (decimalPart / 10) % 10;
    int digit5 = decimalPart % 10;
    displaySegment(segChar[digit5]);
    displaySegment(segChar[digit4]);
    displaySegment(segChar[digit3]);
    displaySegment(segChardot[integerPart]);
  }
  if (integerPart >= 10 && integerPart < 100 ) {
    Serial.println("mode2so");
    int decimalPart = int(number * 100) % 100;     // Phần thập phân của số (lấy 2 chữ số thập phân)
    // Hiển thị từng chữ số của phần nguyên
    int digit3 = decimalPart / 10;
    int digit4 = decimalPart % 10;
    displaySegment(segChar[digit4]);
    displaySegment(segChar[digit3]);
    int digit1 = integerPart / 10;
    int digit2 = integerPart % 10;
    displaySegment(segChardot[digit2]);
    displaySegment(segChar[digit1]);

  }
  if ( integerPart >= 100 ) {
    Serial.println("mode3so");
    int decimalPart = int(number * 10) % 10;     // Phần thập phân của số (lấy 1 chữ số thập phân)
    int digit1 = integerPart / 100;
    int digit2 = (integerPart / 10) % 10;
    int digit3 = integerPart % 10;
    int digit4 = decimalPart;
    displaySegment(segChar[digit4]);
    displaySegment(segChardot[digit3]);
    displaySegment(segChar[digit2]);
    displaySegment(segChar[digit1]);

  }

  delay(20);
}
void displaySegment(byte segment) {
  digitalWrite(strobePin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, segment);
  digitalWrite(strobePin, HIGH);
}
