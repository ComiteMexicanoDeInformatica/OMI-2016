#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "pesca.h"

using namespace std;

struct SegTree1D {
    int l, r, dato;
    SegTree1D* izq;
    SegTree1D* der;

    SegTree1D(int l_, int r_)
        : l(l_), r(r_), dato(0),
          izq(NULL), der(NULL) {}

    int Actualizar(int a, int v) {
        if (a < l || r < a) return dato;
        if (a == l && r == a) return dato += v;
        if (!izq) { int m = (l + r) / 2;
            der = new SegTree1D(m + 1, r);
            izq = new SegTree1D(l, m);
        }
        return dato = izq->Actualizar(a, v) +
                      der->Actualizar(a, v);
    }

    int Consultar(int a, int b) {
        if (a <= l && r <= b) return dato;
        if (!izq || b < l || r < a) return 0;
        return izq->Consultar(a, b) +
               der->Consultar(a, b);
    }
};

struct SegTree2D {
    int l, r, w;
    SegTree1D dato;
    SegTree2D* izq;
    SegTree2D* der;

    SegTree2D(int l_, int r_, int w_)
        : l(l_), r(r_), dato(0, w), w(w_),
          izq(NULL), der(NULL) {}

    int Actualizar(int a, int b, int v) {
        if (a == l && r == a)
            return dato.Actualizar(b, v);
        if (a < l || r < a) return dato.dato;
        if (!izq) { int m = (l + r) / 2;
            der = new SegTree2D(m + 1, r, w);
            izq = new SegTree2D(l, m, w);
        }
        izq->Actualizar(a, b, v);
        der->Actualizar(a, b, v);
        return dato.Actualizar(b, v);
    }

    int Consultar(int a, int b, int c, int d) {
        if (a <= l && r <= b)
            return dato.Consultar(c, d);
        if (!izq || b < l || r < a) return 0;
        return izq->Consultar(a, b, c, d) +
               der->Consultar(a, b, c, d);
    }
};

const int kMaxTiros = 100000;

int w, h, n, k;
SegTree2D* segtree;
int consultas, tiros, capturas;

int Abortar() { puts("0.0"); exit(0); }

int UsarApp(int x1, int y1, int x2, int y2) {
    if (k < ++consultas) Abortar();
    if (x2 < x1) swap(x1, x2); if (y2 < y1) swap(y1, y2);
    if (x2 < 0 || w < x1 || x2 - x1 == 0 ||
        y2 < 0 || h < y1 || y2 - y1 == 0) return -1;
    return segtree->Consultar(x1, x2 - 1, y1, y2 - 1);
}

int TirarRed(int x1, int y1, int x2, int y2) {
    if (kMaxTiros < ++tiros) Abortar();
    if (x2 < x1) swap(x1, x2); if (y2 < y1) swap(y1, y2);
    if (x2 < 0 || w < x1 || x2 - x1 != 1 ||
        y2 < 0 || h < y1 || y2 - y1 != 1) return -1;
    int peces = segtree->Consultar(x1, x2 - 1, y1, y2 - 1);
    if (peces) segtree->Actualizar(x1, y1, -peces);
    capturas += peces; return peces;
}

int main() {
    scanf("%d%d%d%d", &h, &w, &n, &k);
    segtree = new SegTree2D(0, w - 1, h - 1);
    for (int i = 0; i < n; ++i) {
        int x, y; scanf("%d%d", &y, &x);
        segtree->Actualizar(x, y, 1);
    }
    fclose(stdin);

    Pescar(w, h, n, k);
    if (capturas < n) puts("0.0");
    else {
        double nsq = pow(n, 2);
        double tsq = pow(max(0, tiros - n), 2);
        double score = 0.8 * nsq / (0.1 * tsq + nsq);
        printf("%.2f\n", 0.2 + score);
    }
    return 0;
}
