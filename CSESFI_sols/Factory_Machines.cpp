#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Check if we can produce at least 'T' products in 'mid' time
bool check(ll mid, ll N, ll T, const vector<ll>& K) {
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
        sum += mid / K[i];
        if (sum >= T) return true; // early stopping
    }
    return false;
}

// Binary search to find the minimum time to make at least 'T' products
ll solve(ll N, ll T, const vector<ll>& K) {
    ll low = 1;
    ll high = *min_element(K.begin(), K.end()) * T; // upper bound
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid, N, T, K)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    ll N, T;
    cin >> N >> T;

    vector<ll> K(N);
    for (ll i = 0; i < N; i++) {
        cin >> K[i];
    }

    cout << solve(N, T, K) << '\n';
}
