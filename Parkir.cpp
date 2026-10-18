#include <iostream>
#include <string>
#include <iomanip>
#include <locale>

using namespace std;

// Pengaturan bawaan C++ untuk otomatis memberi titik ribuan (Bukan Function)
struct TitikRibuan : numpunct<char>
{
    char do_thousands_sep() const { return '.'; }
    string do_grouping() const { return "\3"; }
};

// 1. Fungsi menghitung tarif dasar berdasarkan jenis kendaraan dan durasi
int hitungTarifParkir(int jenisKendaraan, int durasi)
{
    if (durasi <= 0)
        return 0;

    int tarifJamPertama = 0;
    int tarifJamBerikutnya = 0;

    if (jenisKendaraan == 1)
    { // Motor
        tarifJamPertama = 3000;
        tarifJamBerikutnya = 2000;
    }
    else if (jenisKendaraan == 2)
    { // Mobil
        tarifJamPertama = 5000;
        tarifJamBerikutnya = 3000;
    }

    if (durasi == 1)
    {
        return tarifJamPertama;
    }
    else
    {
        return tarifJamPertama + ((durasi - 1) * tarifJamBerikutnya);
    }
}

// 2. Fungsi menghitung diskon berdasarkan status keanggotaan
int hitungDiskon(int tarifDasar, int statusMember)
{
    if (statusMember == 1)
    { // Member Gold (20%)
        return tarifDasar * 20 / 100;
    }
    else if (statusMember == 2)
    { // Member Silver (10%)
        return tarifDasar * 10 / 100;
    }
    return 0; // Non-Member (0%)
}

// 3. Fungsi menghitung biaya tambahan jika parkir lebih dari 8 jam
int hitungBiayaTambahan(int durasi)
{
    if (durasi > 8)
    {
        return 5000;
    }
    return 0;
}

// 4. Fungsi menghitung total biaya akhir
int hitungTotalBayar(int tarifDasar, int diskon, int biayaTambahan, int &potonganTambahan)
{
    int biayaSetelahDiskon = tarifDasar - diskon;
    potonganTambahan = 0;

    // Jika total biaya setelah diskon minimal Rp 30.000, dapat potongan Rp 2.000
    if (biayaSetelahDiskon >= 30000)
    {
        potonganTambahan = 2000;
    }

    int totalAkhir = biayaSetelahDiskon + biayaTambahan - potonganTambahan;

    // Biaya akhir tidak boleh negatif
    if (totalAkhir < 0)
    {
        totalAkhir = 0;
    }

    return totalAkhir;
}

// 5. Fungsi menampilkan rincian struk transaksi
void tampilkanStruk(string namaKendaraan, int durasi, string namaMember,
                    int tarifDasar, int diskon, int biayaTambahan,
                    int potonganTambahan, int totalBayar,
                    string metodeBayar, int nominalBayar, int kembalian)
{
    cout << "\n========================================\n";
    cout << "          STRUK PARKIR OTOMATIS         \n";
    cout << "========================================\n";
    cout << left << setw(22) << "Jenis Kendaraan" << ": " << namaKendaraan << "\n";
    cout << left << setw(22) << "Durasi Parkir" << ": " << durasi << " jam\n";
    cout << left << setw(22) << "Status Keanggotaan" << ": " << namaMember << "\n";
    cout << "----------------------------------------\n";
    cout << left << setw(22) << "Tarif Dasar" << ": Rp " << tarifDasar << "\n";
    cout << left << setw(22) << "Diskon Member" << ": -Rp " << diskon << "\n";
    cout << left << setw(22) << "Biaya Tambahan (>8j)" << ": Rp " << biayaTambahan << "\n";
    cout << left << setw(22) << "Potongan Tambahan" << ": -Rp " << potonganTambahan << "\n";
    cout << "----------------------------------------\n";
    cout << left << setw(22) << "TOTAL BAYAR" << ": Rp " << totalBayar << "\n";
    cout << left << setw(22) << "Metode Pembayaran" << ": " << metodeBayar << "\n";

    if (metodeBayar == "Tunai")
    {
        cout << left << setw(22) << "Uang Diterima" << ": Rp " << nominalBayar << "\n";
        cout << left << setw(22) << "Uang Kembalian" << ": Rp " << kembalian << "\n";
    }
    else
    {
        cout << left << setw(22) << "Status QRIS" << ": Lunas (Rp " << totalBayar << ")\n";
    }
    cout << "========================================\n";
    cout << "   Terima Kasih Atas Kunjungan Anda!    \n";
    cout << "========================================\n";
}

int main()
{
    // Mengaktifkan format titik otomatis pada cout
    cout.imbue(locale(cout.getloc(), new TitikRibuan));

    int jenisKendaraan, durasi, statusMember, pilihMetode;
    int nominalBayar = 0, kembalian = 0, potonganTambahan = 0;

    cout << "=== SISTEM PEMBAYARAN PARKIR OTOMATIS ===\n";

    // Input Jenis Kendaraan
    cout << "Pilih Jenis Kendaraan:\n";
    cout << "1. Motor (Jam pertama Rp 3.000, berikutnya Rp 2.000/jam)\n";
    cout << "2. Mobil (Jam pertama Rp 5.000, berikutnya Rp 3.000/jam)\n";
    cout << "Masukkan pilihan (1/2): ";
    cin >> jenisKendaraan;

    if (jenisKendaraan != 1 && jenisKendaraan != 2)
    {
        cout << "Error: Jenis kendaraan tidak valid!\n";
        return 1;
    }

    // Input Durasi Parkir
    cout << "\nMasukkan durasi parkir (jam): ";
    cin >> durasi;

    if (durasi <= 0)
    {
        cout << "Error: Durasi parkir harus minimal 1 jam!\n";
        return 1;
    }

    // Input Status Keanggotaan
    cout << "\nPilih Status Keanggotaan:\n";
    cout << "1. Member Gold (Diskon 20%)\n";
    cout << "2. Member Silver (Diskon 10%)\n";
    cout << "3. Non-Member (Tanpa Diskon)\n";
    cout << "Masukkan pilihan (1/2/3): ";
    cin >> statusMember;

    if (statusMember < 1 || statusMember > 3)
    {
        cout << "Error: Status keanggotaan tidak valid!\n";
        return 1;
    }

    // Proses Perhitungan menggunakan Function
    int tarifDasar = hitungTarifParkir(jenisKendaraan, durasi);
    int diskon = hitungDiskon(tarifDasar, statusMember);
    int biayaTambahan = hitungBiayaTambahan(durasi);
    int totalBayar = hitungTotalBayar(tarifDasar, diskon, biayaTambahan, potonganTambahan);

    // Tampilkan ringkasan tagihan sebelum pembayaran
    cout << "\nTotal Tagihan Parkir Anda: Rp " << totalBayar << "\n";

    // Input Metode Pembayaran
    cout << "\nPilih Metode Pembayaran:\n";
    cout << "1. Tunai\n";
    cout << "2. QRIS\n";
    cout << "Masukkan pilihan (1/2): ";
    cin >> pilihMetode;

    string namaKendaraan = (jenisKendaraan == 1) ? "Motor" : "Mobil";
    string namaMember = (statusMember == 1) ? "Member Gold" : (statusMember == 2) ? "Member Silver"
                                                                                  : "Non-Member";
    string metodeBayar = "";

    if (pilihMetode == 1)
    {
        metodeBayar = "Tunai";
        cout << "Masukkan jumlah uang tunai (tanpa titik): Rp ";
        cin >> nominalBayar;

        // Validasi pembayaran tunai
        if (nominalBayar < totalBayar)
        {
            cout << "\n[TRANSAKSI GAGAL] Uang pembayaran kurang Rp " << (totalBayar - nominalBayar) << "!\n";
            return 0;
        }
        kembalian = nominalBayar - totalBayar;
    }
    else if (pilihMetode == 2)
    {
        metodeBayar = "QRIS";
        nominalBayar = totalBayar;
        kembalian = 0;
    }
    else
    {
        cout << "Error: Metode pembayaran tidak valid!\n";
        return 1;
    }

    // Cetak Struk
    tampilkanStruk(namaKendaraan, durasi, namaMember, tarifDasar, diskon,
                   biayaTambahan, potonganTambahan, totalBayar,
                   metodeBayar, nominalBayar, kembalian);

    return 0;
}