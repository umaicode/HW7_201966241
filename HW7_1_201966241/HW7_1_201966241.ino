// map(reading, 350, 800, 0, 4)인 이유는 촬영환경에서 기본적으로 조도센서가 읽어오는 값이 300을 넘기기
// 때문에 350부터 시작하였고, 800인 이유는 완전히 덮었을 때 800을 넘기기 때문입니다.
// 0, 1023 까지 해야하는데 불을 완전히 꺼도 1023이 안나오고 불을 완전히 켜도 0이 나오지 않아서 수정하였습니다.

int pins_LED[] = {2, 3, 4, 5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < 4; i++) {
    pinMode(pins_LED[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(56);
  Serial.print("조도센서 값 : ");
  Serial.println(reading);

  if(reading > 150) {
    int light = map(reading, 350, 800, 0, 4);
    for(int i = 0; i < light; i++) {
      digitalWrite(pins_LED[i], HIGH);
    }
    for(int i = light; i < 4; i++) {
      digitalWrite(pins_LED[i], LOW);
    }
  }
  if(reading <= 150) {
    for(int i = 0; i < 4; i++) {
      digitalWrite(pins_LED[i], LOW);
    }
  }
  delay(500);
}
