#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// FUNGSI untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3f * uts + 0.4f * uas + 0.3f * tugas;
}

int main() {
    Mahasiswa mhs[MAX];
    int n;

    do {
        cout << "Jumlah mahasiswa (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cin.ignore();
        cout << "Nama  : "; getline(cin, mhs[i].nama);
        cout << "NIM   : "; getline(cin, mhs[i].nim);
        cout << "UTS   : "; cin >> mhs[i].uts;
        cout << "UAS   : "; cin >> mhs[i].uas;
        cout << "Tugas : "; cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=== DATA MAHASISWA ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << mhs[i].nama
             << " | NIM: " << mhs[i].nim
             << " | UTS: " << mhs[i].uts
             << " | UAS: " << mhs[i].uas
             << " | Tugas: " << mhs[i].tugas
             << " | Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
    return 0;
}