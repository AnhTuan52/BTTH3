
#include <bits/bits-stdc++.h>
#include "Phanso.h"
using namespace std;
int main() {
    Phanso a, b, giatri;
    cout << "Nhap phan so a: ";
    cin >> a;

    // Nhập phân số b
    cout << "Nhap phan so b: ";
    cin >> b;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    if (a == b)
        cout << "a == b";
    else {
        cout << "a != b\n";
        if (a > b) {
            cout << "a > b"; 
        }
        else {
            cout << "a < b";
        }
    }
    return 0;
}
