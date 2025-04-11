#include <bits/stdc++.h>
using namespace std;

// cs with recursion.
// barn has M conditioners we try each one.  
// we can either choose to use or not to use current ac unit so we can use 
// a search method and then another method to see if the current ac unit works 
// for our specs and update our min_cost accordingly. 
int n, m; 
vector<array<int, 3>> cows; 
vector<array<int, 4>> air_con; 
// need to track what ac's we are using.
vector<bool> uses;
int min_cost = INT_MAX;

void update() {
    bool valid = true; 
    // check all positions (100)
    // pick a stall
    for (int i = 1; i <= 100; i++) {
        int cooling = 0;
        // pick an ac pos 
        for (int j = 0; j < m; j++) {
            if (!uses[j]) { continue; }
            auto &[a, b, p, m] = air_con[j];
            if (a <= i && i <= b) { cooling += p; }
        }
        // if we have a valid ac unit we need to figure out what the correct cow
        // to operate on is 
        int cow_req = 0;
        for (int j = 0; j < n; j++) {
            auto &[s,t,c] = cows[j]; 
            if (s <= i && i <= t) { 
                cow_req = c;
                break; 
            }
        }

        if (cooling < cow_req) {
            valid = false; 
            break; 
        }
    }

    if (valid) {
        int cost = 0; 
        for (int i = 0; i < m; i++) {
            if(uses[i]) {
                cost += air_con[i][3]; 
            }
        }

        min_cost = min(cost, min_cost);
    }
}

void search(int i) { 
    // after we build our subset we can eval so that's our base case 
    if (i == m) { 
        update();
        return; 
    }
    uses[i] = false; 
    search(i + 1); 
    uses[i] = true;
    search(i + 1);
}

int main() {
    cin >> n >> m; 
    for (int i = 0; i < n; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        cows.push_back({s, t, c});
    }

    for (int i = 0; i < m; i++) {
        int a, b, p, m; 
        cin >> a >> b >> p >> m; 
        air_con.push_back({a, b, p, m}); 
    }

    // we can assign uses with false values to start 
    uses.assign(m, false); 
    search(0);

    cout << min_cost << endl; 
}
