#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {
public:
	string maps[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> result;
	int n = 0;
	string str;
	
	vector<char> s;

    vector<string> letterCombinations(string digits) {
    	str = digits;
    	n = digits.length();

    	if (n == 0)
    		return result;

    	//cout << n << endl;

    	recusive(0);

    	return result;
    }

    void recusive(int pos) {
    	//cout << "pos = " <<  pos << endl;
    	//cout << "n = " << n << endl;
    	if (pos == n) {
    		string ans(s.begin(), s.end());

    		result.push_back(ans);

    		//cout << ans << endl;
    		return;
    	}


    	int digit = str[pos] - '0';
    	//cout << "digit = " << digit << endl;

    	if (digit == 1) {
   		 	recusive(pos+1);
    	}
    	else {
    		string candidates = maps[digit];
	    	for (int i = 0; i < candidates.length(); ++ i) {
    			s.push_back(candidates[i]);
   		 		recusive(pos+1);
  		  		s.pop_back();
  		  	}
    	}




    	

    }

};





int main() {
	cout << Solution().letterCombinations("123").size() << endl;


	return 0;
}