int red = 8;
int yellow = 7;
int green = 6;

int time = 1000;
int cnt = 1;
int blink = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void BLINK(int led1, int led2){
  int LOOP = 3;
  while(LOOP--){
    digitalWrite(led1, HIGH);
    delay(blink);
    digitalWrite(led1, LOW);
    
    digitalWrite(led2, HIGH);
    delay(blink);
    digitalWrite(led2, LOW);
  }
}

void loop() {

  digitalWrite(red, HIGH);
  delay(time);
  digitalWrite(red, LOW);

  BLINK(red, yellow);

  digitalWrite(yellow, HIGH);
  delay(time / 4);
  digitalWrite(yellow, LOW);

  digitalWrite(green, HIGH);
  delay(time);
  digitalWrite(green, LOW);

  BLINK(green, yellow);

  digitalWrite(yellow, HIGH);
  delay(time / 4);
  digitalWrite(yellow, LOW);

  if(cnt % 4 == 1){
    time = time * 2;
  }
  else if(cnt % 4 == 2){
    time = time * 2;
  }
  else if(cnt % 4 == 3){
    time = time / 2;
  }
  else{
    time = time / 2;
    cnt = 0;
  }
  cnt++;
}
