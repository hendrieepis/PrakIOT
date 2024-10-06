# Change default platformIO:
- get project folder: pio settings get projects_dir
- change project Folder: pio settings set projects_dir "New Directory"
# Perbandingan ESP32 ESP32-S3, ESP32-C3 dan ESP32-C6 
# ESP32 Family Comparison
Perbandingan spesifikasi antara varian ESP32 yang populer digunakan.

| Feature | ESP32 | ESP32-S3 | ESP32-C6 | ESP32-C3 |
|---------|-------|----------|----------|----------|
| **CPU** | Dual-core Xtensa LX6 (240 MHz) | Dual-core Xtensa LX7 (240 MHz) | Single-core RISC-V (160 MHz) | Single-core RISC-V (160 MHz) |
| **Architecture** | 32-bit | 32-bit | 32-bit RISC-V | 32-bit RISC-V |
| **Flash Memory** | Up to 16 MB | Up to 16 MB | Up to 4 MB | Up to 4 MB |
| **SRAM** | 520 KB | 512 KB | 400 KB | 400 KB |
| **GPIO Pins** | 34 | 45 | 22 | 22 |
| **ADC** | 18 channels (2×SAR ADC)<br>12-bit resolution | 20 channels (2×SAR ADC)<br>12-bit resolution | 8 channels (1×SAR ADC)<br>12-bit resolution | 6 channels (1×SAR ADC)<br>12-bit resolution |
| **DAC** | 2 channels (8-bit) | 2 channels (8-bit) | No | No |
| **Timers** | 4 | 4 | 4 | 3 |
| **PWM Channels** | 16 | 16 | 6 | 6 |
| **Hardware Interrupts** | 32 | 32 | 22 | 22 |
| **Communication Interfaces** |
| - I2C | 2 | 2 | 2 | 1 |
| - SPI | 4 (2 full + 2 slave) | 4 (2 full + 2 slave) | 2 (1 full + 1 slave) | 2 (1 full + 1 slave) |
| - UART | 3 | 3 | 2 | 2 |
| **Security** |
| - Crypto Acceleration | ✓ | ✓ | ✓ | ✓ |
| - Secure Boot | ✓ | ✓ | ✓ | ✓ |
| - Flash Encryption | ✓ | ✓ | ✓ | ✓ |
| **Wireless Connectivity** |
| - Wi-Fi | 802.11 b/g/n | 802.11 b/g/n | 802.11ax (Wi-Fi 6) | 802.11 b/g/n |
| - Bluetooth | Classic + BLE 4.2 | Classic + BLE 5.0 | BLE 5.3 | BLE 5.0 |
| **Special Features** |
| - Temperature Sensor | ✓ | - | - | - |
| - Hall Sensor | ✓ | - | - | - |
| - USB OTG | - | ✓ | - | - |
| - LCD Interface | ✓ | ✓ | - | - |
| - Camera Interface | ✓ | ✓ | - | - |

### Catatan Penting:
- ESP32 original memiliki fitur paling lengkap dengan sensor tambahan (Hall & Temperature)
- ESP32-S3 fokus pada peningkatan kinerja AI/ML dan interface USB OTG
- ESP32-C6 adalah satu-satunya yang mendukung Wi-Fi 6 (802.11ax)
- ESP32-C3 adalah versi ekonomis dengan RISC-V single-core

### Use Case Yang Disarankan:
- **ESP32**: Proyek kompleks yang membutuhkan banyak GPIO dan sensor
- **ESP32-S3**: Aplikasi AI/ML atau yang membutuhkan USB OTG
- **ESP32-C6**: Aplikasi yang membutuhkan Wi-Fi 6
- **ESP32-C3**: Proyek sederhana dengan budget terbatas

*Note: Spesifikasi dapat berubah tergantung pada revisi chip dan manufacturer. Selalu periksa datasheet terbaru untuk informasi yang paling akurat.*

# Tabel GPIO ESP32 DevkitC V4 (Wroom-32D)

| Pin GPIO | Fungsi Khusus | Input/Output | Normal/Inverted | Pull-Up/Pull-Down | Catatan |
|----------|---------------|--------------|-----------------|-------------------|---------|
| GPIO0 | Boot mode, strapping pin | Input | Normal | Available | Harus low saat booting, hindari penggunaan tanpa perencanaan matang |
| GPIO1 | UART0 TX | Output | Normal | Available | Digunakan untuk UART (TX) pada serial monitor, hindari jika pakai UART |
| GPIO2 | UART1 TX, ADC2_CH2, strapping pin | Output | Available | Available | Harus low saat booting, sering digunakan untuk flash mode |
| GPIO3 | UART0 RX | Input | Normal | Available | Digunakan untuk UART (RX) pada serial monitor, hindari jika pakai UART |
| GPIO4 | PWM, ADC2_CH0 | Kedua | Normal | Available | Aman digunakan |
| GPIO5 | PWM, DAC1, HSPI_CS0 | Output | Normal | Available | Digunakan untuk SPI (HSPI_CS0) |
| GPIO6 | Flash (SCK) | Tidak digunakan | Normal | Available | Jangan digunakan, pin flash memory |
| GPIO7 | Flash (SDO) | Tidak digunakan | Normal | Available | Jangan digunakan, pin flash memory |
| GPIO8 | Flash (SDI) | Tidak digunakan | Normal | Available | Jangan digunakan, pin flash memory |
| GPIO9 | Flash (SIO) | Input | Normal | Available | Jangan digunakan, pin flash memory |
| GPIO10 | Flash (WP) | Input | Normal | Available | Jangan digunakan, pin flash memory |
| GPIO11 | Flash (HD) | Input | Normal | Available | Jangan digunakan, pin flash memory |
| GPIO12 | Boot mode, ADC2_CH5, strapping pin | Input | Normal/Inverted | Available | Terkait boot mode, hindari penggunaan tanpa perencanaan matang |
| GPIO13 | PWM, ADC2_CH4 | Kedua | Normal | Available | Aman digunakan |
| GPIO14 | PWM, ADC2_CH6, HSPI_CLK | Kedua | Normal | Available | Digunakan untuk SPI |
| GPIO15 | PWM, ADC2_CH3, HSPI_CS0 | Kedua | Normal | Available | Aman digunakan |
| GPIO16 | PWM, GPIO | Kedua | Normal | Available | Aman digunakan |
| GPIO17 | PWM, GPIO | Kedua | Normal | Available | Aman digunakan |
| GPIO18 | PWM, SPI_CLK (VSPI) | Kedua | Normal | Available | Digunakan untuk SPI, aman digunakan |
| GPIO19 | PWM, SPI_MISO (VSPI) | Kedua | Normal | Available | Digunakan untuk SPI, aman digunakan |
| GPIO21 | I2C SDA, PWM | Kedua | Normal | Available | Digunakan untuk I2C |
| GPIO22 | I2C SCL, PWM | Kedua | Normal | Available | Digunakan untuk I2C |
| GPIO23 | PWM, SPI_MOSI (VSPI) | Output | Normal | Available | Digunakan untuk SPI |
| GPIO25 | PWM, DAC2, ADC2_CH8 | Kedua | Normal | Available | Aman digunakan |
| GPIO26 | PWM, DAC1, ADC2_CH9 | Kedua | Normal | Available | Aman digunakan |
| GPIO27 | PWM, ADC2_CH7 | Kedua | Normal | Available | Aman digunakan |
| GPIO32 | ADC1_CH4, PWM, Touch0 | Kedua | Normal | Available | Touch sensor, aman digunakan |
| GPIO33 | ADC1_CH5, PWM, Touch1 | Kedua | Normal | Available | Touch sensor, aman digunakan |
| GPIO34 | ADC1_CH6 | Input | Normal | Not Available | Hanya input, tidak ada fungsi pull-up/pull-down |
| GPIO35 | ADC1_CH7 | Input | Normal | Not Available | Hanya input, tidak ada fungsi pull-up/pull-down |
| GPIO36 | ADC1_CH0 | Input | Normal | Not Available | Hanya input, tidak ada fungsi pull-up/pull-down |
| GPIO39 | ADC1_CH3 | Input | Normal | Not Available | Hanya input, tidak ada fungsi pull-up/pull-down |

## Pin yang Harus Dihindari (Digunakan untuk Boot/Flash)

| Pin GPIO | Catatan |
|----------|---------|
| GPIO0 | Strapping pin, harus low saat boot |
| GPIO2 | Strapping pin, sering digunakan untuk flash mode |
| GPIO12 | Strapping pin, harus diatur dengan benar saat boot |
| GPIO6 | Digunakan untuk flash (SCK) |
| GPIO7 | Digunakan untuk flash (SDO) |
| GPIO8 | Digunakan untuk flash (SDI) |
| GPIO9 | Digunakan untuk flash (SIO) |
| GPIO10 | Digunakan untuk flash (WP) |
| GPIO11 | Digunakan untuk flash (HD) |

# IO Map Shield pada board ESP32 devkitC V4

| Component | GPIO | I/O Type | Logic | Pull-Up/Down | Notes |
|-----------|------|----------|-------|--------------|--------|
| **Digital Outputs** |
| Relay 1 | GPIO16 | Output | Normal | Available | - Adjacent to GPIO16<br>- Suitable for relay control |
| Relay 2 | GPIO17 | Output | Normal | Available | - Adjacent to GPIO17<br>- Suitable for relay control |
| LED 1 | GPIO14 | Output | Normal | Available | -  |
| LED R | GPIO27 | Output | Normal | Available | -  |
| LED G | GPIO26 | Output | Normal | Available | - Also supports DAC functionality |
| LED B | GPIO25 | Output | Normal | Available | - Also supports DAC functionality |
| Buzzer | GPIO2 | Output | Normal | Available | -  PWM capable |
| **Analog Inputs** |
| Photo Resistor | GPIO34 | Input | Normal | Not Available | - Input only (ADC1_6)<br>- No pull-up/down |
| Potensio 1 | GPIO33 | Input | Normal | Available | - ADC1_5<br>- Adjacent to Potensio 1 |
| Potensio 2 | GPIO32 | Input | Normal | Available | - ADC1_4<br>- Analog input capable |
| **Digital Inputs** |
| Button 1 | GPIO35 | Input | Normal | Not Available | - Input only<br>- Use external pull-up |
| Button 2 | GPIO0 | Input | Normal | Available | - Boot pin*<br>- Use internal pull-up |
| Button 3 | GPIO15 | Input | Normal | Available | - Use internal pull-up <br> |
| Button 4 | GPIO13 | Input | Normal | Available | - Use internal pull-up |
| PIR Sensor | GPIO4 | Input | Normal | Available | - Use internal pull-up |
| **One Wire** |
| DHT22 | GPIO12 | INPUT | Normal | Available | - adafruit/DHT sensor <br> - adafruit/Adafruit Unified <br> - Use external pull-up (4.7kΩ)|
| **I2C Interface** |
| OLED SCL | GPIO22 | Output | Normal | Available | - Default I2C SCL<br>- Use external pull-up (4.7kΩ) |
| OLED SDA | GPIO21 | Output | Normal | Available | - Default I2C SDA<br>- Use external pull-up (4.7kΩ) |
| **SPI Interface** |
| IMU CLK | GPIO18 | Output | Normal | Available | - Default VSPI SCK |
| IMU MISO | GPIO19 | Input | Normal | Available | - Default VSPI MISO |
| IMU MOSI | GPIO23 | Output | Normal | Available | - Default VSPI MOSI |
| IMU CS | GPIO5 | Output | Normal | Available | - Default VSPI CS |

## Important Notes

### Keamanan
- Semua digital IO beroperasi pada 3.3V
- Maximim Arus perpin: 40mA
- Maximum arus total ESP32: 200mA
- Jangan pernah menghubungkan LED langsung tanpa resistor
- Recommended LED series resistor: 330Ω

### Pin Yang Dihindari
   - GPIO 0, 2, 12 (Boot pins)
   - GPIO 6-11 (Flash memory)
   - GPIO 1, 3 (UART0 default console)

### Input-Only Pins
   - GPIO34-39 are input-only
   - No internal pull-up/down resistors

### For Analog Inputs
   - ADC1 (GPIO 32-39): Bisa digunakan saat WiFi aktif
   - ADC2 (GPIO 4,0,2,15,13,12,14,27,25,26): Tidak bisa digunakan saat WiFi aktif

### I2C Configuration
   - External pull-up resistors (4.7kΩ) required
   - Standard speed: 100kHz
   - Fast speed: 400kHz

### SPI Configuration
   - Maximum speed: 80MHz
   - Default VSPI pins used

###  Rekomendasi praktis
1. **Push Button**:
   - Gunakan internal pullup apabila memungkinkan
   - Gunakan External pull-up (10kΩ) untuk input saja
   - Gunakan resistor series untuk LED (330Ω - 1kΩ)
   - Gunakan pull-up resistor 4.7kΩ untuk I2C
 
2. **LED**:
   - Gunakan resistor pembatas arus
   - Gunakan PWM untuk mengontrol LED

3. **Relay**:
   - Gunakan Driver Relay yang mempunya FLyback dioda untuk menghindarai kerusakan

4. **DHT22**:
   - interface DHT22, gunakan pull-up resistor sekitar 4.7kΩ. 
   <br>Pull-up resistor diperlukan untuk memastikan jalur data berada dalam kondisi logika yang benar saat tidak ada perangkat yang sedang menariknya ke bawah.


# Spesifikasi Arus LED

## Standard LEDs (5mm/3mm)

| Warna LED | Forward Current (If) | Forward Voltage (Vf) | Brightness Typical | Recommended Current |
|-----------|---------------------|---------------------|-------------------|-------------------|
| Merah | 20mA | 1.8-2.2V | 2-3 cd | 16-18mA |
| Hijau | 20mA | 2.0-2.2V | 4-5 cd | 16-18mA |
| Biru | 20mA | 3.0-3.2V | 4-5 cd | 16-18mA |
| Kuning | 20mA | 2.0-2.2V | 2-3 cd | 16-18mA |
| Putih | 20mA | 3.0-3.2V | 5-6 cd | 16-18mA |
| UV | 20mA | 3.2-3.4V | - | 15-18mA |

## Perhitungan Resistor untuk LED
Untuk ESP32 (VCC = 3.3V), gunakan rumus:
```
R = (VCC - Vf) / If

Dimana:
- R = Resistor yang dibutuhkan (Ω)
- VCC = Tegangan sumber (3.3V untuk ESP32)
- Vf = Forward voltage LED
- If = Forward current yang diinginkan
```

### Contoh Perhitungan:
1. **LED Merah (Vf = 2.0V, If = 16mA)**:
   - R = (3.3V - 2.0V) / 0.016A
   - R = 81.25Ω
   - Gunakan resistor 82Ω standar

2. **LED Biru/Putih (Vf = 3.0V, If = 16mA)**:
   - R = (3.3V - 3.0V) / 0.016A
   - R = 18.75Ω
   - Gunakan resistor 20Ω standar

## Catatan Penting LED
1. **Tips Penggunaan**:
   - Gunakan arus lebih rendah (10-15mA) untuk umur LED lebih panjang
   - Untuk brightness tinggi, pertimbangkan LED high-brightness khusus
   - Untuk mengontrol brightness, gunakan PWM

2. **Kondisi Operasi**:
   - Temperatur operasi: -25°C sampai +85°C
   - Humidity: 85% RH max
   - Lifetime: 50,000-100,000 jam (pada arus nominal)

3. **Troubleshooting**:
   - LED redup: Cek nilai resistor atau arus terlalu rendah
   - LED cepat panas: Arus terlalu tinggi
   - LED tidak menyala: Cek polaritas atau resistor putus


# Panduan Penggunaan GPIO 0 ESP32

## Karakteristik GPIO 0
- Merupakan **strapping pin** (boot pin)
- Menentukan mode boot saat startup/reset
- Mendukung input dan output
- Memiliki internal pull-up

## Mode Boot GPIO 0
| GPIO 0 State | Mode Boot |
|--------------|-----------|
| LOW (0V) | Download Mode (Flashing) |
| HIGH (3.3V) | Normal Boot Mode |

## Penggunaan Aman GPIO 0

### 1. Sebagai Input (Recommended)
```
Rekomendasi Konfigurasi:
✅ Menggunakan internal pull-up
✅ Koneksi button ke ground (active-low)
❌ Hindari external pull-up
❌ Hindari active-high configuration
```

**Contoh Kode yang Aman:**
```cpp
// Konfigurasi yang aman untuk GPIO 0 sebagai input
void setup() {
  // Menggunakan internal pull-up
  pinMode(0, INPUT_PULLUP);
}

void loop() {
  // Membaca state GPIO 0
  if (digitalRead(0) == LOW) {
    // Button ditekan
    // Tambahkan debounce delay
    delay(50);
    // Proses
  }
}
```

### 2. Sebagai Output (Not Recommended)
```
⚠️ Tidak disarankan, tapi jika terpaksa:
- Pastikan tidak menggunakan output LOW saat startup/reset
- Gunakan resistor pembatas arus
- Hindari beban induktif
```

**Contoh Kode (Jika Terpaksa):**
```cpp
// Konfigurasi GPIO 0 sebagai output (tidak disarankan)
void setup() {
  // Tunggu sistem stabil
  delay(1000);
  pinMode(0, OUTPUT);
  // Set HIGH dulu untuk amannya
  digitalWrite(0, HIGH);
}
```

## Skematik yang Aman
```
1. Konfigurasi Input (Recommended):

3.3V ──┐
       │
       └── [Internal Pull-up dalam ESP32]
           │
GPIO 0 ────┤
           │
           ├── [Push Button]
           │
GND   ────┘

2. Konfigurasi Output (Not Recommended):

GPIO 0 ────[330Ω Resistor]────[LED]────GND
```

## Hal yang Harus Dihindari
1. ❌ **Jangan gunakan external pull-up resistor**
   - Bisa konflik dengan internal pull-up
   - Dapat mengganggu proses boot

2. ❌ **Jangan hubungkan langsung ke VCC**
   - Bisa mencegah masuk mode download

3. ❌ **Jangan gunakan untuk:**
   - Relay control
   - Motor control
   - High-current loads
   - Critical timing applications

4. ❌ **Jangan set LOW saat startup**
   - Akan memaksa masuk download mode

## Best Practices
1. ✅ **Selalu gunakan internal pull-up**
   ```cpp
   pinMode(0, INPUT_PULLUP);
   ```

2. ✅ **Implementasikan debounce untuk button**
   ```cpp
   // Contoh simple debounce
   if (digitalRead(0) == LOW) {
     delay(50);  // debounce delay
     if (digitalRead(0) == LOW) {
       // Proses
     }
   }
   ```

3. ✅ **Gunakan pin lain jika memungkinkan**
   - GPIO 4, 5, 13, 14, 15 lebih aman untuk general purpose

4. ✅ **Dokumentasikan penggunaan**
   ```cpp
   // GPIO 0 digunakan sebagai input button
   // Perhatian: Pin ini adalah boot pin
   // Gunakan internal pull-up dan active-low
   #define BUTTON_PIN 0
   ```

## Troubleshooting
| Masalah | Kemungkinan Penyebab | Solusi |
|---------|---------------------|---------|
| Tidak bisa upload program | GPIO 0 terkunci HIGH | Tekan boot button saat upload |
| ESP32 selalu boot ke download mode | GPIO 0 terkunci LOW | Cek rangkaian, pastikan pull-up aktif |
| Behavior tidak konsisten | Noise pada GPIO 0 | Tambah kapasitor 100nF ke GND |

*Note: Jika memungkinkan, lebih baik menggunakan GPIO lain yang tidak terkait dengan proses boot untuk menghindari masalah potensial.*


## Konfigurasi Mosquitto:
default konfigurasi mosquitto tidak mengijinkan koneksi selain dari localhost, agar bisa menghubungkan dengan ip external langkah yang harus dilakukkan:
1. Edit Lokasi file konfigurasi Mosquitto biasanya berada di /etc/mosquitto/mosquitto.conf atau /etc/mosquitto/conf.d/default.conf. gunakan perintah berikut:
```bash
sudo nano /etc/mosquitto/mosquitto.conf
```

2. Cari atau tambahkan baris berikut untuk mengonfigurasi Mosquitto agar mendengarkan pada semua antarmuka jaringan:
```yaml
listener 1883
allow_anonymous true
```
3.  Pastikan listener 1883 tidak terbatas hanya untuk localhost. hapus jika  ada baris seperti ini:
```yaml
bind_address 127.0.0.1
```
4. Restart Mosquitto:
```bash
sudo systemctl restart mosquitto
```

# Screen Android di desktop Linux
Untuk menampilkan Layar smartphone android di Linux Desktop langkhnya
1. sudo apt install scrcpy
2. Aktifkan USB Debugging di Android:
- Buka Settings → About phone.
- Tap Build number sebanyak 7 kali untuk mengaktifkan Developer options.
- Kembali ke Settings dan cari Developer options.
- Aktifkan USB Debugging.
3. lebih jelas lihat gambar ini:
Berikut adalah gambar Android:
![Android Picture](https://github.com/hendrieepis/PrakIOT/raw/main/picture/01-android.png)
## Hubungkan Android ke PC dengan USB:
- Gunakan kabel USB dan sambungkan ponsel ke komputer Ubuntu.
- Jika diminta, izinkan akses debugging USB di perangkat Android (biasanya akan muncul pop-up yang harus kamu setujui).
- Jalankan scrcpy
```bash
scrcpy
```
## Hubungkan Android ke PC dengan wifi:
untuk menampilkan layar android ke PC pada jaringan yang sama  lakukan perintah ini
1. pastikan opsi ADB wireless debugging diaktifkan dulu
Berikut adalah gambar Android:
![Android Picture](https://github.com/hendrieepis/PrakIOT/blob/main/picture/02-android-adb-wireless.png)
2. lakukan perintah berikut
```bash
adb tcpip 5555
adb connect <IP-Address-Android>:5555
scrcpy
```
Ganti <IP-Address-Android> dengan alamat IP ponselmu (yang bisa ditemukan di Wi-Fi settings di Android).