const int buzzer = 8;
const int trig_pin = 9;
const int echo_pin = 10;
float timing = 0.0;
float distance = 0.0;

void setup()
{
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  digitalWrite(trig_pin, LOW);
  digitalWrite(buzzer, LOW);
    
  Serial.begin(9600);
}

double getDistance(){
  digitalWrite(trig_pin, LOW);
  delay(2);
  
  digitalWrite(trig_pin, HIGH);
  delay(10);
  digitalWrite(trig_pin, LOW);
  
  timing = pulseIn(echo_pin, HIGH);
  distance = (timing * 0.034) / 2; 
  return distance; // cm
}

void print(double d){
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm\n");
}

void loop()
{
  print(getDistance());
  int trial = 10, minError = 1, maxError = 10, error = 5;
  for(int i = 0; i < trial; i++){
    
  }
  delay(1000);
}