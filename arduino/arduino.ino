#define ECHO_FRONT 6
#define TRIG_FRONT 7
#define ECHO_BACK 8
#define TRIG_BACK 9

void setup() {
  Serial.begin(9600); 

  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_BACK, OUTPUT);
  pinMode(ECHO_BACK, INPUT);

}

void loop()

{
  long duration_front, distance_front, duration_back, distance_back;

  digitalWrite(TRIG_FRONT, LOW);
  digitalWrite(TRIG_BACK, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_FRONT, HIGH);
  digitalWrite(TRIG_BACK, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_FRONT, LOW);
  digitalWrite(TRIG_BACK, LOW);

  duration_front = pulseIn (ECHO_FRONT, HIGH);
  duration_back = pulseIn (ECHO_BACK, HIGH);
  distance_front = duration_front * 17 / 1000;
  distance_back = duration_back * 17 / 1000;

  Serial.print("Front : ");
  Serial.print(distance_front);
  Serial.print(" Cm, Back : ");
  Serial.print(distance_back);
  Serial.println(" Cm");

  delay(100);

}
