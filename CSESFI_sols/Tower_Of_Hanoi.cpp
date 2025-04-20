#include <bits/stdc++.h>
using namespace std;

void move_disk(int n, int start, int helper, int end, vector<pair<int, int>> &moves) {
    if (n == 1) {
        moves.push_back({start, end});
        return; 
    }

    move_disk(n - 1, start, end, helper, moves);
    moves.push_back({start, end}); 
    move_disk(n - 1, helper, start, end, moves); 
}

int main() {
    int n; cin >> n; 
    vector<pair<int, int>> moves; 

    move_disk(n, 1, 2, 3, moves);
    cout << moves.size() << endl; 
    for (auto [a, b] : moves) {
        cout << a << " " << b << endl; 
    }

    return 0; 
}