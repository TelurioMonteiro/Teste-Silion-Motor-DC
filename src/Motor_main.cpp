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
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Motor DC Silion");
  Serial.begin(115200); // Inicializa a comunicação serial
}

void loop() {
  handleButtonPress();
}

void handleButtonPress() {
  static unsigned long lastPressTime = 0;
  if (digitalRead(BUTTON_PIN) == HIGH) {
    if (millis() - lastPressTime > 200) { // Debounce
      digitalWrite(MOTOR_PIN, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Motor Ligado");
      //Serial.println("Motor Ligado"); // Imprime no monitor serial
      buzzBeep(2, 100);// Beep 2 vezes
      delay(10000); // Motor ligado por 10 segundos
      digitalWrite(MOTOR_PIN, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Motor Desligado");
      //Serial.println("Motor Desligado"); // Imprime no monitor serial
      lastPressTime = millis();
    }
  }
}

void buzzBeep(int beeps, int ms) {
  if (beeps <= 0)
    return;
  //Serial.print("Beep "); // Adiciona mensagem de depuração
  Serial.println(beeps);
  digitalWrite(BUZZ_PIN, HIGH);
  delay(ms);
  digitalWrite(BUZZ_PIN, LOW);
  delay(ms);
  buzzBeep(beeps - 1, ms);
}  // fim buzzBeep()