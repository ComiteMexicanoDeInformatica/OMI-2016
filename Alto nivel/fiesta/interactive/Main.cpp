#include <stdio.h>
#include <stdlib.h>
#include "fiesta.h"

const int kMaxN = 2000;
const int kMaxK = 6000;

int n, preguntas;
int conocido[kMaxN][kMaxN];

int Abortar() { puts("0.0"); exit(0); }

int Preguntar(int a, int b) {
    if (kMaxK < ++preguntas) Abortar();
    if (a < 1 || n < a || a == b ||
        b < 1 || n < b) return -1;
    return conocido[--a][--b];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &conocido[i][j]);
    fclose(stdin);

    int popular = 0;
    for (int i = 0; i < n; ++i) {
        bool es_popular = true;
        for (int j = 0; j < n; ++j)
            if (i != j && (!conocido[j][i] ||
                conocido[i][j])) es_popular = false;
        if (es_popular) popular = i + 1;
    }

    if (popular == BusquedaCool(n))
        puts("1.0");
    else
        puts("0.0");
    return 0;
}
