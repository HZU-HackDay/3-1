#define echoPin 7
#define trigPin 8
#define LEDPin 13

int maximumRange = 200;
int minimumRange = 0;
long duration, distance;

void setup() {
 	Serial.begin (9600);
 	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
 	pinMode(LEDPin, OUTPUT);
}

void loop() {
	digitalWrite(trigPin, LOW); 
	delayMicroseconds(2); 

	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10); 
 
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	//Serial.println("duration => " + (String)duration);
 
	distance = duration/58.2;
 
 	if (distance >= maximumRange || distance <= minimumRange){
		digitalWrite(LEDPin, HIGH); 
	} else {
		digitalWrite(LEDPin, LOW); 
	}
	//Serial.println("distance => " + (String)distance);
	delay(50);
}