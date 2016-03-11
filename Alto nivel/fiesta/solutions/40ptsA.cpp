#include "fiesta.h"

const int kMaxN = 2002;
int conocido[kMaxN][kMaxN];

int BusquedaCool(int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)  conocido[i][j] = Preguntar(i, j);

    int popular = 0;
    for (int i = 1; i <= n; ++i) {
        bool es_popular = true;
        for (int j = 1; j <= n; ++j)
            if (i != j && (!conocido[j][i] ||
                conocido[i][j])) es_popular = false;
        if (es_popular) popular = i;
    }
    return popular;
}
