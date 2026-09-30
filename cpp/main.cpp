/*
code source 1_This is where we control the pre-built functions, main working space
 
Author 1: DOAN HAI PHONG (TEDDY)
Author 2: ChatGPT =)))
Origin: Vietnamese
Date of finish: 20 July 2026
OPEN SOURCE, FREE FOR COMMUNITY



*/




#include <Arduino.h>

#include "Ledeffect.h"
#include "OLEDDisplay.h"
#include "UI.h"

void setup()
{
  pinMode(DATA_COL, OUTPUT);
  pinMode(LATCH_COL, OUTPUT);
  pinMode(CLOCK_COL, OUTPUT);

  pinMode(DATA_LAY, OUTPUT);
  pinMode(LATCH_LAY, OUTPUT);
  pinMode(CLOCK_LAY, OUTPUT);

  clearCube();

  initOLED();
  showLogoIntro();

  initUI();
}

void loop()
{
  updateUI();
}