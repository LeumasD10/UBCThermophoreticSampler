
int sensorPin = A0;   
int ledPin = 13;      // select the pin for the LED
int sensorValue = 50;  // variable to store the value coming from the sensor
int flag;
boolean wasOff;
unsigned long timer = 0;
unsigned long previoustime;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  Serial.println(timer);
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  if (sensorValue * (5.0 / 1023.0) >= 4) {
    digitalWrite(ledPin, HIGH);
    flag = 1;
  } 
  
  else {
    digitalWrite(ledPin, LOW);
    flag = 0;
  }

  if (flag == 1) {
    if (wasOff) {
      // Button was just pressed on
      // Mark start of sampling
      wasOff = false;
      previoustime = millis()/1000;
    } 
    
    else {
      if (~wasOff) {
      // Button was JUST pressed off
      // (i.e. the sampler was just on)
      // Mark end of sampling
      wasOff = true;
      timer = millis()/1000 - previoustime;
      // Display the timer data
      
    } // Otherwise do nothing
  
  }
}
}
