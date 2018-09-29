const int LED_PIN = 11;
const double C = 255.0; // 用いるLEDに依存する定数
int trig = 8; // 出力ピン
int echo = 9; // 入力ピン

void setup() {
  pinMode(LED_PIN, OUTPUT); 
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(1);
  // 超音波を出力
  digitalWrite(trig,HIGH);
  delayMicroseconds(11);
  // 超音波を出力終了
  digitalWrite(trig,LOW);
  // 出力した超音波が返って来る時間を計測
  int t = pulseIn(echo,HIGH);
  // 計測した時間と音速から反射物までの距離を計算
  float distance = t*0.017;
  
  if(distance < 15 && distance > 0){
    for(int i = 0; i <= 255; i++){
      analogWrite(LED_PIN, getDuty(i/255.0));
      delay(30);
    }
    analogWrite(LED_PIN, 255);
    delay(2000);
    for(int k = 255; k >= 0; k--){
      analogWrite(LED_PIN, getDuty(k/255.0));
      delay(30);
    }
  }
}

int getDuty(double ratio){
  return round(exp(log(255.0) - (1 - ratio) * log(C)));
}
