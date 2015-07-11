#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
	vector<string> ans;
	
    vector<string> generateParenthesis(int n) {
        generate("", n, n);

        return ans;
    }

    void generate(string s, int left, int right) {
    	if (left == 0 && right == 0)
    		ans.push_back(s);

    	if (left > 0)
    		generate(s+'(', left - 1, right);

    	if (right > 0 && right > left)
    		generate(s+')', left, right - 1);

    }
};


int main() {

	vector<string> ans = Solution().generateParenthesis(2);


	for (auto it = ans.begin(); it != ans.end(); ++ it) {
		cout << *it << endl;
	}


	return 0;
}