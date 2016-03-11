#include "pesca.h"
#include <algorithm>

using namespace std;

const int BlockSize=2;

void Pescar(int w, int h, int n, int k) 
{
  for(int i=0; i<=w; i+=BlockSize)
    for(int j=0; j<=h; j+=BlockSize)
    {
      int x1=i, y1=j;
      int x2=min(x1+BlockSize, w), y2=min(y1+BlockSize, h);
      if(k--<=0 || UsarApp(x1, y1, x2, y2))
        for(int k=x1; k<x2; k++)
          for(int l=y1; l<y2; l++)
            TirarRed(k, l, k+1, l+1);
    }
}
