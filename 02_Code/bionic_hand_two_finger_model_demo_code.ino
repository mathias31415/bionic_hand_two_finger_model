// Project:       Bionic Hand Drive
// Topic:         Motor control of servo motors
// Description:   This program controls six gestures of two fingers, each with four servo motors. The program runs on an Arduino Uno.

// Authors:       Mathias Fuhrer
//                Tobias Klausmann
//                Jens Polzien
//                Thomas Rapp

// Date:          21.07.2022

#include <Servo.h>                                    // Servo library

#define spread_Finger1_pin 2                          // Servo MG995                --> Spread middle finger
#define spread_Finger2_pin 3                          // Servo MG995                --> Spread index finger

#define Finger1_Joint_1_pin 4                         // Servo MG995                --> Bend middle finger
#define Finger1_Joint_2_pin 5                         // Servo MG995                --> Bend middle finger
#define Finger1_Joint_3_pin 6                         // Servo MG995                --> Bend middle finger

#define Finger2_Joint_1_pin 7                         // Servo MG995                --> Bend index finger
#define Finger2_Joint_2_pin 8                         // Servo MG995                --> Bend index finger
#define Finger2_Joint_3_pin 9                         // Servo MG995                --> Bend index finger

int buttonPin = 13;                                   // Set pin for button
int buttonPin_old;                                    // Variable to store previous button state
int gestureIndex = 0;                                 // Counter initialization
int numberOfGestures = 6;                             // Set number of gestures

Servo spread_Finger1;                                 // Initialize servo motor
Servo spread_Finger2;                                 // Initialize servo motor

Servo Finger1_Joint_1;                                // Initialize servo motor
Servo Finger1_Joint_2;                                // Initialize servo motor
Servo Finger1_Joint_3;                                // Initialize servo motor
Servo Finger2_Joint_1;                                // Initialize servo motor
Servo Finger2_Joint_2;                                // Initialize servo motor
Servo Finger2_Joint_3;                                // Initialize servo motor

// ------ Function declarations ------
void gestureRock();
void gesturePaper();
void gestureScissor();
void gestureMiddleFinger();
void gestureHalfPos1();
void gestureHalfPos2();
// -----------------------------------

void setup() {
  Serial.begin(9600);                                 // Initialize serial monitor with baud rate

  pinMode(buttonPin, INPUT);                          // Set button pin as input
  buttonPin_old = digitalRead(buttonPin);             // Store initial button state

  spread_Finger1.attach(spread_Finger1_pin);          // Attach servo to pin
  spread_Finger2.attach(spread_Finger2_pin);          // Attach servo to pin
  Finger1_Joint_1.attach(Finger1_Joint_1_pin);        // Attach servo to pin
  Finger1_Joint_2.attach(Finger1_Joint_2_pin);        // Attach servo to pin
  Finger1_Joint_3.attach(Finger1_Joint_3_pin);        // Attach servo to pin
  Finger2_Joint_1.attach(Finger2_Joint_1_pin);        // Attach servo to pin
  Finger2_Joint_2.attach(Finger2_Joint_2_pin);        // Attach servo to pin
  Finger2_Joint_3.attach(Finger2_Joint_3_pin);        // Attach servo to pin

  spread_Finger1.detach();                            // Detach servo to save energy
  spread_Finger2.detach();                            // Detach servo to save energy
  Finger1_Joint_1.detach();                           // Detach servo to save energy
  Finger2_Joint_1.detach();                           // Detach servo to save energy
  Finger1_Joint_2.detach();                           // Detach servo to save energy
  Finger2_Joint_2.detach();                           // Detach servo to save energy
  Finger1_Joint_3.detach();                           // Detach servo to save energy
  Finger2_Joint_3.detach();                           // Detach servo to save energy
}

void loop() 
{
  while(digitalRead(buttonPin) == buttonPin_old)      // Wait here as long as no button press is detected
  {
    delay (50);
  }
  
  buttonPin_old = digitalRead(buttonPin);             // Remember last button state
  Serial.println("Edge detected");                    // Continue program when button press detected
  gestureIndex = gestureIndex + 1;                    // Increase counter

  switch(gestureIndex)
  {
    case 1: gestureRock();                            // If counter gestureIndex = 1, call gestureRock
    break;
    case 2: gesturePaper();                           // If counter gestureIndex = 2, call gesturePaper
    break;
    case 3: gestureScissor();                         // If counter gestureIndex = 3, call gestureScissor
    break;
    case 4: gestureMiddleFinger();                    // If counter gestureIndex = 4, call gestureMiddleFinger
    break;
    case 5: gestureHalfPos1();                        // If counter gestureIndex = 5, call gestureHalfPos1
    break;
    case 6: gestureHalfPos2();                        // If counter gestureIndex = 6, call gestureHalfPos2
    break;
    default:
    break;
  }

  if(gestureIndex >= numberOfGestures)                // If last gesture reached ...
  {
    gestureIndex = 0;                                 // ... reset counter
  }
}

// ---------------------------------------- Gesture functions --------------------------------------------------------------------------

// ------ Info about servo end positions ------
// Bend Joint 1:
//   140°  - extended
//   35°   - bent
// Bend Joint 2 and 3:
//   35°   - extended
//   140°  - bent
// Spread:
//   90° center position +- approx. 10°
// ------ End of info ------------------------

void gestureScissor()
{
    spread_Finger1.attach(2);           // Attach servo
    spread_Finger2.attach(3);           // Attach servo
    Finger1_Joint_1.attach(4);          // Attach servo
    Finger2_Joint_1.attach(7);          // Attach servo
    Finger1_Joint_2.attach(5);          // Attach servo
    Finger2_Joint_2.attach(8);          // Attach servo
    Finger1_Joint_3.attach(6);          // Attach servo
    Finger2_Joint_3.attach(9);          // Attach servo
    
    spread_Finger1.write(90);           // no spreading
    spread_Finger2.write(90);           // no spreading
    Finger1_Joint_1.write(35);          // fully extended
    Finger2_Joint_1.write(35);          // fully extended
    Finger1_Joint_2.write(140);         // fully extended
    Finger2_Joint_2.write(140);         // fully extended
    Finger1_Joint_3.write(140);         // fully extended
    Finger2_Joint_3.write(140);         // fully extended
    delay(400);
    
    spread_Finger1.detach();            // Detach servo to save energy
    spread_Finger2.detach();            // Detach servo to save energy
    Finger1_Joint_1.detach();           // Detach servo to save energy
    Finger2_Joint_1.detach();           // Detach servo to save energy
    Finger1_Joint_2.detach();           // Detach servo to save energy
    Finger2_Joint_2.detach();           // Detach servo to save energy
    Finger1_Joint_3.detach();           // Detach servo to save energy
    Finger2_Joint_3.detach();           // Detach servo to save energy
}

void gestureRock()
{
    spread_Finger1.attach(2);           // Attach servo
    spread_Finger2.attach(3);           // Attach servo
    Finger1_Joint_1.attach(4);          // Attach servo
    Finger2_Joint_1.attach(7);          // Attach servo
    Finger1_Joint_2.attach(5);          // Attach servo
    Finger2_Joint_2.attach(8);          // Attach servo
    Finger1_Joint_3.attach(6);          // Attach servo
    Finger2_Joint_3.attach(9);          // Attach servo
    
    spread_Finger1.write(80);           // spread finger 1
    spread_Finger2.write(100);          // spread finger 2
    Finger1_Joint_1.write(139);         // fully bent
    Finger2_Joint_1.write(145);         // fully bent
    Finger1_Joint_2.write(35);          // fully bent
    Finger2_Joint_2.write(35);          // fully bent
    Finger1_Joint_3.write(35);          // fully bent
    Finger2_Joint_3.write(35);          // fully bent
    delay (400);
    
    spread_Finger1.detach();            // Detach servo to save energy
    spread_Finger2.detach();            // Detach servo to save energy
    Finger1_Joint_1.detach();           // Detach servo to save energy
    Finger2_Joint_1.detach();           // Detach servo to save energy
    Finger1_Joint_2.detach();           // Detach servo to save energy
    Finger2_Joint_2.detach();           // Detach servo to save energy
    Finger1_Joint_3.detach();           // Detach servo to save energy
    Finger2_Joint_3.detach();           // Detach servo to save energy
}

void gesturePaper()
{
    spread_Finger1.attach(2);           // Attach servo
    spread_Finger2.attach(3);           // Attach servo
    Finger1_Joint_1.attach(4);          // Attach servo
    Finger2_Joint_1.attach(7);          // Attach servo
    Finger1_Joint_2.attach(5);          // Attach servo
    Finger2_Joint_2.attach(8);          // Attach servo
    Finger1_Joint_3.attach(6);          // Attach servo
    Finger2_Joint_3.attach(9);          // Attach servo
    
    spread_Finger1.write(95);           // minimal spread to press fingers together
    spread_Finger2.write(85);           // minimal spread to press fingers together
    Finger1_Joint_1.write(139);         // fully extended
    Finger2_Joint_1.write(145);         // fully extended
    Finger1_Joint_2.write(35);          // fully extended
    Finger2_Joint_2.write(35);          // fully extended
    Finger1_Joint_3.write(35);          // fully extended
    Finger2_Joint_3.write(35);          // fully extended
    delay (400);
    
    spread_Finger1.detach();            // Detach servo to save energy
    spread_Finger2.detach();            // Detach servo to save energy
    Finger1_Joint_1.detach();           // Detach servo to save energy
    Finger2_Joint_1.detach();           // Detach servo to save energy
    Finger1_Joint_2.detach();           // Detach servo to save energy
    Finger2_Joint_2.detach();           // Detach servo to save energy
    Finger1_Joint_3.detach();           // Detach servo to save energy
    Finger2_Joint_3.detach();           // Detach servo to save energy
}

void gestureMiddleFinger()
{
    spread_Finger1.attach(2);           // Attach servo
    spread_Finger2.attach(3);           // Attach servo
    Finger1_Joint_1.attach(4);          // Attach servo
    Finger2_Joint_1.attach(7);          // Attach servo
    Finger1_Joint_2.attach(5);          // Attach servo
    Finger2_Joint_2.attach(8);          // Attach servo
    Finger1_Joint_3.attach(6);          // Attach servo
    Finger2_Joint_3.attach(9);          // Attach servo
    
    spread_Finger1.write(90);           // no spreading
    spread_Finger2.write(90);           // no spreading
    Finger1_Joint_1.write(140);         // fully bent
    Finger2_Joint_1.write(35);          // fully extended
    Finger1_Joint_2.write(35);          // fully bent
    Finger2_Joint_2.write(140);         // fully bent
    Finger1_Joint_3.write(35);          // fully bent
    Finger2_Joint_3.write(140);         // fully bent
    delay (400);
    
    spread_Finger1.detach();            // Detach servo to save energy
    spread_Finger2.detach();            // Detach servo to save energy
    Finger1_Joint_1.detach();           // Detach servo to save energy
    Finger2_Joint_1.detach();           // Detach servo to save energy
    Finger1_Joint_2.detach();           // Detach servo to save energy
    Finger2_Joint_2.detach();           // Detach servo to save energy
    Finger1_Joint_3.detach();           // Detach servo to save energy
    Finger2_Joint_3.detach();           // Detach servo to save energy 
}

void gestureHalfPos1()
{
    spread_Finger1.attach(2);           // Attach servo
    spread_Finger2.attach(3);           // Attach servo
    Finger1_Joint_1.attach(4);          // Attach servo
    Finger2_Joint_1.attach(7);          // Attach servo
    Finger1_Joint_2.attach(5);          // Attach servo
    Finger2_Joint_2.attach(8);          // Attach servo
    Finger1_Joint_3.attach(6);          // Attach servo
    Finger2_Joint_3.attach(9);          // Attach servo
    
    spread_Finger1.write(70);           // strongly spread
    spread_Finger2.write(75);           // strongly spread
    Finger1_Joint_1.write(50);          // slightly bent
    Finger2_Joint_1.write(120);         // strongly bent
    Finger1_Joint_2.write(100);         // slightly bent 
    Finger2_Joint_2.write(70);          // more bent
    Finger1_Joint_3.write(100);         // slightly bent
    Finger2_Joint_3.write(50);          // strongly bent
    delay (400);
    
    spread_Finger1.detach();            // Detach servo to save energy
    spread_Finger2.detach();            // Detach servo to save energy
    Finger1_Joint_1.detach();           // Detach servo to save energy
    Finger2_Joint_1.detach();           // Detach servo to save energy
    Finger1_Joint_2.detach();           // Detach servo to save energy
    Finger2_Joint_2.detach();           // Detach servo to save energy
    Finger1_Joint_3.detach();           // Detach servo to save energy
    Finger2_Joint_3.detach();           // Detach servo to save energy 
}

void gestureHalfPos2()
{
    spread_Finger1.attach(2);           // Attach servo
    spread_Finger2.attach(3);           // Attach servo
    Finger1_Joint_1.attach(4);          // Attach servo
    Finger2_Joint_1.attach(7);          // Attach servo
    Finger1_Joint_2.attach(5);          // Attach servo
    Finger2_Joint_2.attach(8);          // Attach servo
    Finger1_Joint_3.attach(6);          // Attach servo
    Finger2_Joint_3.attach(9);          // Attach servo
    
    spread_Finger1.write(70);           // strongly spread
    spread_Finger2.write(110);          // strongly spread
    Finger1_Joint_1.write(140);         // fully bent
    Finger2_Joint_1.write(70);          // more extended
    Finger1_Joint_2.write(140);         // fully extended
    Finger2_Joint_2.write(70);          // more bent
    Finger1_Joint_3.write(70);          // more bent
    Finger2_Joint_3.write(90);          // medium bent
    delay (400);
    
    spread_Finger1.detach();            // Detach servo to save energy
    spread_Finger2.detach();            // Detach servo to save energy
    Finger1_Joint_1.detach();           // Detach servo to save energy
    Finger2_Joint_1.detach();           // Detach servo to save energy
    Finger1_Joint_2.detach();           // Detach servo to save energy
    Finger2_Joint_2.detach();           // Detach servo to save energy
    Finger1_Joint_3.detach();           // Detach servo to save energy
    Finger2_Joint_3.detach();           // Detach servo to save energy 
}
