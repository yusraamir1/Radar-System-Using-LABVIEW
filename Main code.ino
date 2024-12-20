#include <Servo.h>
Servo myservo;
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 12; // Buzzer connected to pin 12
float duration, distance;
int pos = 0;
const float thresholdDistance = 10.0; // Threshold distance in cm
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
  Serial.begin(9600);
  myservo.attach(11);
}
void loop() {
  if (Serial.available() > 0) {
    for (pos = 0; pos <= 180; pos += 10) {
      myservo.write(pos);
      Serial.println(pos);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration * 0.0343) / 2; // Calculate distance in cm
      if (distance < thresholdDistance) {
        digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
        Serial.println("Warning: Object is too close!");
      } else {
        digitalWrite(buzzerPin, LOW); // Turn off the buzzer
      }
      float p = distance * 1000; // Convert distance to millimeters if needed
      Serial.println(p);
      delay(500);
    }
    for (pos = 180; pos >= 0; pos -= 10) {
      myservo.write(pos);
      Serial.println(pos);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration * 0.0343) / 2; // Calculate distance in cm
      if (distance < thresholdDistance) {
        digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
        Serial.println("Warning: Object is too close!");
      } else {
        digitalWrite(buzzerPin, LOW); // Turn off the buzzer}
      float p = distance * 1000; // Convert distance to millimeters if needed
      Serial.println(p);
      delay(500); }}}

