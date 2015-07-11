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


struct Interval {
	int x;
	int y;

	Interval(int x, int y): x(x), y(y) {}

	bool operator == (const Interval& interval) const {
		return (x == interval.x && y == interval.y);
	}
};

template <>
struct hash<Interval> {
	std::size_t operator() (const Interval& interval) const {
		return interval.x * 10000 + interval.y;
	}
};


class Solution {
public:
	int* partitions = NULL; 
	string s;
	int n;

	

    int minCut(string _s) {
        if (_s.length() <= 1)
        	return 0;

        s = _s;

        n = s.length();


        bool palindrome[n][n];

		for (int i = 0; i < n; ++ i) {
			palindrome[i][i] = true;
			for (int j = i+1; j < n; ++ j) {
				palindrome[i][j] = is_palindrome(s.substr(i, j-i+1));
			}
		}

		return 1;
    }


    // int get_partitions(int k) {
    // 	if (partitions[k] != -1)
    // 		return partitions[k];

    // 	if (is_palindrome(0,k)) {
    // 		partitions[k] = 1;
    // 		return 1;
    // 	}

    // 	int min_val = INT_MAX;

    // 	for (int i = 1; i <= k; ++ i) {
    // 		if (is_palindrome(i,k)) {
    // 			min_val = min(min_val, get_partitions(i-1) + 1);
    // 		}
    // 	}

    // 	partitions[k] = min_val;
    // 	return min_val;
    // }

    bool is_palindrome(string c) {
		int len = c.length();

		if (len <= 1)
			return true;

		for (int i = 0; i < len/2; ++ i)
			if (c[i] != c[len-1-i])
				return false;

		return true;
	}

    // bool is_palindrome(int left, int right) {
    // 	Interval interval = {left, right};

    // 	if (palindrome.find(interval) != palindrome.end())
    // 		return palindrome[interval];

    // 	while (left < right && s[left] == s[right]) {
    // 		++ left;
    // 		-- right;
    // 	}

    // 	bool result = false;

    // 	if (left >= right)
    // 		result = true;

    // 	palindrome[interval] = result;

    // 	return result;
    // }
};








int main() {

	cout << Solution().minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
	//cout << Solution().minCut("aab") << endl;

	return 0;
}