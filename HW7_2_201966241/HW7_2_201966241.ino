#include <pitches.h>

int vResistor = A0;

int speakerPin = 56;
int melody[] = {0, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};  // 무음 + 도레미파솔라시도
int noteDuration = 4; // 4분 음표

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(vResistor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(vResistor);
  int index = map(value, 0, 1023, 0, 8);
  int noteLength = 1000 / noteDuration;
  Serial.print("가변저항 값 : ");
  Serial.println(value);
  tone(speakerPin, melody[index], noteLength);

  delay(noteLength);
  noTone(speakerPin);
  delay(100);
}
