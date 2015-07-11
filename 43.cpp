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
#include <cmath>
#include <queue>
#include "common.h"


using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
    	vector<int> n1 = str2vec(num1);
    	vector<int> n2 = str2vec(num2);


    	vector<int> v(n1.size() + n2.size() + 1, 0);


    	for (int i = 0; i < n1.size(); ++ i) {
    		for (int j = 0; j < n2.size(); ++ j) {
    			v[i+j] +=  n1[i] * n2[j];
    		}
    	}


    	int additive = 0;
    	for (int i = 0; i < v.size(); ++ i) {
    		v[i] = v[i] + additive;
    		additive = v[i] / 10;
    		v[i] = v[i] % 10;
    	}

    	int p = v.size() - 1;
    	while (p >= 0 && v[p] == 0)
    		-- p;


    	if (p < 0)
    		return "0";

		string ans = "";
    	while (p >= 0) {
    		ans = ans + char('0' + v[p]);
    		--p;
    	}
    	
    	return ans;
    }

    vector<int> str2vec(const string& s) {
    	vector<int> v;
    	for (int i = s.length() - 1; i >= 0; -- i)
    		v.push_back(s[i] - '0');
    	return v;
    }
};



int main() {
	cout << Solution().multiply("98","9") << endl;


	return 0;
}