#include <iostream>
using namespace std;

void tukarDanKali10(int &x, int &y) {
    int sementara;

    sementara = x;
    x = y;
    y = sementara;

    x = x * 10;
    y = y * 10;
}

int main() {
    int x, y;

    cin >> x >> y;

    tukarDanKali10(x, y);

    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}