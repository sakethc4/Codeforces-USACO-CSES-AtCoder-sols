// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int index(const vector<int> &vec, const int &n) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == n) { return i; }
	}

	return -1; 
}

int main() {
	int sessions, cows; cin >> sessions >> cows; 
	vector<vector<int>> indivSessions(sessions, vector<int> (cows));
	for (int i = 0; i < sessions; i++) {
		for (int c = 0; c < cows; c++) {
			cin >> indivSessions[i][c];
			indivSessions[i][c]--; 
		}
	}
	int consistentPairs = 0; 
	for (int c1 = 0; c1 < cows; c1++) {
		for (int c2 = 0; c2 < cows; c2++) {
			if (c1 == c2) { continue; }
			bool valid = true; 
			for (const vector<int> &s : indivSessions) {
				if (index(s, c1) < index(s, c2)) {
					valid = false; 
					break; 
				}
			}

			consistentPairs += valid; 
		}
	}

	cout << consistentPairs << endl; 
}
