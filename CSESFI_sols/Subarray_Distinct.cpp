#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> arr, ll N, ll K)
{

    ll left = 0, right = 0;
    ll distinct_count = 0;
    ll result = 0;

    unordered_map<ll, ll> frequency;

    while (right < N) {
        if (frequency.find(arr[right]) == frequency.end()
            || frequency[arr[right]] == 0)
            distinct_count++;

        frequency[arr[right]]++;

        while (distinct_count > K) {
            frequency[arr[left]]--;
            if (frequency[arr[left]] == 0)
                distinct_count--;
            left++;
        }

        result += right - left + 1;

        right++;
    }

    return result;
}

int main()
{
    ll N; cin >> N;
    ll K; cin >> K;
    vector<ll> arr(N);
    for (ll i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << solve(arr, N, K) << "\n";

    return 0;
}