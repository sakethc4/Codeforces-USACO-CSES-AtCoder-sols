// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    string circleCrossings; cin >> circleCrossings; 
    vector<int> start(26, -1);
    vector<int> end(26, -1);
    for (int i = 0; i < circleCrossings.size(); i++) {
        if (start[circleCrossings[i]- 'A'] == -1) {
            start[circleCrossings[i] - 'A'] = i;
        }
        else {
            end[circleCrossings[i] - 'A'] = i; 
        }
    }

    int pairs = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            pairs += (start[i] < start[j] && end[i] < end[j] && start[j] < end[i]);
        }
    }

    cout << pairs << endl; 
}
