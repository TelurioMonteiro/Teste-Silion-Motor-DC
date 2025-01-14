/* ------------------------------------------- */
/*             Motor DC Silion ESP32           */
/*                                             */
/* ------------------------------------------- */
/*Autor: Estevão Farias Temerloglou Monteiro   */
/*Data: 14/01/24                               */
/*ultima rev: --/--                            */
/*Ver.:                                        */
#define VER 0.01
/*-------------------------------------------- */

// #include <Motor_header.h>


/*-- To do
Crie um projeto, esquemático e placa, usando o software de sua preferência que atenda os seguintes requisitos:
-Utilize um microcontrolador de sua preferência
-Utilize um motor DC de 5V que deverá ser acionado pelo microcontrolador
-Utilize um display 16x2, que deverá se comunicar com o microcontrolador utilizando uma das seguintes opções de comunicação: i2c ou por barramento.
-Utilize um push-button conectado a uma entrada do microcontrolador 
-A placa será alimentada por uma fonte externa de 5v.
-Implemente um trecho de código em linguagem C (não é necessário compilar, mas é importante seguir as boas práticas), para tratar a leitura do sinal do Botão e a partir deste sinal, acionar a saída que irá ligar o motor. O motor deve permanecer ligado por 10 segundos após cada acionamento.
[OPCIONAL] Dimensionar uma fonte DC que receba até 36v e alimente a sua placa com 5v.
*/

// ---- Bibliotecas ----
#include <Arduino.h>
#include <Wire.h>              // Biblioteca para comunicação I2C
#include <LiquidCrystal_I2C.h> // Biblioteca para o display 16x2 com I2C
#include <WebServer.h>         // Servidor web
#include <WiFi.h>              // Wi-Fi

// ---- Definições ----
//--Pinos utilizados
#define MOTOR_PIN 5            // Pino para acionar o motor
#define BUTTON_PIN 4           // Pino do push-button

//-- Default Config
#define I2C_ADDR 0x27          // Endereço I2C do display 16x2

// ---- Instâncias ----
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2); // Inicializa o display

// ---- Variáveis Globais ----
//--Configs


// ---- Protótipos das Funções ----
/**
 * @brief Função setup do Arduino
 */
void setup();

/**
 * @brief Função loop do Arduino
 */
void loop();

/**
 * @brief Gera um número de beeps
 *
 * @param beeps Número de beeps
 * @param ms    Tempo em milisegundos
 */
void buzzBeep(int beeps = 1, int ms = 50);

/**
 * @brief Trata o acionamento do botão
 */
void handleButtonPress();


// end
