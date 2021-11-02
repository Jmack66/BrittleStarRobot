#pragma once
#include "common.h"
enum step{
  QUARTER = 512,
  HALF = 1024,
  THREE_QUART = 1536,
  FULL = 2048
};
enum direction{BACKWARD,FORWARD};

namespace Stepper{

void driveStepper(int* pins, int steps, bool forward, int delayTime) {
  int set = 0;
  for (auto j = 0; j < steps; j++) {
    if (set > 3) {
      set = 0;
    }
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
  for (auto i = 0; i < 4; i++) {
    digitalWrite(*(pins + i), LOW);
  }
}

void setPins(int* pins) {
  for (auto i = 0; i < 4; i++) {
    pinMode(*(pins + i), OUTPUT);
  }

}
}
