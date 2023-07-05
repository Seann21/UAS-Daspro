#include <iostream>

using namespace std;
struct Data{
	string tujuan;
	int harga;
	string status;
	string kelas;
	string pesawat;
	
};
void tampilanawal(){
	cout<<"======================================="<<endl
		<<"               TRAVELAIR               "<<endl
		<<"======================================="<<endl
		<<"1. Tiket List"<<endl
		<<"pilih menu : ";
}

void Tiket(Data temp[], int jml) {
    cout << "Tiket yang Tersedia" <<endl;
    for (int i = 0; i < jml; i++) {
       if (temp[i].status == "tersedia"){
            cout<<"Maskapai : "<<temp[i].pesawat<<endl;
            cout<<"Kelas : "<<temp[i].kelas<<endl;
            cout<<"Tujuan : "<<temp[i].tujuan<<endl;
            cout<<"Status : "<<temp[i].status<<endl;
            cout<<"Harga : "<<temp[i].harga<<endl;  
      }cout<<endl;
    }
}
int main(){
	int pilih;
	char ulang;
	const int jml = 5;
    Data tiket[jml] = {
        {"Jakarta - Surabaya", 100000, "tersedia", "Ekonomi", "ATR"},
        {"Surabaya - kalimantan", 150000, "tersedia", "Ekslusive", "AIRLANGGA"},
        {"Kalimantan - Bandung", 120000, "tersedia", "Ekonomi", "LION AIR"},
        {"Medan - Yogyakarta", 80000, "tersedia", "Ekonomi", "AIRBUS"},
        {"Makasar - Bali", 200000, "tersedia", "Ekonomi", "BOEING"}
    };
    
    //
   do{	
   		system("cls");
    	tampilanawal();
    	cin>>pilih;
    	switch(pilih){
    		case 1:
    			system("cls");
    			Tiket(tiket, jml);
    			cout<<"home y/n : ";
    			cin>>ulang;
    		break;
		}
	}while(ulang == 'y');
   
    
	return 0;
}
