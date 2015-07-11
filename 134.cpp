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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        vector<int> r;

        for (int i = 0; i < n; ++ i)
        	r.push_back(gas[i] - cost[i]);

        for (int i = 0; i < n;)
        	if (r[i] < 0) {
        		++ i;
        	}
        	else {
        		int p = i;
        		bool mark = true;
        		int s = 0;

        		for (int j = 0; j < n; ++ j) {
        			s += r[p];
        			p = (p + 1) % n;

        			if (s < 0) {
        				mark = false;
        				break;
        			}
        		}

        		if (mark == true)
        			return i;
        		else {
        			if (p > i)
        				i = p;
        			else
        				return -1;
        		}
        	}

        return -1;
    }
};

int main() {
	vector<int> gas = {2,4};
	vector<int> cost = {3,4};

	cout << Solution().canCompleteCircuit(gas, cost) << endl;


	return 0;
}