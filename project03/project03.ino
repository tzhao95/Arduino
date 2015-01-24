const int sensor = A0;
const float baseT = 20.0;

void setup() {
  Serial.begin(9600);
  for(int i = 2; i< 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, 0);
  }
}

void loop() {
  int sensorvalue = analogRead(sensor);
  Serial.print("Sensor Value: ");
  Serial.print(sensorvalue);
  float volts = (sensorvalue/1024) * 5.0;
  Serial.print(" , Volts: ");
  Serial.print(volts);
  float temp = (volts - 0.5) * 100;
  Serial.print(", Degrees C: ");
  Serial.println(temp);
  
  if(temp < baseT) {
    for(int i = 2; i< 5; i++) {
      digitalWrite(i, 0);
    }
  }
  else if(temp >= baseT + 2 && temp < baseT + 4) {
    digitalWrite(2, 1);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
  }
  else if(temp >= baseT + 4 && temp < baseT + 6) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 0);
  }
  else if(temp >= baseT + 6) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
  }
  delay(1);
}
