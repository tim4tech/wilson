int dirL = 12;
int dirR = 13;
int brkL = 9;
int brkR = 8;
int spdL = 3;
int spdR = 11;

int pingPin = 2;

void setup()
{
  pinMode(dirL, OUTPUT); //direction pins
  pinMode(dirR, OUTPUT);
  pinMode(brkL, OUTPUT); //brake pins
  pinMode(brkR, OUTPUT);
  pinMode(spdL, OUTPUT); //speed pins
  pinMode(spdR, OUTPUT);
}

void forward()
{
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);
  digitalWrite(brkL, LOW);
  digitalWrite(brkR, LOW);
  digitalWrite(spdL, HIGH);
  digitalWrite(spdR, HIGH);
}

void backward()
{
  digitalWrite(dirL, HIGH);
  digitalWrite(dirR, HIGH);
  digitalWrite(brkL, LOW);
  digitalWrite(brkR, LOW);
  digitalWrite(spdL, HIGH);
  digitalWrite(spdR, HIGH);
}

void left()
{
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, HIGH);
  digitalWrite(brkL, LOW);
  digitalWrite(brkR, LOW);
  digitalWrite(spdL, HIGH);
  digitalWrite(spdR, HIGH);
}

void right()
{
  digitalWrite(dirL, HIGH);
  digitalWrite(dirR, LOW);
  digitalWrite(brkL, LOW);
  digitalWrite(brkR, LOW);
  digitalWrite(spdL, HIGH);
  digitalWrite(spdR, HIGH);
}

void halt()
{
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);
  digitalWrite(brkL, HIGH);
  digitalWrite(brkR, HIGH);
  digitalWrite(spdL, HIGH);
  digitalWrite(spdR, HIGH);
}

long duration, inches;

void detect()
{
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  inches = microsecondsToInches(duration);

  delay(100);
}

void loop()
{ 
  detect();

  if(inches < 12) {
    halt();
    delay(20);
    left();
    delay(50);
    halt();
    detect();

    if(inches > 12) {
      forward();
    }
  }

  else {
    forward();
  }
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

