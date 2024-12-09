#include <Servo.h> // servo library
Servo s1; //initialize servo

const int trigPin = 9; // ultrasonic sensor pin trig 9
const int echoPin = 10; // ultrasonic sensor pin echo 10

long duration;

void setup(){
  pinMode(trigPin, OUTPUT); //set trig pin to OUTPUT
  pinMode(echoPin,INPUT); //set echo pin to OUTPUT
  s1.attach(3);  //set servo to pin 3
  s1.write(0); //Servo position 0deg
}      

void loop(){
  //ultrasonic code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    
  //echopin duration
  duration = pulseIn(echoPin, HIGH);
  
  //calculating distance in cm
  int distance = duration * 0.0343/2;
  
  //display distance to serial  
  Serial.print("Jarak:");
  Serial.println(distance);
  Serial.println("cm");
    
  //If the distance is less than 15 cm or 0cm, open the trash can lid
  if (distance < 15 && distance > 0) {
  s1.write(180);  //open the trash can lid
  delay(500);//wait 0,5 sec
  s1.write(0); //Closing back
  delay(500); //wait 0,5 sec
  }
  
  delay(100); // Delay kecil untuk loop
}