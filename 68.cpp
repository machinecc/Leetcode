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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int n = words.size();

        if (n == 0)
        	return ans;
        //cout << total_length << endl;

		vector<vector<string>> lines;

		vector<string> line;

        int p = 0;

        int l = 0;

        while (p < n) {
        	string& word = words[p];

        	if (l > 0)
        		++ l;
        	if (l + word.length() <= maxWidth) {
        		line.push_back(word);
        		l += word.length();
        		++ p;
        	}
        	else {
        		lines.push_back(line);
        		line.clear();
        		l = 0;
        	}
        }

        if (line.size() > 0)
        	lines.push_back(line);
/*
        for (int i = 0; i < lines.size(); ++ i) {
        	cout << lines[i].size() << endl;
        	for (int j = 0; j < lines[i].size(); ++ j)
        		cout << lines[i][j] << ' ';
        	cout << endl;
        }
*/

        for (int i = 0; i < lines.size(); ++ i) {
        	vector<string>& curr_line = lines[i]; 

        	if ( i != lines.size() - 1 ) {
        		int num_space = maxWidth - get_total_length(curr_line);

        		int p , q;
        		stringstream ss;

        		if (curr_line.size() == 1) {
        			ss << curr_line[0] << string(num_space, ' ');
        		}
        		else {
					p = num_space / (curr_line.size() - 1);
	        		q = num_space % (curr_line.size() - 1);

	        		ss << curr_line[0];

	        		for (int j = 1; j <= q; ++ j)
	        			ss << string(p + 1, ' ') << curr_line[j];

	        		for (int j = q + 1; j < curr_line.size(); ++ j)
	        			ss << string(p, ' ') << curr_line[j];
        		}

	        	ans.push_back(ss.str());
        	}
        	else {
        		int num_space = maxWidth - get_total_length(curr_line) - (curr_line.size() - 1);

        		stringstream ss;

        		for (int j = 0; j < curr_line.size() - 1; ++ j)
        			ss << curr_line[j] << ' ';

        		ss << curr_line[curr_line.size() - 1];

        		ss << string(num_space, ' ');

        		ans.push_back(ss.str());
        	}
        }


        return ans;
    }

    int get_total_length(vector<string>& words) {
    	int total_length = 0;
        for (int i = 0; i < words.size(); ++ i)
        	total_length  += words[i].length();
        return total_length;
    }

};


int main() {
	vector<string> words = {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};

	vector<string> ans = Solution().fullJustify(words, 30);

	for (int i = 0; i < ans.size(); ++ i)
		cout << "\"" << ans[i] << "\"" << endl;


	return 0;
}