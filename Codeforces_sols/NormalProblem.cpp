#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t; 
	for (int i = 0; i < t; i++) {
		string s; cin >> s; 
		int strLen = s.size(); 
		for (int j = 0; j < strLen; j++) {
			if (s[j] == 'p') {
				s[j] = 'q';
			}
			else if (s[j] == 'q') {
				s[j] = 'p';
			}
		}

		reverse(s.begin(), s.end());
		cout << s << endl; 
	}
}