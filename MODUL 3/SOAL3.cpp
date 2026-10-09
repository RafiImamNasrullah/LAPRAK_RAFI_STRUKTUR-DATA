#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    int B[3][3] = {{10, 20, 30},
                   {40, 50, 60},
                   {70, 80, 90}};

    int *ptr1, *ptr2;
    int baris, kolom;

    cout << "=== Array A (awal) ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B (awal) ===" << endl;
    tampilArray(B);

    cout << "\nMasukkan posisi yang akan ditukar (baris kolom, 0-2): ";
    cin >> baris >> kolom;

    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        tukarArray(A, B, baris, kolom);
        cout << "\n=== Setelah tukar array pada posisi [" << baris << "][" << kolom << "] ===" << endl;
        cout << "Array A:" << endl;
        tampilArray(A);
        cout << "Array B:" << endl;
        tampilArray(B);
    } else {
        cout << "Posisi tidak valid!" << endl;
    }

    ptr1 = &A[0][0];
    ptr2 = &B[0][0];

    cout << "\n=== Sebelum tukar pointer ===" << endl;
    cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    tukarPointer(ptr1, ptr2);

    cout << "\n=== Setelah tukar pointer ===" << endl;
    cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    return 0;
}