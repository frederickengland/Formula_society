const int motor_left1 = 3;
const int motor_left2 = 5;

const int motor_right1 = 6;
const int motor_right2 = 9;

const int potPin = A0;

int pot_read = 0;
int throttle = 60; // set this to whatever you want to mimic a throttle
// later this will become another potentiometer and change with the steering in realtime.
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

void set_motor(int pin1, int pin2, int speed)
{
  int pwm = map(abs(speed), 0, 100, 0, 255);

  if (speed >= 0)
  {
    analogWrite(pin1, pwm);
    analogWrite(pin2, 0);
  }
  else
  {
    analogWrite(pin1, 0);
    analogWrite(pin2, pwm);
  }
}

void setup()
{
  pinMode(motor_left1, OUTPUT);
  pinMode(motor_left2, OUTPUT);

  pinMode(motor_right1, OUTPUT);
  pinMode(motor_right2, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  pot_read = analogRead(potPin);

  steering = map(pot_read, 0, 1023, -100, 100);

  int left;
  int right;

  calculate_turning(throttle, steering, left, right);
  Serial.print("Potentiometer: ");
  Serial.print(pot_read);
  Serial.print(" | Steering: ");
  Serial.print(steering);
  Serial.print(" | Left Motor: ");
  Serial.print(left);
  Serial.print(" | Right Motor: ");
  Serial.println(right);
  set_motor(motor_left1, motor_left2, left);
  set_motor(motor_right1, motor_right2, right);

  delay(50);
}
