#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
    while (t--) {
        int n, k, q; cin >> n >> k >> q;
        vector<int> arr(n); 
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int windowSize = 0; 
        long long output = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= q) {
                windowSize += 1;
            }
            else {
                windowSize = 0;
            }
            // just need to do 1 + (len prev elements chain) 
            if (windowSize >= k) {
                output += windowSize - k + 1;
            }
        }

        cout << output << endl; 
        }

    }