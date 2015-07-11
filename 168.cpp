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
    string convertToTitle(int n) {
    	int base = 26;

    	string ans = "";

    	while (n > 0) {
    		-- n;

    		char ch = char(n % 26 + 'A');

    		n /= 26;

    		ans = ch + ans;
    	}


        return ans;
    }
};


int main() {
	cout << Solution().convertToTitle(27) << endl;


	return 0;
}