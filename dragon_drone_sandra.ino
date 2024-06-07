#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
#define Brushless_Motor_PIN 25
#define Brushless_Motor_PIN2 26
#define Brushless_Motor_PIN3 27
#define Brushless_Motor_PIN4 14

int x;
int speed;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  ledcSetup(4, 1000, 8); //PWM channel is 0, Frequency 1000Hz, 8 bit(Duty with 256 levels of resolution, the value is 0-255)
  ledcSetup(1, 1000, 8); //PWM channel is 0, Frequency 1000Hz, 8 bit(Duty with 256 levels of resolution, the value is 0-255)
  ledcSetup(2, 1000, 8); //PWM channel is 0, Frequency 1000Hz, 8 bit(Duty with 256 levels of resolution, the value is 0-255)
  ledcSetup(3, 1000, 8); //PWM channel is 0, Frequency 1000Hz, 8 bit(Duty with 256 levels of resolution, the value is 0-255)

  pinMode(Brushless_Motor_PIN, OUTPUT); //Brushless_Motor_PIN as OUTPUT
  ledcAttachPin(Brushless_Motor_PIN,4); //Assign channel 0 to Brushless_Motor_PIN

  pinMode(Brushless_Motor_PIN2, OUTPUT); //Brushless_Motor_PIN as OUTPUT
  ledcAttachPin(Brushless_Motor_PIN2,1); //Assign channel 0 to Brushless_Motor_PIN

  pinMode(Brushless_Motor_PIN3, OUTPUT); //Brushless_Motor_PIN as OUTPUT
  ledcAttachPin(Brushless_Motor_PIN3,2); //Assign channel 0 to Brushless_Motor_PIN

  pinMode(Brushless_Motor_PIN4, OUTPUT); //Brushless_Motor_PIN as OUTPUT
  ledcAttachPin(Brushless_Motor_PIN4,3); //Assign channel 0 to Brushless_Motor_PIN

  x = 0;
  speed = 0;

}

void loop() {

  ledcWrite(4,speed); //(channel, speed)
  ledcWrite(1,speed); //(channel, speed)
  ledcWrite(2,speed); //(channel, speed)
  ledcWrite(3,speed); //(channel, speed)

  if (SerialBT.available()) {
    char data = SerialBT.read();
 
    if (data == 'C') {
    
      speed = 0;
      ledcWrite(4,speed); //(channel, speed)
      ledcWrite(1,speed); //(channel, speed)
      ledcWrite(2,speed); //(channel, speed)
      ledcWrite(3,speed); //(channel, speed)
    }


    else if (data == 'T') {
      
      speed += 10;
      ledcWrite(4,speed); //(channel, speed)
      ledcWrite(1,speed); //(channel, speed)
      ledcWrite(2,speed); //(channel, speed)
      ledcWrite(3,speed); //(channel, speed)
    }

    else if (data == 'S') {
      speed -= 10;
      ledcWrite(4,speed); //(channel, speed)
      ledcWrite(1,speed); //(channel, speed)
      ledcWrite(2,speed); //(channel, speed)
      ledcWrite(3,speed); //(channel, speed)
    }
  }
}
