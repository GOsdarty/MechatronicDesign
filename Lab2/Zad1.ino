unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int currentState;
int oldState;
int realButtonState;
bool stateChanged = 0;
unsigned int launchCounter = 0;
void setup()
{
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);
  pinMode(12, OUTPUT);
  realButtonState = digitalRead(4);
  Serial.begin(9600);
}

void loop()
{
  currentState = digitalRead(4);
  if(stateChanged == 0){
    if(currentState != realButtonState){
    	stateChanged = 1;
    	lastDebounceTime = millis();
      	oldState = currentState;
  	}
  }
  else{
    if(millis()-debounceDelay > lastDebounceTime){
      if(currentState == oldState){
        realButtonState = oldState;
        stateChanged = 0;
        if(realButtonState == HIGH){
        	launchCounter ++;
        }
      }
    }
  }
  
  
  
  if(realButtonState == HIGH){
    if(digitalRead(2) == HIGH){
    	digitalWrite(6, HIGH);
    }
    else{
      	digitalWrite(6, LOW);
    }
    if(digitalRead(3) == HIGH){
      	digitalWrite(12, HIGH);
    }
    else{
      	digitalWrite(12, LOW);
    }  
  }
  else{
    digitalWrite(6, LOW);
    digitalWrite(12, LOW);
  }
  delay(10);
  Serial.println(launchCounter);
}