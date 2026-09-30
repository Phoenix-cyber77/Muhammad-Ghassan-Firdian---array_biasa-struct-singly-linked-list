#include <iostream>
#include <string>
using namespace std;

const int JUMLAH = 40;

string nim[JUMLAH];
string nama[JUMLAH];
float persentaseKehadiran[JUMLAH];

void inputData() {
    for (int i = 0; i < JUMLAH; i++) {
        cout << "NIM: ";
        cin >> nim[i];
        cin.ignore(1000, '\n');
        cout << "Nama: ";
        getline(cin, nama[i]);
        cout << "Persentase: ";
        cin >> persentaseKehadiran[i];
    }
}

void tampilkanData() {
    cout << "=== DAFTAR MAHASISWA ===" << endl;
    for (int i = 0; i < JUMLAH; i++) {
        cout << i + 1 << " | " << nim[i] << " | " << nama[i]
             << " | " << persentaseKehadiran[i] << "%" << endl;
    }
    cout << "Total Mahasiswa: " << JUMLAH << endl;
}

int cariNIM(string target) {
    for (int i = 0; i < JUMLAH; i++) {
        if (nim[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    inputData();
    tampilkanData();

    string target;
    cout << "Cari NIM: ";
    cin >> target;

    int idx = cariNIM(target);
    if (idx == -1) {
        cout << "NIM tidak ditemukan" << endl;
    } else {
        cout << idx + 1 << " | " << nim[idx] << " | " << nama[idx]
             << " | " << persentaseKehadiran[idx] << "%" << endl;
    }

    cout << "Update NIM: ";
    cin >> target;

    idx = cariNIM(target);
    if (idx == -1) {
        cout << "NIM tidak ditemukan" << endl;
    } else {
        float baru;
        cout << "Persentase baru: ";
        cin >> baru;

        cout << "Sebelum: " << persentaseKehadiran[idx] << "%" << endl;
        persentaseKehadiran[idx] = baru;
        cout << "Sesudah: " << persentaseKehadiran[idx] << "%" << endl;
    }

    tampilkanData();
    return 0;
}
