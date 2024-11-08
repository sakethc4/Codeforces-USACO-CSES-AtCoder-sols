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

#define trav(a, x) for (auto &a : x)

// Input/Output - s is basically the file name without the ".in" and ".out"
// N cows performing three shuffles. Cows are 1 indexed in positions. Input:
// first line number of cows. Next: si, ti with si as start ti as end bi (num of buckets) is third value. 
// O(N + T). Where t is 1000. 
void setIO(string s) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX_TIME = 1000;

int main() { 
    setIO("blist");
    int n; cin >> n;
    int count = 0;
    
    vi bucket_counter(MAX_TIME + 1000);
    for(int i = 0; i < n; i++) {
        int s, t, b; cin >> s >> t >> b;
        bucket_counter[s] += b;
        bucket_counter[t] -= b;
    }

    int max_buckets = 0;
    int curr_buckets = 0; 
    // Iterate over each time value to calculate how many buckets are in cycle. 
    for(int t = 0; t < MAX_TIME; t++) {
        curr_buckets += bucket_counter[t];
        max_buckets = std::max(max_buckets, curr_buckets);
    }

    cout << max_buckets << '\n';
    }