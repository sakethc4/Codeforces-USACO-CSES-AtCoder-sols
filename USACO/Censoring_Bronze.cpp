#include <iostream>
using namespace std;

int main() {
	freopen("censor.in", "r", stdin);
	string s, t; cin >> s >> t; 
	int length_s = s.size(); 
	int length_t = t.size(); 
	string curr_output; 
	for (char c : s) {
		curr_output += c; 
		if (curr_output.size() >= length_t && curr_output.substr(curr_output.size() - length_t) == t) {
			curr_output.resize(curr_output.size() - length_t);
		}
	}
	freopen("censor.out", "w", stdout); 
	cout << curr_output << endl; 
}