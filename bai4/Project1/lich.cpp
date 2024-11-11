#include "lich.h"
#include<iostream>
using namespace std;

// Hàm kiểm tra năm nhuận: 
// Kiểm tra xem một năm có phải là năm nhuận không dựa vào quy tắc: năm nhuận chia hết cho 4 và không chia hết cho 100, hoặc chia hết cho 400.
bool lich::lanamnhuan(int nam) const {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// Hàm tính số ngày trong một tháng:
// Dùng mảng `ngayThang` để xác định số ngày của từng tháng. Nếu tháng là tháng 2 (tháng 2 có thể có 28 hoặc 29 ngày) và năm là năm nhuận, thì trả về 29, ngược lại trả về số ngày trong mảng `ngayThang`.
int lich::so_ngay_trong_thang(int thang, int nam) const {
    static int ngayThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (thang == 2 && lanamnhuan(nam)) return 29;
    return ngayThang[thang - 1];
}

// Hàm khởi tạo mặc định: 
// Thiết lập ngày mặc định là 01/01/2000.
lich::lich() : ngay(1), thang(1), nam(2000) {}

// Hàm khởi tạo với tham số: 
// Khởi tạo đối tượng `lich` với ngày, tháng, năm do người dùng nhập vào.
lich::lich(int ingay, int ithang, int inam) {
    ngay = ingay;
    thang = ithang;
    nam = inam;
}

// Hàm `tinhngay`: 
// Tính tổng số ngày từ 01/01/0001 đến ngày được xác định bởi đối tượng hiện tại. 
// Tính tổng số ngày của các năm trước đó, sau đó tính tổng số ngày của các tháng trước tháng hiện tại, và cuối cùng cộng ngày hiện tại.
int lich::tinhngay() const {
    int day = ngay;
    for (int i = 1; i < nam; ++i) {
        if (lanamnhuan(i))
            day += 366;
        else
            day += 365;
    }
    for (int j = 1; j < thang; ++j)
        day += so_ngay_trong_thang(j, nam);
    return day;
}

// Nạp chồng toán tử cộng (+): 
// Cộng thêm số ngày `ngay` vào đối tượng `lich` hiện tại. Nếu số ngày vượt quá số ngày trong tháng, chuyển sang tháng tiếp theo và tăng năm nếu cần.
lich lich::operator +(int ngay) {
    lich bien = *this;
    bien.ngay += ngay;
    while (bien.ngay > so_ngay_trong_thang(bien.thang, bien.nam)) {
        bien.ngay -= so_ngay_trong_thang(bien.thang, bien.nam);
        if (++bien.thang > 12) {
            bien.thang = 1;
            ++bien.nam;
        }
    }
    return bien;
}

// Nạp chồng toán tử trừ (-) với số nguyên: 
// Trừ số ngày `ngay` khỏi đối tượng `lich` hiện tại. Nếu ngày âm, lùi sang tháng trước và giảm năm nếu cần.
lich lich::operator -(int ngay) {
    lich bien = *this;
    bien.ngay -= ngay;
    while (bien.ngay <= 0) {
        if (--bien.thang < 1) {
            bien.thang = 12;
            --bien.nam;
        }
        bien.ngay += so_ngay_trong_thang(bien.thang, bien.nam);
    }
    return bien;
}

// Nạp chồng toán tử trừ giữa hai đối tượng `lich`: 
// Tính khoảng cách số ngày giữa hai đối tượng bằng cách lấy hiệu của tổng số ngày (dựa trên `tinhngay`).
int lich::operator - (const lich& n) const {
    return tinhngay() - n.tinhngay();
}

// Nạp chồng toán tử tăng hậu tố (++): 
// Tăng đối tượng `lich` lên một ngày. Nếu ngày vượt quá số ngày trong tháng, chuyển sang tháng kế tiếp hoặc năm kế tiếp.
lich lich::operator ++(int) {
    lich bien = *this;
    bien.ngay = bien.ngay + 1;
    while (bien.ngay > so_ngay_trong_thang(bien.thang, bien.nam)) {
        bien.ngay -= so_ngay_trong_thang(bien.thang, bien.nam);
        if (++bien.thang > 12) {
            bien.thang = 1;
            ++bien.nam;
        }
    }
    return bien;
}

// Nạp chồng toán tử giảm hậu tố (--): 
// Giảm đối tượng `lich` một ngày. Nếu ngày âm, lùi về tháng trước hoặc năm trước nếu cần.
lich lich::operator --(int) {
    lich bien = *this;
    bien.ngay = bien.ngay - 1;
    while (bien.ngay <= 0) {
        if (--bien.thang < 1) {
            bien.thang = 12;
            --bien.nam;
        }
        bien.ngay += so_ngay_trong_thang(bien.thang, bien.nam);
    }
    return bien;
}

// Nạp chồng toán tử so sánh bằng (==): 
// So sánh xem ngày, tháng và năm của hai đối tượng có bằng nhau không.
bool lich::operator ==(const lich& n) const {
    return ngay == n.ngay && thang == n.thang && nam == n.nam;
}

// Nạp chồng toán tử so sánh khác (!=): 
// So sánh xem ngày, tháng và năm của hai đối tượng có khác nhau không.
bool lich::operator !=(const lich& n) const {
    return ngay != n.ngay || thang != n.thang || nam != n.nam;
}

// Nạp chồng toán tử so sánh lớn hơn hoặc bằng (>=):
// So sánh tổng số ngày giữa hai đối tượng dựa vào `tinhngay`.
bool lich::operator >=(const lich& n) const {
    return tinhngay() >= n.tinhngay();
}

// Nạp chồng toán tử so sánh nhỏ hơn hoặc bằng (<=):
bool lich::operator <=(const lich& n) const {
    return tinhngay() <= n.tinhngay();
}

// Nạp chồng toán tử so sánh lớn hơn (>):
bool lich::operator >(const lich& n) const {
    return tinhngay() > n.tinhngay();
}

// Nạp chồng toán tử so sánh nhỏ hơn (<):
bool lich::operator <(const lich& n) const {
    return tinhngay() < n.tinhngay();
}

// Nạp chồng toán tử << để xuất đối tượng `lich`:
// Xuất ngày/tháng/năm của đối tượng theo định dạng "ngay/thang/nam".
ostream& operator <<(ostream& out, const lich& n) {
    out << n.ngay << "/" << n.thang << "/" << n.nam;
    return out;
}

// Nạp chồng toán tử >> để nhập đối tượng `lich`:
// Nhập giá trị cho các thành viên `ngay`, `thang`, và `nam` từ bàn phím.
istream& operator >>(istream& in, lich& n) {
    cout << "Nhap ngay: ";
    in >> n.ngay;
    cout << "Nhap thang: ";
    in >> n.thang;
    cout << "Nhap nam: ";
    in >> n.nam;
    return in;
}
