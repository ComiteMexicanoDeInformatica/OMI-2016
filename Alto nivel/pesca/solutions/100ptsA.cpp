#include <queue>
#include "pesca.h"

struct Rect {
    int x1, y1, x2, y2, n;
    Rect(int a, int b, int c, int d, int e)
        : x1(a), y1(b), x2(c), y2(d), n(e) {}
};

void Pescar(int w, int h, int n, int k) {
    std::queue<Rect> segmentos;
    segmentos.push(Rect(0, 0, w, h, n));

    while (!segmentos.empty()) {
        int x1 = segmentos.front().x1;
        int x2 = segmentos.front().x2;
        int y1 = segmentos.front().y1;
        int y2 = segmentos.front().y2;
        n = segmentos.front().n;
        segmentos.pop();

        if (k && (x1 + 1 < x2 || y1 + 1 < y2)) {
            if (x2 - x1 > y2 - y1) {
                int m = (x1 + x2) / 2; --k;
                int p = UsarApp(x1, y1, m, y2);
                if (p) segmentos.push(
                    Rect(x1, y1, m, y2, p));
                if (n - p) segmentos.push(
                    Rect(m, y1, x2, y2, n - p));
            } else {
                int m = (y1 + y2) / 2; --k;
                int p = UsarApp(x1, y1, x2, m);
                if (p) segmentos.push(
                    Rect(x1, y1, x2, m, p));
                if (n - p) segmentos.push(
                    Rect(x1, m, x2, y2, n - p));
            }
        } else {
            for (int i = x1; i < x2; ++i)
                for (int j = y1; j < y2; ++j)
                    if (n) n -= TirarRed(i, j, i + 1, j + 1);
        }
    }
}
