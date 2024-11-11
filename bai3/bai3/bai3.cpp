#include<iostream>
#include"thoigian.h"
using namespace std;

int main() {
    thoigian tg1, tg2;  // Khởi tạo hai đối tượng `thoigian` là `tg1` và `tg2`
    int igiay;  // Khởi tạo biến `igiay` để lưu số giây muốn cộng thêm vào thời gian

    // Nhập thông tin cho `tg1`
    cout << "Nhap thoi gian 1: " << endl;
    cin >> tg1;

    // Nhập thông tin cho `tg2`
    cout << "Nhap thoi gian 2: " << endl;
    cin >> tg2;

    // Tính tổng hai đối tượng `tg1` và `tg2` bằng cách sử dụng toán tử `+` đã nạp chồng
    cout << "Tong thoi gian cua 2 thoi gian = " << tg1 + tg2 << endl;

    // Tính hiệu hai đối tượng `tg1` và `tg2` bằng cách sử dụng toán tử `-` đã nạp chồng
    cout << "Hieu thoi gian cua 2 thoi gian = " << tg1 - tg2 << endl;

    // Nhập số giây muốn tăng thêm vào `tg1`
    cout << "Nhap so giay muon tang them cua thoi gian 1: ";
    cin >> igiay;

    // Cộng thêm số giây vào `tg1` và hiển thị kết quả
    cout << "Thoi gian 1 sau khi tang them la: " << tg1 + igiay << endl;

    // Tăng `tg1` thêm 1 giây bằng cách sử dụng toán tử `++` đã nạp chồng và hiển thị kết quả
    cout << "Tang thoi gian 1 them 1 giay: " << tg1++ << endl;

    // So sánh hai đối tượng `tg1` và `tg2` bằng toán tử `==` đã nạp chồng
    if (tg1 == tg2)
        cout << "2 thoi gian bang nhau.";
    else {
        // Nếu không bằng, kiểm tra xem `tg1` lớn hơn `tg2` hay không bằng toán tử `>`
        if (tg1 > tg2)
            cout << " Thoi gian 1 lon hon thoi gian 2";
        else
            cout << "Thoi gian 2 lon hon thoi gian 1";
    }

    return 0;
}
