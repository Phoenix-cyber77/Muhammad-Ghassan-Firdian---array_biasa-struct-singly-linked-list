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

struct ElmMahasiswa {
    Mahasiswa info;
    ElmMahasiswa* next;
};

struct List {
    ElmMahasiswa* first;
};

void createList(List &L) {
    L.first = nullptr;
}

ElmMahasiswa* createElm(Mahasiswa x) {
    ElmMahasiswa* p = new ElmMahasiswa;
    p->info = x;
    p->next = nullptr;
    return p;
}

void insertLast(List &L, ElmMahasiswa* p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        ElmMahasiswa* q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

void tampilkanList(List L) {
    cout << "=== LIST MAHASISWA ===" << endl;
    ElmMahasiswa* p = L.first;
    int no = 0;
    while (p != nullptr) {
        no++;
        cout << no << " | " << p->info.nim << " | " << p->info.nama
             << " | " << p->info.persentaseKehadiran << "%" << endl;
        p = p->next;
    }
    cout << "Total Mahasiswa: " << no << endl;
}

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

    List L;
    createList(L);
    for (int i = 0; i < JUMLAH; i++) {
        insertLast(L, createElm(mahasiswa[i]));
    }
    tampilkanList(L);

    return 0;
}
