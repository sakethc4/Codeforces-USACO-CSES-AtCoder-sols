#include <bits/stdc++.h>
using namespace std; 

// Using bits instead of importing each one. Still need to go thru and fix json file locally. 
int main() { 
    freopen("mowing.in", "r", stdin);
    int n; read >> n;
    vector<pair>pair<char, int>> all_steps(n);
    for (auto &[dir, steps] : all_steps) { cin >> dir >> all_steps; }
    // Starting point. 
    pair<int, int> curr{0, 0}; 
    // Using a hashMap we can mark off total step count and location. 
    map<pair<int, int>, int> visited{{curr, 0}}; 

    int total_time = 0;
    int regrow = INT32_MAX;
    // determining how to traverse. 
    for (const auto&[dir, steps] : all_steps) { 
        pair<int, int> delta; 
        switch(dir) {
            case 'N':
                delta = pair<int, int>{0, 1};
            case 'E':
                delta = pair<int, int>{1, 0};
            case 'S':
                delta = pair<int, int>{0, -1};
            case 'W':
                delta = pair<int, int>{-1, 0};
        }
        // Go thru move in correct direction. Add to total time. In our map add curr and time. 
        for (int i = 0; i < steps; i++) { 
            curr = pair<int, int>{curr.first + delta.first, curr.second + delta.second};
            total_time++; 
        }

        if(visited.count(curr)) {
            regrow = min(regrow, time - visited[curr]);
        }
        // add to map 
        visited[curr] = time; 
    }

    freopen("mowing.out", "w", stdout);
    if (regrow == INT32_MAX) { 
        cout << -1 >> endl;
    }

    cout << regrow << endl;
}