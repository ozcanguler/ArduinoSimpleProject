 // servo motorun kütüphanesi ekleniyor
#include <Servo.h>.  
const int trigPin = 2; // Trig pine 10 numaralı pin tanımlanıyor  
const int echoPin = 3; // Echo pine 13 numaralı pin tanımlanıyor 
long duration;  //süre değer
int distance; //mesafe değer
 
Servo myServo;  //servo nesnesi ekleniyor motorun kontrolü için 
 
void setup() {  // ilk değerler ve ilk başta bir kere çalışacak kodlar
  pinMode(trigPin, OUTPUT); //trigpin çıkışa ayarlanıyor
  pinMode(echoPin, INPUT); //echopin girişe ayarlanıyor
  Serial.begin(9600); //iletişim hızını ayarlama.Seri iletişim 1 ve 0’ların tek hat üzerinden peşi sıra iletilmesine denir.
  myServo.attach(9); // Servo motor sinyal pini
}
void loop() { // devamlı tekrarlanarak sırasıyla çalışacak  kodları buraya yazıyoruz
  // 15 derece ile 165 derece arasında dön
  for(int i=15;i<=165;i++){ myServo.write(i); delay(30); distance = calculateDistance(); 
  Serial.print(i); Serial.print(","); Serial.print(distance); Serial.print("."); } 
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance(); //mesafeyi hesapla
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
 
int calculateDistance(){ 
   
  digitalWrite(trigPin, LOW); //trigger pin düşüğe ayarla
  delayMicroseconds(2);   //2 mikrosaniye ertele
  digitalWrite(trigPin, HIGH); //trigger pin yükseğe ayarla
  delayMicroseconds(10);  //10 mikrosaniye ertele
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);//EchoPin'i okur, ses dalgasının yolculuk zamanını mikrosaniye ile döndürür 
  distance= duration*0.034/2; //zamanı mesafeye çeviren işlem
  return distance; //mesafeyi döndür
}
