#include <iostream>
using namespace std;

struct Data {
    string tujuan;
    int harga;
    string status;
    string kelas;
    string pesawat;
};

void tampilanawal() {
    cout << "=======================================\n"
         << "               TRAVEL AIR               \n"
         << "=======================================\n"
         << "1. Tiket List\n"
         << "2. Data urut Terendah - Tertinggi\n"
         << "3. Tiket Yang Tersedia\n"
         << "4. Pesan Tiket\n"
         << "pilih menu: ";
}
//menampilkan seluruh data
void SeluruhData(Data temp[], int jml) {
    cout << "Tiket List\n";
    for (int i = 0; i < jml; i++) {
        cout << "Maskapai: " << temp[i].pesawat << endl;
        cout << "Kelas: " << temp[i].kelas << endl;
        cout << "Tujuan: " << temp[i].tujuan << endl;
        cout << "Status: " << temp[i].status << endl;
        cout << "Harga: " << temp[i].harga << endl << endl;
    }cout<<endl;
}
//menampilkan tiket dengan urut terendah ke tertinggi
void DataUrut(Data tiket[], int jml) {
    for (int i = 0; i < jml - 1; i++) {
        for (int j = 0; j < jml - i - 1; j++) {
            if (tiket[j + 1].harga < tiket[j].harga) {
                swap(tiket[j + 1], tiket[j]);
            }
        }
    }
}
//menukarkan 2 data struct
void swap(Data& a, Data& b) {
    Data tmp = a;
    a = b;
    b = tmp;
}

//menampilkan tiket yang tersedia
void Tiket(Data temp[], int jml) {
    cout << "Tiket yang Tersedia\n";
    for (int i = 0; i < jml; i++) {
        if (temp[i].status == "tersedia") {
            cout << "Maskapai: " << temp[i].pesawat << endl;
            cout << "Kelas: " << temp[i].kelas << endl;
            cout << "Tujuan: " << temp[i].tujuan << endl;
            cout << "Status: " << temp[i].status << endl;
            cout << "Harga: " << temp[i].harga << endl << endl;;
        }
    }
}

int main() {
    int pilih;
    char ulang;
    const int jml = 6;
    Data tiket[jml] = {
        {"Jakarta - Surabaya", 1200000, "tersedia", "Ekonomi", "CITILINK"},
        {"Surabaya - Semarang", 2500000, "tersedia", "Ekslusive", "GARUDA INDONESIA"},
        {"Solo - Bandung", 1400000, "tersedia", "Ekonomi", "LION AIR"},
        {"Medan - Yogyakarta", 2300000, "tersedia", "Ekslusive", "WINGS AIR"},
        {"Makassar - Bali", 2000000, "tersedia", "Ekonomi", "AIR ASIA"},
        {"Kediri - Yogyakarta", 1800000, "tersedia", "Ekonomi", "SRIWIJAYA AIR"}
    };

    do {
        system("cls");
        tampilanawal();
        cin >> pilih;
        switch (pilih) {
            case 1:
                system("cls");
                SeluruhData(tiket, jml);
                break;
            case 2:
                system("cls");
                DataUrut(tiket, jml);
                SeluruhData(tiket, jml);
                break;
            case 3:
            	system("cls");
                Tiket(tiket, jml);
                break;               
		}
        cout << "Apakah Anda ingin melanjutkan (y/n)? ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
