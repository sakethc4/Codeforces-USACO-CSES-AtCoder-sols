#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; 
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> cnt;
    int ans = 0, r = -1, num = 0;

    for (int l = 0; l < n; l++) {
        while (r + 1 < n && (num + (cnt[arr[r + 1]] == 0)) <= k) {
            r++;
            cnt[arr[r]]++;
            if (cnt[arr[r]] == 1) num++;
        }

        ans += (r - l + 1);

        cnt[arr[l]]--;
        if (cnt[arr[l]] == 0) num--;
    }

    cout << ans << endl;
    return 0;
}