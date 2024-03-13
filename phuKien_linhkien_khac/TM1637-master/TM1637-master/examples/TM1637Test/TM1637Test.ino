#include <TM1637Display.h>

#define CLK_PIN 2  // Chân kết nối CLK của Module với chân 2 của Arduino
#define DIO_PIN 3  // Chân kết nối DIO của Module với chân 3 của Arduino

TM1637Display display(CLK_PIN, DIO_PIN);

void setup() {
  display.setBrightness(7);  // Đặt độ sáng (từ 0 đến 7, số càng lớn sáng càng tăng)
}

void loop() {
  int decimal = 145;  // Giá trị số muốn hiển thị (0.145)

  int digit1 = decimal / 100;  // Chữ số hàng trăm (0)
  int digit2 = (decimal / 10) % 10;  // Chữ số hàng chục (1)
  int digit3 = decimal % 10;  // Chữ số hàng đơn vị (4)
  int digit4 = 10;  // Dấu chấm (.)

  int digits[4] = {digit1, digit2, digit3, digit4};

  display.setSegments(digits);  // Hiển thị các chữ số trên LED 7 thanh

  delay(2000);  // Delay 2 giây

  display.clear();  // Xóa hiển thị trên LED 7 thanh

  delay(2000);  // Delay 2 giây trước khi lặp lại
}
