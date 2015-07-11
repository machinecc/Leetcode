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
	vector<vector<string>> ans;

	vector<string> stk;

	string s;

	int n;

	bool** palindrome;



	vector<vector<string>> partition(string _s) {
		s = _s;

		if (s.length() == 0)
			return ans;

		n = s.length();

		palindrome = new bool*[n];
		for (int i = 0; i < n; ++ i)
			palindrome[i] = new bool [n];

		for (int i = 0; i < n; ++ i) {
			palindrome[i][i] = true;
			for (int j = i+1; j < n; ++ j) {
				palindrome[i][j] = is_palindrome(s.substr(i, j-i+1));
			}
		}

		// for (int i = 0; i < n; ++ i) {
		// 	for (int j = 0; j < n; ++ j)
		// 		cout << palindrome[i][j] << ' ';
		// 	cout << endl;
		// }
		// cout << endl << endl;

		bfs(0);

		return ans;
	}


	void bfs(int start_pos) {
		if (start_pos == n) {
			ans.push_back(stk);
		}

		for (int i = start_pos; i < n; ++ i) {
			if (palindrome[start_pos][i] == true) {
				stk.push_back(s.substr(start_pos, i - start_pos + 1));

				bfs(i+1);

				stk.pop_back();
			}
		}
	}

	bool is_palindrome(string c) {
		int len = c.length();

		if (len <= 1)
			return true;

		for (int i = 0; i < len/2; ++ i)
			if (c[i] != c[len-1-i])
				return false;

		return true;
	}
};


int main() {

	vector<vector<string>> ans = Solution().partition("aab");

	for (int i = 0; i < ans.size(); ++ i) {
		for (int j = 0; j < ans[i].size(); ++ j)
			cout << ans[i][j] << " ";
		cout << endl;
	}

	return 0;
}