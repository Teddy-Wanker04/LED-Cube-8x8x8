/*
code source 2

Author 1: DOAN HAI PHONG (TEDDY)
Author 2: ChatGPT =)))
Origin: Vietnamese
Date of finish: 20 July 2026
OPEN SOURCE, FREE FOR COMMUNITY

*/


//A .cpp file can call a function from another .cpp file, but it must know the function exists first.
//That “knowing” usually comes from the .h file.


#pragma once // include this header file one time during compilation.
#include <Arduino.h>

#define DATA_COL 25
#define LATCH_COL 32
#define CLOCK_COL 33

#define DATA_LAY 14
#define LATCH_LAY 26
#define CLOCK_LAY 27

void clearCube();

void LEDeffect1_numberdisplay_1  ();
void LEDeffect2_numberdisplay_2  ();
void LEDeffect3_numberdisplay_3  ();
void LEDeffect4_numberdisplay_4  ();
void LEDeffect5_numberdisplay_5  ();
void LEDeffect6_numberdisplay_6  ();
void LEDeffect7_numberdisplay_7  ();
void LEDeffect8_numberdisplay_8  ();
void LEDeffect9_numberdisplay_9  ();
void LEDeffect10_numberdisplay_0 ();
void LEDeffect11_TheRain         ();
void LEDeffect12_Fireworks       ();
void LEDeffect13_layerchecking   ();
void LEDeffect14_512LEDs         ();