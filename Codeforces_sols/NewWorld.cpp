#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int k; cin >> k;
        int p; cin >> p;
        k = abs(k);
        int currSum = 0;
        int ops = 0;
        for (int i = 0; i < n; i++) {
            int whatWeNeed = k - currSum;
            if (currSum >= k) {
                break; 
            }
            currSum += min(p, whatWeNeed);
            ops++;
        }

        if (currSum >= k) {
            cout << ops << endl;
        }
        else {
            cout << -1 << endl; 
        }
    }
}


