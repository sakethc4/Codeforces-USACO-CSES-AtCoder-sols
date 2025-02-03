#include <bits/stdc++.h>
using namespace std;


int main() {
	int N; cin >> N;
	int H; cin >> H;

	int output = 0;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x; 
		if (x <= H) {
			output++; 
		}
		else {
			output += 2; 
		}
	}

	cout << output << endl; 
}
