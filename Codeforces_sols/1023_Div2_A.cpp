#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
    while (t--) {
        int n; cin >> n; 
        vector<int> stuff(n);
        int dupes = 0;
        int prev = -1; 
        for (int i = 0; i < n; i++) {
            cin >> stuff[i];
            if (prev == stuff[i]) {
                dupes++; 
            }
            prev = stuff[i]; 
        }

        if (dupes == stuff.size() - 1) {
            cout << "NO" << endl; 
        }
        else { 
            cout << "YES" << endl;
            vector<int> output(n, 1); 
            int max = *max_element(stuff.begin(), stuff.end());
            for (int i = 0; i < n; i++) {
                if (stuff[i] == max) {
                    output[i] = 2;
                    break;  
                }
            }
            for (auto x : output) {
                cout << x << " ";
            }
            cout << "\n";
         }
    }
}
