#define enA 6
#define in2 5
#define in1 3


const int potPin = A0;

int pot_read = 0;
int motorSpeed = 0;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  Serial.begin(9600);

  // Set motor direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void loop()
{
  // Read potentiometer (0–1023)
  pot_read = analogRead(potPin);

  // Convert reading to PWM (0–255)
  motorSpeed = map(pot_read, 0, 1023, 0, 255);

  // Control motor speed
  analogWrite(enA, motorSpeed);

  // Print values to Serial Monitor
  Serial.print("Potentiometer: ");
  Serial.print(pot_read);

  Serial.print(" | Motor Speed (PWM): ");
  Serial.println(motorSpeed);

  delay(50);
}
