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
    string simplifyPath(string path) {
        stringstream ss(path);

        string item;

        vector<string> stk;

        while (getline(ss, item, '/')) {
        	//cout << item << endl;
        	if (item.empty() || item == ".")
        		continue;
			else if (item == "..") {
				if (stk.size() > 0)
					stk.pop_back();
        	}
        	else
        		stk.push_back(item);
        }

        if (stk.size() == 0)
        	return "/";

        stringstream outputss;

        for (int i = 0; i < stk.size(); ++ i)
        	outputss << '/' << stk[i];

        return outputss.str();
    }
};


int main() {
	cout << Solution().simplifyPath("/home/../") << endl;


	return 0;
}