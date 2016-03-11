#include<iostream>
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
    return true;
  }
  int l;
  bool possible;
  for(int i = 0; i < 4 ;i++){
    if(sp[i] >= K){
      l = tipos[i].length();
      for(int j = 0 ; j < l ; j++){
        if(tipos[i][j] == enemigos[p]){
          solucion[p] = i;
          sp[i] -= K;
          cuenta[i]++;
          possible = buscarSolucion(p+1);
          if(possible) return true;
          cuenta[i]--;
          sp[i] += K;
          solucion[p] = -1;
          break;
        }
      }
    }
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
  buscarSolucion(0);
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
