// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int start, end; 
}; 


int main() {
	int n; cin >> n; 
    vector<Cow> timings(n);
    int maxTime = 0; 
    for (Cow &x : timings) {
        cin >> x.start >> x.end;
        maxTime = max(maxTime, x.end);
    }


    // now lets try each possible combo. So ig we know up till what time 
    // we need to iterate thru so we can try excluding each cow and 
    // see how much time we can get as our output. 
    int output = 0; 
    for (int i = 0; i < n; i++) {
        int timeExplored = 0; 
        for (int t = 1; t < maxTime; t++) {
            for (int j = 0; j < n; j++) {
                if (i == j) { continue; }
                if (timings[j].start <= t && timings[j].end > t) {
                    timeExplored++;
                    break; 
                }
            }
        }

        output = max(output, timeExplored);
    }

    cout << output << endl; 

}
