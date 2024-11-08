#include <algorithm>
#include <cstdio>
#include <vector>

using std::vector;
// Road is 100 miles long. Divided into N segs. Each seg has a pos len and a speed limit 1-100. 
// Each segment she travels a certain miles at a certain speed. Tractor max speed is 100. 
// input specs: N is len and speed. Next M is len and speed Bessie moves at. 

const int LEN = 100;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int ouput = 0; 
    int N, M;
    cin >>N >> M;
    int start = 0;

    vector<int> limit(LEN);
    for (int i = 0; i < N; i ++) {
        int length, speed;
        cin >> length >> speed;
        for(int j = start; j < length + start; j ++) { limit[j] = speed; }
        start += length;
    }

    int start = 0
    vector<int> bessie(LEN);
    for (int i = 0; i < M; i++) {
        int length, speed;
        cin >> length >> speed;
        for(int j = start; j < start + length; j++) { bessie[j] = speed; }
        start += length;
    }

    for(int i = 0; i < LEN; i++) { output = max(output, bessie[i] - limit[i]); }
    cout << output << endl;

}
    
}