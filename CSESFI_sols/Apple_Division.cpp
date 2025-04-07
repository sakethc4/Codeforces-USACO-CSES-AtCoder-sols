#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n; 
vector<ll> weights; 
ll generate_groupings(int index, ll sum1, ll sum2) {
    if (index == n) {
        return abs(sum1 - sum2); 
    }

    // we want both sums to be reasonably close together so everytime we encounter a new number we want 
    // to allocate to the smaller number. 
    return min(generate_groupings(index + 1, sum1 + weights[index], sum2), 
    generate_groupings(index + 1, sum1, sum2 + weights[index]));
}

int main() {
    cin >> n;
    weights.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }


    cout << generate_groupings(0, 0, 0) << endl;
}
