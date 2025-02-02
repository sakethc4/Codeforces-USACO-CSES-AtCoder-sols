// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n; 
	vector<int> x (n);
	vector<int> y (n); 
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	int output = 0; 
	// pick starting coordinate 
	for (int i = 0; i < n; i++) {
		// pick second point 
		for (int j = 0; j < n; j++) {
			// pick third point 
			for (int k = 0; k < n; k++) {
				// check to see if point one and point two are 
				// parallel to x and y then we can try a whole bunch of third points. 
				if (y[i] == y[j] && x[i] == x[k]) {
					int area = abs((x[j] - x[i]) * (y[k] - y[i]));
					output = max(output, area);
				}
			}
		}
	}

	cout << output << endl; 

}
