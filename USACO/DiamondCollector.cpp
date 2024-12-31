// Source: https://usaco.guide/general/io

#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main() {
  // we are given len(input) and a k value. 
  int n, k; cin >> n >> k; 
  vector<int> diamonds(n);
  for (int &d : diamonds) { cin >> d; }

  int output = 0; 

  for (int i = 0; i < n; i++) {
    int possible = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      if (abs(diamonds[i] - diamonds[j]) <= k) { possible++; }
    }

    output = max(output, possible);
  }

  cout << output << endl; 

}
