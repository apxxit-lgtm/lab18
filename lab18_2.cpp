#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
    double x, y, w, h;
};

double overlap(Rect* R1, Rect* R2) {
    double R1_L = R1->x - R1->w / 2.0;
    double R1_R = R1->x + R1->w / 2.0;
    double R1_B = R1->y - R1->h / 2.0;
    double R1_T = R1->y + R1->h / 2.0;

    double R2_L = R2->x - R2->w / 2.0;
    double R2_R = R2->x + R2->w / 2.0;
    double R2_B = R2->y - R2->h / 2.0;
    double R2_T = R2->y + R2->h / 2.0;

    // หาพื้นที่ทับซ้อน
    double overlap_w = min(R1_R, R2_R) - max(R1_L, R2_L);
    double overlap_h = min(R1_T, R2_T) - max(R1_B, R2_B);

    if (overlap_w <= 0 || overlap_h <= 0) return 0;

    return overlap_w * overlap_h;
}
