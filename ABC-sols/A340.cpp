#include <bits/stdc++.h>
using namespace std;

int main() {
	int a; cin >> a;
	int b; cin >> b;
	int d; cin >> d; 
	string output = "";
	for (int i = a; i <= b; i+= d) {
		output += " " + std::to_string(a); 
	}

	cout << output << endl;
	return 0;  
}