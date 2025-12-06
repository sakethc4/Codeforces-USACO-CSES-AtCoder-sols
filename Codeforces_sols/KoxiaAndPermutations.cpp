#include <bits/stdc++.h>
using namespace std;
// Main ideas: 
// If the k value we are given is k = 1 then 
// observe that p_i+k-1 = p_i therefore there is no 
// differences between the windows we look at. 
// So for k = 1 no matter how we permute we get the same values for each c_i
// just in different orders and when we take the max we get 2n always. 
// For k >= 2 we want to try to minimize the final maximum value. So we can 
// arrange elements as such: n 1 n-1 2 n-2 ... that way we can minimize each c_i value
// so with this we can define a lower bound n + 1 because no matter whay we will always 
// have a segment with n and 1 making the c_i for that segment n + 1. 

// Implementation: 
// for k = 1 we can just output 1,..., n
// for k >= 2 we want to do the aforementioned element arrangement so
// we can output the last element and post decrement for the next time its used. 
// We want to do this every odd element so (i + 1) % k == 0 would work here for
// both the k = 1 case and the alternating arrangement. 


int main() {
	int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int start = 1, end = n; 
        for (int i = 0; i < n; i++) {
            if (i % 2 != 0 || k == 1) {
                cout << start++ << " ";                 
            }
            else {
                cout << end-- << " ";
            } 
        }
        
        cout << "\n";
    }
}
