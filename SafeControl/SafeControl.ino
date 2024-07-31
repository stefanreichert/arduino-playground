static int STATE_OPEN = 0;
static int STATE_CLOSED = 1;

static int PASSWORD_MIN_LENGTH = 4;
static int PASSWORD_MAX_LENGTH = 6;

static boolean is_confirm(char typing){
  return typing == '#' || typing == '*';
}

int current_state;
String password;
String typings;

void update_typings_when_closed(char typing){
  if(is_confirm(typing)){
    if(password == typings){
      // password entered correctly, open safe
      update_lcd_password_matched();
      password = "";
      open_safe();
    }
    else{
      // password entered incorrectly, re-close safe
      update_lcd_password_wrong(typings);
      close_safe();
    }
  }
  else{
    // register typing
    typings = typings + typing;
    update_lcd_typing_enter(typings);
  }
}

void update_typings_when_open(char typing){
  if(is_confirm(typing)){
    // check password validity
    if(typings.length() < PASSWORD_MIN_LENGTH){
      update_lcd_password_too_short(typings);
      open_safe();
    }
    else if(typings.length() > PASSWORD_MAX_LENGTH){
      update_lcd_password_too_long(typings);
      open_safe();
    }
    else{
      // valid password, close safe
      update_lcd_password_set();
      password = typings;
      close_safe();
    }
  }
  else {
    // register typing
    typings = typings + typing;
    update_lcd_typing_new(typings);
  }
}

void close_safe(){
  current_state = STATE_CLOSED;
  typings = "";
  delay(2000);
  update_lcd_safe_closed();
}

void open_safe(){
  current_state = STATE_OPEN;
  typings = "";
  delay(2000);
  update_lcd_safe_open();
}

void setup() {
  setup_lcd();
  setup_built_in();
  open_safe();
}

void loop() {
  char typing = getKey();
  if(typing){
    flash_builtin_led();
    if(current_state == STATE_CLOSED){
      update_typings_when_closed(typing);
    }
    else{
      update_typings_when_open(typing);
    }
  }
}
