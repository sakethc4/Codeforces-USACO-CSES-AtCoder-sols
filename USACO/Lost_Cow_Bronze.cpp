// USACO Bronze template I found on USACO.org. 
#include <bits/stdc++.h>
using namespace std;

// Type aliases

using ll = long long;
using str = string;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using si = set<int>;

// Vector Operations

#define sz (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define del(x, i) erase(begin(x) + i)
#define rem(x, i) erase(begin(x), begin(x) + i)

// Pairs

#define mp make_pair
#define sec second
#define fir first

// Sets and Maps

#define ins insert
#define ez erase
#define cnt count

// Math

#define MOD 1e9 + 7
#define MAX_INT 1e18 * 9

// Permutation

#define possibilities(x) while(next_permutation(all(x)))

// Loops

#define Trav(a, x) for (auto &a : x)
#define For(i, a, b) for (int i = (a); i < (b); ++i)

// Input/Output - s is basically the file name without the ".in" and ".out"

void setIO(string s) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("lostcow");

    int x, y; cin >> x >> y;
    vi zigzag; 

    if (x == y) {
        cout << 0 << endl; 
    }
    else if (x < y) {
        int dist = 1; 
        while (x + dist < y) {
            zigzab.pb(x + dist);
            dist *= -2;
        }

        zigzag.pb(x + dist);
        int output = 1;
        For(i, 0, zigzag.size() - 1) { output += abs(zigzag[i] - zigzag[i + 1]); }
        // Removing extra steps. 
        output -= (zigzag[zigzag.size() - 1] - y);
        cout << ans << endl;
    }
    // Handling a larger x value. 
    else {
        int dist = 1;

        while (x + dist > y) {
            zigzag.pb(x + dist);
            dist *= -2;
        }

        zigzag.pb(x + dist);
        int output = 1;
        For(i, 0, zigzag.size() - 1) { output += abs(zigzag[i] - zigzag[i + 1]); }
        output -= (y - zigzag[zigzag.size() - 1]);
        cout << output << endl;
    }
}
