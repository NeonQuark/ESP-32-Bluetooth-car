#include "BluetoothSerial.h"  // Include the BluetoothSerial library
#include <ESP32Servo.h>

// Motor pins ..You can adjust it as per your preference 
#define ENA1 13
#define In1 12
#define in2 14
#define ENB1 15
#define In3 2
#define in4 4
#define ENA2 16
#define In5 17
#define in6 5
#define ENB2 19
#define In7 21
#define in8 3

BluetoothSerial ESP_BT;  // Create a BluetoothSerial object

void setup() {
    Serial.begin(115200);         // Initialize serial communication
    ESP_BT.begin("ESP32_BT");     // Start Bluetooth with the name "ESP32_BT"
    Serial.println("Bluetooth is ready to pair...");

    // Set motor control pins as outputs
    pinMode(In1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(In3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(In5, OUTPUT);
    pinMode(in6, OUTPUT);
    pinMode(In7, OUTPUT);
    pinMode(in8, OUTPUT);
}

void loop() {
    // Check if a Bluetooth device is connected
    if (ESP_BT.hasClient()) {
        // If Bluetooth has received data
        if (ESP_BT.available()) {
            char receivedChar = ESP_BT.read();  // Read the incoming character
            Serial.print("Received: ");
            Serial.println(receivedChar);       // Print to serial monitor
            
            // Perform actions based on the received data
            switch (receivedChar) {
                case '1':
                    moveForward();
                    ESP_BT.println("MOVING FORWARD");
                    break;
                case '2':
                    moveBackward();
                    ESP_BT.println("MOVING BACKWARD");
                    break;
                case '3':
                    turnLeft();
                    ESP_BT.println("TURNING LEFT");
                    break;
                case '4':
                    turnRight();
                    ESP_BT.println("TURNING RIGHT");
                    break;
                default:
                    Serial.println("Sorry, I didn't get you!");
                    break;
            }
        }
    }

    delay(100);  // Short delay for stability
}

// Function to move forward
void moveForward() {
    Serial.println("Button 1 Pressed");
    delay(1000);
    digitalWrite(In1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENA1, 128);
    
    digitalWrite(In3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB1, 128);
    
    digitalWrite(In5, LOW);
    digitalWrite(in6, HIGH);
    analogWrite(ENA2, 128);
    
    digitalWrite(In7, HIGH);
    digitalWrite(in8, LOW);
    analogWrite(ENB2, 128);
}

// Function to move backward
void moveBackward() {
    Serial.println("Button 2 Pressed");
    delay(1000);
    digitalWrite(In1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENA1, 128);
    
    digitalWrite(In3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ENB1, 128);
    
    digitalWrite(In5, LOW);
    digitalWrite(in6, HIGH);
    analogWrite(ENA2, 128);
    
    digitalWrite(In7, LOW);
    digitalWrite(in8, HIGH);
    analogWrite(ENB2, 128);
}

// Function to turn left
void turnLeft() {
    Serial.println("Button 3 Pressed");
    delay(1000);
    digitalWrite(In1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA1, 100);
    
    digitalWrite(In3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB1, 128);
    
    digitalWrite(In5, HIGH);
    digitalWrite(in6, LOW);
    analogWrite(ENA2, 100);
    
    digitalWrite(In7, HIGH);
    digitalWrite(in8, LOW);
    analogWrite(ENB2, 128);
}

// Function to turn right
void turnRight() {
    Serial.println("Button 4 Pressed");
    delay(1000);
    digitalWrite(In1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA1, 128);
    
    digitalWrite(In3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB1, 100);
    
    digitalWrite(In5, HIGH);
    digitalWrite(in6, LOW);
    analogWrite(ENA2, 128);
    
    digitalWrite(In7, HIGH);
    digitalWrite(in8, LOW);
    analogWrite(ENB2, 100);
}