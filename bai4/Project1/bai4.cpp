#include <iostream>
#include "lich.h"

using namespace std;

int main() {
    // Khởi tạo và nhập giá trị ngày tháng
    lich date1, date2;
    cout << "Nhap ngay thang nam cho date1:\n";
    cin >> date1;
    cout << "Nhap ngay thang nam cho date2:\n";
    cin >> date2;

    // Xuất các giá trị ngày tháng
    cout << "Date1: " << date1 << "\nDate2: " << date2 << endl;

    // Thực hiện các phép toán với ngày
    cout << "Date1 + 10 ngay: " << date1 + 10 << endl;
    cout << "Date1 - 15 ngay: " << date1 - 15 << endl;
    cout << "Khoang cach ngay giua Date1 va Date2: " << date1 - date2 << " ngay" << endl;

    // Kiểm tra toán tử ++ và --
    cout << "Date1 sau khi ++: " << date1++ << "\nDate2 sau khi --: " << date2-- << endl;

    // So sánh hai ngày
    cout << "Date1 " << (date1 == date2 ? "bang" : date1 > date2 ? "lon hon" : "nho hon") << " Date2\n";
    cout << "Date1 != Date2: " << (date1 != date2) << "\nDate1 >= Date2: " << (date1 >= date2)
        << "\nDate1 <= Date2: " << (date1 <= date2) << endl;

    return 0;
}
