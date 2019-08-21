const int D13 = 13;
boolean wasoff = true;
int t0 = 0;
int timer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(D13, OUTPUT);
  pinMode(7,INPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,LOW);
}

void loop() {
  // put your main code here, to run repeatedly
  
  if (digitalRead(7) == HIGH) {
    if (wasoff == true) {
      // start timer
      wasoff = false;
      t0 = millis();
    }
  } else {
    if (wasoff == false) {
      // stop timer
      wasoff = true;
      timer = millis() - t0;
      t0 = timer;
      // display timer here
      
      timer = 0;
    }
  }
}
