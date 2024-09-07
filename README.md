# IoT Remote AC dengan Web Interface Menggunakan ESP8266
Proyek ini bertujuan untuk merangkai sistem IoT yang memungkinkan pengguna mengontrol AC (Air Conditioner) secara remote melalui web interface. Sistem ini menggunakan modul ESP8266 yang terhubung dengan modul relay 1 channel untuk mengendalikan AC.

## Fitur Utama :
Kontrol AC melalui web interface yang dapat diakses dari perangkat apa pun yang terhubung ke jaringan WiFi yang sama.
Monitoring Status relay untuk memastikan apakah AC sedang aktif atau tidak.
Konfigurasi Sederhana untuk menghubungkan ESP8266 dengan jaringan WiFi yang ada.
Skema Koneksi

## ESP8266 ke Relay 1 Channel:
1. VCC (Relay) → 3V (ESP8266)
2. IN1 (Relay) → D4 (ESP8266)
3. GND (Relay) → GND (ESP8266)
   
## WiFi Configuration:
ESP8266 akan tersambung ke jaringan WiFi sesuai dengan pengaturan yang diinput oleh pengguna.
Ubah SSID dan Password WiFi pada code <b><i>smartAC_Local_ESP8266_V1.ino</i></b>

# Langkah-Langkah Instalasi
## Persiapan Hardware:
- Siapkan ESP8266 dan modul relay 1 channel.
- Hubungkan pin sesuai dengan skema koneksi di atas.

## Persiapan Software:
- Unduh dan instal Arduino IDE. <a>https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.2_Windows_64bit.exe</a>
- Instal library <b>ESP8266WiFi</b> dan <b>ESPAsyncWebServer</b> melalui Arduino Library Manager.

## Upload Sketch ke ESP8266:
Gunakan kode <b><i>smartAC_Local_ESP8266_V1.ino.ino</i></b>

## Cek IP Address dari Serial Monitor:
- Buka Serial Monitor pada Arduino IDE dengan BAUD Rate 9600.
- Anda akan melihat pesan yang menunjukkan status koneksi WiFi dan alamat IP ESP8266.
### Web Interface
Setelah mengetahui IP Address dari ESP8266, masukkan alamat tersebut di browser untuk mengakses web interface dan mengontrol relay.

## Troubleshooting
- Jika ESP8266 tidak tersambung ke WiFi, pastikan SSID dan password WiFi sudah benar.
Periksa koneksi kabel antara ESP8266 dan relay.
