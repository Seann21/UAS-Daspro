           case 4: {
                string tujuan;
                int jumlah;
                bool tiketTersedia = false;

                cout << "Masukkan tujuan penerbangan: ";
                cin.ignore();
                getline(cin, tujuan);
					
                cout << "Masukkan jumlah tiket yang dipesan: ";
                cin >> jumlah;
				system("cls");
                for (int i = 0; i < jml; i++) {
                    if (tiket[i].tujuan == tujuan && tiket[i].status == "tersedia") {
                        tiketTersedia = true;
                        cout << "==========================================="<<endl;
                        cout << "       Pemesanan tiket Anda berhasil!      " << endl;
                        cout << "=========================================== " << endl;

                        cout << "---------------------------------" << endl;
                        cout << "Detail tiket yang sudah dipesan: " << endl;
                        cout << "--------------------------------- " << endl;
                        cout << "Maskapai: " << tiket[i].pesawat << endl;
                        cout << "Kelas: " << tiket[i].kelas << endl;
                        cout << "Tujuan: " << tiket[i].tujuan << endl;
                        cout << "Harga per tiket: " << tiket[i].harga << endl;
                        cout << "Jumlah tiket yang dipesan: " << jumlah << endl;
                        cout << "Total harga: " << tiket[i].harga * jumlah << endl;
                        break;
                    }
                }

                if (!tiketTersedia) {
                    cout << "Tiket tidak tersedia untuk tujuan tersebut." << endl;
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
