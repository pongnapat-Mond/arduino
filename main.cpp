#include <Servo.h>

// Define pins for the ultrasonic sensor
const int trigPin = 12;
const int echoPin = 11;

// Define servo object and pin
Servo myServo;


// Variables for distance calculation
long duration;
int distance;

void setup() {
    // Set pin modes
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);


    myServo.attach(8);

  
    Serial.begin(9600);
}

void loop() {
    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echo pin
    duration = pulseIn(echoPin, HIGH);

    // Calculate disltance (in cm)
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
