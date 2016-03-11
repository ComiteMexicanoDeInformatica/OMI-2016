#include "pesca.h"

void Segmentar(int x1, int y1, int x2, int y2, int n, int& k) {
    if (k && (x1 + 1 < x2 || y1 + 1 < y2)) {
        if (x2 - x1 > y2 - y1) {
            int m = (x1 + x2) / 2; --k;
            int p = UsarApp(x1, y1, m, y2);
            if (p) Segmentar(x1, y1, m, y2, p, k);
            if (n - p) Segmentar(m, y1, x2, y2, n - p, k);
        } else {
            int m = (y1 + y2) / 2; --k;
            int p = UsarApp(x1, y1, x2, m);
            if (p) Segmentar(x1, y1, x2, m, p, k);
            if (n - p) Segmentar(x1, m, x2, y2, n - p, k);
        }
    } else 
        for (int i = x1; i < x2; ++i)
            for (int j = y1; j < y2; ++j)
                if (n) n -= TirarRed(i, j, i + 1, j + 1);
}

void Pescar(int w, int h, int n, int k) {
    Segmentar(0, 0, w, h, n, k);
}
