#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();
        int k = words[0].length();
        vector<int> ans;
        
        unordered_map<string,int> dict;

        for (auto it = words.begin(); it != words.end(); ++ it) {
        	if (dict.find(*it) != dict.end())
        		dict[*it] += 1;
        	else
        		dict[*it] = 1;
        }

       	int step = k;
       	int i = 0;
       	int j = 0;
       	unordered_map<string,int> curr_dict;


       	for (int init_pos = 0; init_pos < k; ++ init_pos) {
       		i = init_pos;
       		j = i;
       		//cout << "init_pos = " << init_pos << endl;
       		curr_dict = dict;

	       	while (j <= n - k) {
	       		string word = s.substr(j, k);
	       		bool move_i = false;
	       		//cout << "i = " << i << "   " << "j = " << j << endl;
	       		//cout << "word = " << word << endl;
	       		//cout << endl << endl;

	       		if (curr_dict.find(word) != curr_dict.end()) {
       				curr_dict[word] = curr_dict[word] - 1;

	       			if (curr_dict[word] == 0)
	       				curr_dict.erase(word);

	       			j = j + k;
	       		
	       			if (curr_dict.empty() == true) {
	       				ans.push_back(i);
	       				move_i = true;
	       			}
	       		} else {
	       			move_i = true;
	       		}

	       		if (move_i == true) {
	       			string left_word = s.substr(i, k);
	       			if (curr_dict.find(left_word) != curr_dict.end())
	       				curr_dict[left_word] += 1;
	       			else
	       				curr_dict[left_word] = 1;
	       			i = i + k;
	       		}
	       	}
    	}
        return ans;
    }
};


int main() {
	string s = "barfoothefoobarman";
	vector<string> words = {"foo", "bar"};
	//string s = "a";
	//vector<string> words = {"a"};
	
	vector<int> ans = Solution().findSubstring(s, words);

	for (int i = 0; i < ans.size(); ++ i)
		cout << ans[i] << ' ';

	cout << endl;



	return 0;
}