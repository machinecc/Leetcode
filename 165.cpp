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
    int compareVersion(string version1, string version2) {
    	vector<string> v1 = separate(version1);
    	vector<string> v2 = separate(version2);

    	// for (int i = 0; i < v1.size(); ++ i)
    	// 	cout << v1[i] << '-';
    	// cout << endl;

    	int i = 0;
    	for (i = 0; i < min(v1.size(), v2.size()); ++ i) {
    		int n1 = stoi(v1[i]);
    		int n2 = stoi(v2[i]);
    		if (n1 < n2)
    			return -1;
    		if (n1 > n2)
    			return 1;
    	}

		if (v1.size() == v2.size())
    		return 0;

    	if (v1.size() > v2.size()) {
    		for (; i < v1.size(); ++ i)
    			if (stoi(v1[i]) > 0)
    				return 1;
    		return 0;
    	}

    	if (v1. size() < v2.size()) {
    		for (; i < v2.size(); ++ i)
    			if (stoi(v2[i]) > 0)
    				return -1;
    		return 0;
    	}

    	return 0;
    	
    }


    vector<string> separate(string& s) {
    	vector<string> numbers;

    	string number = "";

    	for (int i = 0; i < s.length(); ++ i) {
    		if (s[i] == '.') {
    			numbers.push_back(number);
    			number = "";
    		}
    		else
    			number = number + s[i];
    	}

    	if (!number.empty()) {
    		numbers.push_back(number);
    	}

    	return numbers;
    }
};



int main() {

	cout << Solution().compareVersion("1.0", "1") << endl;

	return 0;
}