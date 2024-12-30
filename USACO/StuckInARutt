// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x, y; 
    int index; 
};

int main() {
	int n; cin >> n;
    vector<Cow> nCows;
    vector<Cow> eCows; 

    for (int i = 0; i < n; i++) {
        char dir;
        int x; 
        int y; 
        cin >> dir; 
        cin >> x >> y; 
        if (dir == 'E') {
            eCows.push_back({x, y, i});
        } else if (dir == 'N') {
            nCows.push_back({x, y, i});
        }
    }

    sort(nCows.begin(), nCows.end(), [&](const Cow &c1, const Cow &c2) { return c1.x < c2.x; });
    sort(eCows.begin(), eCows.end(), [&](const Cow &c1, const Cow &c2) { return c1.y < c2.y; });

    vector<int> stopPos(n, -1); 
    for (const Cow &ncow : nCows) {
        for (const Cow &ecow : eCows) {
            if (ncow.x > ecow.x && ncow.y < ecow.y) {
                int nTrav = ecow.y - ncow.y;
                int eTrav = ncow.x - ecow.x; 

                if (nTrav < eTrav && stopPos[ecow.index] == -1) {
                    stopPos[ecow.index] = ncow.x;
                }

                if (nTrav > eTrav && stopPos[ncow.index] == -1) {
                    stopPos[ncow.index] = ecow.y;
                    break; 
                }
            }
        }
    }

    vector<int> dist(n, -1);
    for (const Cow &nc : nCows) {
        if (stopPos[nc.index] != -1) {
            dist[nc.index] = stopPos[nc.index] - nc.y;
        }
    }

    for (const Cow &ec : eCows) {
        if (stopPos[ec.index] != -1) {
            dist[ec.index] = stopPos[ec.index] - ec.x;
        }
    }

    for (auto const d : dist) { cout << (d == -1 ? "Infinity" : to_string(d)) << '\n'; }

}
