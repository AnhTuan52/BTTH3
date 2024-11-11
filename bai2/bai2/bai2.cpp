#include <iostream>
#include "sophuc.h"
using namespace std;

int main() {
    Sophuc a, b;  // Khởi tạo hai đối tượng số phức là `a` và `b`

    // Nhập số phức `a` từ người dùng
    cout << "Nhap so phuc a: ";
    cin >> a;

    // Nhập số phức `b` từ người dùng
    cout << "Nhap so phuc b: ";
    cin >> b;

    // Cộng hai số phức `a` và `b` bằng cách sử dụng toán tử `+` đã nạp chồng và in kết quả
    cout << "So phuc a + So phuc b = " << a + b << endl;

    // Trừ số phức `b` từ `a` bằng cách sử dụng toán tử `-` đã nạp chồng và in kết quả
    cout << "So phuc a - So phuc b = " << a - b << endl;

    // Nhân hai số phức `a` và `b` bằng cách sử dụng toán tử `*` đã nạp chồng và in kết quả
    cout << "So phuc a * So phuc b = " << a * b << endl;

    // Chia số phức `a` cho `b` bằng cách sử dụng toán tử `/` đã nạp chồng và in kết quả
    cout << "So phuc a / So phuc b = " << a / b << endl;

    // So sánh số phức `a` và `b` bằng toán tử `==` đã nạp chồng
    if (a == b)
        cout << "So phuc a = So phuc b";
    else
        cout << "So phuc a != So phuc b";

    return 0;
}
