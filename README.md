# IoT Remote AC dengan Web Interface Menggunakan ESP8266
Proyek ini bertujuan untuk merangkai sistem IoT yang memungkinkan pengguna mengontrol AC (Air Conditioner) secara remote melalui web interface. Sistem ini menggunakan modul ESP8266 yang terhubung dengan modul relay 1 channel untuk mengendalikan AC.

## Fitur Utama :
Kontrol AC melalui web interface yang dapat diakses dari perangkat apa pun yang terhubung ke jaringan WiFi yang sama.
Monitoring Status relay untuk memastikan apakah AC sedang aktif atau tidak.
Konfigurasi Sederhana untuk menghubungkan ESP8266 dengan jaringan WiFi yang ada.

## ESP8266 ke Relay 1 Channel:
1. VCC (Relay) → 3V (ESP8266)
2. IN1 (Relay) → D4 (ESP8266)
3. GND (Relay) → GND (ESP8266)

## Skema Rangkaian
![Skema](https://raw.githubusercontent.com/sagasitas-indonesia/iot-smart-ac/main/Skema%20Rangkaian.jpg)
   
## WiFi Configuration:
ESP8266 akan tersambung ke jaringan WiFi sesuai dengan pengaturan yang diinput oleh pengguna.
Ubah SSID dan Password WiFi pada code <b><i>smartAC_Local_ESP8266_V1.ino</i></b>

# Langkah-Langkah Instalasi
## Persiapan Hardware:
- Siapkan ESP8266 dan modul relay 1 channel.
- Hubungkan pin sesuai dengan skema koneksi di atas.

## Persiapan Software:
- Install driver Arduino
- Unduh dan instal Arduino IDE. <a>https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.2_Windows_64bit.exe</a>
- Install ESP8266 di Arduino IDE : <a>http://arduino.esp8266.com/stable/package_esp8266com_index.json</a>
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


# IoT Remote AC dengan Blynk App Menggunakan ESP8266
## Fitur Utama :
Kontrol AC melalui Aplikasi <b>Blynk</b> yang dapat diakses dari perangkat apa pun dan di manapun melalui internet.
Monitoring Status relay untuk memastikan apakah AC sedang aktif atau tidak.
Konfigurasi Sederhana untuk menghubungkan ESP8266 dengan jaringan WiFi yang ada.

## ESP8266 ke Relay 1 Channel:
1. VCC (Relay) → 3V (ESP8266)
2. IN1 (Relay) → D1 (ESP8266)
3. GND (Relay) → GND (ESP8266)
   
## WiFi Configuration:
ESP8266 akan tersambung ke jaringan WiFi sesuai dengan pengaturan yang diinput oleh pengguna.
Ubah SSID dan Password WiFi pada code <b><i>smartAC_Blynk_ESP8266_V1.ino</i></b>

# Setup Aplikasi Blynk
## Buat Akun Blynk
- Buka Blynk Console di browser Anda.
- Daftar atau login menggunakan akun Anda.

## Buat Template Baru:
- Klik "Templates" di sidebar kiri.
- Klik "New Template".
- Isi informasi sebagai berikut:
- Template Name: Berikan nama template (misalnya, "Relay Control").
- Hardware: Pilih ESP8266.
- Connection Type: Pilih WiFi.
- Klik Create.
- Catat Template ID dan Auth Token:

Setelah template dibuat, catat Template ID, Template Name, dan Auth Token.
Gunakan informasi ini di kode Arduino yang sudah kita buat sebelumnya.

## Tambahkan Data Stream
Tambahkan Data Stream untuk Relay:
- Di dalam template yang baru saja Anda buat, klik "Datastreams".
- Klik "New Datastream" dan pilih Virtual Pin.
- Isi konfigurasi sebagai berikut:
- Name: Berikan nama (misalnya, "Relay Control").
- Pin: Pilih V1 (sesuai dengan kode).
- Type: Pilih Integer.
- Min Value: 0.
- Max Value: 1.
- Klik Create.
  
## Buat Perangkat (Device)
- Klik "Devices" di sidebar kiri.
- Klik "New Device", lalu pilih From Template.
- Pilih template yang telah Anda buat tadi dan beri nama perangkat Anda.
- Setelah perangkat dibuat, klik perangkat tersebut untuk mendapatkan Auth Token. Anda juga bisa mengedit detail perangkat.
  
## Konfigurasi di Aplikasi Blynk (Mobile App)
### Buka Aplikasi Blynk:
- Login dengan akun yang sama dengan Blynk Console.
### Tambahkan Perangkat:
- Tambahkan perangkat menggunakan template yang sudah Anda buat.
### Tambahkan Widget Tombol:
- Tambahkan widget tombol ke dashboard aplikasi.
- Pilih perangkat yang sudah dibuat.
- Pilih Datastream yang terhubung dengan Virtual Pin V1.
### Konfigurasi Tombol:
Konfigurasikan tombol untuk mode Switch atau Push (sesuai kebutuhan).

## Referensi :
YouTube : <a>https://www.youtube.com/watch?v=M39fPIH6440</a>
