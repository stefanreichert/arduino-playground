#include <LiquidCrystal.h>

// LCD PIN config
static const int PIN_LCD_RS = 12;
static const int PIN_LCD_EN = 11;
static const int PIN_LCD_D4 = 5;
static const int PIN_LCD_D5 = 4;
static const int PIN_LCD_D6 = 3;
static const int PIN_LCD_D7 = 2;

// LCD config
static const String TEXT_LCD_TEMPERATURE_UNIT = String((char)223) + " Cel.";
static const String TEXT_LCD_TEMPERATURE = "Temp.";
static const String TEXT_LCD_TEMPERATURE_NO_DATA = "Temp.: -no data-";
static const String TEXT_LCD_HUMIDITY = "Hmdt.";
static const String TEXT_LCD_HUMIDITY_UNIT = "%";
static const String TEXT_LCD_HUMIDITY_NO_DATA = "Hmdt.: -no data-";
static const int COUNT_LCD_CHARS = 16;
static const int COUNT_LCD_ROWS = 2;

LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_EN, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);

// LCD control
static void update_lcd_text(String text_line_one, String text_line_two){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text_line_one);
  lcd.setCursor(0, 1);
  lcd.print(text_line_two);
}

static void update_lcd_text(float temperatur, float humidity){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(TEXT_LCD_TEMPERATURE);
  lcd.print(": ");
  lcd.print(temperatur, 0);
  lcd.print(TEXT_LCD_TEMPERATURE_UNIT);
  lcd.setCursor(0, 1);
  lcd.print(TEXT_LCD_HUMIDITY);
  lcd.print(": ");
  lcd.print(humidity, 0);
  lcd.print(TEXT_LCD_HUMIDITY_UNIT);
}

static void setup_lcd(){
  lcd.begin(COUNT_LCD_CHARS, COUNT_LCD_ROWS);
  update_lcd_text(TEXT_LCD_TEMPERATURE_NO_DATA, TEXT_LCD_HUMIDITY_NO_DATA);
}