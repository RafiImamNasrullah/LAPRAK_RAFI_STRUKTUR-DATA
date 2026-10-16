#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertLast(const string& nama) {
    Node* baru = new Node{nama, nullptr};
    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

bool deleteFirst(string& nama) {
    if (head == nullptr) return false;
    Node* hapus = head;
    nama = hapus->nama;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete hapus;
    return true;
}

void tampilAntrean() {
    if (head == nullptr) {
        cout << "Antrean: kosong" << endl;
        return;
    }
    cout << "Antrean: ";
    for (Node* p = head; p != nullptr; p = p->next) {
        cout << p->nama;
        if (p->next != nullptr) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int pilihan;
    while (cin >> pilihan && pilihan != 3) {
        if (pilihan == 1) {
            string nama;
            cin >> ws;
            getline(cin, nama);
            insertLast(nama);
            tampilAntrean();
        } else if (pilihan == 2) {
            string nama;
            if (deleteFirst(nama)) {
                cout << "Melayani: " << nama << endl;
                tampilAntrean();
            } else {
                cout << "Antrean kosong" << endl;
            }
        }
    }
    while (head != nullptr) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}