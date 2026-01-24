#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
 
        vector<int> b(k);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
        }
 
        int missing = n - k;
        string output = "";
        if (missing == 0) {
            for (int i = 0; i < m; i++) {
                output += '1';
            }
            cout << output << endl;
            continue; 
        }
        else if (missing >= 2) {
            for (int i = 0; i < m; i++) {
                output += '0';
            }
            cout << output << endl;
            continue; 
        }
        else {
            int x = 1, y = 0;
            while (x < n && y < k && b[y] == x) {
                x++;
                y++;
            }
 
            for (int i = 0; i < m; i++) {
                if (a[i] == x) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }
        }
 
        cout << '\n';
    }
}