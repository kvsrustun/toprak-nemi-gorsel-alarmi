#include <Deneyap_ToprakNemiOlcer.h>     
#include <Deneyap_OLED.h>                
#include <Deneyap_5x7LedEkran.h>        
#include <Deneyap_Hoparlor.h>            

#include "beni_sula.h"                   

SoilMoisture ToprakNemi;
OLED oled;
DotMatrix ledMatrix;
Speaker speaker(D11, 0);               
Wav beniSulaSes(beni_sula);             

const int NEM_ESIGI = 900;              

const byte mutsuzSurat[35] = {
  0,1,0,1,0,
  0,1,0,1,0,
  0,0,0,0,0,
  0,1,1,1,0,
  1,0,0,0,1,
  0,0,0,0,0,
  0,0,0,0,0
};

const byte gulenSurat[35] = {
  0,1,0,1,0,
  0,1,0,1,0,
  0,0,0,0,0,
  1,0,0,0,1,
  0,1,1,1,0,
  0,0,0,0,0,
  0,0,0,0,0
};

void setup() {
  Serial.begin(115200);

  if (!ToprakNemi.begin(0x0F)) {
    delay(3000);
    Serial.println("Toprak nem sensörü I2C bağlantısı başarısız!");
    while (1);
  }

  if (!oled.begin(0x7A)) {
    Serial.println("OLED başlatılamadı!");
    while (1);
  }

  if (!ledMatrix.begin(0x0A)) {
    Serial.println("LED Matris başlatılamadı!");
    while (1);
  }

  oled.clearDisplay();
  oled.setFont(font5x7);
  oled.setTextXY(0, 0);
  oled.putString("Basliyor...");
  delay(1000);
}

void loop() {
  uint16_t nem = ToprakNemi.ReadSoilMoisture();
  Serial.print("Toprak nemi: ");
  Serial.println(nem);

  oled.clearDisplay();
  oled.setTextXY(0, 0);
  ledMatrix.resetDotRows();

  if (nem < NEM_ESIGI) {
    oled.putString("Beni sula!");
    ledMatrix.drawLedMatrix(mutsuzSurat, 500);

    speaker.Play(&beniSulaSes);
    while (speaker.AlreadyPlaying(&beniSulaSes)) {
      speaker.FillBuffer();
    }

  } else {
    oled.putString("Toprak nemli");
    ledMatrix.drawLedMatrix(gulenSurat, 500);
  }

  delay(2000);
}
