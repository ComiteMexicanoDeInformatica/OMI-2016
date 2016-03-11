#include "fiesta.h"

int BusquedaCool(int n) {
    for (int i = 1; i <= n; ++i) {
        int j = 1; for (; j <= n; ++j) {
            if (i == j) continue;
            if (Preguntar(i, j)) break;
            if (!Preguntar(j, i)) break;
        }
        if (j > n) return i;
    }
    return 0;
}
