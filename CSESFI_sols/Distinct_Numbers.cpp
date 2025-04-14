#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
    vector<int> numbers(n); 
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int output = 0;
    int prev = -1; 
    for (int j = 0; j < n; j++) {
        if (numbers[j] == prev) {
            prev = numbers[j];
            continue; 
        }
        prev = numbers[j];
        output++; 
    }

    cout << output << endl; 
}