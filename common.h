#pragma once

//General System Defs
#define STEPS 32 //Intrinsic to the stepper 
#define SPEED 640 //Sets the speed of the stepper motor
#define S11 25
#define S12 26
#define S13 27
#define S14 28
#define S21 29
#define S22 30
#define S23 31
#define S24 32



//General Funcs 
#define LOGN(x) { Serial.println(x); } //serial print a line
#define LOGF(x,n){ Serial.println(x,n);} //Log a float/double/long to n decimal places
#define LOG(x) { Serial.print(x); } //serial print
#define PLOT(name,x) {Serial.print(String(name) + ":"); Serial.print(x); Serial.print("\t");}
#define ENDPLOT() {Serial.println();}
#define DEG2RAD 0.01745329251f
#define RAD2DEG 57.2957795131f
