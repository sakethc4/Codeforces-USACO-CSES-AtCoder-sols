#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int output = 0; 
        // 1 - 2, 2 - 1 => 2 
        // 1 - 3, 2 - 2, 3 - 1 => 4
        for (int i = 1, j = n; i <= n; i++, j--) {
            output += abs(i - j);
        }

        cout << (output / 2) + 1 << endl; 
    }
}
