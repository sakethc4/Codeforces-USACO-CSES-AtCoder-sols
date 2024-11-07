#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

using std::vector;
// 100 pour operations untile bucket a empty or bucket b full. 
const int n = 3;
const int turn_count = 100;

int main() {
    freopen("shell.in", "r", stdin);

    vector<int> capacity(n);
    vector<int> milk(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &capacity[i], &milk[i]);
    }

    for (int i = 0; i < turn_count; i ++) {
        int bucket_one = i % n;
        int bucket_two = (i + 1) % n;

        // Now handle moving substance to another bucket. 
        int amt = min(milk[bucket_one], capacity[bucket_two] - milk[bucket_two]);

        milk[bucket_one] -= amt;
        milk[bucket_two] += amt;

    }

    freopen("shell.out", "w", stdout);
    for (int m : milk) { cout << m << '\n';}
}