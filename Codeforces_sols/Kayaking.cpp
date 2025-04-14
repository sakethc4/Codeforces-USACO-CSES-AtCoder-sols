#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
    n *= 2;
    vector<int> weights(n);
    for (int &p : weights) { cin >> p; }
    sort(weights.begin(), weights.end());

    int min_inst = INT_MAX;
    // we can select one person to be on single with i and our second person to be on single with j 
    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> tandems;
            for (int p = 0; p < n; p++) {
                if (p != i && p != j) {
                    tandems.push_back(weights[p]);
                }
            }
            int total_inst = 0;
            for (int p = 0; p < n - 2; p+=2) {
                total_inst += tandems[p + 1] - tandems[p];
            }

            min_inst = min(min_inst, total_inst);
        }
    }

    cout << min_inst << endl; 

}