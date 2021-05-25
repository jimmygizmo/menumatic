#ifndef CUSTOMCHARS_H
#define CUSTOMCHARS_H

// ########    CUSTOM CHARACTER DEFINITIONS (ICONS)   ########

int CHR_SELECT = 1;
int CHR_UP = 2;
int CHR_DOWN = 3;
int CHR_LEFT = 4;
int CHR_RIGHT = 5;
int CHR_RESET = 6;

byte c_up[8] = {
  B00000,
  B00100,
  B01110,
  B11111,
  B01110,
  B01110,
  B01110,
  B00000,
};

byte c_down[8] = {
  B00000,
  B01110,
  B01110,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000,
};

byte c_left[8] = {
  B00000,
  B00100,
  B01111,
  B11111,
  B01111,
  B00100,
  B00000,
  B00000,
};

byte c_right[8] = {
  B00000,
  B00100,
  B11110,
  B11111,
  B11110,
  B00100,
  B00000,
  B00000,
};

byte c_select[8] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000,
};

byte c_reset[8] = {
  B00000,
  B01110,
  B10001,
  B10101,
  B10101,
  B10001,
  B01110,
  B00000,
};

#endif

////
//
