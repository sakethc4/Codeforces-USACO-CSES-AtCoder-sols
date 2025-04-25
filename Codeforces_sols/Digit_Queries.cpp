#include <bits/stdc++.h>
using namespace std;

char find_digit(long long k) {
	long long length = 1;
	long long count = 9;
	long long start = 1;

	while (k > count * length) {
		k -= length * count;
		length++; 
		count *= 10; 
		start *= 10; 
	}

	long long number_offset = (k - 1) / length;
    long long digit_index = (k - 1) % length;
    long long actual_number = start + number_offset;

    string s = to_string(actual_number);
    return s[digit_index];

}

int main() {
	// if pos < 10 we can just return kth
	// this is going to change every time we move into a new range like 
	// 10's, 100's, 999's, etc
	// 10 -99 -> 99-10 + 1 = 90 numbers * 2 gives us 180 digits + 9 for 0-9 nums gives us 189
	int q; cin >> q;
	while (q--) {
		long long k;
		cin >> k;
		cout << find_digit(k);
	}

	return 0;
}