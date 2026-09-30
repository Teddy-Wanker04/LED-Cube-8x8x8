/*
code source 7_User interface
 
Author 1: DOAN HAI PHONG (TEDDY)
Author 2: ChatGPT =)))
Origin: Vietnamese
Date of finish: 20 July 2026
OPEN SOURCE, FREE FOR COMMUNITY

*/



#include "UI.h"
#include "OLEDDisplay.h"
#include "Ledeffect.h"

#include <DHT.h>

// =====================================================
// Button pins
// External pull-up resistor version
//
// Not pressed = HIGH
// Pressed     = LOW
// =====================================================

#define BTN_TOP    19
#define BTN_LEFT   18
#define BTN_RIGHT  5
#define BTN_BOTTOM 17
#define BTN_ENTER  16

// =====================================================
// DHT11 sensor
// =====================================================

#define DHTPIN 23
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// =====================================================
// Menu items: 14 LED effects only
// =====================================================

int menuIndex = 0;
int menuTopIndex = 0;

const int visibleRows = 4;

const char* menuItems[] = {
  "Number 1",
  "Number 2",
  "Number 3",
  "Number 4",
  "Number 5",
  "Number 6",
  "Number 7",
  "Number 8",
  "Number 9",
  "Number 0",
  "Rain",
  "Fireworks",
  "Layer Check",
  "512 LEDs"
};

const int menuCount = sizeof(menuItems) / sizeof(menuItems[0]);

// =====================================================
// Screen mode
// =====================================================

bool inEffectScreen = false;
int runningEffectIndex = -1;

// =====================================================
// DHT saved values
// =====================================================

float lastHumidity = NAN;
float lastTemperature = NAN;
unsigned long lastDHTReadTime = 0;

// =====================================================
// Button debounce
// =====================================================

struct Button {
  int pin;
  bool lastReading;
  bool stableState;
  unsigned long lastChangeTime;
};

Button topButton    = {BTN_TOP, HIGH, HIGH, 0};
Button leftButton   = {BTN_LEFT, HIGH, HIGH, 0};
Button rightButton  = {BTN_RIGHT, HIGH, HIGH, 0};
Button bottomButton = {BTN_BOTTOM, HIGH, HIGH, 0};
Button enterButton  = {BTN_ENTER, HIGH, HIGH, 0};

const unsigned long debounceDelay = 50;

bool wasPressed(Button &button)
{
  bool reading = digitalRead(button.pin);

  if (reading != button.lastReading) {
    button.lastChangeTime = millis();
    button.lastReading = reading;
  }

  if ((millis() - button.lastChangeTime) > debounceDelay) {
    if (reading != button.stableState) {
      button.stableState = reading;

      // External pull-up:
      // LOW means button pressed
      if (button.stableState == LOW) {
        return true;
      }
    }
  }

  return false;
}

bool leftButtonHeld()
{
  return digitalRead(BTN_LEFT) == LOW;
}

// =====================================================
// Read DHT11
// =====================================================

void updateDHTValues()
{
  // DHT11 should not be read too fast
  if (lastDHTReadTime != 0 && millis() - lastDHTReadTime < 2000) {
    return;
  }

  lastDHTReadTime = millis();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (!isnan(humidity) && !isnan(temperature)) {
    lastHumidity = humidity;
    lastTemperature = temperature;
  }
}

// =====================================================
// Draw main menu
// =====================================================

void drawMenu()
{
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.println("LED Cube Menu");

  display.drawLine(0, 10, 127, 10, SH110X_WHITE);

  // Keep selected item visible
  if (menuIndex < menuTopIndex) {
    menuTopIndex = menuIndex;
  }

  if (menuIndex >= menuTopIndex + visibleRows) {
    menuTopIndex = menuIndex - visibleRows + 1;
  }

  for (int row = 0; row < visibleRows; row++) {
    int itemIndex = menuTopIndex + row;

    if (itemIndex >= menuCount) {
      break;
    }

    display.setCursor(0, 16 + row * 12);

    if (itemIndex == menuIndex) {
      display.print("> ");
    } else {
      display.print("  ");
    }

    display.println(menuItems[itemIndex]);
  }

  display.setCursor(96, 56);
  display.print(menuIndex + 1);
  display.print("/");
  display.print(menuCount);

  display.display();
}

// =====================================================
// Draw running effect screen with humidity/temp
// =====================================================

void drawEffectScreen()
{
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.println("Running:");

  display.setCursor(0, 12);

  if (runningEffectIndex >= 0 && runningEffectIndex < menuCount) {
    display.println(menuItems[runningEffectIndex]);
  } else {
    display.println("Unknown");
  }

  display.drawLine(0, 24, 127, 24, SH110X_WHITE);

  if (isnan(lastHumidity) || isnan(lastTemperature)) {
    display.setCursor(0, 30);
    display.println("DHT11 no data");

    display.setCursor(0, 42);
    display.println("Check wiring");
  } else {
    display.setCursor(0, 30);
    display.print("Humidity: ");
    display.print(lastHumidity, 1);
    display.println(" %");

    display.setCursor(0, 42);
    display.print("Temp: ");
    display.print(lastTemperature, 1);
    display.println(" C");
  }

  display.setCursor(0, 56);
  display.println("White button = return");

  display.display();
}
// =====================================================
// Run one LED effect once
// =====================================================

void runEffectOnce(int effectIndex)
{
  if (effectIndex == 0) {
    LEDeffect1_numberdisplay_1();
  }

  else if (effectIndex == 1) {
    LEDeffect2_numberdisplay_2();
  }

  else if (effectIndex == 2) {
    LEDeffect3_numberdisplay_3();
  }

  else if (effectIndex == 3) {
    LEDeffect4_numberdisplay_4();
  }

  else if (effectIndex == 4) {
    LEDeffect5_numberdisplay_5();
  }

  else if (effectIndex == 5) {
    LEDeffect6_numberdisplay_6();
  }

  else if (effectIndex == 6) {
    LEDeffect7_numberdisplay_7();
  }

  else if (effectIndex == 7) {
    LEDeffect8_numberdisplay_8();
  }

  else if (effectIndex == 8) {
    LEDeffect9_numberdisplay_9();
  }

  else if (effectIndex == 9) {
    LEDeffect10_numberdisplay_0();
  }

  else if (effectIndex == 10) {
    LEDeffect11_TheRain();
  }

  else if (effectIndex == 11) {
    LEDeffect12_Fireworks();
  }

  else if (effectIndex == 12) {
    LEDeffect13_layerchecking();
  }

  else if (effectIndex == 13) {
    LEDeffect14_512LEDs();
  }
}

// =====================================================
// Select current LED effect
// =====================================================

void selectCurrentItem()
{
  runningEffectIndex = menuIndex;
  inEffectScreen = true;

  clearCube();

  // Read DHT once when entering the effect screen
  lastDHTReadTime = 0;
  updateDHTValues();

  // Draw OLED only once before the LED effect starts
  drawEffectScreen();

  delay(300);
}

// =====================================================
// Init UI
// =====================================================

void initUI()
{
  // You already have external pull-up resistors,
  // so use INPUT, not INPUT_PULLUP.
  pinMode(BTN_TOP, INPUT);
  pinMode(BTN_LEFT, INPUT);
  pinMode(BTN_RIGHT, INPUT);
  pinMode(BTN_BOTTOM, INPUT);
  pinMode(BTN_ENTER, INPUT);

  dht.begin();

  drawMenu();
}

// =====================================================
// Update UI
// Put only updateUI() in main loop()
// =====================================================

void updateUI()
{
  // ===================================================
  // Effect screen mode
  // ===================================================

  if (inEffectScreen) {

  // White button / G18 returns to menu
  if (leftButtonHeld()) {
    clearCube();

    inEffectScreen = false;
    runningEffectIndex = -1;

    drawMenu();
    delay(250);
    return;
  }

  // IMPORTANT:
  // Do NOT redraw OLED here.
  // Redrawing OLED pauses LED cube refresh and causes huge OFF gaps.

  runEffectOnce(runningEffectIndex);

  // Check return button again after one effect cycle
  if (leftButtonHeld()) {
    clearCube();

    inEffectScreen = false;
    runningEffectIndex = -1;

    drawMenu();
    delay(250);
    return;
  }

  return;
}

  // ===================================================
  // Main menu mode
  // ===================================================

  if (wasPressed(topButton)) {
    menuIndex--;

    if (menuIndex < 0) {
      menuIndex = menuCount - 1;
    }

    drawMenu();
  }

  if (wasPressed(bottomButton)) {
    menuIndex++;

    if (menuIndex >= menuCount) {
      menuIndex = 0;
    }

    drawMenu();
  }

  if (wasPressed(enterButton)) {
    selectCurrentItem();
  }

  if (wasPressed(rightButton)) {
    selectCurrentItem();
  }

  if (wasPressed(leftButton)) {
    drawMenu();
  }
}