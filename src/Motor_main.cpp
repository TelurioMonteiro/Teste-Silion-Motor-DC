/**
 * @file Motor_main.cpp
 * @brief Arquivo principal para teste de atuação do motor DC Silion
 * @version 1.0
 * @date 2025-01-14
 * 
 */

#include <Motor_header.h>  //arquivo Header do Teste motor DC Silion (dentro da pasta include)

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Motor DC Silion");
}

void loop() {
  handleButtonPress();
}

void handleButtonPress() {
  static unsigned long lastPressTime = 0;
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (millis() - lastPressTime > 200) { // Debounce
      digitalWrite(MOTOR_PIN, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Motor Ligado");
      delay(10000); // Motor ligado por 10 segundos
      digitalWrite(MOTOR_PIN, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Motor Desligado");
      lastPressTime = millis();
    }
  }
}

void buzzBeep(int beeps, int ms) {
  if (beeps <= 0)
    return;
  digitalWrite(BUZZ, HIGH);
  delay(ms);
  digitalWrite(BUZZ, LOW);
  delay(ms);
  buzzBeep(beeps - 1, ms);
}  // fim buzzBeep()
