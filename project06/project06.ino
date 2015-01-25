int sensorvalue;
int sensorlow = 1023;
int sensorhigh = 0;

const int LED = 13;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, 1);
  
  while(millis() < 5000) {
    sensorvalue = analogRead(A0);
    if(sensorvalue > sensorhigh) {
      sensorhigh = sensorvalue;
    }
    if(sensorvalue < sensorlow) {
      sensorlow = sensorvalue;
    }
  }
  digitalWrite(LED, 0);
}

void loop () {
  sensorvalue = analogRead(A0);
  int pitch = map(sensorvalue, sensorlow, sensorhigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}
