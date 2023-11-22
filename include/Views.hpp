#ifndef VIEWS_HPP
#define VIEWS_HPP

#include "Arduino.h"
#include "View.hpp"

// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00111111111111111111111111111111111111110000000000111111110001100011000110000000000000000111111100000000000000000000000000000000
// 00101111111111111111100000000000000000011000000000100000000001100000001100000000000000111111100000000000000000000000000000000000
// 00101111111111111111100000000000000000000100000000111111100001100000011000000000000111111111100000000000000000000000000000000000
// 00101111111111111111100000000000000000000100000000000000110001100000110000000000111111100111100000000000000000000000000000000000
// 00101111111111111111100000000000000000011000000000000000110001100001100000000111111001100000000000000000000000000000000000000000
// 00111111111111111111111111111111111111110000000000111111110001100011000110011111111111100000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

#define BITMAP_T static uint8_t

#define CHAR_WIDTH 8
#define CHAR_HEIGHT 6
#define CHAR_SPACING_MIN 1
#define CHAR_SPACING_MAX 3

BITMAP_T one_bmp[] = {
  0b00011000,
  0b00111000,
  0b01011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000 
};

BITMAP_T two_bmp[] = {
  0b11111111,
  0b00000001,
  0b00000001,
  0b01111111,
  0b10000000,
  0b10000000,
  0b11111111
};

BITMAP_T three_bmp[] = {
  0b11111110,
  0b00000001,
  0b00000001,
  0b11111110,
  0b00000010,
  0b00000001,
  0b00000010,
  0b11111100
};

BITMAP_T four_bmp[] = {
  0b10000001,
  0b10000001,
  0b10000001,
  0b01111111,
  0b00000001,
  0b00000001,
  0b00000001,
  0b00000001
};

BITMAP_T five_bmp[] = {
  0b11111111,
  0b10000000,
  0b10000000,
  0b01111100,
  0b00000010,
  0b00000001,
  0b00000001,
  0b11111110
};

BITMAP_T six_bmp[] = {
  0b01111111,
  0b10000000,
  0b10000000,
  0b11111100,
  0b10000010,
  0b10000001,
  0b10000001,
  0b01111110
};

BITMAP_T seven_bmp[] = {
  0b11111111,
  0b00000011,
  0b00000110,
  0b00001100,
  0b00011010,
  0b00110000,
  0b00110000,
  0b00110000
};

BITMAP_T eight_bmp[] = {
  0b01111110,
  0b10000001,
  0b11000011,
  0b01111110,
  0b10000001,
  0b10000001,
  0b10000001,
  0b01111110
};

BITMAP_T nine_bmp[] = {
  0b01111110,
  0b10000001,
  0b10000001,
  0b01111110,
  0b00000011,
  0b00000001,
  0b00000001,
  0b01111110
};

BITMAP_T zero_bmp[] = {
  0b01111111,
  0b10000001,
  0b10000001,
  0b10000001,
  0b10000001,
  0b10000001,
  0b10000001,
  0b01111111
};

BITMAP_T percentage_bmp[] = {
  0b11000011,
  0b11000110,
  0b00001100,
  0b00011000,
  0b00110000,
  0b01100000,
  0b11000110,
  0b10000110,
};

#define LOGO_WIDTH 16
#define LOGO_HEIGHT 16
BITMAP_T logo_bmp[] = {
  0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000
};

#define CO_BATTERY_LOGO_X 15
#define CO_BATTERY_LOGO_Y 6
#define LB_BATTERY_LOGO_X 15
#define LB_BATTERY_LOGO_Y 19
#define BATTERY_LOGO_WIDTH 40
#define BATTERY_LOGO_HEIGHT 8
#define BATTERY_SPLITS 32
BITMAP_T battery_bmp[] = {
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000,
  0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b01100000,
  0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b01100000,
  0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b00010000,
  0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b00010000,
  0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b01100000,
  0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b01100000,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000
};

#define BATTERY_SPLIT_WIDTH 1
#define BATTERY_SPLIT_HEIGHT 6
BITMAP_T battery_split_bmp[] = {
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000
};

static View getPercentageCharView() {
  return View(CHAR_WIDTH, CHAR_HEIGHT, 0, 0, percentage_bmp);
}

static View getDigitView(uint8_t num) {
  switch (num) {
    case 0:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, zero_bmp);
    case 1:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, one_bmp);
    case 2:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, two_bmp);
    case 3:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, three_bmp);
    case 4:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, four_bmp);
    case 5:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, five_bmp);
    case 6:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, six_bmp);
    case 7:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, seven_bmp);
    case 8:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, eight_bmp);
    case 9:
      return View(
        CHAR_WIDTH,
        CHAR_HEIGHT,
        0, 0, nine_bmp);
    default:
      return NULL;
  }
}

static View get_percentage_view(float percentage, uint8_t x, uint8_t y) {
  if (percentage < 0) {
    percentage = 0;
  }
  if (percentage > 100) {
    percentage = 100;
  }
  View battery_percentage_view(
    CHAR_WIDTH * 4 + CHAR_SPACING_MIN * 3,
    CHAR_HEIGHT, x, y
  );
  View percentage_char_view = getPercentageCharView();
  percentage_char_view.y = battery_percentage_view.y;
  if (percentage == 100) {
    View oneView = getDigitView(1);
    oneView.x = battery_percentage_view.x;
    oneView.y = battery_percentage_view.y;
    battery_percentage_view += oneView;
    View zeroView = getDigitView(0);
    zeroView.x = oneView.x + CHAR_WIDTH + CHAR_SPACING_MIN;
    zeroView.y = oneView.y;
    battery_percentage_view += zeroView;
    zeroView.x = zeroView.x + CHAR_WIDTH + CHAR_SPACING_MIN;
    battery_percentage_view += zeroView;
    percentage_char_view.x = zeroView.x + CHAR_WIDTH + CHAR_SPACING_MIN;
    battery_percentage_view += percentage_char_view;
  } else if (percentage > 9) {
    uint8_t firstDigit = (uint8_t) (percentage - 5) / 10;
    uint8_t secondDigit = ((uint8_t) percentage) % 10;
    View firstDigitView = getDigitView(firstDigit);
    View secondDigitView = getDigitView(secondDigit);
    firstDigitView.x = battery_percentage_view.x;
    firstDigitView.y = battery_percentage_view.y;
    battery_percentage_view += firstDigitView;
    secondDigitView.x = firstDigitView.x + CHAR_WIDTH + CHAR_SPACING_MIN;
    secondDigitView.y = firstDigitView.y;
    battery_percentage_view += secondDigitView;
    percentage_char_view.x = secondDigitView.x + CHAR_WIDTH + CHAR_SPACING_MIN;
    battery_percentage_view += percentage_char_view;
  } else {
    View digitView = getDigitView(percentage);
    digitView.x = battery_percentage_view.x;
    digitView.y = battery_percentage_view.y;
    battery_percentage_view += digitView;
    percentage_char_view.x = digitView.x + CHAR_WIDTH + CHAR_SPACING_MIN;
    battery_percentage_view += digitView;
  }
  return percentage;
}

#endif // !VIEWS_HPP
