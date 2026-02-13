#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
    double x, y, w, h;
};


double overlap(Rect *R1, Rect *R2) {
    double L1 = R1->x;
    double R1_right = R1->x + R1->w;
    double T1 = R1->y;
    double B1 = R1->y - R1->h; 

    double L2 = R2->x;
    double R2_right = R2->x + R2->w;
    double T2 = R2->y;
    double B2 = R2->y - R2->h;

    double overlap_L = max(L1, L2);
    double overlap_R = min(R1_right, R2_right);
    double overlap_T = min(T1, T2);
    double overlap_B = max(B1, B2);

    double overlap_w = overlap_R - overlap_L;
    double overlap_h = overlap_T - overlap_B;

    if (overlap_w <= 0 || overlap_h <= 0) {
        return 0;
    }

    return overlap_w * overlap_h;
}

