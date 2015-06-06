#include <Arduino.h>

#ifndef __Ultrasonic_H__
#define __Ultrasonic_H__

class Ultrasonic{
	public:
		int GetDistance(int TRIG, int ECHO);
		void Setup(int TRIG, int ECHO);
	private:
		void begin();
};

#endif