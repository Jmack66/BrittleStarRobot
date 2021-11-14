#pragma once
#include "common.h"

//enum for the various common steps we might use with the stepper 
enum step{
  SMALL = 128,
  EIGHTH = 256,
  QUARTER = 512,
  HALF = 1024,
  THREE_QUART = 1536,
  FULL = 2048
};

//enum for directions of the stepper
enum direction{BACKWARD,FORWARD};

namespace Stepper{

//drives a stepper takes in the 4 pins as an array, iterates through setting the correct drive pins high to low
//steps defines the number of cycles the setting process will go through 
//forward defines if the stepper will move forward or backwards 
//delaytime is how long the pin states are held high and low 
void driveStepper(int* pins, int steps, bool forward, int delayTime) {
  int set = 0;
  //iterate for the number of steps
  for (auto j = 0; j < steps; j++) {
    if (set > 3) {
      set = 0;
    }
    //iterate through the 4 pins
    for (auto i = 0; i < 4; i++) {
      if (set == i) {
        if (forward) {
          digitalWrite(*(pins + i), HIGH);
        } else {
          digitalWrite(*(pins + (3 - i)), HIGH);
        }
      } else {
        if (forward) {
          digitalWrite(*(pins + i), LOW);
        } else {
          digitalWrite(*(pins + (3 - i)), LOW);
        }
      }

    }
    delay(delayTime);
    set++;
  }
  //end by setting all pins low
  for (auto i = 0; i < 4; i++) {
    digitalWrite(*(pins + i), LOW);
  }
}

//lazy way of setting all the correct pins to output pins
void setPins(int* pins) {
  for (auto i = 0; i < 4; i++) {
    pinMode(*(pins + i), OUTPUT);
  }

}
}//namespace Stepper
