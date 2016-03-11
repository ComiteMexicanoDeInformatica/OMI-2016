#include "pesca.h"

void Pescar(int w, int h, int n, int k) {
    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j)
            if (--k < 0) TirarRed(i, j, i + 1, j + 1);
            else if (UsarApp(i, j, i + 1, j + 1))
                TirarRed(i, j, i + 1, j + 1);
}
