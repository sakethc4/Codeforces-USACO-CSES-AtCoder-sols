#include <bits/stdc++.h>
using namespace std;

string stuff;
vector<string> perms; 
int frequency[26];

void find_perm(const string &curr = "") {
    if (curr.size() == stuff.size()) {
        perms.push_back(curr);
        return; 
    }

    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            frequency[i]--;
            find_perm(curr + (char)('a' + i));
            frequency[i]++;
        }
    }
}

int main() {
    cin >> stuff;
    for (char c : stuff) {
        frequency[c - 'a']++; 
    }

    find_perm();

    cout << perms.size() << endl;
    for (const string &perm : perms) {
        cout << perm << endl; 
    }
}
