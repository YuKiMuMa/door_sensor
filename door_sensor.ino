#include <BleKeyboard.h>

BleKeyboard bleKeyboard("door"); //デバイス名を任意のものに

void setup() {
  Serial.begin(115200);
  Serial.println("Serial Check");
  bleKeyboard.begin();

  pinMode(5,INPUT_PULLUP);    //スイッチを直つなぎしたのでINPUT_PULLUPしてあげる
  //attachInterrupt(digitalPinToInterrupt(5),keyp,RISING);  //ドアが開いた時だけミュートにする場合こちらのコメントを外す
  //attachInterrupt(digitalPinToInterrupt(5),keyp,CHANGE);  //ドアが開いた時にミュートにしてしまったときに解除したい場合こちらのコメントを外す
}

void loop() {

}

void keyp(){
  bleKeyboard.press(KEY_LEFT_SHIFT);    //ショートカットをShift+F1に設定した
  bleKeyboard.press(KEY_F1);
  delay(100);                           //0.1秒の間押される
  bleKeyboard.releaseAll();
}
