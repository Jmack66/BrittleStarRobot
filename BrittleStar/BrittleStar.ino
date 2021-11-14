#include "common.h"
#include "Stepper.h"
int stepper1[4] = {S11, S12, S13, S14};
int stepper2[4] = {S21, S22, S23, S24};
int delayTime = 3;


void setup() {
  Serial.begin(115200);
  delay(500);
  
  Stepper::setPins(stepper1);
  Stepper::setPins(stepper2);
  
  LOG("GO");
  //Stepper::driveStepper(stepper1, QUARTER, FORWARD, delayTime);
  //delay(1000);
  //Stepper::driveStepper(stepper1, QUARTER, BACKWARD, delayTime);
  //delay(1000);
  //Stepper::driveStepper(stepper2, QUARTER, FORWARD, delayTime);
  //delay(1000);
  //Stepper::driveStepper(stepper2, QUARTER, BACKWARD, delayTime);
}

void loop() {
  Stepper::driveStepper(stepper1, EIGHTH + SMALL, FORWARD, delayTime);
  Stepper::driveStepper(stepper2, EIGHTH + SMALL, FORWARD, delayTime);
  Stepper::driveStepper(stepper1, EIGHTH + SMALL, BACKWARD, delayTime);
  Stepper::driveStepper(stepper2, EIGHTH + SMALL, BACKWARD, delayTime);

}
