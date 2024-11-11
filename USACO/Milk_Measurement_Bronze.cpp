#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// each cow produces 7 gallons of milk per day. Measured over 100 day period

const int RATE = 7;
const vector<string> NAMES{"Bessie", "Elsie", "Mildred"};

int main() {
  freopen("measurement.in", "r", stdin);
  int n;
  cin >> n;
  vector<tuple<int, string, int>> updates;
  for (int i = 0; i < n; i++) {
    int day, change;
    string cow;
    cin >> day >> cow >> change;
    updates.push_back(make_tuple(day, cow, change));
  }
  // After parsing input we can now apply simulation. First we need to sort so
  // the most recent day comes first in our vector.
  sort(updates.begin(), updates.end());
  // We can also use a hashmap to map curr_output to each cow.
  map<string, int> outputs;
  for (const auto &name : NAMES) {
    outputs[name] = RATE;
  }
  // vector for prize list. Essentially tracking highest performing cows. Easy
  // to compare against later on if we need to make updates.
  vector<string> prizes = NAMES;
  int result = 0;
  for (const tuple<int, string, int> &change : updates) {
    outputs[get<1>(change)] += get<2>(change);
    int max_output = 0;
    for (const auto &it : outputs) {
      max_output = max(max_output, it.second);
    }

    vector<string> new_prizes;
    for (const auto &it : outputs) {
      const string &name = it.first;
      const int &output = it.second;
      if (output == max_output) {
        new_prizes.push_back(name);
      }
    }

    result += new_prizes != prizes;
    prizes = new_prizes;
  }
  freopen("measurement.out", "w", stdout);
  cout << result << endl;
}