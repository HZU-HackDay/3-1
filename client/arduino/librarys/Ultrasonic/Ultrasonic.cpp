#include <Arduino.h>
#include <Ultrasonic.h>

int duration;
int distance;

void Ultrasonic::Setup(int TRIG, int ECHO){
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
}

int Ultrasonic::GetDistance(int TRIG, int ECHO){
	digitalWrite(TRIG, LOW); 
	delayMicroseconds(2); 

	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10); 
 
	digitalWrite(TRIG, LOW);
	duration = pulseIn(ECHO, HIGH);
	distance = duration/58.2;
 	
	delay(50);
	return distance;
}
