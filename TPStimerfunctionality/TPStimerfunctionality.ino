boolean isOn;
boolean wasOff;
int sensorValue = 50;
int sensorPin = A0;
int ledPin = 13;
unsigned long timer;
unsigned long previoustime;

void setup() {
  wasOff = true;
  isOn = false;
  previoustime = 0;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  // Read digital button pin
  sensorValue = analogRead(sensorPin);
  
  if (sensorValue * (5.0 / 1023.0) >= 4) {
    if (wasOff) {
      // Button was just pressed on
      // Mark start of sampling
      wasOff = false;
      digitalWrite(ledPin, HIGH);
      previoustime = millis()/1000;
    } // Otherwise do nothing
  } else {
    if (~wasOff) {
      // Button was JUST pressed off
      // (i.e. the sampler was just on)
      // Mark end of sampling
      wasOff = true;
      digitalWrite(ledPin, LOW);
      timer = millis()/1000 - previoustime;
      // Display the timer data
      Serial.println(timer);
    } // Otherwise do nothing
  }
}
