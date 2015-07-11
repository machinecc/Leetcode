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
	bool isPalindrome(string s) {
		int n = s.size();

		if (n == 0)
			return true;

		int i = 0;
		int j = n-1;

		while (i < j) {
			while (i < n && !isvalid(s[i]))
				++ i;
			
			while (j >=0 && !isvalid(s[j]))
				-- j;

			if (i >= j || i >= n || j < 0)
				break;

			if (tolower(s[i]) != tolower(s[j]))
				return false;

			++ i;
			-- j;
		}

		return true;
    }


    bool isPalindrome1(string s) {
        string s1 = "";

        for (int i = 0; i < s.size(); ++ i)
        	if (isvalid(s[i]))
        		s1 = s1 + tolower(s[i]);

        string s2 = s1;

        reverse(s2.begin(), s2.end());

        return s1 == s2;
    }

    bool isvalid(char ch) {
    	if (ch >= '0' && ch <= '9')
    		return true;

    	if (ch >= 'a' && ch <= 'z')
    		return true;

    	if (ch >= 'A' && ch <= 'Z')
    		return true;

    	return false;
    }

    char tolower(char ch) {
    	if (ch >= '0' && ch <= '9')
    		return ch;

    	if (ch >= 'a' && ch <= 'z')
    		return ch;

    	if (ch >= 'A' && ch <= 'Z')
    		return ch + 'a' - 'A';

    	return false;
    }
};


int main() {

	cout << Solution().isPalindrome("!!!") << endl;

	return 0;
}