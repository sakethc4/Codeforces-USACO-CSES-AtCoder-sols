#include <bits/stdc++.h>
using namespace std;
// memorized recursion. 
map<long long, long long> m; 
long long f(long long n) {
    if (n == 1) {
        return 0; 
    }
    if (m.count(n)) { 
        return m[n]; 
    }

    return m[n] = f(floor(n / 2.0)) + f(ceil(n / 2.0)) + n; 
}

int main () {
    long long n; 
    cin >> n; 
    cout << f(n) << endl; 
}