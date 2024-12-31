// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	// complete search the space. Unoptimal time but does the job 
	int n; cin >> n; 
	vector<int> flowerPetals(n);
	for (int &petal : flowerPetals) { cin >> petal; }

	int output = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double average = 0;
			if (i == j) {
				output++; 
				continue; 
			}
			
			for (int f = i; f <= j; f++) { average += flowerPetals[f]; }
			average /= (j - i + 1); 

			for (int poss = i; poss <= j; poss++) {
				if (flowerPetals[poss] == average) {
					output++; 
					break; 
				}
			}

		}
	}

	cout << output << endl; 
}
