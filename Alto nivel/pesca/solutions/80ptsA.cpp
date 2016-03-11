#include <queue>
#include "pesca.h"

struct Rect {
    int x1, y1, x2, y2;
    Rect(int a, int b, int c, int d)
        : x1(a), y1(b), x2(c), y2(d) {}
};

void Pescar(int w, int h, int n, int k) {
    std::queue<Rect> segmentos;
    segmentos.push(Rect(0, 0, w, h));
    while (!segmentos.empty()) {
        int x1 = segmentos.front().x1;
        int x2 = segmentos.front().x2;
        int y1 = segmentos.front().y1;
        int y2 = segmentos.front().y2;
        segmentos.pop();

        if (k-- > 0 && !UsarApp(x1, y1, x2, y2)) continue;
        
        if (x1 + 1 < x2 || y1 + 1 < y2) {
            if (x2 - x1 > y2 - y1) {
                int m = (x1 + x2) / 2;
                segmentos.push(Rect(x1, y1, m, y2));
                segmentos.push(Rect(m, y1, x2, y2));
            } else {
                int m = (y1 + y2) / 2;
                segmentos.push(Rect(x1, y1, x2, m));
                segmentos.push(Rect(x1, m, x2, y2));
            }
        } else if (n) n -= TirarRed(x1, y1, x2, y2);
    }
}
