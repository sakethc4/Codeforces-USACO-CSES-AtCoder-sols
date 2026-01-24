#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if (a == 1 || b == 1) {
            cout << "NO" << endl;
        }
        else if (a == 2 && b == 2) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl; 
        }
    }
}