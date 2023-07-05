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
    string status;
    string kelas;
};

// Fungsi untuk menampilkan semua data tiket
void tampilkanDataTiket(const vector<Tiket>& tiketList) {
    cout << "Data Tiket Pesawat:\n";
    cout << "-------------------\n";
    for (const Tiket& tiket : tiketList) {
        cout << "Maskapai: " << tiket.maskapai << endl;
        cout << "Tujuan: " << tiket.tujuan << endl;
        cout << "Harga: " << tiket.harga << endl;
        cout << "Status: " << tiket.status << endl;
        cout << "Kelas: " << tiket.kelas << endl;
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
        cout << "Status: " << tiket.status << endl;
        cout << "Kelas: " << tiket.kelas << endl;
        cout << "---------------------------\n";
    }
}

// Fungsi untuk menampilkan tiket yang tersedia berdasarkan tujuan
void tampilkanTiketTersedia(const vector<Tiket>& tiketList, const string& tujuan) {
    cout << "Tiket Pesawat Tersedia untuk Tujuan " << tujuan << ":\n";
    cout << "--------------------------------------\n";
    bool tersedia = false;
    for (const Tiket& tiket : tiketList) {
        if (tiket.tujuan == tujuan && tiket.status == "Tersedia") {
            cout << "Maskapai: " << tiket.maskapai << endl;
            cout << "Harga: " << tiket.harga << endl;
            cout << "Kelas: " << tiket.kelas << endl;
            cout << "--------------------------------------\n";
            tersedia = true;
        }
    }
    if (!tersedia) {
        cout << "Tidak ada tiket tersedia untuk tujuan tersebut.\n";
    }
}

// Fungsi untuk menghitung total harga sewa tiket berdasarkan tujuan
int hitungTotalHargaSewa(const vector<Tiket>& tiketList, const string& tujuan, int jumlah) {
    int totalHarga = 0;
    for (const Tiket& tiket : tiketList) {
        if (tiket.tujuan == tujuan && tiket.status == "Tersedia") {
            totalHarga += tiket.harga * jumlah;
        }
    }
    return totalHarga;
}

int main() {
    vector<Tiket> tiketList = {
        {"Garuda Indonesia", "Jakarta - Bali", 1000000, "Tersedia", "Ekonomi"},
        {"Lion Air", "Jakarta - Surabaya", 500000, "Tersedia", "Ekonomi"},
        {"AirAsia", "Jakarta - Yogyakarta", 300000, "Tersedia", "Ekonomi"},
        {"Citilink", "Jakarta - Bandung", 200000, "Tidak Tersedia", "Ekonomi"},
        {"Batik Air", "Jakarta - Medan", 800000, "Tersedia", "Bisnis"}
    };

    int pilihan;
    do {
        cout << "\nProgram Penyewaan Tiket Pesawat\n";
        cout << "-------------------------------\n";
        cout << "1. Tampilkan Seluruh Data Tiket\n";
        cout << "2. Tampilkan Urutan Harga Tiket\n";
        cout << "3. Tampilkan Tiket Pesawat Tersedia\n";
        cout << "4. Pesan Tiket\n";
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
            case 3: {
                string tujuan;
                cout << "Masukkan tujuan: ";
                cin.ignore();
                getline(cin, tujuan);
                tampilkanTiketTersedia(tiketList, tujuan);
                break;
            }
            case 4: {
                string tujuan;
                int jumlah;
                cout << "Masukkan tujuan: ";
                cin.ignore();
                getline(cin, tujuan);
                cout << "Masukkan jumlah tiket yang ingin dipesan: ";
                cin >> jumlah;

                int totalHarga = hitungTotalHargaSewa(tiketList, tujuan, jumlah);
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
