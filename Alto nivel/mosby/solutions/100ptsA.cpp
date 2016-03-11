#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MCD(ll a, ll b){
	if(b == 0) return 0;
	return MCD(b, a % b) + (a / b);
}

int main(){
	ll a, b;
	cin >> a >> b;
	cout << MCD(a, b) << "\n";
	return 0;
}