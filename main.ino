#include "DigiKeyboard.h"

char get_pass(char *pass, int length) {
  char available[82] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '_', '+', '[', '{', '}', ']', '/', '.',
                        '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

  for (int i = 0; i < length; i++) {
    pass[i] = available[random(0, 82)];
  }
  pass[length] = '\0';

  return *pass;
}

void setup() {
  pinMode(1, LOW);

  Serial.begin(9600);
  randomSeed(analogRead(0));

  char pass[129];  // 128 chars + 1 NULL
  get_pass(pass, 128);

  DigiKeyboard.print(pass);
  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  for (int i = 0; i < 9; i++) {
    DigiKeyboard.sendKeyStroke(0x51);  // ARROW_DOWN
    DigiKeyboard.delay(10);
  }

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);

  DigiKeyboard.print("Add-Content passwords.txt \"");
  DigiKeyboard.print(pass);
  DigiKeyboard.print("\"\nexit\n");
  
  DigiKeyboard.delay(100);

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);

  pinMode(1, HIGH);
}

void loop() {
}
