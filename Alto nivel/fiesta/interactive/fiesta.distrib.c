#include "fiesta.h"

// Plantilla de ejemplo. Funciona unicamente para n <= 2.

int BusquedaCool(int n) {
    if (n == 1) return 1; // Caso especial de n = 1.

    // Si 2 conoce a 1 y 1 no conoce a 2, entonces 1 es popular.
    if (Preguntar(2, 1) && !Preguntar(1, 2)) return 1;

    // Si 1 conoce a 2 y 2 no conoce a 1, entonces 2 es popular.
    if (Preguntar(1, 2) && !Preguntar(2, 1)) return 2;

    return 0; // Ninguno de los dos es un chico popular.
}
