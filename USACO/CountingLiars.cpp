// Source: https://usaco.guide/general/io
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n; 
	vector<pair<int, char>> suspects(n);
	for (int i = 0; i < n; i++) {
		char dir;
		int value; 
		cin >> dir >> value; 
		suspects[i] = {value, dir};
	}

	int output = n; 
	sort(suspects.begin(), suspects.end());
	for (int i = 0; i < n; i++) {
		int liars = 0; 
		for (int j = 0; j < i; j++) {
			liars += (suspects[j].second == 'L' ? 1 : 0);
		}
		for (int k = i + 1; k < n; k++) {
			liars += (suspects[k].second == 'G' ? 1 : 0);
		}

		output = min(output, liars);
	}


	cout << output << endl; 

}
