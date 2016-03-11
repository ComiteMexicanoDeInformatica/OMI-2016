#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

const int kElems = 7;
  const int kAmigos = 4;

map<char, int> elems = {{'N', 0},
              {'F', 1}, {'H', 2},
              {'A', 3}, {'E', 4},
              {'L', 5}, {'O', 6}};

char buffer[10];
string baffer;
int puntos[kAmigos];
bool visitado[kAmigos][kElems];
bool habilidad[kAmigos][kElems];
vector<int> vencidos[kAmigos][kElems];

bool Derrotar(int amigo, int elem, int ind) {
    // Checar si esta combinación ya se intentó.
    if (visitado[amigo][elem]) return false;
    visitado[amigo][elem] = true;

    // Si este amigo no tiene la habilidad para
    // este enemigo, entonces no lo puede vencer.
    if (!habilidad[amigo][elem]) return false;

    // Si aún tienes puntos de mágia, puedes
    // vencer a este enemigo de inmediato!
    if (puntos[amigo]) {
        vencidos[amigo][elem].push_back(ind);
        --puntos[amigo]; return true;
    }

    // Cambia el nuevo enemigo con uno previamente
    // vencido por este amigo, el enemigo ya vencido
    // ahora será vencido por otro amigo del grupo.
    bool vencido = false;
    for (int i = 0; i < kAmigos && !vencido; ++i) {
        if (amigo == i) continue; // Saltate a ti mismo.

        for (int j = 0; j < kElems && !vencido; ++j) {
            // Checa que exista un enemigo vencido de
            // este tipo para poder cambiarlo con el nuevo.
            if (!vencidos[amigo][j].size()) continue;

            // Recursivamente haz que alguien más
            // venza al enemigo que tu vas a cambiar.
            int cambio = vencidos[amigo][j].back();
            vencido |= Derrotar(i, j, cambio);

            if (vencido) {
                // Si el otro amigo pudo vencer al cambio,
                // entonces tu puedes vencer al nuevo enemigo.
                vencidos[amigo][j].pop_back();
                vencidos[amigo][elem].push_back(ind);
            }
        }
    }
    return vencido;
}

int main() {
    int n, k, sp;
    cin >> n >> k;

    for (int i = 0 ;  i < kAmigos ; ++i)
      for(int j = 0 ; j < kElems ; ++j)
        habilidad[i][j] = false;

    for (int i = 0; i < kAmigos; ++i) {
        cin >> baffer >> sp;
        for(char & c : baffer)
          habilidad[i][ elems[c] ]=true;
        
        puntos[i] = sp / k;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < kAmigos; ++j)
            for (int k = 0; k < kElems; ++k)
                visitado[j][k] = false;

        cin >> baffer;
        int element = elems[baffer[0]];

        bool vencido = false;
        for (int j = 0; j < kAmigos && !vencido; ++j)
            vencido |= Derrotar(j, element, i);

        if (!vencido) {
            puts("-1");
            return 0;
        }
    }

    vector<int> pertenece(n);
    for (int i = 0; i < kAmigos; ++i)
        for (int j = 0; j < kElems; ++j)
            for (int enemigo : vencidos[i][j])
                pertenece[enemigo] = i;

    for (int i = 0 ; i < kAmigos ; ++i){
      for (int j = 0 ; j < n ; ++j) 
        if(i == pertenece[j])
          cout << j + 1 << ' ';
      cout << '\n';
    }
    return 0;
}
