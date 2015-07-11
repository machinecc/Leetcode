#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size() == 0)
    		return "";

    	string res = "";

    	bool found = false;

    	int minlength = strs[0].length();
    	//cout << strs[0] << endl;
    	//cout << minlength << endl;

    	for (int i = 1; i < strs.size(); ++ i)
    		if (strs[i].length() < minlength)
    			minlength = strs[i].length();

    	//cout << minlength << endl;

    	for (int i = 0; i < minlength; ++i) {
    		bool same = true;
    		char ch = strs[0][i];
    		for (int j = 1; j < strs.size(); ++ j)
    			if (ch != strs[j][i]) {
    				same = false;
    				break;
    			}

    		if (same == false) {
    			break;
    		}
    		else {
    			res = res + ch;
    		}


    	}    

    	return res;
    }
};


int main() {
	vector<string> data;
	data.push_back("aa");
	data.push_back("aa");

	cout << Solution().longestCommonPrefix(data) << endl;


	return 0;
}