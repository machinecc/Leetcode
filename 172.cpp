#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include <array>


using namespace std;


class Solution {
public:
    int trailingZeroes(int n) {
    	int base = 5;
    	int count = 0;

    	while (n >= base) {
    		//count += n / base;
    		n = n / 5;
    		count += n;


   			//cout << "count = " << count << "    base = " << base << endl;
    		//base *= 5;
    	}

    	return count;
    }
};



int main() {

	int n = 5;
	cout << Solution().trailingZeroes(10) << endl;

	return 0;
}