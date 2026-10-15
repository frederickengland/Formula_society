#define enA 10
#define enB 11

#define in1 3
#define in2 5
#define in3 6
#define in4 9

const int potPin = A0;

int pot_read = 0;
int throttle = 60;
int steering = 0;

int clamp(int value, int minimum, int maximum)
{
  return max(minimum, min(value, maximum));
}

void calculate_turning(int throttle, int steering, int &left_power, int &right_power)
{
  left_power = throttle - steering;
  right_power = throttle + steering;

  left_power = clamp(left_power, -100, 100);
  right_power = clamp(right_power, -100, 100);
}

void set_motor(int enablePin, int pin1, int pin2, int speed)
{
  int pwm = map(abs(speed), 0, 100, 0, 255);

  if (speed > 0)
  {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  }
  else if (speed < 0)
  {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  }
  else
  {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }

  analogWrite(enablePin, pwm);
}

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Read potentiometer
  pot_read = analogRead(potPin);

  // Convert 0-1023 to -100 to +100
  steering = map(pot_read, 0, 1023, -100, 100);

  int left;
  int right;

  // Calculate motor powers
  calculate_turning(throttle, steering, left, right);

  // Print values
  Serial.print("Potentiometer: ");
  Serial.print(pot_read);

  Serial.print(" | Steering: ");
  Serial.print(steering);

  Serial.print(" | Left Motor: ");
  Serial.print(left);

  Serial.print(" | Right Motor: ");
  Serial.println(right);

  // Control motors
  set_motor(enA, in1, in2, left);
  set_motor(enB, in3, in4, right);

  delay(50);
}