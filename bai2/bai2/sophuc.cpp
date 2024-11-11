#include "sophuc.h"
#include <iostream>
using namespace std;

// Hàm khởi tạo không tham số, khởi tạo giá trị mặc định
Sophuc::Sophuc() {
    thuc = 0;
    ao = 0;
}

// Hàm khởi tạo có tham số, khởi tạo với giá trị thực và ảo do người dùng cung cấp
Sophuc::Sophuc(float Thuc, float Ao) {
    thuc = Thuc;
    ao = Ao;
}

// Nạp chồng toán tử + để thực hiện phép cộng số phức
Sophuc Sophuc::operator +(const Sophuc& P) const {
    return Sophuc(thuc + P.thuc, ao + P.ao);
}

// Nạp chồng toán tử - để thực hiện phép trừ số phức
Sophuc Sophuc::operator -(const Sophuc& P) const {
    return Sophuc(thuc - P.thuc, ao - P.ao);
}

// Nạp chồng toán tử * để thực hiện phép nhân số phức
Sophuc Sophuc::operator *(const Sophuc& P) const {
    int new_thuc = (thuc * P.thuc - ao * P.ao); // Phần thực của tích
    int new_ao = (thuc * P.ao + ao * P.thuc);   // Phần ảo của tích
    return Sophuc(new_thuc, new_ao);
}

// Nạp chồng toán tử / để thực hiện phép chia số phức
Sophuc Sophuc::operator /(const Sophuc& P) const {
    long long mau = P.thuc * P.thuc + P.ao * P.ao; // Tính mẫu bằng cách bình phương phần thực và ảo của số chia
    if (mau == 0) { // Kiểm tra mẫu khác 0
        cout << "Loi: khong the chia cho so 0." << endl;
        return Sophuc(); // Trả về số phức mặc định (0, 0)
    }
    return Sophuc(
        float((thuc * P.thuc + ao * P.ao) / mau),     // Phần thực của thương
        float((ao * P.thuc - thuc * P.ao) / mau)      // Phần ảo của thương
    );
}

// Nạp chồng toán tử == để kiểm tra hai số phức bằng nhau
bool Sophuc::operator ==(const Sophuc& P) {
    return (thuc == P.thuc && ao == P.ao);
}

// Nạp chồng toán tử != để kiểm tra hai số phức khác nhau
bool Sophuc::operator !=(const Sophuc& P) {
    return (thuc != P.thuc || ao != P.ao);
}

// Nạp chồng toán tử << để xuất số phức ra màn hình
ostream& operator <<(ostream& out, const Sophuc& P) {
    if (P.ao >= 0)
        out << P.thuc << " + " << P.ao << "i";
    else
        out << P.thuc << " " << P.ao << "i";
    return out;
}

// Nạp chồng toán tử >> để nhập số phức từ người dùng
istream& operator >>(istream& in, Sophuc& P) {
    cout << "Nhap phan thuc: ";
    in >> P.thuc;
    cout << "Nhap phan ao: ";
    in >> P.ao;
    return in;
}
