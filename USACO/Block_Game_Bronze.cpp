#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


// We need to output 26 lines each line should be corresponding to a letter of alpha. 
// Denoting number of letters. 
vector<int> frequency(string s) { 
    vector<int> count(26);
    for (char c : s) { count[c - 'a']++; }
    return count; 
}
    

int main() { 
    std::ifstream read("blocks.in");
    int n; read >> n;
    // We need a vector that contains both words. 
    vector<std::pair<string, string>> words(n);
    for (auto &[word1, word2] : words) { read >> word1 >> word2; }
    vector<int> output(26);
    for (const auto &[word1, word2] : words) {
        vector<int> freq1 = frequency(word1);
        vector<int> freq2 = frequency(word2);
        for (int c = 0; c < 26; c++) { 
            output[c] += std::max(freq1[c], freq2[c]);
        }
    }

    std::ofstream write("blocks.out");
    for(int i = 0; i < 26; i++) { write << output[i] << endl; }
}