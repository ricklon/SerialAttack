/*
 * list structure implenented in an array.
 * This is handy for Arduino, and embedded system without memory managment
 *
 *
 * author: Rick Anderson
 * With help from:
 * Data Structures and Program Design in C 
 * by Rober Kruse, Bruce Leung, and Clovis Tondo
 * /
 
#ifndef list_h
#define list_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include "pins_arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

#define MAX 5;

int avail, lastnode;
int next[MAX];


