#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream fin ("data.in", ifstream::in);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string tipos[4];
  char baddies[100000];
  int sp[4];
  int atc[4];
  int strat[4][100000];
  int yaesta[1000000];
  int n,k;
  bool chido = true;
  fin >> n >> k;

  for(int i = 0 ; i < 4 ; i++){
    fin >> tipos[i] >> sp[i];
    sp[i] /= k;
  }
  for(int i = 0 ; i < n ; i++){
    fin >> baddies[i];
    yaesta[i] = false;
  }
  fin.close();
  for(int i = 0 ; i < 4 ; i++){
    cin >> atc[i];
    if(atc[i] > sp[i]) chido = false;
    for(int j = 0 ; j < atc[i] ; j++){
      cin >> strat[i][j];
      if(strat[i][j] <= 0 || strat[i][j] > n)  chido = false;
      yaesta[strat[i][j]-1] = true;
    }
  }
  for(int  i = 0 ; i < n ; i++){
    chido = chido && yaesta[i];
  }
  cout << (chido? 1 : 0) << '\n';
}
