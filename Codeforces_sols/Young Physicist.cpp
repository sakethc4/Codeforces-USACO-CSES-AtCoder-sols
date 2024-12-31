// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n; 
	vector<int> calculations(3, 0);
	int counter = 0;
	while (counter < n) {
		int x, y, z; cin >> x >> y >> z; 
		calculations[0] += x;
		calculations[1] += y;
		calculations[2] += z;
		counter += 1; 
	}

	if (calculations[0] == 0 && calculations[1] == 0 && calculations[2] == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl; 
	}
}
