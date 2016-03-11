#include "pesca.h"

void Segmentar(int x1, int y1, int x2, int y2, int& n, int& k) {
    if (k-- > 0 && !UsarApp(x1, y1, x2, y2)) return;
    if (x1 + 1 < x2 || y1 + 1 < y2) {
        if (x2 - x1 > y2 - y1) {
            int m = (x1 + x2) / 2;
            Segmentar(x1, y1, m, y2, n, k);
            Segmentar(m, y1, x2, y2, n, k);
        } else {
            int m = (y1 + y2) / 2;
            Segmentar(x1, y1, x2, m, n, k);
            Segmentar(x1, m, x2, y2, n, k);
        }
    } else if (n) n -= TirarRed(x1, y1, x2, y2);
}

void Pescar(int w, int h, int n, int k) {
    Segmentar(0, 0, w, h, n, k);
}
