/* 
 * File:   main.cpp
 * Author: Luis
 *
 * Created on 26 de febrero de 2016, 06:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <map>
using namespace std;

map<char,int> elems = {{'N',0},
  {'F',1}, {'H',2}, {'A',3},
  {'E',4}, {'L',5}, {'O',6}};

vector<int> wat;
int Counter = 0;
int EdgesMask = 0;
int BIT_COUNT[(1<<7)];
int *HP;
int *SP;
int E[11];
int Attrib[11];
int Ataque[4][7];

int getEdgeNumber(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    assert(a < 4 && b >= 4);
    return a * 7 + (b - 4);
}

int cuentaBits(int n) {
    int ret = 0;
    while (n > 0) {
        if (n & 1) {
            ret++;
        }
        n >>= 1;
    }
    return ret;
}
void computeBitCount(){
    for(int i=0;i<(1<<7);i++){
        BIT_COUNT[i]=cuentaBits(i);
    }
}

int heroesDisponibles(int mask){
    int ocupados=BIT_COUNT[mask&(15)];
    return 4-ocupados;
}
int monstruosDisponibles(int mask){
    int ocupados=BIT_COUNT[mask>>4];
    return 7-ocupados;
}
bool duelo(int hoja, int otro){
    int heroe;
    int monstruo;
    if(hoja<4){
        heroe=hoja;
        monstruo=otro-4;
    }else{
        heroe=otro;
        monstruo=hoja-4;        
        if(HP[monstruo]>SP[heroe]){
            return false;
        }
    }
    if (SP[heroe] >= HP[monstruo]) {
        Ataque[heroe][monstruo]+=HP[monstruo];
        SP[heroe] -= HP[monstruo];
        HP[monstruo] = 0;
    } else {
        Ataque[heroe][monstruo]+=SP[heroe];
        HP[monstruo] -= SP[heroe];
        SP[heroe] = 0;
    }
    return true;    
}

void imprimeSolucion(){
    int N = wat.size();
    vector<int> things[4];
    for(int j = 0 ; j < N ; j++){
      for(int i = 0 ; i < 4 ; i++){
        if (Ataque[i][wat[j]]){
          Ataque[i][wat[j]]--;
          things[i].push_back(j);
          break;
        }
      }
    }
    for(int i = 0 ; i < 4 ; i ++){
      int M = things[i].size();
      cout << M << '\n';
      for(int j  = 0 ; j < M; j ++){
        cout << things[i][j] + 1<< ' ';
      }
      cout << '\n';
    }
}

void buscaSolucion(int mask, int v, int n) {
  if(Counter) return;
    if (n == 11) {
        if (mask == ((1 << 11) - 1)) {
            imprimeSolucion();
            Counter++;
        }
        return;
    }
    int nextv;
    int nextn;
    nextv = n + 1;
    nextn = n + 1;
    if (nextn != 11 || mask == 1023) {
        //Si v tiene grado 0
        if (v == n) {
            if(v<4 || HP[v-4]==0){
                buscaSolucion(mask | (1 << v), nextv, nextn);
            }
        }
    }
    
    //Si v tiene grado mayor que 0 checa que haya nodos disponibles
    int disp;
    if (v < 4) { //Si es heroe
        disp = monstruosDisponibles(mask);
        if(disp==0){
            return;
        }
    } else {
        disp = heroesDisponibles(mask);
        if(disp==0){
            return;
        }
    }
    
    //Si v tiene grado mayor que 1    
    if (nextn != 11) {
        if (disp>1) {
            if(v<4){ //Si es heroe
                buscaSolucion(mask, nextv, nextn);
            }else{
                buscaSolucion(mask, nextv, nextn);
            }
        }
    }
    //Si v si es hoja
    int startIndex;
    int endIndex;
    if (v < 4) {
        startIndex = 4;
        endIndex = 10;
    } else {
        startIndex = 0;
        endIndex = 3;
    }
    int hp, sp;
    mask|=(1<<v);
    int vecinos=E[v];
    int at1=Attrib[v];
    if(endIndex<n || (nextn == 11 && mask != 2047) ){
        if(endIndex>=n){
            endIndex=n-1;
        }
        for (int i = startIndex; i <= endIndex; i++) {
            if ((mask & (1 << i)) == 0 && (vecinos&(1<<i))!=0) {
                int at2=Attrib[i];
                int lastAtaque;
                if(v<4){
                    lastAtaque=Ataque[v][i-4];
                }else{
                    lastAtaque=Ataque[i][v-4];
                }                
                if(duelo(v, i)){
                    buscaSolucion(mask, i, n);
                    if(v<4){
                        Ataque[v][i-4]=lastAtaque;
                    }else{
                        Ataque[i][v-4]=lastAtaque;
                    }                    
                }
                Attrib[v]=at1;
                Attrib[i]=at2;
            }
        }
    }else{
        for (int i = startIndex; i <= endIndex; i++) {
            if ((mask & (1 << i)) == 0 && (vecinos&(1<<i))!=0) {
                int at2=Attrib[i];
                int lastAtaque;
                if (v < 4) {
                    lastAtaque = Ataque[v][i - 4];
                } else {
                    lastAtaque = Ataque[i][v - 4];
                }
                if (i >= n) {
                    if (nextn != 11 || mask == 2047) {
                        if(duelo(v, i)){
                            buscaSolucion(mask, nextv, nextn);
                            if (v < 4) {
                                Ataque[v][i - 4] = lastAtaque;
                            } else {
                                Ataque[i][v - 4] = lastAtaque;
                            }                            
                        }
                    }
                } else {
                    if(duelo(v, i)){
                        buscaSolucion(mask, i, n);
                        if (v < 4) {
                            Ataque[v][i - 4] = lastAtaque;
                        } else {
                            Ataque[i][v - 4] = lastAtaque;
                        }                        
                    }
                }
                Attrib[v]=at1;
                Attrib[i]=at2;
            }
        }
    }
}

/*
 * 
 */

void test1(){
    int N, K, sp;
    string baffer;
    cin >> N >> K;
    for(int i=0;i<4;i++){
        E[i]=0;
        cin >> baffer >> sp;
        for(int k = 0 ; k < baffer.length(); k++)
          E[i] |= (1 << (4 + elems[baffer[k]]));
        SP[i]=sp/K;
    }
    for(int i  = 0 ; i < 7 ; i++) HP[i] = 0;
    for(int i = 0 ; i< N ; i++){
      cin >> baffer;
      HP[elems[baffer[0]]]++;
      wat.push_back(elems[baffer[0]]);
    }

    for(int i=0;i<4;i++)
    for (int k = 4; k < 11; k++) {
        if (E[i]&(1 << k)) {
            E[k] |= (1 << i);
        }
    }
    for(int i = 0 ; i < 4 ; i ++) for(int j = 0 ; j < 7 ; j ++) Ataque[i][j] = 0;
    buscaSolucion(0, 0, 0);
}


int main(int argc, char** argv) {
    computeBitCount();
    HP=&Attrib[4];
    SP=&Attrib[0];
    test1();
    return 0;
}

