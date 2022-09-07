#include <PCF8575.h>
#include <Keypad.h>
// do I need Arduino.h?

PCF8575 pcf8575(0x20); // Set I2C address for PCF8575
//unsigned long timeElapsed; is this necessary?

#ifdef NOT_SEQUENTIAL_PINOUT // Improved definition of PCF8575 pin numbers
#define P00     0
#define P01     1
#define P02     2
#define P03     3
#define P04     4
#define P05     5
#define P06     6
#define P07     7
#define P10     8
#define P11     9
#define P12     10
#define P13     11
#define P14     12
#define P15     13
#define P16     14
#define P17     15
#else
#define P0      0
#define P1      1
#define P2      2
#define P3      3
#define P4      4
#define P5      5
#define P6      6
#define P7      7
#define P8      8
#define P9      9
#define P10     10
#define P11     11
#define P12     12
#define P13     13
#define P14     14
#define P15     15
#endif

// Set up matrix for Casio Casiotone MT-240 keybed <add URL to details>
const byte ROWS = 9;
const byte COLS = 6;

// I am setting the lowest C piano key as "C3," aka MIDI Note 48...
byte mt240Keys[ROWS][COLS] = {
  {53, 52, 51, 50, 49, 48},
  {59, 58, 57, 56, 55, 54},
  {71, 70, 69, 68, 67, 66},
  {1, 1, 1, 1, 1, 96}, // The 1, 1, 1, 1, 1 is just a placeholder. The matrix does not connect at these points
  {95, 94, 93, 92, 91, 90},
  {89, 88, 87, 86, 85, 84},
  {83, 82, 81, 80, 79, 78},
  {77, 76, 75, 74, 73, 72},
  {65, 64, 63, 62, 61, 60}
};

// I am using the PCF8575 to handle the keyboard matrix so as not to use up all of my Uno pins
byte rowPins[ROWS] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
byte colPins[COLS] = {9, 10, 11, 12, 13, 14};

Keypad customKeypad = Keypad( makeKeymap(mt240Keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  //sample "keyPressedPin1 sets pinModes... do I have to? Keypad library handles that?
  pcf8575.begin();
}

void loop() {
  byte customKey = customKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);
    // make sounds happen!
  }
}
