#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// An arbitrary number that's large compared to the ones in the problem.
const int LARGE = 1e9;

int main() { 
	std::ifstream read("traffic.in");
	int num_miles; read >> num_miles;

	vector<std::string> seg_type(num_miles);
	vector<int> start(num_miles);
	vector<int> end(num_miles);
	for (int i = 0; i < num_miles; i++) {
		read >> seg_type[i] >> start[i] >> end[i];
	}

	// Now we need to go through and set ranges. 
	// Start off by calculating before mile 1. 
	int low = 0;
	int high = LARGE;
	for (int i = num_miles - 1; i >= 0; i--) {
		if (seg_type[i] == "none") {
			low = std::max(low, start[i]);
			high = std::min(high, end[i]);
		}
		else if (seg_type[i] == "off") {
			low += start[i];
			high += end[i];
		}
		else if(seg_type[i] == "on") {
			low -= start[i];
			high -= end[i];
			// If we decrement too much.
			low = std::max(0, low);
		}
	}

	std::ofstream write("traffic.out");
	write << low << ' ' << high << endl;
	low = 0;
	high = LARGE;
	for(int i = 0; i < num_miles; i++) {
		if (seg_type[i] == "none") {
			low = std::max(low, start[i]);
			high = std::min(high, end[i]);
		}
		else if(seg_type[i] == "off") {
			low -= start[i];
			high -= end[i];

			low = std::max(0, low);
		}
		else if (seg_type[i] == "on") {
			low += start[i];
			high += end[i];
		}
	}
	
	write << low << ' ' << high << endl;

}