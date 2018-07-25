#include <Wire_slave.h>
#define SLAVE_ADDRESS 0x04 //i2c地址
int data;
void setup() {
Serial.begin(9600); // start serial for output
// initialize i2c as slave
Wire.begin(SLAVE_ADDRESS);
// define callbacks for i2c communication
Wire.onReceive(receiveData);//从机 接收 主机 发来的数据
Wire.onRequest(sendData); //从机 请求 主机 发送数据
Serial.println("Ready");
}
void loop() {
 delay(100);
 }
// callback for received data
void receiveData(int byteCount){
while(Wire.available()) {
data = Wire.read();
Serial.print("data received: ");
Serial.println(data);
}
}
// callback for sending data
 void sendData(){
 Wire.write(data);
 }
