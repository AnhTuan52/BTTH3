// Import thư viện tiêu chuẩn của C++
#include <bits/bits-stdc++.h>

// Import file header "Phanso.h" để sử dụng lớp Phanso
#include "Phanso.h"

// Sử dụng không gian tên std để sử dụng các hàm tiêu chuẩn như cout, cin
using namespace std;

// Hàm main - điểm bắt đầu của chương trình
int main() {
    // Khai báo ba đối tượng kiểu Phanso là a, b và giatri
    Phanso a, b, giatri;

    // Nhập phân số a
    cout << "Nhap phan so a: ";
    cin >> a;

    // Nhập phân số b
    cout << "Nhap phan so b: ";
    cin >> b;

    // Thực hiện phép cộng hai phân số a và b và in kết quả
    cout << "a + b = " << a + b << endl;

    // Thực hiện phép trừ hai phân số a và b và in kết quả
    cout << "a - b = " << a - b << endl;

    // Thực hiện phép nhân hai phân số a và b và in kết quả
    cout << "a * b = " << a * b << endl;

    // Thực hiện phép chia hai phân số a và b và in kết quả
    cout << "a / b = " << a / b << endl;

    // Kiểm tra xem hai phân số a và b có bằng nhau không
    if (a == b)
        cout << "a == b"; // In thông báo nếu a bằng b
    else {
        // Nếu a khác b, in thông báo và tiếp tục so sánh
        cout << "a != b\n";

        // Kiểm tra xem a có lớn hơn b không
        if (a > b) {
            cout << "a > b"; // In thông báo nếu a lớn hơn b
        }
        else {
            cout << "a < b"; // In thông báo nếu a nhỏ hơn b
        }
    }

    // Trả về 0 để kết thúc chương trình
    return 0;
}
