#include <iostream>
#include <string>
using namespace std;

const int JUMLAH = 40;

struct Mahasiswa {
    string nim;
    string nama;
    float persentaseKehadiran;
};

Mahasiswa mahasiswa[JUMLAH];

void inputData() {
    for (int i = 0; i < JUMLAH; i++) {
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cin.ignore(1000, '\n');
        cout << "Nama: ";
        getline(cin, mahasiswa[i].nama);
        cout << "Persentase: ";
        cin >> mahasiswa[i].persentaseKehadiran;
    }
}

void tampilkanData() {
    cout << "=== DAFTAR MAHASISWA ===" << endl;
    for (int i = 0; i < JUMLAH; i++) {
        cout << i + 1 << " | " << mahasiswa[i].nim << " | "
             << mahasiswa[i].nama << " | "
             << mahasiswa[i].persentaseKehadiran << "%" << endl;
    }
    cout << "Total Mahasiswa: " << JUMLAH << endl;
}

int cariNIM(string target) {
    for (int i = 0; i < JUMLAH; i++) {
        if (mahasiswa[i].nim == target) {
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
        cout << idx + 1 << " | " << mahasiswa[idx].nim << " | "
             << mahasiswa[idx].nama << " | "
             << mahasiswa[idx].persentaseKehadiran << "%" << endl;
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

        cout << "Sebelum: " << mahasiswa[idx].persentaseKehadiran << "%" << endl;
        mahasiswa[idx].persentaseKehadiran = baru;
        cout << "Sesudah: " << mahasiswa[idx].persentaseKehadiran << "%" << endl;
    }

    tampilkanData();
    return 0;
}
