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
    vector<string> restoreIpAddresses(string s) {
    	vector<string> ans;

        int n = s.size();

        if (n < 4)
        	return ans;

        int count = 0;

        for (int i1 = 1; i1 <= 3; ++ i1) {
        	for (int i2 = 1; i2 <= min(3, n - i1 - 2); ++ i2) {
        		for (int i3 = 1; i3 <= min(3, n - i1 - i2 - 1); ++ i3) {
        			if (isValid(s.substr(0, i1)) && isValid(s.substr(i1, i2)) && isValid(s.substr(i1+i2, i3)) && isValid(s.substr(i1+i2+i3))) {
        					++ count;
        					ans.push_back(s.substr(0, i1) + "." + s.substr(i1, i2) + "." + s.substr(i1+i2, i3) + "." + s.substr(i1+i2+i3));
        				}
        		}
        	}
        }
        return ans;
    }


    bool isValid(string s) {
    	if (s.size() > 3)
    		return false;

    	if (s.size() > 1 && s[0] == '0')
    		return false;

    	int num = stoi(s);

    	if (num > 0 && num <= 255)
    		return true;
    	
    	if (num == 0 && s.size() == 1)
    		return true;

    	return false;
    }
};


int main() {
	vector<string> ans = Solution().restoreIpAddresses("1231231231234");
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}


	return 0;
}