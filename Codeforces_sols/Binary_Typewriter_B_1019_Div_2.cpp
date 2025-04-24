#include <bits/stdc++.h>
using namespace std;

// 100 -> 001 
// casework here -> If we switch to we don't have to do two swaps. We only have to do 
// one swap at the end. 
// So we can deduce: if we have original changes of 2 we can reduce by 1. 
// If we have original changes of 1 or 0 nothing. 010 or 011 we only swap once. 
// 1101010010011011100 -> 12

int main() {
	int t; cin >> t;
	while (t--) {
		// simulate cost for each iteration 
		int n; cin >> n;
		string stuff; cin >> stuff; 
		stuff = "0" + stuff;
		int swaps = 0; 
		int cur = stuff[0];
		for (int i = 1; i <= n; i++) {
			int look_ahead = stuff[i];
			if (cur != look_ahead) {
				swaps ++;
			}
			cur = look_ahead;
		}

		if (swaps == 2) {
			cout << swaps - 1 + n << endl; 
		}
		else if (swaps >= 3) {
			cout << swaps - 2 + n << endl; 
		}
		else {
			cout << swaps + n << endl; 
		}
	}
}