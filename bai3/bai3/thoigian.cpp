#include "thoigian.h"
#include <iostream>
using namespace std;

// Hàm khởi tạo mặc định của lớp `thoigian`
thoigian::thoigian() {}

// Hàm khởi tạo với tham số:
// Thiết lập các giá trị giờ, phút, giây dựa trên các tham số được truyền vào.
thoigian::thoigian(int igio, int iphut, int igiay) {
    gio = igio;
    phut = iphut;
    giay = igiay;
}

// Hàm `sogiay`:
// Tính tổng số giây từ giờ, phút và giây của đối tượng hiện tại.
int thoigian::sogiay() const {
    return (gio * 3600 + phut * 60 + giay);
}

// Hàm `Tinhlaigio`:
// Chuyển đổi số giây `igiay` thành giá trị giờ, phút, giây và thiết lập lại đối tượng hiện tại.
void thoigian::Tinhlaigio(int igiay) {
    gio = igiay / 3600;
    phut = (igiay % 3600) / 60;
    giay = igiay % 60;
}

// Nạp chồng toán tử cộng (+) với số nguyên:
// Cộng thêm số giây `igiay` vào đối tượng hiện tại, chuyển đổi kết quả thành giờ, phút, giây mới.
thoigian thoigian::operator+ (int igiay) const {
    int tinhgiay = sogiay() + igiay;
    thoigian bien;
    bien.Tinhlaigio(tinhgiay);
    return bien;
}

// Nạp chồng toán tử trừ (-) với số nguyên:
// Trừ số giây `igiay` khỏi đối tượng hiện tại, chuyển đổi kết quả thành giờ, phút, giây mới.
thoigian thoigian::operator -(int igiay) const {
    int tinhgiay = sogiay() - igiay;
    thoigian bien;
    bien.Tinhlaigio(tinhgiay);
    return bien;
}

// Nạp chồng toán tử cộng (+) với một đối tượng `thoigian` khác:
// Cộng thời gian của đối tượng `tg` vào đối tượng hiện tại.
thoigian thoigian::operator +(const thoigian& tg) const {
    int tinhgiay = sogiay() + tg.sogiay();
    thoigian bien;
    bien.Tinhlaigio(tinhgiay);
    return bien;
}

// Nạp chồng toán tử trừ (-) với một đối tượng `thoigian` khác:
// Trừ thời gian của đối tượng `tg` khỏi đối tượng hiện tại.
thoigian thoigian::operator -(const thoigian& tg) const {
    int tinhgiay = sogiay() - tg.sogiay();
    thoigian bien;
    bien.Tinhlaigio(tinhgiay);
    return bien;
}

// Nạp chồng toán tử tăng hậu tố (++):
// Tăng giây của đối tượng lên 1. Nếu giây đạt 60, tăng phút lên 1; nếu phút đạt 60, tăng giờ lên 1.
thoigian thoigian::operator ++(int) {
    giay++;
    phut += giay / 60;
    gio += phut / 60;
    giay = giay % 60;
    return *this;
}

// Nạp chồng toán tử giảm hậu tố (--):
// Giảm giây của đối tượng đi 1. Nếu giây âm, lùi phút và giây về giá trị hợp lệ.
thoigian thoigian::operator --(int) {
    giay--;
    if (giay == -1) {
        phut -= 1;
        giay = 59;
    }
    if (phut == -1) {
        gio -= 1;
        phut = 59;
    }
    return *this;
}

// Nạp chồng toán tử so sánh bằng (==):
// So sánh giờ, phút, giây của hai đối tượng `thoigian` để kiểm tra bằng nhau.
bool thoigian::operator ==(const thoigian& tg) {
    return (gio == tg.gio && phut == tg.phut && giay == tg.giay);
}

// Nạp chồng toán tử so sánh khác (!=):
// So sánh giờ, phút, giây của hai đối tượng `thoigian` để kiểm tra khác nhau.
bool thoigian::operator !=(const thoigian& tg) {
    return (gio != tg.gio || phut != tg.phut || giay != tg.giay);
}

// Nạp chồng toán tử so sánh lớn hơn hoặc bằng (>=):
// So sánh tổng số giây của hai đối tượng để kiểm tra lớn hơn hoặc bằng.
bool thoigian::operator >=(const thoigian& tg) {
    return (sogiay() >= tg.sogiay());
}

// Nạp chồng toán tử so sánh nhỏ hơn hoặc bằng (<=):
bool thoigian::operator <=(const thoigian& tg) {
    return (sogiay() <= tg.sogiay());
}

// Nạp chồng toán tử so sánh lớn hơn (>):
bool thoigian::operator >(const thoigian& tg) {
    return (sogiay() > tg.sogiay());
}

// Nạp chồng toán tử so sánh nhỏ hơn (<):
bool thoigian::operator <(const thoigian& tg) {
    return (sogiay() < tg.sogiay());
}

// Nạp chồng toán tử << để xuất đối tượng `thoigian`:
// Xuất đối tượng dưới dạng "gioh:phutm:giays".
ostream& operator << (ostream& out, const thoigian& tg) {
    out << tg.gio << "h:" << tg.phut << "m:" << tg.giay << "s";
    return out;
}

// Nạp chồng toán tử >> để nhập đối tượng `thoigian`:
// Nhập giờ, phút, giây từ bàn phím và gán cho đối tượng.
istream& operator >>(istream& in, thoigian& tg) {
    cout << "Nhap gio: ";
    in >> tg.gio;
    cout << "Nhap phut: ";
    in >> tg.phut;
    cout << "Nhap giay: ";
    in >> tg.giay;
    return in;
}
