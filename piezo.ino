int rpin = 6;
int gpin = 5;
int bpin = 3;
char input;

int PIEZO = 11;

void setup() {
  Serial.begin(9600);
  pinMode(rpin, OUTPUT);
  pinMode(gpin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(PIEZO, INPUT);
}

void loop() {
  if(Serial.available() > 0) {
    input = Serial.read();
    
    if(input == 'A') {
      digitalWrite(rpin, HIGH);
      digitalWrite(gpin, LOW);
      digitalWrite(bpin, LOW);
      Serial.println("RED LED ON");
      tone(PIEZO, 1);
      delay(1000);
      noTone(PIEZO);
    }else if(input == 'B') {
      digitalWrite(rpin, LOW);
      digitalWrite(gpin, HIGH);
      digitalWrite(bpin, LOW);
      Serial.println("GREEN LED ON");
      tone(PIEZO, 8000);
      delay(1000);
      noTone(PIEZO);
    }else if(input == 'C') {
      digitalWrite(rpin, LOW);
      digitalWrite(gpin, LOW);
      digitalWrite(bpin, HIGH);
      Serial.println("BLUE LED ON");
      tone(PIEZO, 10000);
      delay(1000);
      noTone(PIEZO);
    }
  }
}
      