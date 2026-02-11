#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
    double x, y, w, h;
};

double overlap(Rect R1, Rect R2) {
    // คำนวณขอบของ R1 (ใช้ x, y เป็นจุดศูนย์กลาง)
    double R1_left   = R1.x - R1.w / 2.0;
    double R1_right  = R1.x + R1.w / 2.0;
    double R1_bottom = R1.y - R1.h / 2.0;
    double R1_top    = R1.y + R1.h / 2.0;

    // คำนวณขอบของ R2
    double R2_left   = R2.x - R2.w / 2.0;
    double R2_right  = R2.x + R2.w / 2.0;
    double R2_bottom = R2.y - R2.h / 2.0;
    double R2_top    = R2.y + R2.h / 2.0;

    // หาช่วงที่ทับซ้อนกัน
    double overlap_w = min(R1_right, R2_right) - max(R1_left, R2_left);
    double overlap_h = min(R1_top, R2_top) - max(R1_bottom, R2_bottom);

    // ตรวจสอบว่าทับกันจริงไหม
    if (overlap_w <= 0 || overlap_h <= 0) return 0;

    return overlap_w * overlap_h;
}