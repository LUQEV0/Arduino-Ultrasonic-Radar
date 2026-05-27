#include <Servo.h>

// Pinek definiálása
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 6;

// Változók a távolságméréshez
long duration;
int distance;

Servo radarServo; // Szervó objektum létrehozása

void setup() {
  Serial.begin(9600);        // Soros kommunikáció indítása
  pinMode(trigPin, OUTPUT);  // Trig pin kimenet
  pinMode(echoPin, INPUT);   // Echo pin bemenet
  pinMode(buzzerPin, OUTPUT);// Buzzer pin kimenet
  
  radarServo.attach(11);     // Szervó a 11-es pinre kötve
}

void loop() {
  // 1. Forgás 15-től 165 fokig (oda)
  for(int i = 15; i <= 165; i++) {  
    radarServo.write(i);
    delay(30);                   // Várunk, amíg a motor odafordul
    distance = measureDistance(); // Távolság mérése
    
    sendData(i, distance);       // Adatok küldése a Soros Monitorra
    checkObstacle(distance);     // Akadály ellenőrzése és riasztás
  }
  
  // 2. Forgás visszafelé 165-től 15 fokig (vissza)
  for(int i = 165; i > 15; i--) {  
    radarServo.write(i);
    delay(30);
    distance = measureDistance();
    
    sendData(i, distance);
    checkObstacle(distance);
  }
}

// Függvény a távolság kiszámítására
int measureDistance() {
  // Alaphelyzetbe állítjuk a trig pint
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Kiváltunk egy 10 mikromásodperces ultrahang impulzust
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Megmérjük, mennyi idő alatt ér vissza a hang (mikromásodpercben)
  duration = pulseIn(echoPin, HIGH);
  
  // Távolság kiszámítása cm-ben (hangsebesség = 0.034 cm/us)
  // Osztva kettővel, mert a hang oda-vissza utat tett meg
  int cm = duration * 0.034 / 2;
  return cm;
}

// Függvény az adatok kiírására (Soros Monitorra)
void sendData(int angle, int dist) {
  Serial.print("Szog: ");
  Serial.print(angle);
  Serial.print(" fok, Tavolsag: ");
  if (dist > 200 || dist <= 0) {
    Serial.println("Kivül esik a hatótávon");
  } else {
    Serial.print(dist);
    Serial.println(" cm");
  }
}

// Függvény a riasztáshoz, ha túl közel van valami
void checkObstacle(int dist) {
  if (dist > 0 && dist < 30) { // Ha 30 cm-en belül van valami
    digitalWrite(buzzerPin, HIGH); // Megszólal a csipogó
    delay(10);
    digitalWrite(buzzerPin, LOW);
  }
}
