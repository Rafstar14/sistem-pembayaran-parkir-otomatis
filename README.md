# 🅿️ Sistem Pembayaran Parkir Otomatis (C++)

Aplikasi konsol (Command Line Interface) berbasis bahasa **C++** untuk mengotomatisasi perhitungan biaya parkir kendaraan (Motor & Mobil) di pusat perbelanjaan. Program ini dirancang untuk mengurangi kesalahan perhitungan oleh petugas parkir, serta mendukung berbagai metode pembayaran dan keanggotaan.

---

## ✨ Fitur Utama & Ketentuan Sistem

1. **Tarif Berdasarkan Kendaraan & Durasi:**
   * **Motor:** Rp 3.000 (Jam pertama) + Rp 2.000/jam untuk jam berikutnya.
   * **Mobil:** Rp 5.000 (Jam pertama) + Rp 3.000/jam untuk jam berikutnya.
2. **Diskon Keanggotaan (Membership):**
   * **Member Gold:** Diskon 20%
   * **Member Silver:** Diskon 10%
   * **Non-Member:** Tanpa diskon (0%)
3. **Ketentuan & Biaya Tambahan:**
   * **Biaya Tambahan (>8 Jam):** Dikenakan tambahan tetap Rp 5.000 jika durasi parkir lebih dari 8 jam.
   * **Potongan Ekstra:** Jika total biaya setelah diskon mencapai minimal Rp 30.000, pelanggan mendapat potongan tambahan sebesar Rp 2.000.
   * **Validasi Negatif:** Total biaya akhir dijamin tidak bernilai negatif.
4. **Metode Pembayaran & Validasi:**
   * **Tunai (Cash):** Sistem otomatis menghitung uang kembalian. Jika uang pembayaran kurang dari total tagihan, transaksi otomatis dinyatakan gagal.
   * **QRIS:** Pembayaran digital langsung dinyatakan lunas.
5. **Format Angka Rupiah:** Menggunakan pemisah ribuan otomatis standar Indonesia (contoh: `Rp 38.000`) menggunakan pustaka `<locale>` bawaan C++.

---

## 🛠️ Implementasi 5 Fungsi Wajib

Sesuai dengan spesifikasi studi kasus, program ini menggunakan 5 fungsi utama:

| No. | Nama Fungsi | Tugas / Deskripsi |
| :--- | :--- | :--- |
| 1 | `hitungTarifParkir()` | Menghitung tarif dasar berdasarkan jenis kendaraan dan durasi. |
| 2 | `hitungDiskon()` | Menghitung besaran diskon berdasarkan status keanggotaan. |
| 3 | `hitungBiayaTambahan()` | Menghitung biaya ekstra jika durasi parkir melebihi 8 jam. |
| 4 | `hitungTotalBayar()` | Mengakumulasi tarif, diskon, biaya tambahan, potongan ekstra, dan validasi akhir. |
| 5 | `tampilkanStruk()` | Mencetak rincian struk transaksi ke layar konsol secara rapi. |

---

## 🚀 Cara Orang Lain Menggunakan Kode Ini

Bagi pengguna atau dosen yang ingin menguji program ini, terdapat dua cara mudah:

### Cara A: Langsung Salin Kode (Tanpa Git)
1. Buat file baru di komputer menggunakan aplikasi C++ IDE (seperti Dev-C++, Code::Blocks, atau VS Code) dan beri nama `main.cpp`.
2. Buka file `main.cpp` di repositori GitHub ini, salin seluruh isi kodenya.
3. Tempel (*paste*) ke dalam file `main.cpp` di komputer Anda, lalu **Compile & Run**.

### Cara B: Menggunakan Terminal / Git Bash (Clone Repository)
1. Buka terminal atau Git Bash di komputer Anda, lalu jalankan perintah berikut:
   ```bash
   git clone [https://github.com/Rafstar14/sistem-pembayaran-parkir-otomatis.git](https://github.com/Rafstar14/sistem-pembayaran-parkir-otomatis.git)
   cd sistem-pembayaran-parkir-otomatis
