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


using namespace std;

class Solution {
public:

    string getPermutation(int n, int k) {
    	if (n <= 0 || k <= 0)
    		return "";

        long product = 1;

        vector<char> digits;
        string s = "";

        k = k - 1;

        for (int i = 1; i <= n; ++ i) {
        	digits.push_back(char('0' + i));
        	product = product * i;
        }

        for (int i = n; i >= 1; -- i) {
        	product = product / i;

        	int idx = k / product;

        	s = s + digits[idx];

        	digits.erase(digits.begin() + idx);

        	k = k % product;
        }

        cout << s << endl;

        return s;
    }
};


int main() {
	Solution().getPermutation(3,5);


	return 0;
}