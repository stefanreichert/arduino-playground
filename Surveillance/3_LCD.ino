#include <LiquidCrystal.h>

// LCD PIN config
static const int PIN_LCD_RS = 9;
static const int PIN_LCD_EN = 8;
static const int PIN_LCD_D4 = 7;
static const int PIN_LCD_D5 = 6;
static const int PIN_LCD_D6 = 5;
static const int PIN_LCD_D7 = 4;

// LCD config
static const String TEXT_LCD_ANGLE = "Angle";
static const String TEXT_LCD_ANGLE_UNIT = String((char)223);
static const String TEXT_LCD_DISTANCE = "Dist.";
static const String TEXT_LCD_DISTANCE_UNIT = "cm";
static const String TEXT_LCD_SURVEILLANCE = "Surveillance";
static const String TEXT_LCD_SURVEILLANCE_NO_CONTACT = "- no contact -";
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

static void update_lcd_text(int angle, float distance, char severity){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(TEXT_LCD_ANGLE);
  lcd.print(": ");
  lcd.print(angle);
  lcd.print(TEXT_LCD_ANGLE_UNIT);
  lcd.setCursor(0, 1);
  lcd.print(TEXT_LCD_DISTANCE);
  lcd.print(": ");
  lcd.print(distance, 0);
  lcd.print(TEXT_LCD_DISTANCE_UNIT);
  lcd.print(" (");
  lcd.print(severity);
  lcd.print(")");
}

static void update_lcd_text_no_contact(){
  update_lcd_text(TEXT_LCD_SURVEILLANCE, TEXT_LCD_SURVEILLANCE_NO_CONTACT);
}

static void setup_lcd(){
  lcd.begin(COUNT_LCD_CHARS, COUNT_LCD_ROWS);
  update_lcd_text_no_contact();
}