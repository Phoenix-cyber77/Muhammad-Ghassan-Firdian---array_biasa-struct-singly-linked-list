#include <iostream>

using namespace std;

string nama[40];
string nim[40];
float percentageAbsen[40];

int main(){
int n,i;
cout << "Masukkan Jumlah Mahasiswa : ";
cin >> n;
for (i=0;i<n;i++){
    cout<<"Nama Mahasiswa : ";
    cin>>nama[i];
    cout<<"NIM Mahasiswa : ";
    cin>>nim[i];
    cout<<"Percentage Absen Mahasiswa : ";
    cin>>percentageAbsen[i];
}
}