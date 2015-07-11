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
    int titleToNumber(string s) {
		int n = s.length();

		int num = 0;
		int base = 1;

		for (int i = n - 1; i >= 0; -- i) {
			num += (s[i] - 'A' + 1) * base;
			base *= 26;
		}        

		return num;
    }
};


int main() {
	cout << Solution().titleToNumber("ZZ") << endl;


	return 0;
}