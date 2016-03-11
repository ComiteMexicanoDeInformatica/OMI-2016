#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b;
	cin >> a >> b;
	if(a < b) swap(a,b);
	long long respuesta = 0;
	while(b != 0){
        respuesta++;
        a = a - b;
        if(a < b) swap(a,b);
	}
	cout << respuesta << "\n";
	return 0;
}