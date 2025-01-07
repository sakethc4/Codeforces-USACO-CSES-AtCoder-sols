// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<string>> identifiers(n);

	for (int i = 0; i < n; i++) {
		string name; cin >> name; 
		int len; cin >> len; 
		for (int j = 0; j < len; j++) {
			string identifier; cin >> identifier; 
			identifiers[i].push_back(identifier);
		}
	}

	int output = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int commonalities = 0; 
			for (auto &character1 : identifiers[i]) {
				for (auto &character2 : identifiers[j]) {
					if (character1 == character2) {
						commonalities++;
						break; 
					}
				}
			}

			output = max(output, commonalities);
		}
	}
	// need to add one for the last arbitrary question that gives our answer 
	cout << output + 1 << endl; 
}
