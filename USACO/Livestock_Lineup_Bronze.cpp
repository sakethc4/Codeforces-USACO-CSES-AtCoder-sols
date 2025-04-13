#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; 
    vector<pair<string, string>> restrictions;
    // for input we need to handle garbage values (useless strings in between)
    for (int i = 0; i < n; i++) {
        string a, x, b; 
        cin >> a; 
        cin >> x >> x >> x >> x;
        cin >> b; 
        restrictions.push_back({a, b}); 
    } 
    // we need cows sorted when calling next_perm so we can just hardcode 
    // the vector so that it has the cows in lexogrpahical order 
    vector<string> cows = {
        "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", 
        "Buttercup", "Sue"
    };

    int count = 0;
    while (next_permutation(cows.begin(), cows.end())) {
        bool valid = true;
        // need to compare a's index with b's index in the 
        // current perm to determine if its valid. 
        for (auto p : restrictions) {
            string cow1 = p.first; 
            string cow2 = p.second;
            auto a = find(cows.begin(), cows.end(), cow1);
            auto b = find(cows.begin(), cows.end(), cow2);
            if (abs(a - b) != 1) { 
                valid = false; 
            } 
        }

        if (valid) {
            break; 
        }
    }

    for (auto c : cows) { 
        cout << c << endl; 
    }
}