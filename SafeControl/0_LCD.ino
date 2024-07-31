#include <LiquidCrystal.h>

// LCD PIN config
static const int PIN_LCD_RS = 5;
static const int PIN_LCD_EN = 4;
static const int PIN_LCD_D4 = 3;
static const int PIN_LCD_D5 = 2;
static const int PIN_LCD_D6 = 1;
static const int PIN_LCD_D7 = 0;

// LCD config
static const String TEXT_LCD_ENTER_PASSWORD = "Enter Password!";
static const String TEXT_LCD_NEW_PASSWORD = "Set Password!";
static const String TEXT_LCD_PASSWORD_ENTER = "Password:";
static const String TEXT_LCD_PASSWORD_NEW = "New Password:";
static const String TEXT_LCD_PASSWORD_SET = "Password Is Set!";
static const String TEXT_LCD_PASSWORD_TOO_SHORT = "Too Short (4)!";
static const String TEXT_LCD_PASSWORD_TOO_LONG = "Too Long (6)!";
static const String TEXT_LCD_PASSWORD_MATCH = "Password Match!";
static const String TEXT_LCD_PASSWORD_WRONG = "Wrong Password!";
static const String TEXT_LCD_SAFE_OPEN = "Safe Is Open";
static const String TEXT_LCD_SAFE_CLOSED = "Safe Is Closed";

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

static void setup_lcd(){
  lcd.begin(COUNT_LCD_CHARS, COUNT_LCD_ROWS);
  update_lcd_safe_open();
}

static String anonymise_password(String password){
  String anonymized_password = "";
  for(int index = 0; index < password.length(); index++){
    anonymized_password = anonymized_password + "*";
  }
  return anonymized_password;
}

static void update_lcd_safe_open(){
  update_lcd_text(TEXT_LCD_SAFE_OPEN, TEXT_LCD_NEW_PASSWORD);
}

static void update_lcd_safe_closed(){
  update_lcd_text(TEXT_LCD_SAFE_CLOSED, TEXT_LCD_ENTER_PASSWORD);
}

static void update_lcd_password_set(){
  update_lcd_text(TEXT_LCD_PASSWORD_SET, TEXT_LCD_SAFE_CLOSED);
}

static void update_lcd_typing_new(String password){
  update_lcd_text(TEXT_LCD_PASSWORD_NEW, anonymise_password(password));
}

static void update_lcd_typing_enter(String password){
  update_lcd_text(TEXT_LCD_PASSWORD_ENTER, anonymise_password(password));
}

static void update_lcd_password_too_short(String password){
  update_lcd_text(TEXT_LCD_PASSWORD_TOO_SHORT, anonymise_password(password));
}

static void update_lcd_password_too_long(String password){
  update_lcd_text(TEXT_LCD_PASSWORD_TOO_LONG, anonymise_password(password));
}

static void update_lcd_password_matched(){
  update_lcd_text(TEXT_LCD_PASSWORD_MATCH, TEXT_LCD_SAFE_OPEN);
}

static void update_lcd_password_wrong(String password){
  update_lcd_text(TEXT_LCD_PASSWORD_WRONG, anonymise_password(password));
}

