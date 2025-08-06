# Toprak Nem Ölçer & Görsel-Alarm Sistemi

Bu proje, toprak nemini ölçerek nem seviyesine göre görsel ve işitsel alarm veren bir sistemdir. Deneyap modülleri kullanılarak, toprak nemi algılanır; OLED ekranda mesaj gösterilir, LED matris üzerinde duygu ifadesi belirir ve hoparlör aracılığıyla alarm sesi çalınır.

---

## İçindekiler

- `toprak_nemi_gorsel_alarmi.ino` - Ana Arduino kodu
- `beni_sula.h` - Hoparlör için ses verisi dosyası
- Kütüphaneler: `Deneyap_ToprakNemiOlcer`, `Deneyap_OLED`, `Deneyap_5x7LedEkran`, `Deneyap_Hoparlor`

---

## Kullanılan Donanımlar

- **Deneyap Toprak Nem Sensörü** (I2C adres: 0x0F)
- **Deneyap OLED Ekran** (I2C adres: 0x7A)
- **Deneyap 5x7 LED Matris** (I2C adres: 0x0A)
- **Deneyap Hoparlör** (DAC1 pininde bağlı)
- Arduino Deneyap Kart veya uyumlu Arduino modeli

---

## Kütüphaneler

Aşağıdaki Deneyap kütüphaneleri kullanılmaktadır:

- `Deneyap_ToprakNemiOlcer`
- `Deneyap_OLED`
- `Deneyap_5x7LedEkran`
- `Deneyap_Hoparlor`

Bu kütüphaneleri Arduino IDE kütüphane yöneticisinden veya Deneyap sitesinden temin edebilirsiniz.

---

## Çalışma Mantığı

- Toprak nem sensörü I2C üzerinden nem değerini okur.
- Nem seviyesi `NEM_ESIGI` (900) eşik değerinden düşükse:
  - OLED ekranda **"Beni sula!"** mesajı gösterilir.
  - LED matris üzerinde mutsuz surat görüntülenir.
  - Hoparlör aracılığıyla uyarı sesi çalınır (beni_sula.h içindeki ses).
- Nem seviyesi eşik değerinin üzerindeyse:
  - OLED ekranda **"Toprak nemli"** mesajı gösterilir.
  - LED matris üzerinde gülen surat görüntülenir.
- Döngü her 2 saniyede bir tekrarlanır.

---

## Dosya Açıklamaları

### toprak_nemi_gorsel_alarmi.ino

Ana çalışma dosyasıdır. Donanımların başlatılması, sensör okuması, görsel ve işitsel geri bildirimlerin kontrolü burada yapılır.

### beni_sula.h

Hoparlörde çalınacak uyarı sesinin ham verilerini içeren header dosyasıdır. `Wav` formatında ses verisi içerir ve hoparlör sınıfı tarafından oynatılır.

---

## Bağlantılar

| Donanım          | Arduino Pin / I2C Adres |
|------------------|------------------------|
| Toprak Nem Sensörü| I2C (0x0F)             |
| OLED Ekran       | I2C (0x7A)             |
| 5x7 LED Matris   | I2C (0x0A)             |
| Hoparlör         | DAC1       |

---

## Kurulum ve Çalıştırma

1. Donanımları uygun pinlere ve I2C adreslerine bağlayın.
2. Arduino IDE'de gerekli Deneyap kütüphanelerini yükleyin.
3. Proje klasöründeki `beni_sula.h` dosyasını Arduino projesi içine dahil edin.
4. `toprak_nemi_gorsel_alarmi.ino` dosyasını açıp derleyin ve kartınıza yükleyin.
5. Seri monitörden sensör değerlerini izleyebilirsiniz.

---

## Sorun Giderme

- **Sensör veya ekran başlamıyor:** I2C adreslerinin doğru ve donanım bağlantılarının sağlam olduğundan emin olun.
- **Ses çıkmıyor:** Hoparlör bağlantısını ve DAC1 pinini kontrol edin.
- **LED Matris ışık vermiyor:** Kütüphane ve I2C adresi uyumluluğunu tekrar kontrol edin.



---
## 👩‍💻 Geliştirici

**Kevser ÜSTÜN**  
Giresun Üniversitesi – Bilgisayar Mühendisliği  
