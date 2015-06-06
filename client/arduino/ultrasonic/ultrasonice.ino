#include <Ultrasonic.h>

int dis1;
int dis2;
int trigPin=8;
int echoPin=7;
Ultrasonic myUltra = Ultrasonic();

void setup() {
  Serial.begin(9600); 
  myUltra.Setup(6, 7); 
  myUltra.Setup(8, 9);  
}

void loop() {
     dis1 = myUltra.GetDistance(6,7);
     dis2 = myUltra.GetDistance(8,9);
     Serial.println("distance => " + (String)dis1);
     Serial.println("distance => " + (String)dis2);
     Serial.println("\n");
     delay(200);
}
