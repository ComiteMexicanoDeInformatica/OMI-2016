#include<iostream>
#include<cassert>
using namespace std;

const int MAXN=200;
int N,K;
string tipos[4];
int sp[4];
char enemigos[MAXN];
int cuenta[4];
int solucion[MAXN];

bool buscarSolucion(int p){
  if(p == N){
    for(int i = 0 ; i < 4; i++){
      if(cuenta[i]*K > sp[i]) return false;
    }
    int l , pers;
    for(int i = 0 ; i <  N ; i++){
      pers = solucion[i];
      l = tipos[pers].length();
      bool bueno = false;
      for(int j = 0 ; j < l ; j++){
        if(tipos[pers][j] == enemigos[i]){
          bueno = true;
          break;
        }
      }
      if(!bueno) return false;
    }
    return true;
  }
  int l;
  bool posible;
  for(int  i = 0 ; i < 4 ; i ++){
    solucion[p] = i;
    cuenta[i]++;
    posible = buscarSolucion(p+1);
    if(posible) return true;
    cuenta[i]--;
    solucion[p] = -1;
  }
  return false;
}

int main(){
  cin >> N >> K;
  for(int i = 0 ; i < 4 ; i++){
    cin >> tipos[i] >> sp[i];
    cuenta[i] = 0;
  }

  for(int i = 0 ; i < N ; i++){
    cin >> enemigos[i];
    solucion[i] = -1;
  }
  assert(buscarSolucion(0));
  for(int i = 0 ; i < 4 ; i++){
    cout << cuenta[i] << '\n';
    for(int  j= 0 ;j  < N; j++){
      if(solucion[j] ==i){
        cout << j + 1<< ' ';
      }
    }
    cout << '\n';
  }
}
