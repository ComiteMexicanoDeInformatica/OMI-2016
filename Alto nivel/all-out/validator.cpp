#include <iostream>
#include <fstream>

using namespace std;

char baddies[100000];
int sp[4];
int atc[4];
int strat[4][100000];
bool yaesta[1000000];

int validate() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string tipos[4];
	int n, k;
	try {
		{
			ifstream fin("data.in", ifstream::in);
			fin >> n >> k;

			for (int i = 0; i < 4; i++){
				fin >> tipos[i] >> sp[i];
				sp[i] /= k;
			}
			for (int i = 0; i < n; i++){
				fin >> baddies[i];
			}
		}
		for (int i = 0; i < 4; i++){
			if (!(cin >> atc[i])) return 0;
			if (atc[i] > sp[i]) return 0;
			for (int j = 0; j < atc[i]; j++){
				if (!(cin >> strat[i][j])) return 0;
				if (strat[i][j] <= 0 || strat[i][j] > n) return 0;
				yaesta[strat[i][j] - 1] = true;
			}
		}
		for (int i = 0; i < n; i++){
			if (!yaesta[i]) return 0;
		}
	} catch (...) {
		return 0;
	}
	return 1;
}

int main() {
	cout << validate() << endl;
}
