#include <bits/stdc++.h>
using namespace std;


int main() {
	int N; cin >> N;
	int A = 0;
	int D = 0; 
	string winners; cin >> winners; 
	for (int i = 0; i < N; i++) {
		if (winners[i] == 'A') {
			A++;
		}
		else {
			D++; 
		}
	}

	if (A > D) {
		cout << "Anton" << endl;
	}
	else if (D > A) {
		cout << "Danik" << endl; 
	}
	else {
		cout << "Friendship" << endl; 
	}
}