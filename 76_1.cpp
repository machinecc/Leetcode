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
    string minWindow(string s, string t) {
        unordered_map<char, int> alphabet;

        for (int i = 0; i < t.length(); ++ i) {
        	if (alphabet.find(t[i]) == alphabet.end())
        		alphabet[t[i]] = 1;
        	else
        		alphabet[t[i]] += 1;
        }


        // for (auto it = alphabet.begin(); it != alphabet.end(); ++ it) {
        // 	cout << it->first << ':' << it->second << "   ";
        // }
        // cout << endl;

        //cout << m << endl;

        int n = s.length();

        if (alphabet.size() == 0 || n == 0)
        	return "";

        unordered_map<char,int> dict;

        int left = -1;
        int right = -1;
        int minlen = INT_MAX;
        int pos = -1;


        while (left < n && right <= n) {
        	++ left;

        	if (left != 0) {
        		char ch = s[left - 1];
        		if (alphabet.find(ch) != alphabet.end()) {
        			dict[ch] = dict[ch] - 1;
        			if (dict[ch] == 0)
        				dict.erase(ch);
        		}        			
        	}
        	else {
        		right = 1;

        		if (alphabet.find(s[0]) != alphabet.end())
        			dict[s[0]] = 1;
        	}

        	while ((right <= n) && (if_chars_all_found(dict, alphabet) == false)) {
        		char ch = s[right];

        		if (alphabet.find(ch) != alphabet.end()) {
	        		if (dict.find(ch) == dict.end())
	        			dict[ch] = 1;
	        		else
	        			dict[ch] += 1;
        		}

        		++ right;
        	}

        	// cout << left << ' ' << right << endl;
        	// cout << dict.size() << endl << endl;

        	if (if_chars_all_found(dict, alphabet) == true) {
        		if (right - left < minlen) {
        			minlen = right - left;
        			pos = left;
        		}
        	}
        }

        if (pos == -1)
        	return "";

        return s.substr(pos, minlen);
    }


    bool if_chars_all_found(unordered_map<char,int>& chs, unordered_map<char,int>& alphabet) {
		// for (auto it = chs.begin(); it != chs.end(); ++ it) {
  //       	cout << it->first << ':' << it->second << "   ";
  //       }
  //       cout << endl;



    	int ans = false;

    	if (chs.size() != alphabet.size())
    		return false;


    	for (auto it = alphabet.begin(); it != alphabet.end(); ++ it) {
    		char ch = it->first;

    		if (chs.find(ch) == chs.end())
    			return false;
    		else {

    		}

    		if (chs[ch] < it->second)
    			return false;
    	}
    	return true;
    }
};


int main() {
	cout << Solution().minWindow("a", "aa") << endl;


	return 0;
}