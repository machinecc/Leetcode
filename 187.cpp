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
	
	const int len = 10;

    vector<string> findRepeatedDnaSequences(string s) {
    	unordered_map<int,int> dict;
    	
    	int n = s.length();

    	for (int i = 0; i < n - len + 1; ++ i) {
    		string subs = s.substr(i, len);
    		int val = str2int(subs);

    		if (dict.find(val) == dict.end())
    			dict[val] = 1;
    		else
    			dict[val] += 1;
    	}

    	vector<int> numbers;

    	for (auto it = dict.begin(); it != dict.end(); ++ it)
    		if (it->second > 1)
    			numbers.push_back(it->first);


    	vector<string> ans;
    	for (auto it = numbers.begin(); it != numbers.end(); ++ it)
    		ans.push_back(int2str(*it));


    	return ans;
    }


    int str2int(const string& s) {
    	int val = 0;
    	for (int i = 0; i < s.length(); ++ i)
    		val = val * 4 + char2int(s[i]);

    	return val;
    }

    int char2int(char ch) {
    	int val = 0;

    	switch (ch) {
    		case 'A':
    			val = 0;
    			break;
    		case 'C':
    			val = 1;
    			break;
    		case 'G':
    			val = 2;
    			break;
    		case 'T':
    			val = 3;
    			break;
    	}

    	return val;
    }





    string int2str(int num) {
    	string s = "";

    	do {
    		s = int2char(num % 4) + s;
    		num = num / 4;
    	} while (num > 0);

    	if (s.length() < len)
    		s = string(len - s.length(), 'A') + s;

    	return s;
    }


    char int2char(int num) {
    	char ch;
    	switch (num) {
    		case 0:
    			ch = 'A';
    			break;
    		case 1:
    			ch = 'C';
    			break;
    		case 2:
    			ch = 'G';
    			break;
			case 3:
    			ch = 'T';
    			break;
    	}
    	return ch;
    }
};


int main() {
	// Solution slo;
	// string s = "CTAGT";

	// cout << slo.str2int(s) << endl;
	// int n = slo.str2int(s);
	// cout << slo.int2str(n) << endl;



	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> ans = Solution().findRepeatedDnaSequences(s);

	for (int i = 0; i < ans.size(); ++ i)
		cout << ans[i] << endl;



	return 0;
}