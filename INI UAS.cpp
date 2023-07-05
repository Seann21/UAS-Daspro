#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Struktur data untuk tiket pesawat
struct Tiket {
    string maskapai;
    string tujuan;
    int harga;
};

// Fungsi untuk menampilkan semua data tiket
void tampilkanDataTiket(const vector<Tiket>& tiketList) {
    cout << "Data Tiket Pesawat:\n";
    cout << "-------------------\n";
    for (const Tiket& tiket : tiketList) {
        cout << "Maskapai: " << tiket.maskapai << endl;
        cout << "Tujuan: " << tiket.tujuan << endl;
        cout << "Harga: " << tiket.harga << endl;
        cout << "-------------------\n";
    }
}

// Fungsi untuk menampilkan tiket berdasarkan urutan harga terendah-tertinggi
void tampilkanUrutanHarga(const vector<Tiket>& tiketList) {
    vector<Tiket> sortedList = tiketList;
    sort(sortedList.begin(), sortedList.end(), [](const Tiket& a, const Tiket& b) {
        return a.harga < b.harga;
    });

    cout << "Urutan Harga Tiket Pesawat:\n";
    cout << "---------------------------\n";
    for (const Tiket& tiket : sortedList) {
        cout << "Maskapai: " << tiket.maskapai << endl;
        cout << "Tujuan: " << tiket.tujuan << endl;
        cout << "Harga: " << tiket.harga << endl;
        cout << "---------------------------\n";
    }
}

// Fungsi untuk menampilkan tiket yang tersedia
void tampilkanTiketTersedia(const vector<Tiket>& tiketList) {
    cout << "Tiket Pesawat Tersedia:\n";
    cout << "-----------------------\n";
    for (const Tiket& tiket : tiketList) {
        cout << "Maskapai: " << tiket.maskapai << endl;
        cout << "Tujuan: " << tiket.tujuan << endl;
        cout << "-----------------------\n";
    }
}

// Fungsi untuk menghitung total harga sewa tiket
int hitungTotalHargaSewa(const vector<Tiket>& tiketList) {
    int totalHarga = 0;
    for (const Tiket& tiket : tiketList) {
        totalHarga += tiket.harga;
    }
    return totalHarga;
}

int main() {
    vector<Tiket> tiketList = {
        {"Garuda Indonesia", "Jakarta - Bali", 1000000},
        {"Lion Air", "Jakarta - Surabaya", 500000},
        {"AirAsia", "Jakarta - Yogyakarta", 300000},
        {"Citilink", "Jakarta - Bandung", 200000},
        {"Batik Air", "Jakarta - Medan", 800000}
    };

    int pilihan;
    do {
        cout << "\nProgram Penyewaan Tiket Pesawat\n";
        cout << "-------------------------------\n";
        cout << "1. Tampilkan Seluruh Data Tiket\n";
        cout << "2. Tampilkan Urutan Harga Tiket\n";
        cout << "3. Tampilkan Tiket Pesawat Tersedia\n";
        cout << "4. Hitung Total Harga Sewa Tiket\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanDataTiket(tiketList);
                break;
            case 2:
                tampilkanUrutanHarga(tiketList);
                break;
            case 3:
                tampilkanTiketTersedia(tiketList);
                break;
            case 4: {
                int totalHarga = hitungTotalHargaSewa(tiketList);
                cout << "Total Harga Sewa Tiket: " << totalHarga << endl;
                break;
            }
            case 0:
                cout << "Terima kasih. Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
