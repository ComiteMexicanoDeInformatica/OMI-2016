#include "fiesta.h"

int BusquedaCool(int n) {

    int guyA=1, guyB=2, next=2, cand;

    while(next<=n)
    {
        if(Preguntar(guyA, guyB))
            guyA=++next;
        else
            guyB=++next;
    }

    cand=guyA+guyB-next;
    
    for(int i=1; i<=n; i++)
        if(i!=cand && (Preguntar(cand, i) || !Preguntar(i, cand)))
            return 0;

    return cand;
}
