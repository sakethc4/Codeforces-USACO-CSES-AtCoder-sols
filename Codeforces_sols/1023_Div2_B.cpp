#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> apples(n);
        long long s = 0;  
        for (int i = 0; i < n; i++) {
            cin >> apples[i];
            s += apples[i];
        }
        // compute winner just by checking who picks the last apple 
        // assuming the max - min thing does not pick for us. 
        // Just grab from biggest pile and repeat each time
        sort(apples.begin(), apples.end());
        apples.back()--;
        sort(apples.begin(), apples.end());
        // now check for the max min conditiong
        if ((apples.back() - apples.front()) > k) {
            cout << "Jerry" << endl;
            continue; 
        }

        if (s % 2 == 0) {
            cout << "Jerry" << endl;
        }
        else {
            cout << "Tom" << endl; 
        }
    }
}