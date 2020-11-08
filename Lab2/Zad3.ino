int cm = 0;
int targetDistance = 150;
int kp = 2;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  
  int distanceDeviation = cm-targetDistance;
  int controlSignal = kp * distanceDeviation;
  
    if(controlSignal > 0){
      	map(controlSignal,0,800,0,255);
      if(controlSignal > 255){
        	controlSignal = 255;
      	}
    	analogWrite(6, controlSignal);
    }
    else{
      	digitalWrite(6, LOW);
    }
    if(controlSignal < 0){
      	controlSignal = -1 * controlSignal;
      	if(controlSignal > 255){
        	controlSignal = 255;
      	}
      	map(controlSignal,0,800,0,255);
    	analogWrite(10, controlSignal);
    }
    else{
      	digitalWrite(10, LOW);
    }
  Serial.println(distanceDeviation);
}