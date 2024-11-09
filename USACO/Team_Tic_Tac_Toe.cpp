#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;

vector<string> board(3);
// Need this to be four so that we have a spot for all three distinct values. 
set<set<char>> winners[4];

void insert(vector<std::pair<int, int>> coordinates) {
    set<char> cows;
    for(const std::pair<int, int> &p : coordinates) {
        cows.insert(board[p.first][p.second]);
    }

    winners[cows.size()].insert(cows);
}

// We have 26 cows each has a distinc letter associated. Output is line1: indivl victories. line2: team victories. 
int main() { 
    std::ifstream read("tttt.in");
    // build our board with input strings. 
    for(int i = 0; i < 3; i++) { read >> board[i]; }
    // inserting rows/cols. 
    for (int r = 0; r < 3; r++) { insert({{r, 0}, {r, 1}, {r, 2}}); }
    for (int c = 0; c < 3; c++) { insert({{0, c}, {1, c}, {2, c}}); }
    // Handling diags. 
    insert({{0, 0}, {1, 1}, {2, 2}});
    insert({{2, 0}, {1, 1}, {0, 2}});

    std::ofstream write("tttt.out");
    write << winners[1].size() << endl;
    write << winners[2].size() << endl;
}