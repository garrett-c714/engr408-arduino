#include <AccelStepper.h>

const int stepsPerRevolution = 200;
const int stepPin = 2;
const int dirPin = 3;

AccelStepper stepper(1, stepPin, dirPin);

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int targetAngle = Serial.parseInt();
    long targetPosition = targetAngle * (stepsPerRevolution / 360.0);
    stepper.moveTo(targetPosition);

    while (stepper.isRunning()) {
      stepper.run();
    }
  }
}
