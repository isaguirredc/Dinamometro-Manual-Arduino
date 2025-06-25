#include <HX711_ADC.h>
#include <EEPROM.h>

// Pinos do HX711
const int HX711_dout = 4; // DOUT do HX711
const int HX711_sck = 5;  // SCK do HX711

// Objeto da célula de carga
HX711_ADC LoadCell(HX711_dout, HX711_sck);

// Valor de calibração conhecido (ajuste após calibrar)
float calFactor = 696.0;  // Substitua por seu valor real

void setup() {
  Serial.begin(9600);
  delay(100);

  LoadCell.begin();
  LoadCell.start(2000);          // Tempo de estabilização
  LoadCell.setCalFactor(calFactor);
  LoadCell.tare();               // Tare (zerar balança)
  while (!LoadCell.update());   // Aguarda primeira leitura
}

void loop() {
  static bool newDataReady = false;

  if (LoadCell.update()) newDataReady = true;

  if (newDataReady) {
    float peso = LoadCell.getData();
    Serial.println(peso, 2);  // Envia apenas o número, com 2 casas decimais
    newDataReady = false;
  }
}