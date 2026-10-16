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

long long hitungSum() {
    long long total = 0;
    for (Node* p = head; p != nullptr; p = p->next)
        total += p->data;
    return total;
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertLast(x);
    }
    cout << hitungSum() << endl;

    while (head != nullptr) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}