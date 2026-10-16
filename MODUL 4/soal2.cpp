#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertLast(int x) {
    Node* baru = new Node{x, nullptr};
    if (head == nullptr) head = tail = baru;
    else { tail->next = baru; tail = baru; }
}

bool insertAfter(int cari, int baruVal) {
    Node* p = head;
    while (p != nullptr && p->data != cari) p = p->next;
    if (p == nullptr) return false;
    Node* baru = new Node{baruVal, p->next};
    p->next = baru;
    if (p == tail) tail = baru;
    return true;
}

void tampil() {
    for (Node* p = head; p != nullptr; p = p->next) {
        cout << p->data;
        if (p->next != nullptr) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int n, x, cari, baru;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertLast(x);
    }
    cin >> cari >> baru;
    insertAfter(cari, baru);
    tampil();

    while (head != nullptr) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}