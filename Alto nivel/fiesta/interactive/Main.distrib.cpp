#include <stdio.h>
#include "fiesta.h"

const int kMaxN = 2002;

int n, preguntas = 0;
int conocido[kMaxN][kMaxN];

int Preguntar(int a, int b) {
    ++preguntas; // Hiciste una pregunta mas.
    printf("Se ha llamado a Preguntar(%d, %d).\n", a, b);

    // a y b deben ser diferentes y estar en el intervalo [1, n].
    if (a != b && 1 <= a && a <= n && 1 <= b && b <= n) {
        
        if (conocido[a][b] == 1)
            printf("La persona %d conoce a la persona %d.\n\n", a, b);
        else
            printf("La persona %d NO conoce a la persona %d.\n\n", a, b);

        // Responder a la funcion.
        return conocido[a][b];
    }

    // Se detecta el error en los indices y se imprime informacion.
    if (a < 1 || n < a) puts("Error: El valor de a no esta entre 1 y n.\n");
    if (b < 1 || n < b) puts("Error: El valor de b no esta entre 1 y n.\n");
    if (a == b) puts("Error: Preguntaste por una misma persona.\n");

    return -1; // No hay respuesta para esta pregunta.
}

int main() {
    // Personas en al fiesta.
    scanf("%d", &n);

    // Quien es el chico popular.
    int popular; scanf("%d", &popular);

    // Se leen las respuestas a toda pregunta.
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &conocido[i][j]);

    if (popular == 0)
        puts("No hay un chico popular aqui.\n");
    else
        printf("El chico popular es la persona %d.\n\n", popular);

    // Llamada inicial a tu funcion.
    int tu_respuesta = BusquedaCool(n);

    // Despliega informacion sobre tu funcion.
    printf("Tu funcion retorno %d", tu_respuesta);
    printf(" y realizo %d preguntas.\n", preguntas);

    if (tu_respuesta == popular)
        puts("Has resuelto correctamente el problema!");
    else
        puts("No has logrado resolver el problema...");

    return 0;
}
