int buttons[6];
int buttons[0] = 2;

int notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyval = analogRead(A0);
  Serial.println(keyval);
  
  if(keyval = 1023) {
    tone(8, notes[0]);
  }
