#include <Keypad.h>

// Keypad PIN config
static const int PIN_KEYPAD_ROW_ONE = 6;
static const int PIN_KEYPAD_ROW_TWO = 7;
static const int PIN_KEYPAD_ROW_THREE = 8;
static const int PIN_KEYPAD_ROW_FOUR = 9;
static const int PIN_KEYPAD_COLUMN_ONE = 10;
static const int PIN_KEYPAD_COLUMN_TWO = 11;
static const int PIN_KEYPAD_COLUMN_THREE = 12;
static const int PIN_KEYPAD_COLUMN_FOUR = 13;

static const byte COUNT_KEYPAD_ROWS = 4;
static const byte COUNT_KEYPAD_COLS = 4;

static const byte ROW_PINS[COUNT_KEYPAD_ROWS] = {PIN_KEYPAD_ROW_ONE, PIN_KEYPAD_ROW_TWO, PIN_KEYPAD_ROW_THREE, PIN_KEYPAD_ROW_FOUR};
static const byte COLUMN_PINS[COUNT_KEYPAD_COLS] = {PIN_KEYPAD_COLUMN_ONE, PIN_KEYPAD_COLUMN_TWO, PIN_KEYPAD_COLUMN_THREE, PIN_KEYPAD_COLUMN_FOUR};

// Keypad config
static const char ONE = '1';
static const char TWO = '2';
static const char THREE = '3';
static const char FOUR = '4';
static const char FIVE = '5';
static const char SIX = '6';
static const char SEVEN = '7';
static const char EIGHT = '8';
static const char NINE = '9';
static const char ZERO = '0';
static const char A = 'A';
static const char B = 'B';
static const char C = 'C';
static const char D = 'D';
static const char HASH = '#';
static const char ASTERISK = '*';

static char hexaKeys[COUNT_KEYPAD_ROWS][COUNT_KEYPAD_COLS] = {
  {ONE, TWO, THREE, A},
  {FOUR, FIVE, SIX, B},
  {SEVEN, EIGHT, NINE, C},
  {ASTERISK, ZERO, HASH, D}
};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), ROW_PINS, COLUMN_PINS, COUNT_KEYPAD_ROWS, COUNT_KEYPAD_ROWS);

// Keypad control
static char getKey(){
  return customKeypad.getKey();
}
