#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string str_num; cin >> str_num;
		int ops = 0; 
		// operate on string s.
		int count = 0;
		bool flag = false;
		while (count <  n) {
			if (str_num[count] == '1' && !flag) {
				ops++;
				flag = true; 
			}
			else if (str_num[count] == '0' && flag) {
				ops++;
				flag = false; 
			}

			count++;
		}

		cout << ops << endl; 

	}
	}