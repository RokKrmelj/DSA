float getTemp(int a){
  float volt = a * (5000.0/1023);
  volt = volt - 400;
  float temperatura = volt / 19.5;
  return temperatura;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int senzor = analogRead(A1);
  float temperatura = getTemp(senzor);
  Serial.println(temperatura);
  delay(1);
}
