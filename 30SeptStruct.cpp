#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float percentageAbsen;
};

int main() {
    Mahasiswa mahasiswa[40];

    for (int i = 0; i < 40; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;

        cout << "Nama Mahasiswa : ";
        cin >> mahasiswa[i].nama;

        cout << "NIM Mahasiswa : ";
        cin >> mahasiswa[i].nim;

        cout << "Percentage Absen Mahasiswa : ";
        cin >> mahasiswa[i].percentageAbsen;
    }

    cout << "\n Data Semua Mahasiswa \n";

    for (int i = 0; i < 40; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : " << mahasiswa[i].nama << endl;
        cout << "NIM : " << mahasiswa[i].nim << endl;
        cout << "Percentage Absen : "
             << mahasiswa[i].percentageAbsen << "%" << endl;
    }

    return 0;
}