#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m; cin >> n >> m;
	long long a; cin >> a;
	long long output = ((n + a - 1) / a) * ((m + a - 1) / a);
	cout << output << endl; 
}