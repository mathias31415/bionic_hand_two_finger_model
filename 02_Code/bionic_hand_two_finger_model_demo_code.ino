// Projekt:       Bionic Hand Drive
// Thema:         Motorsteuerung der Servomotoren
// Beschreibung:  Mit diesem Programm werden sechs Gesten der beiden Finger mit jeweils vier Servomotoren gesteuert. Das Programm läuft auf einem Arduino Uno.

// Autoren:       Mathias Fuhrer
//                Tobias Klausmann
//                Jens Polzien
//                Thomas Rapp

// Datum:         21.07.2022


#include <Servo.h>                                    //Servo library

#define spread_Finger1_pin 2                          // Servo MG995                --> Spreizen Mittelfinger
#define spread_Finger2_pin 3                          // Servo MG995                --> Spreizen Zeigefinger

#define Finger1_Gelenk_1_pin 4                        // Servo MG995                --> Beugen Mittelfinger
#define Finger1_Gelenk_2_pin 5                        // Servo MG995                --> Beugen Mittelfinger
#define Finger1_Gelenk_3_pin 6                        // Servo MG995                --> Beugen Mittelfinger

#define Finger2_Gelenk_1_pin 7                        // Servo MG995                --> Beugen Zeigefinger
#define Finger2_Gelenk_2_pin 8                        // Servo MG995                --> Beugen Zeigefinger
#define Finger2_Gelenk_3_pin 9                        // Servo MG995                --> Beugen Zeigefinger


int tasterPin = 13;                                   // Anschlusspin des Tasters festlegen
int tasterPin_alt;                                    // Speichervariable für den alten Tasterzustand deklarieren
int i = 0;                                            // Zähler initialisieren
int Anzahl_Gesten = 6;                                // Festlegen der Gestenanzahl


Servo spread_Finger1;                                 // Servomotor initialisieren
Servo spread_Finger2;                                 // Servomotor initialisieren

Servo Finger1_Gelenk_1;                               // Servomotor initialisieren
Servo Finger1_Gelenk_2;                               // Servomotor initialisieren
Servo Finger1_Gelenk_3;                               // Servomotor initialisieren
Servo Finger2_Gelenk_1;                               // Servomotor initialisieren
Servo Finger2_Gelenk_2;                               // Servomotor initialisieren
Servo Finger2_Gelenk_3;                               // Servomotor initialisieren

// ------ Funktionen deklarieren ------
void gesture_rock();
void gesture_paper();
void gesture_scissor();
void gesture_Mittelfinger();
void gesture_halfPos1();
void gesture_halfPos2();
// ------------------------------------


void setup() {
  
  Serial.begin(9600);                                 // Initialisierung des seriellen Monitors mit entsprechender Baudrate

  pinMode(tasterPin, INPUT);                          // Pin des Tasters als Input deklarieren
  tasterPin_alt = digitalRead(tasterPin);             // Speichervariable für den alten Tasterzustand beim Start einmalig auf den aktuellen Zustand setzen

  spread_Finger1.attach(spread_Finger1_pin);          //Zuweisung des Servomotors zu einem Pin
  spread_Finger2.attach(spread_Finger2_pin);          //Zuweisung des Servomotors zu einem Pin
  Finger1_Gelenk_1.attach(Finger1_Gelenk_1_pin);      //Zuweisung des Servomotors zu einem Pin
  Finger1_Gelenk_2.attach(Finger1_Gelenk_2_pin);      //Zuweisung des Servomotors zu einem Pin
  Finger1_Gelenk_3.attach(Finger1_Gelenk_3_pin);      //Zuweisung des Servomotors zu einem Pin
  Finger2_Gelenk_1.attach(Finger2_Gelenk_1_pin);      //Zuweisung des Servomotors zu einem Pin
  Finger2_Gelenk_2.attach(Finger2_Gelenk_2_pin);      //Zuweisung des Servomotors zu einem Pin
  Finger2_Gelenk_3.attach(Finger2_Gelenk_3_pin);      //Zuweisung des Servomotors zu einem Pin

  spread_Finger1.detach();                            //Servomotor trennen zum Energiesparen
  spread_Finger2.detach();                            //Servomotor trennen zum Energiesparen
  Finger1_Gelenk_1.detach();                          //Servomotor trennen zum Energiesparen
  Finger2_Gelenk_1.detach();                          //Servomotor trennen zum Energiesparen
  Finger1_Gelenk_2.detach();                          //Servomotor trennen zum Energiesparen
  Finger2_Gelenk_2.detach();                          //Servomotor trennen zum Energiesparen
  Finger1_Gelenk_3.detach();                          //Servomotor trennen zum Energiesparen
  Finger2_Gelenk_3.detach();                          //Servomotor trennen zum Energiesparen
}



void loop() 
{
  while(digitalRead(tasterPin)== tasterPin_alt)       // Solange kein Tastendruck erkannt wurde,bbleibt das Programm hier stehen
  {
    delay (50);
  }
  
  tasterPin_alt = digitalRead(tasterPin);             // Letzte Tastenzustand merken
  Serial.println("Flankenwechsel erkannt");           // Sobald ein Tastendruck erkannt wurde, setzt das Programm fort
  i=i+1;                                              // Zähler erhöhen

  
  switch(i)
  {
    case 1: gesture_rock();                           // Wenn Zähler i = 1, Funktion gesture_rock aufrufen
    break;
    case 2: gesture_paper();                          // Wenn Zähler i = 2, Funktion gesture_paper aufrufen
    break;
    case 3: gesture_scissor();                        // Wenn Zähler i = 3, Funktion gesture_scissor aufrufen
    break;
    case 4: gesture_Mittelfinger();                   // Wenn Zähler i = 4, Funktion gesture_Mittelfinger aufrufen
    break;
    case 5: gesture_halfPos1();                       // Wenn Zähler i = 5, Funktion gesture_halfpos1 aufrufen
    break;
    case 6: gesture_halfPos2();                       // Wenn Zähler i = 6, Funktion gesture_halfPos2 aufrufen
    break;
    default:
    break;
  }

  if(i>=Anzahl_Gesten)                                // Wenn letzte Geste erreicht ...
  {
    i=0;                                              // ... Zähler zurücksetzen
  }
}


// ---------------------------------------- Funktionen der Gesten --------------------------------------------------------------------------

// ------ Info zu den Motorendlagen ------
  // Beugen Gelenk 1:
    // 140°  - gestreckt
    // 35° - angewinkelt
  // Beugen Gelenk 2 und 3:
    // 35°  - gestreckt
    // 140° - angewinkelt
  //Spreizen:
    //90° Mittellage +- ca. 10°
// ------ Info Ende ----------------------

void gesture_scissor()
{
    spread_Finger1.attach(2);           // Servomotor verbinden
    spread_Finger2.attach(3);           // Servomotor verbinden
    Finger1_Gelenk_1.attach(4);         // Servomotor verbinden
    Finger2_Gelenk_1.attach(7);         // Servomotor verbinden
    Finger1_Gelenk_2.attach(5);         // Servomotor verbinden
    Finger2_Gelenk_2.attach(8);         // Servomotor verbinden
    Finger1_Gelenk_3.attach(6);         // Servomotor verbinden
    Finger2_Gelenk_3.attach(9);         // Servomotor verbinden
    
    spread_Finger1.write(90);           // kein Spreizen
    spread_Finger2.write(90);           // kein Spreizen
    Finger1_Gelenk_1.write(35);         // maximal gestreckt
    Finger2_Gelenk_1.write(35);         // maximal gestreckt
    Finger1_Gelenk_2.write(140);        // maximal gestreckt
    Finger2_Gelenk_2.write(140);        // maximal gestreckt
    Finger1_Gelenk_3.write(140);        // maximal gestreckt
    Finger2_Gelenk_3.write(140);        // maximal gestreckt
    delay(400);
    
    spread_Finger1.detach();            // Servomotor trennen zum Energie sparen
    spread_Finger2.detach();            // Servomotor trennen zum Energie sparen
    Finger1_Gelenk_1.detach();          // Servomotor trennen zum Energie sparen
    Finger2_Gelenk_1.detach();          // Servomotor trennen zum Energie sparen
    Finger1_Gelenk_2.detach();          // Servomotor trennen zum Energie sparen
    Finger2_Gelenk_2.detach();          // Servomotor trennen zum Energie sparen
    Finger1_Gelenk_3.detach();          // Servomotor trennen zum Energie sparen
    Finger2_Gelenk_3.detach();          // Servomotor trennen zum Energie sparen
}

void gesture_rock()
{
    spread_Finger1.attach(2);           // Servomotor verbinden
    spread_Finger2.attach(3);           // Servomotor verbinden
    Finger1_Gelenk_1.attach(4);         // Servomotor verbinden
    Finger2_Gelenk_1.attach(7);         // Servomotor verbinden
    Finger1_Gelenk_2.attach(5);         // Servomotor verbinden
    Finger2_Gelenk_2.attach(8);         // Servomotor verbinden
    Finger1_Gelenk_3.attach(6);         // Servomotor verbinden
    Finger2_Gelenk_3.attach(9);         // Servomotor verbinden
    
    spread_Finger1.write(80);           // Finger 1 spreizen
    spread_Finger2.write(100);          // Finger 2 spreizen
    Finger1_Gelenk_1.write(139);        // maximal angewinkelt
    Finger2_Gelenk_1.write(145);        // maximal angewinkelt
    Finger1_Gelenk_2.write(35);         // maximal angewinkelt
    Finger2_Gelenk_2.write(35);         // maximal angewinkelt
    Finger1_Gelenk_3.write(35);         // maximal angewinkelt
    Finger2_Gelenk_3.write(35);         // maximal angewinkelt
    delay (400);
    
    spread_Finger1.detach();            // Servomotor trennen zum Energiesparen
    spread_Finger2.detach();            // Servomotor trennen zum Energiesparen
    Finger1_Gelenk_1.detach();          // Servomotor trennen zum Energiesparen
    Finger2_Gelenk_1.detach();          // Servomotor trennen zum Energiesparen
    Finger1_Gelenk_2.detach();          // Servomotor trennen zum Energiesparen
    Finger2_Gelenk_2.detach();          // Servomotor trennen zum Energiesparen
    Finger1_Gelenk_3.detach();          // Servomotor trennen zum Energiesparen
    Finger2_Gelenk_3.detach();          // Servomotor trennen zum Energiesparen
}

void gesture_paper()
{
    spread_Finger1.attach(2);           // Servomotor verbinden
    spread_Finger2.attach(3);           // Servomotor verbinden
    Finger1_Gelenk_1.attach(4);         // Servomotor verbinden
    Finger2_Gelenk_1.attach(7);         // Servomotor verbinden
    Finger1_Gelenk_2.attach(5);         // Servomotor verbinden
    Finger2_Gelenk_2.attach(8);         // Servomotor verbinden
    Finger1_Gelenk_3.attach(6);         // Servomotor verbinden
    Finger2_Gelenk_3.attach(9);         // Servomotor verbinden
    
    spread_Finger1.write(95);           // minimal spreizen, um die beiden Finger zusammen zu pressen
    spread_Finger2.write(85);           // minimal spreizen, um die beiden Finger zusammen zu pressen
    Finger1_Gelenk_1.write(139);        // maximal gestreckt
    Finger2_Gelenk_1.write(145);        // maximal gestreckt
    Finger1_Gelenk_2.write(35);         // maximal gestreckt
    Finger2_Gelenk_2.write(35);         // maximal gestreckt
    Finger1_Gelenk_3.write(35);         // maximal gestreckt
    Finger2_Gelenk_3.write(35);         // maximal gestreckt
    delay (400);
    
    spread_Finger1.detach();            // Servomotor trennen zum Energiesparen
    spread_Finger2.detach();            // Servomotor trennen zum Energiesparen
    Finger1_Gelenk_1.detach();          // Servomotor trennen zum Energiesparen
    Finger2_Gelenk_1.detach();          // Servomotor trennen zum Energiesparen
    Finger1_Gelenk_2.detach();          // Servomotor trennen zum Energiesparen
    Finger2_Gelenk_2.detach();          // Servomotor trennen zum Energiesparen
    Finger1_Gelenk_3.detach();          // Servomotor trennen zum Energiesparen
    Finger2_Gelenk_3.detach();          // Servomotor trennen zum Energiesparen
}

void gesture_Mittelfinger()
{
    spread_Finger1.attach(2);           // Servomotor verbinden
    spread_Finger2.attach(3);           // Servomotor verbinden
    Finger1_Gelenk_1.attach(4);         // Servomotor verbinden
    Finger2_Gelenk_1.attach(7);         // Servomotor verbinden
    Finger1_Gelenk_2.attach(5);         // Servomotor verbinden
    Finger2_Gelenk_2.attach(8);         // Servomotor verbinden
    Finger1_Gelenk_3.attach(6);         // Servomotor verbinden
    Finger2_Gelenk_3.attach(9);         // Servomotor verbinden
    
    spread_Finger1.write(90);           // kein Spreizen
    spread_Finger2.write(90);           // kein Spreizen
    Finger1_Gelenk_1.write(140);        // maximal angewinkelt
    Finger2_Gelenk_1.write(35);         // maximal gestreckt
    Finger1_Gelenk_2.write(35);         // maximal angewinkelt
    Finger2_Gelenk_2.write(140);        // maximal angewinkelt
    Finger1_Gelenk_3.write(35);         // maximal angewinkelt
    Finger2_Gelenk_3.write(140);        // maximal angewinkelt
    delay (400);
    
    spread_Finger1.detach();            //Servomotor trennen zum Energiesparen
    spread_Finger2.detach();            //Servomotor trennen zum Energiesparen
    Finger1_Gelenk_1.detach();          //Servomotor trennen zum Energiesparen
    Finger2_Gelenk_1.detach();          //Servomotor trennen zum Energiesparen
    Finger1_Gelenk_2.detach();          //Servomotor trennen zum Energiesparen
    Finger2_Gelenk_2.detach();          //Servomotor trennen zum Energiesparen
    Finger1_Gelenk_3.detach();          //Servomotor trennen zum Energiesparen
    Finger2_Gelenk_3.detach();          //Servomotor trennen zum Energiesparen 
}

void gesture_halfPos1()
{
    spread_Finger1.attach(2);           // Servomotor verbinden
    spread_Finger2.attach(3);           // Servomotor verbinden
    Finger1_Gelenk_1.attach(4);         // Servomotor verbinden
    Finger2_Gelenk_1.attach(7);         // Servomotor verbinden
    Finger1_Gelenk_2.attach(5);         // Servomotor verbinden
    Finger2_Gelenk_2.attach(8);         // Servomotor verbinden
    Finger1_Gelenk_3.attach(6);         // Servomotor verbinden
    Finger2_Gelenk_3.attach(9);         // Servomotor verbinden
    
    spread_Finger1.write(70);           // stark abgespreizt
    spread_Finger2.write(75);           // stark abgespreizt
    Finger1_Gelenk_1.write(50);         // leicht gebeugt
    Finger2_Gelenk_1.write(120);        // stark gebeugt
    Finger1_Gelenk_2.write(100);        // leicht gebeugt 
    Finger2_Gelenk_2.write(70);         // stärker gebeugt
    Finger1_Gelenk_3.write(100);        // leicht gebeugt
    Finger2_Gelenk_3.write(50);         // stark gebeugt
    delay (400);
    
    spread_Finger1.detach();            //Servomotor trennen zum Energiesparen
    spread_Finger2.detach();            //Servomotor trennen zum Energiesparen
    Finger1_Gelenk_1.detach();          //Servomotor trennen zum Energiesparen
    Finger2_Gelenk_1.detach();          //Servomotor trennen zum Energiesparen
    Finger1_Gelenk_2.detach();          //Servomotor trennen zum Energiesparen
    Finger2_Gelenk_2.detach();          //Servomotor trennen zum Energiesparen
    Finger1_Gelenk_3.detach();          //Servomotor trennen zum Energiesparen
    Finger2_Gelenk_3.detach();          //Servomotor trennen zum Energiesparen 
}

void gesture_halfPos2()
{
    spread_Finger1.attach(2);           // Servomotor verbinden
    spread_Finger2.attach(3);           // Servomotor verbinden
    Finger1_Gelenk_1.attach(4);         // Servomotor verbinden
    Finger2_Gelenk_1.attach(7);         // Servomotor verbinden
    Finger1_Gelenk_2.attach(5);         // Servomotor verbinden
    Finger2_Gelenk_2.attach(8);         // Servomotor verbinden
    Finger1_Gelenk_3.attach(6);         // Servomotor verbinden
    Finger2_Gelenk_3.attach(9);         // Servomotor verbinden
    
    spread_Finger1.write(70);           // stark abgespreizt
    spread_Finger2.write(110);          // stark abgespreizt
    Finger1_Gelenk_1.write(140);        // maximal angewinkelt
    Finger2_Gelenk_1.write(70);         // stärker gestreckt
    Finger1_Gelenk_2.write(140);        // maximal gestreckt
    Finger2_Gelenk_2.write(70);         // stärker angewinkelt
    Finger1_Gelenk_3.write(70);         // stärker angewinkelt
    Finger2_Gelenk_3.write(90);         // mittel angewinkelt
    delay (400);
    
    spread_Finger1.detach();            //Servomotor trennen zum Energiesparen
    spread_Finger2.detach();            //Servomotor trennen zum Energiesparen
    Finger1_Gelenk_1.detach();          //Servomotor trennen zum Energiesparen
    Finger2_Gelenk_1.detach();          //Servomotor trennen zum Energiesparen
    Finger1_Gelenk_2.detach();          //Servomotor trennen zum Energiesparen
    Finger2_Gelenk_2.detach();          //Servomotor trennen zum Energiesparen
    Finger1_Gelenk_3.detach();          //Servomotor trennen zum Energiesparen
    Finger2_Gelenk_3.detach();          //Servomotor trennen zum Energiesparen 
}