boolean isOn;
boolean wasOff;
int pumpPin;
unsigned long timer;

void setup() {
  // put your setup code here, to run once:
  wasOff = true;
  isOn = false;
  pumpPin = 1;  // Initialize the pin for the button
  timer = 0;
  Serial.begin(9600);
}

void loop() {
  // Read digital button pin
  if (digitalRead(pumpPin) == HIGH) {
    if (wasOff) {
      // Button was just pressed on
      // Mark start of sampling
      wasOff = false;
    } // Otherwise do nothing
  } else {
    if (~wasOff) {
      // Button was JUST pressed off
      // (i.e. the sampler was just on)
      // Mark end of sampling
      wasOff = true;
      timer = millis()*1000;
      // Display the data
    } // Otherwise do nothing
  }
}
