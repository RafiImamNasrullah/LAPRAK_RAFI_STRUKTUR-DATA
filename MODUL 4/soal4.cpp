#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Buku {
    string judul;
    string tahun;
    Buku* next;
};

Buku* head = nullptr;
Buku* tail = nullptr;

void insertLast(const string& judul, const string& tahun) {
    Buku* baru = new Buku{judul, tahun, nullptr};
    if (head == nullptr) head = tail = baru;
    else { tail->next = baru; tail = baru; }
}

void deleteLast() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = tail = nullptr;
        return;
    }
    Buku* p = head;
    while (p->next != tail) p = p->next;
    delete tail;
    tail = p;
    tail->next = nullptr;
}

void tampil() {
    cout << "Daftar Buku:" << endl;
    for (Buku* p = head; p != nullptr; p = p->next)
        cout << p->judul << " (" << p->tahun << ")" << endl;
}

bool semuaAngka(const string& s) {
    if (s.empty()) return false;
    for (char c : s) if (!isdigit((unsigned char)c)) return false;
    return true;
}

int main() {
    string baris;
    int batas = -1;
    int terbaca = 0;
    bool pertama = true;

    while (getline(cin, baris)) {
        if (!baris.empty() && baris.back() == '\r') baris.pop_back();
        if (baris.empty()) break;

        if (pertama) {
            pertama = false;
            if (semuaAngka(baris)) {
                batas = stoi(baris);
                continue;
            }
        }

        size_t pos = baris.find_last_of(' ');
        if (pos != string::npos) {
            insertLast(baris.substr(0, pos), baris.substr(pos + 1));
            terbaca++;
        }

        if (batas != -1 && terbaca >= batas) break;
    }

    deleteLast();
    tampil();

    while (head != nullptr) {
        Buku* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}