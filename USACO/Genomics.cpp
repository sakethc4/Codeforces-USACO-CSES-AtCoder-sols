// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int cowPerGroup, inputLen; cin >> cowPerGroup >> inputLen;
	vector<vector<char>> spotted(cowPerGroup, vector<char> (inputLen));
	for (int i = 0; i < cowPerGroup; i++) {
		for (int j = 0; j < inputLen; j++) {
			cin >> spotted[i][j];
		}
	}
	vector<vector<char>> normal(cowPerGroup, vector<char> (inputLen));
	for (int i = 0; i < cowPerGroup; i++) {
		for (int j = 0; j < inputLen; j++) {
			cin >> normal[i][j];
		}
	}

	int output = 0; 
	for (int i = 0; i < inputLen; i++) {
		// go through plain and spotted.
		bool duplicate = false; 
		// plain here 
		for (int j = 0; j < cowPerGroup; j++) {
			// spotted here
			for (int k = 0; k < cowPerGroup; k++) {
				if (normal[j][i] == spotted[k][i]) {
					duplicate = true; 
					break; 
				}
			}

			if (duplicate) {
				break; 
			}
 		}
		
		if (!duplicate) {
			output++; 
		}
		
	}

	cout << output << endl; 
}
