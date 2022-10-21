void setup() {
  pinMode(10, OUTPUT);  //clock
  pinMode(11, OUTPUT);  //latch
  pinMode(12, OUTPUT);  //data
}

void posljiPodatek(char podatek){
  
  digitalWrite(10, LOW);  //init clock
  digitalWrite(11, LOW);  //init latch
  digitalWrite(12, LOW);  //init data
  
  for(int i =0; i < 8; i++){
    char maska = B00000001;
    if(podatek & maska){
      digitalWrite(12, HIGH);
    }
    else{
      digitalWrite(12, LOW);
    }
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
    podatek = podatek >> 1;
  }
  digitalWrite(11, HIGH);
  digitalWrite(11, LOW);
}

void loop() {
  posljiPodatek(B00110010);
}
