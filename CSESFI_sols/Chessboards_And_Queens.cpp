#include <bits/stdc++.h>
using namespace std;
// imma just do backtracking for this
const int DIM = 8; 
vector<vector<bool>> reserved(DIM, vector<bool>(DIM));
vector<bool> rows_taken(DIM);
// need to track diagonals from bottom left up to top
vector<bool> diags_one(DIM * 2 - 1);
// for bottom right up to top 
vector<bool> diags_two(DIM * 2 - 1); 

int valid = 0; 
// complete search placements each time we call it avoiding blocked and 
// taken points on our grid. 
void search_q(int c = 0) {
    // base case of placing each queen we now have another valid 
    // data point 
    if (c == DIM) {
        valid++;
        return;
    }

    for (int r = 0; r < DIM; r++) {
        bool row_check = !rows_taken[r];
        bool diag_check = !diags_one[r + c] && !diags_two[r -c  + DIM - 1];
        // we can place the queen at this spot 
        if (!reserved[r][c] && row_check && diag_check) {
            rows_taken[r] = diags_one[r + c] = diags_two[r - c + DIM - 1] = true;
            search_q(c + 1);
            rows_taken[r] = diags_one[r + c] = diags_two[r - c + DIM - 1] = false;
        }
    }
}

int main() {
    // reading in grid also need to fill reserved when we have "*"
    for (int r = r; r < DIM; r++) {
        string row; cin >> row; 
        for (int c = 0; c < DIM; c++) { reserved[r][c] = row[c] == '*'; }
    }

    search_q(); 

    cout << valid << endl; 
}