#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Sim total distance for each door all the while tracking min dist. Then return min dist. 
int main() {
    std::ifstream read("cbarn.in");
    int n; read >> n;
    // Start by counting total number of cows. Can get this by sum(rooms). 
    int total_cows = 0;
    vector <int> rooms(n);
    for (int i = 0; i < n; i++) {
        read >> rooms[i];
        total_cows += rooms[i];
    }

    int min_dist = INT32_MAX;
    // Go through each room and simulate.
    for(int i = 0; i < n; i++) {
        int dist = 0;
        int cows_rem = total_cows;
        for(int j = 0; j < n; j++) {
            cows_rem -= rooms[(i + j) % n];
            dist += cows_rem;
        }

        min_dist = std::min(min_dist, dist);
    }

    std::ofstream write("cbarn.out");
    write << min_dist << endl;
}