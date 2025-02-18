#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t; 
	for (int i = 0; i < t; i++) {
		int a; cin >> a;
		int b; cin >> b;
		int c; cin >> c; 
		int x; cin >> x;
		int y; cin >> y;

		int total = x + y; 
		total -= min(x, a); 
		total -= min(y, b);
		if (total - c <= 0) {
			cout << "YES" << endl; 
		} 
		else {
			cout << "NO" << endl; 
		}
	}
}