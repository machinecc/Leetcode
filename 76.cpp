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
    string minWindow(string s, string t) {
        unordered_set<char> alphabet;

        for (int i = 0; i < t.length(); ++ i)
        	alphabet.insert(t[i]);

        int n = alphabet.size();



        int m = s.length();

        if (m == 0)
        	return n == 0;

        unordered_map<char, int> dict;

        int i = 0, j = 0;
        dict

        while (j < n) {

        }


    }
};




int main() {



	return 0;
}