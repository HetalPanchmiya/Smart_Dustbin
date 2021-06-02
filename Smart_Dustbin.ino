#include <Blynk.h>
#define  BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
char auth[] = "";
char ssid[] = "";
char pass[] = "";
SimpleTimer timer;
#define ESP8266_BAUD 115200
ESP8266 wifi(&Serial);
#include <LiquidCrystal.h>
LiquidCrystal lcd(6,7,8,9,10,11); //RS,EN,D4,D5,D6,D7
#include <Servo.h>
#define irl A1
#define sen1 A0
#define trigPin1 A4
#define echoPin1 A5
#define trigPin2 A2
#define echoPin2 A3
int lvl1=0;
int lvl2=0;
long duration, distance, sensor1, sensor2;
int onetime=0, onetime=0;
int wet=0, moisture=0, objet=0, cabin2=0, c1=0,c2=0;
Servo myservo;
void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Automatic Waste");
  lcd.setCursor(0,1);
  lcd.print("Segregation sys");
  delay(3000);
  pinMode(irl,INPUT);
  pinMode(senl,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
 myservo.attach(3);
 myservo.write(75);
 delay(10);
 lcd.clear();
 lcd.print("Connecting....");
 Blynk.begin(auth, wifi, ssid, pass);
 lcd.clear();
 lcd.print("connected...");
 delay(1000);
 lcd.clear();
}
void loop()
{
  Blynk.run();
  timer.run();
  moisture=alalogRead(senl);
  Serial.print("moisture=");
  Serial.println(moisture);
  delay(500);
  ultrasensor(trigPin1, echoPin1);
  sensor1=distance;
  delay(10);
  ultrasensor(trigPin2, echoPin2);
  sensor2=distance;
  delay(10);
  Serial.println(sensor1);
  Serial.println(sensor2);
  lvl1=(30-sensor1)*6.5;
  lvl2=(30-sensor2)*6.5;
  Serial.println(lvl1);
  Serial.println(lvl2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WET|DRY);
  lcd.serCursor(2,1);
  lcd.print(lvl1);
  lcd.setCursor(11,1);
  lcd.print(lvl2);
  delay(1000);
  object=digitalRead(irl);
  moisture=analogRead(sen1);
  if(object==HIGH)
  {
    lcd.clear();
    moisture=analogRead(sen1);
    lcd.setCursor(0,0);
    lcd.print("-GARBAGE SENSE-");
    lcd.setCursor(0,1);
    lcd.print("moisture:");
    lcd.setCursor(12,1);
    lcd.print(moisture);
    Serial.print("moisture=");
    Serial.println(moisture);
    delay(500);
    if(moisture>=40)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("WET GARBAGE");
      myservo.write(0);
      delay(5000);
      myservo.write(75);
      delay(2000);
      Serial.println("wet');
    }
    else if(moisture<100)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DRY GARBAGE");
      myservo.write(135);
      delay(50000);
      myservo.write(75);
      delay(2000);
      Serial.println("dry");
      lcd.clear();
    }
  }
}
void sendSensor()
{
  Blynk.virtualWrite(v5, lvl1);
  Blynk.virtualWrite(v6, lvl2);
}
void ultrasensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/30);
}
