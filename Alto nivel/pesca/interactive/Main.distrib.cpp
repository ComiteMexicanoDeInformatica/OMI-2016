#include <stdio.h>
#include <vector>
#include <algorithm>
#include "pesca.h"

using namespace std;

const int kMaxTiros = 100000;

struct Banco {
    double x, y;
    Banco() : x(), y() {}
    Banco(double X, double Y)
        : x(X), y(Y) {}
};

int h, w, n, k;
int consultas = 0;
int tiros_red = 0;
vector<Banco> peces;

int UsarApp(int x1, int y1, int x2, int y2) {
    ++consultas; // Una consulta mas.
    printf("\nLlamada a UsarApp(%d, %d, %d, %d)\n", x1, y1, x2, y2);
    if (x2 < x1) swap(x1, x2); if (y2 < y1) swap(y1, y2);

    // Verificar que las esquinas opuestas del
    // rectangulo consultado esten dentro del mapa.
    if (0 <= x1 && x2 <= w && x1 < x2 &&
        0 <= y1 && y2 <= h && y1 < y2 && consultas <= k) {

        int peces_dentro = 0;
        for (int i = 0; i < peces.size(); ++i)
            // Checar si un pez esta dentro del rectangulo.
            if (x1 <= peces[i].x && peces[i].x <= x2 &&
                y1 <= peces[i].y && peces[i].y <= y2)
                ++peces_dentro; // Uno mas dentro.

        printf("Hay %d bancos de peces dentro.\n", peces_dentro);
        return peces_dentro; // Responder a la funcion.
    }

    if (consultas > k)
        puts("Has excedido el limite de consultas.");
    if (x1 == x2 || y1 == y2)
        puts("No es posible consultar un area nula.");
    if (x1 < 0 || h < x2 || y1 < 0 || w < y2)
        puts("Consulta fuera del area de cobertura.");
    return -1; // No es una consulta valida.
}

int TirarRed(int x1, int y1, int x2, int y2) {
    ++tiros_red; // Un uso mas de la red.
    printf("\nLlamada a TirarRed(%d, %d, %d, %d)\n", x1, y1, x2, y2);
    if (x2 < x1) swap(x1, x2); if (y2 < y1) swap(y1, y2);

    // Verificar que las esquinas opuestas del
    // rectangulo de la red esten dentro del mapa.
    if (0 <= x1 && x2 <= w && x1 + 1 == x2 &&
        0 <= y1 && y2 <= h && y1 + 1 == y2 && tiros_red <= kMaxtiros) {

        vector<Banco> peces_restantes;
        for (int i = 0; i < peces.size(); ++i)
            // Checar si un pez esta fuera de la red.
            if (peces[i].x < x1 || x2 < peces[i].x ||
                peces[i].y < y1 || y2 < peces[i].y)
                // Si esta fuera, entonces no es capturado.
                peces_restantes.push_back(peces[i]);

        int capturados = peces.size() - peces_restantes.size();
        printf("Se capturaron %d bancos de peces.\n", capturados);
        peces = peces_restantes; // Se quitan los peces capturados.
        return capturados; // Responder a la funcion.
    }

    if (tiros_red > kMaxtiros)
        puts("Has tirado la red mas de 100,000 veces.");
    if (x1 == x2 || y1 == y2)
        puts("No es posible tirar la red en un area nula.");
    else if (x1 + 1 < x2 || y1 + 1 < y2)
        puts("La red solo tiene 1 metro cuadrado de area.");
    if (x1 < 0 || h < x2 || y1 < 0 || w < y2)
        puts("No se puede tirar la red fuera del mapa.");
    return -1; // No es posible tirar la red.
}

int main() {
    scanf("%d%d%d%d", &w, &h, &n, &k);
    for (int i = 0; i < n; ++i) {
        double x, y; scanf("%lf%lf", &x, &y);
        peces.push_back(Banco(x, y));
    }
    fclose(stdin);

    printf("Pescar(%d, %d, %d, %d)\n", w, h, n, k);
    Pescar(w, h, n, k); // Llamada inicial a tu funcion.

    printf("\nUsaste %d veces la app de pesca.\n", consultas);
    printf("Tiraste %d veces la red de pesca.\n", tiros_red);

    if (peces.size() > 0)
        puts("No atrapaste a todos los peces...");
    else
        puts("Atrapaste a todos los peces!");
    
    return 0;
}
