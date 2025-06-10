#include <bits/stdc++.h>
using namespace std;

int main {
	int t; cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		ac_min = min(a, c);
		bd_min = min(b, d);

		if (bc_min <= ac_min) {
			cout << "Gellyfish" << endl;
		}
		else {
			cout << "Flower" << endl; 
		}
	}		
}