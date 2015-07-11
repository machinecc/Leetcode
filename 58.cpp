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
    int lengthOfLastWord(string s) {
    	int n = s.length();

    	if (n == 0)
    		return 0;

    	if (n == 1) {
    		if (s != " ")
    			return 1;
    		else
    			return 0;
    	}


    	int i = 0;
    	while (s[i] == ' ' && i < n) 
    		++ i;

    	if (i == n)
    		return 0;


    	int j = n-1;

    	while (s[j] == ' ' && j >= 0)
			-- j;


		s = s.substr(i, j - i + 1);

		cout << s << endl;

		int p = s.length();

    	while (p >= 0) {
    		-- p;
    		if (p >= 0 && s[p] == ' ')
    			break;
    	}
    	//cout << p << endl;
    	//cout << s.length() - p - 1 << endl;

        return s.length() - p - 1;
    }
};


int main() {
	string s = "a ";
	cout << Solution().lengthOfLastWord(s) << endl;
	//cout << s.find_last_of("h") << endl;


	return 0;
}