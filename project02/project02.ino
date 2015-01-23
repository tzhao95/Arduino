int switch = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switch = digitalRead(2);
  if (switch == 0) {
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
  }
  else{
    digitalWrite(3, 0);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    
    delay(250);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    delay(250);
  }
}
