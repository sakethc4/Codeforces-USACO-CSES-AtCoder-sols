#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int seats; cin >> seats;
		int total = 0;
		int remainder = 0; 
		int a; cin >> a;
		total += min(seats, a);
		remainder += seats - min(seats, a);
		int b; cin >> b;
		total += min(seats, b);
		remainder += seats - min(seats, b);
		int c; cin >> c; 
		total += min(remainder, c);
		cout << total << endl;
	}
}