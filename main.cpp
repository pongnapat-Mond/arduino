#include <Servo.h>


const int trigPin = 12;
const int echoPin = 11;


Servo myServo;



long duration;
int distance;

void setup() {
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);


    myServo.attach(8);

  
    Serial.begin(9600);
}

void loop() {
   
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

   
    duration = pulseIn(echoPin, HIGH);

   
    distance = (duration/2) / 29.1;

    
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    
    if (distance < 10) {
        myServo.write(90); 
        
    } else {
        myServo.write(0);  
    }

    
    delay(500);
}
