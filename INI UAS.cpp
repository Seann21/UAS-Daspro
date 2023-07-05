#include <iostream>

using namespace std;
int i,j;
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
		<<"2. Data urut Terendah - Tertinggi"<<endl
		<<"3. Tiket Yang Tersedia"<<endl
		<<"4. Total Harga"<<endl
		<<"pilih menu : ";
}
void Tiket(Data temp[], int jml) {
    cout << "Tiket yang Tersedia" <<endl;
    for (i = 0; i < jml; i++) {
       if (temp[i].status == "tersedia"){
            cout<<"Maskapai : "<<temp[i].pesawat<<endl;
            cout<<"Kelas : "<<temp[i].kelas<<endl;
            cout<<"Tujuan : "<<temp[i].tujuan<<endl;
            cout<<"Status : "<<temp[i].status<<endl;
            cout<<"Harga : "<<temp[i].harga<<endl;  
      }cout<<endl;
    }
}
void SeluruhData(Data temp[], int jml){
	cout<<"Urutan tiket dari terendah - tertinggi"<<endl;
	for (i = 0; i < jml; i++) {
		cout<<"Maskapai : "<<temp[i].pesawat<<endl;
        cout<<"Kelas : "<<temp[i].kelas<<endl;
        cout<<"Tujuan : "<<temp[i].tujuan<<endl;
        cout<<"Status : "<<temp[i].status<<endl;
        cout<<"Harga : "<<temp[i].harga<<endl;  
	}
}
void DataUrut(Data tiket[], int jml){
	int i,j;
 	i = jml-1;
 	do{
 		for(j=0;j<i;j++){
 			if(tiket[j+1].harga < tiket[j].harga)
 				swap(tiket[j+1],tiket[j]);
			}
 	i--;
 	}while(i>0);
}
void swap(int &a, int &b){
	int tmp;
 	tmp = a;
 	a = b;
 	b = tmp;
}

int main(){
	int pilih;
	char ulang;
	const int jml = 10;
    Data tiket[jml] = {
        {"Jakarta - Surabaya", 100000, "tersedia", "Ekonomi", "ATR"},
        {"Surabaya - Semarang", 150000, "tersedia", "Ekslusive", "AIRLANGGA"},
        {"solo - Bandung", 120000, "tersedia", "Ekonomi", "LION AIR"},
        {"Medan - Yogyakarta", 80000, "tersedia", "Ekonomi", "AIRBUS"},
        {"Makasar - Bali", 200000, "tersedia", "Ekonomi", "BOEING"},
        {"Kediri - Yogyakarta", 150000, "tersedia", "Ekonomi", "AIRLANGGA"}
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
    		case 2:
    			system("cls");
    			DataUrut(tiket, jml);
    			Tiket(tiket, jml);
    		break;
		}
	}while(ulang == 'y');
   
    
	return 0;
}
