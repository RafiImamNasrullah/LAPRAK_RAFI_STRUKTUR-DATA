
#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    infotype x;
    address P, Prec, Hapus;

    CreateList(L);

    for (int i = 1; i <= 4; i++) {
        cout << "\nMasukkan nomor polisi: ";
        cin >> x.nopol;

        cout << "Masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "Masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != nullptr) {
            cout << "Nomor polisi sudah terdaftar" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
    }

    printInfo(L);

    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> x.nopol;

    P = findElm(L, x);

    if (P != nullptr) {
        cout << "\nNomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data kendaraan tidak ditemukan" << endl;
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> x.nopol;

    P = findElm(L, x);

    if (P != nullptr) {
        if (P == L.First) {
            deleteFirst(L, Hapus);
        } else if (P == L.Last) {
            deleteLast(L, Hapus);
        } else {
            Prec = P->prev;
            deleteAfter(Prec, Hapus);
        }

        dealokasi(Hapus);
        cout << "Data dengan nomor polisi " << x.nopol
             << " berhasil dihapus." << endl;
    } else {
        cout << "Data kendaraan tidak ditemukan." << endl;
    }

    printInfo(L);

    return 0;
}
