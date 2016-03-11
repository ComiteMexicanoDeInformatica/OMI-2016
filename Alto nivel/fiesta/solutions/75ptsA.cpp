#include "fiesta.h"

#include <queue>
using namespace std;

int BusquedaCool(int n) {
    queue<int> cola;
    for (int i = 0; i < n; ++i)
        cola.push(i + 1);

    while (cola.size() > 1) {
        int a = cola.front(); cola.pop();
        int b = cola.front(); cola.pop();
        int ab = Preguntar(a, b);
        int ba = Preguntar(b, a);

        if (ab && !ba) cola.push(b);
        if (ba && !ab) cola.push(a);
    }

    int popular = cola.front();
    for (int i = 1; i <= n; ++i) {
        if (i == popular) continue;
        if (Preguntar(popular, i)) return 0;
        if (!Preguntar(i, popular)) return 0;
    }
    return popular;
}
