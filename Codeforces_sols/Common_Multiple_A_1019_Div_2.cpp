#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; 
		set<int> seen;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			seen.insert(num);
		}

		cout << seen.size() << endl; 
	}
}