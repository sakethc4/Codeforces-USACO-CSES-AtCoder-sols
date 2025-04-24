#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t; 
    // simulate creation of a for each index pos. 
    // all we need to do then is count total 1's from simulated a.
    // count while simulating a for each character check against 1 character. 
    while(t--) {
        int cnt = 0; 
        int n; cin >> n; 
        int num; cin >> num;
        string new_num = "" + str(num);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (new_num[j] == '0') {
                    cnt++;
                }
            }
        }

        cout << cnt << endl; 
    }
}