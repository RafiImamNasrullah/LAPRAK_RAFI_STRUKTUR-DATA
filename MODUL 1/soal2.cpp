#include <iostream>
using namespace std;

string satuan[] = {
    "nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh",
    "delapan", "sembilan", "sepuluh", "sebelas", "dua belas", "tiga belas",
    "empat belas", "lima belas", "enam belas", "tujuh belas",
    "delapan belas", "sembilan belas"
};

string terbilang(int n) {
    if (n < 20) return satuan[n];
    if (n < 100) {
        int puluh = n / 10, sisa = n % 10;
        if (sisa == 0) return satuan[puluh] + " puluh";
        return satuan[puluh] + " puluh " + satuan[sisa];
    }
    return "seratus";
}

int main() {
    int n;
    cin >> n;
    cout << n << " : " << terbilang(n) << endl;
    return 0;
}