#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        map<int, int> occurences;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            occurences[x]++;
        }
        // all frequencies for each num. 
        // trying to get rid of convert least frequent stuff 
        // to same num as most frequent (as many nums as we can
        // with the given k value). 
        vector<int> frequency(n);
        for (auto& [a, b] : occurences) {
            frequency.push_back(b);
        }

        sort(frequency.begin(), frequency.end());
        int output = frequency.size();
        // need to leave one group (last one or biggest one)
        for (int i = 0; i < frequency.size() - 1; i++) {
            if (k >= frequency[i]) {
                k -= frequency[i];
                output -= 1; 
            }
        }
        
        cout << output << endl; 
    }
}