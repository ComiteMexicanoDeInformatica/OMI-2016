/* 
 * File:   Generador.cpp
 * Author: Luis
 *
 * Created on 2 de marzo de 2016, 10:38 PM
 */

#include <cstdlib>
#include <algorithm>
#include<vector>
#include <iostream>
#include<string>
#include <cstring>
using namespace std;

int Aristas[4][7];
int IndicesHeroes[4];
int IndicesMonstruos[7];
int X, Y, N;
char enemigos[1000000];
char tipos[] = "NFHAELO";
int HP[7];
int SP[4];

int randomInRange(int a, int b){
    return a+rand()%(b-a);
}

void generaCasoSmall(int minN, int maxN){
  N = randomInRange(minN, maxN);
  int K = randomInRange(1,100);
  string abil[4];
  for(int i = 0 ; i < 4 ; i++) SP[i] = 0;
  int aux, aux2;
  for(int i = 0 ; i < 7 ; i++){
    aux = randomInRange(1,16);
    for(int j = 0 ; j < 4 ; j++){
      if(aux & (1<<j)){
        abil[j].push_back(tipos[i]);
      }
    }
  }
  for(int i = 0 ; i < 4 ; i++){
    aux = randomInRange(0,7);
    if(abil[i].length() == 0){
      abil[i].push_back(tipos[aux]);
      sort(abil[i].begin(),abil[i].end());
    }
  }
  for(int i = 0 ; i < N ; i++){
    aux = randomInRange(0,4);
    aux2 = randomInRange(0,abil[aux].length());
    enemigos[i] = abil[aux][aux2];
    SP[aux]++;
  }
  for(int i = 0 ; i < 4 ; i++){
    aux = randomInRange(0,K);
    aux2 = randomInRange(0,N/7);
    SP[i]+=aux2;
    SP[i] = SP[i]*K + aux;
  }

  printf("%d %d\n",N,K);
  for(int i = 0 ; i < 4 ; i++){
    printf("%s %d\n", abil[i].c_str(), SP[i]);
  }
  for(int i = 0 ; i < N ; i++){
    printf("%c\n", enemigos[i]);
  }
}

void generaCasoBig(int nmin=100000, int nmax=101000){
    for(int i=0;i<4;i++){
        IndicesHeroes[i]=i;
    }
    random_shuffle(IndicesHeroes, IndicesHeroes+4);
    for(int i=0;i<7;i++){
        IndicesMonstruos[i]=i;
    }
    int *M=&IndicesMonstruos[0];
    random_shuffle(IndicesMonstruos, IndicesMonstruos+7);
    int a=IndicesHeroes[0];
    int b=IndicesHeroes[1];
    int c=IndicesHeroes[2];
    int d=IndicesHeroes[3];
    Aristas[a][M[0]]=1;
    Aristas[a][M[1]]=1;
    Aristas[a][M[2]]=1;
    Aristas[a][M[3]]=1;
    Aristas[d][M[1]]=1;
    Aristas[d][M[2]]=1;
    Aristas[d][M[3]]=1;
    Aristas[d][M[6]]=1;
    N = randomInRange(nmin, nmax);
    do{
        X=rand()%N;
        Y=N-X;
    }while(!(Y*2>X && X>3 && 2*X>Y && 3*((Y-6)-2)>X));
    do{
        SP[a]=rand()%X;
        SP[d]=X-SP[a];
        if(SP[a]<SP[d]){
            swap(SP[a], SP[d]);
        }
    }while(!(SP[a]>2*SP[d] && 3*SP[a]>Y && Y>SP[d]*2 && Y<SP[a]*2));
    do{
        int hp[3];
        HP[M[0]]=randomInRange(X/3+2, Y-6);
    if(HP[M[0]]>SP[d]){
      hp[0]=randomInRange(SP[d], min(X-1-SP[d], HP[M[0]]));
      hp[1]=randomInRange(SP[d], min(X-hp[0], HP[M[0]]));
      hp[2]=X-hp[0]-hp[1];
      sort(hp, hp+3);
      reverse(hp, hp+3);
      for(int i=0;i<3;i++){
        HP[M[i+1]]=hp[i];
      }
    }
    }while(!(Y>HP[M[1]] && HP[M[0]]>HP[M[1]] && 3*HP[M[3]]-6>Y-HP[M[0]]));
    do{
        int hp[3];
        hp[0]=randomInRange(1, min(HP[M[3]], Y-HP[M[0]]-1 ));
        hp[1]=randomInRange(1, min(HP[M[3]], Y-HP[M[0]]-hp[0] ));
        hp[2]=Y-HP[M[0]]-hp[0]-hp[1];
        sort(hp, hp+3);
        reverse(hp, hp+3);
        for(int i=0;i<3;i++){
            HP[M[4+i]]=hp[i];
        }
    }while(!(HP[M[4]]<HP[M[3]]) );
    do{
        SP[b]=randomInRange(1, Y);
        SP[c]=Y-SP[b];
        if(SP[b]<SP[c]){
            swap(SP[b], SP[c]);
        }
    }while(SP[b]>SP[a] || SP[c]<SP[d]);
    bool pasable;
    do{
        int mask1=rand()%16;
        int mask2=rand()%16;
        int hp[4], sp[2];
        int mask[2];
        mask[0]=mask1;
        mask[1]=mask2;
        hp[0]=HP[M[0]];
        hp[1]=HP[M[4]];
        hp[2]=HP[M[5]];
        hp[3]=HP[M[6]];
        sp[0]=SP[b];
        sp[1]=SP[c];
        for(int k=0;k<2;k++){
            for(int i=0;i<4;i++){
                if(mask[k]&(1<<i)){
                    if(sp[k]>=hp[i]){
                        sp[k]-=hp[i];
                        hp[i]=0;                    
                    }else{
                        hp[i]-=sp[k];                    
                        sp[k]=0;                    
                    }
                }
            }
        }
        pasable=true;
        for(int i=0;i<4;i++){
            if(hp[i]>0){
                pasable=false;
            }
        }
        if(pasable){
            if(mask1&(1<<0)){
                Aristas[b][M[0]]=true;
            }
            if(mask1&(1<<1)){
                Aristas[b][M[4]]=true;                
            }
            if(mask1&(1<<2)){
                Aristas[b][M[5]]=true;                
            }
            if(mask1&(1<<3)){
                Aristas[b][M[6]]=true;                
            }
            if(mask2&(1<<0)){
                Aristas[c][M[0]]=true;
            }
            if(mask2&(1<<1)){
                Aristas[c][M[4]]=true;                
            }
            if(mask2&(1<<2)){
                Aristas[c][M[5]]=true;                
            }
            if(mask2&(1<<3)){
                Aristas[c][M[6]]=true;                
            }

        }
    }while(!pasable);
    for(int i=4;i<=5;i++){
        if(rand()%2){
            Aristas[a][M[i]]=true;
        }
        if(rand()%2){
            Aristas[d][M[i]]=true;
        }
    }
    if(rand()%2){
        Aristas[a][M[6]]=true;
    }
    if(rand()%2){
        Aristas[d][M[0]]=true;
    }
    int K =randomInRange(1,100);
    printf("%d %d\n", N, K);
    for(int i=0;i<4;i++){
        for(int k=0;k<7;k++){
          if(Aristas[i][k])
            printf("%c", tipos[k]);
        }
        SP[i] = SP[i]*K+randomInRange(0,K);
        printf(" %d", SP[i]);
        printf("\n");
    }
    int aux=0;
    for(int i=0;i<7;i++){
      for(int j = 0; j < HP[i]; j ++)
        enemigos[aux++] = tipos[i];
    }
    random_shuffle(enemigos, enemigos + N);
    for(int i = 0 ; i < N ; i++){
        printf("%c\n", enemigos[i]);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    // Tiny 
    for(int i=0;i<10;i++){
        string str = "tiny." + to_string(i) + ".in";
        freopen (str.c_str(),"w",stdout);
        memset(Aristas, 0, sizeof(Aristas));
        srand(i);
        generaCasoSmall(8,12);
        fclose(stdout);
        string op = ("./sol < tiny." + to_string(i) + ".in > tiny." + to_string(i) + ".out" );
        system(op.c_str());
    }
    // Small 
    for(int i=0;i<10;i++){
        string str = "small." + to_string(i) + ".in";
        freopen (str.c_str(),"w",stdout);
        memset(Aristas, 0, sizeof(Aristas));
        srand(i);
        generaCasoSmall(40,50);
        fclose(stdout);
        string op = ("./sol < small." + to_string(i) + ".in > small." + to_string(i) + ".out" );
        system(op.c_str());
    }
    // Medium cases
    for(int i=0;i<10;i++){
        string str = "medium." + to_string(i) + ".in";
        freopen (str.c_str(),"w",stdout);
        memset(Aristas, 0, sizeof(Aristas));
        srand(i);
        generaCasoBig(80,100);
        fclose(stdout);
        string op = ("./sol < medium." + to_string(i) + ".in > medium." + to_string(i) + ".out" );
        system(op.c_str());
    }
    // Big cases
    for(int i=0;i<10;i++){
        string str = "big." + to_string(i) + ".in";
        freopen (str.c_str(),"w",stdout);
        memset(Aristas, 0, sizeof(Aristas));
        srand(i);
        generaCasoBig(40000,50000);
        fclose(stdout);
        string op = ("./sol < big." + to_string(i) + ".in > big." + to_string(i) + ".out" );
        system(op.c_str());
    }
    return 0;
}

