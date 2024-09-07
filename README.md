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
Langkah-Langkah Instalasi

## Persiapan Hardware:
- Siapkan ESP8266 dan modul relay 1 channel.
- Hubungkan pin sesuai dengan skema koneksi di atas.

## Persiapan Software:
Unduh dan instal Arduino IDE.
Instal library <b>ESP8266WiFi</b> dan <b>ESPAsyncWebServer</b> melalui Arduino Library Manager.

## Upload Sketch ke ESP8266:
Gunakan kode berikut untuk menghubungkan ESP8266 ke jaringan WiFi dan menampilkan alamat IP:
