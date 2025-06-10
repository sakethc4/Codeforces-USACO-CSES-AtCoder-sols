#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; 
		string a; cin >> a;
		string b; cin >> b;
		vector<int> stuff(n, 1);
		int prev = 0;  
		for (int i = 0; i < n; i++) {
			if (a[i] == '1') {
				if (i != 0) {
					if (a[prev] == '1' && b[i] == '0') {
						stuff[prev] = 0; 
					}
					else if (b[prev] == '0' && a[i] == '1') {
						stuff[i] = 0; 
					}
				}
			}
		}
		bool flag = false; 
		for (int i = 0; i < n; i++) {
			if (stuff[i] == 1) {
				flag = true; 
			}
		}

		if (flag) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl; 
		}
	}
}