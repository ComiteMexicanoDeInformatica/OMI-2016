#include "fiesta.h"

int BusquedaCool(int n) {
    int popular = 1;
    for (int i = 2; i <= n; ++i)
        if (!Preguntar(i, popular)) popular = i;

    for (int i = 1; i <= n; ++i) {
        if (i == popular) continue;
        if (Preguntar(popular, i)) return 0;
        if (!Preguntar(i, popular)) return 0;
    }
    return popular;
}
