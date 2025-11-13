#include <bits/stdc++.h>
#include <fstream>
using namespace std;

string namaFile = "DataTahanan.txt";

struct Date{
    int tanggal;
    int bulan;
    int tahun;
};

struct Tahanan{
    string nama;
    string noTahanan;
    string tmptLahir;
    string kejahatan;
    Date masuk;
    Date keluar;
};

void menu(){
    cout << "==============================" <<
    endl << "1. Tambahkan Tahanan" <<
    endl << "2. Tampilkan sesuai urutan default" << 
    endl << "3. Tampilkan sesuai urutan masuk" << 
    endl << "4. Cari Tahanan" <<
    endl << "5. Delete data tahanan" <<
    endl << "6. Simpan dan keluar" << 
    endl << "==============================\n";
}

void input(Tahanan* list, int& jmlhTahanan){
    jmlhTahanan++;
    cin.ignore();
    cout << "Nama Tahanan\t: "; getline(cin, list[jmlhTahanan - 1].nama);
    cout << "No Tahanan\t: "; cin >> list[jmlhTahanan - 1].noTahanan;
    cout << "Tempat Lahir\t: "; cin >> list[jmlhTahanan - 1].tmptLahir;
    cout << "Kejahatan\t: "; cin >> list[jmlhTahanan - 1].kejahatan;
    cout << "Tanggal Masuk\t: "; cin >> list[jmlhTahanan - 1].masuk.tanggal 
         >> list[jmlhTahanan - 1].masuk.bulan >> list[jmlhTahanan - 1].masuk.tahun;
    cout << "Tanggal Keluar\t: "; cin >> list[jmlhTahanan - 1].keluar.tanggal 
         >> list[jmlhTahanan - 1].keluar.bulan >> list[jmlhTahanan - 1].keluar.tahun;
}

void hapus(Tahanan* list, int& jmlhTahanan){
    bool ketemu = false;
    string nHapus;
    cout << "No Tahanan yang ingin dihapus : "; cin >> nHapus;
    for (int i = 0; i < jmlhTahanan; i++){
        if (list[i].noTahanan == nHapus){
            ketemu = true;
            for (int j = i; j < jmlhTahanan - 1; j++){
                list[j] = list[j + 1];
            }
        }
        if (ketemu){
            jmlhTahanan--;
            break;
        } 
    }
    if (ketemu) cout << "Data tahanan tersebut telah dihapus!!\n";
    else cout << "Data tahanan tersebut tidak ditemukan!!\n";
}

int main(){
    int jmlhTahanan = 0;
    fstream file;
    Tahanan* list = new Tahanan[101];
    Tahanan* ptr = &list[0];
    file.open(namaFile);
    file >> jmlhTahanan;
    Tahanan* max = ptr + jmlhTahanan;
    for (ptr; ptr < max; ptr++){
        file >> ptr->nama >> ptr->noTahanan >> ptr->tmptLahir >> ptr->kejahatan 
        >> ptr->masuk.tanggal >> ptr->masuk.bulan >> ptr->masuk.tahun 
        >> ptr->keluar.tanggal >> ptr->keluar.bulan >> ptr->keluar.tahun;
    }
    file.close();

    while (true){
        int pilih;
        menu();
        cin >> pilih;
        switch (pilih){
            case 1 :
                input(list, jmlhTahanan);
                break;
            case 2 :

            case 3 :

            case 4 :

            case 5 :
                hapus(list, jmlhTahanan);
                break;
            case 6 :
                file.open(namaFile, ios::trunc);
                for (int i = 0; i < jmlhTahanan; i++){
                    file << list[i].nama <<
                    endl << list[i].noTahanan << " " << list[i].tmptLahir << " " << list[i].kejahatan << 
                    endl << list[i].masuk.tanggal << " " << list[i].masuk.bulan << " " << list[i].masuk.tahun <<
                    endl << list[i].keluar.tanggal << " " << list[i].keluar.bulan << " " << list[i].keluar.tahun << endl;
                }
                file.close();
                break;
            
        }
    }
    delete[] list;
    return 0;
}