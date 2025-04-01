#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t; 
    vector<int> stuff(t);
    for (int i = 0; i < t; i++) {
        int q, num; cin >> q >> num;  
        if (q == 1) {
            stuff.push_back(num);
        }
        else {
            cout << stuff[stuff.size() - num] << endl;
        }
    }
}