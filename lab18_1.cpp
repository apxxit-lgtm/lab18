#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
    double x, y, w, h;
};

double overlap(Rect R1, Rect R2) {
    // หาขอบของสี่เหลี่ยมรูปที่ 1
    double L1 = R1.x;
    double R1_right = R1.x + R1.w;
    double T1 = R1.y;
    double B1 = R1.y - R1.h; // ปกติพิกัด y มุมซ้ายบน ค่า y จะลดลงเมื่อลงข้างล่าง

    // หาขอบของสี่เหลี่ยมรูปที่ 2
    double L2 = R2.x;
    double R2_right = R2.x + R2.w;
    double T2 = R2.y;
    double B2 = R2.y - R2.h;

    // หาขอบของพื้นที่ส่วนที่ทับกัน
    double overlap_L = max(L1, L2);
    double overlap_R = min(R1_right, R2_right);
    double overlap_T = min(T1, T2);
    double overlap_B = max(B1, B2);

    // คำนวณความกว้างและความสูงของส่วนที่ทับกัน
    double overlap_w = overlap_R - overlap_L;
    double overlap_h = overlap_T - overlap_B;

    // ถ้าค่าใดค่าหนึ่งเป็นลบหรือศูนย์ แสดงว่าไม่ทับกัน
    if (overlap_w <= 0 || overlap_h <= 0) {
        return 0;
    }

    return overlap_w * overlap_h;
}

