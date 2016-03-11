#include <cstdio>
#include <vector>

using namespace std;

const int PLAYERS=4, TYPES=7, MAXE=100, MAXEE=100000;

struct player
{
  int a;
  int k[TYPES];
};

struct state
{
  short p[PLAYERS-1];
  bool t;
}s, ns;

int enemigos, puntosSP, stamina;
int answers[PLAYERS][MAXEE], sz[PLAYERS], weak[MAXE];
short p[PLAYERS-1];
char inp[TYPES], dp[MAXE][MAXE][MAXE][MAXE];

player pList[PLAYERS+5];

int getElement(char c)
{
  switch (c)
  {
    case 'N':
      return 0;
    case 'F':
      return 1;
    case 'H':
      return 2;
    case 'A':
      return 3;
    case 'E':
      return 4;
    case 'L':
      return 5;
    case 'O':
      return 6;
  }
  return -1;
}

bool dpCheck(int i, int j, int k, int l)
{
  if(dp[i][j][k][l] || j>pList[0].a || k>pList[1].a || l>pList[2].a || i-(j+k+l)>pList[3].a)
    return false;
  if(i==enemigos)
    return true;
  dp[i][j][k][l]=1;

  if(pList[0].k[weak[i]] && dpCheck(i+1, j+1, k, l))
  {
    answers[0][sz[0]++]=i;
    return true;
  }
  if(pList[1].k[weak[i]] && dpCheck(i+1, j, k+1, l))
  {
    answers[1][sz[1]++]=i;
    return true;
  }
  if(pList[2].k[weak[i]] && dpCheck(i+1, j, k, l+1))
  {
    answers[2][sz[2]++]=i;
    return true;
  }
  if(pList[3].k[weak[i]] && dpCheck(i+1, j, k, l))
  {
    answers[3][sz[3]++]=i;
    return true;
  }
  return false;
}

int main()
{
  scanf("%d%d", &enemigos, &puntosSP);
  for(int i=0; i<PLAYERS; i++)
  {
    scanf("%s%d", inp, &stamina);
    for(int j=0; inp[j]; j++)
      pList[i].k[getElement(inp[j])]=1;
    pList[i].a=stamina/puntosSP;
  }

  for(int i=0; i<enemigos; i++)
  {
    scanf("%s", inp);
    weak[i]=getElement(inp[0]);
  }
  dpCheck(0, 0, 0, 0);
  for(int i=0; i<4; i++)
  {
    printf("%d\n", sz[i]);
    for(int j=0; j<sz[i]; j++)
      printf("%d ", answers[i][j]+1);
    printf("\n");
  }
}
