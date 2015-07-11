#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows == 1)
    		return s;


        int n = (numRows - 1) * 2;

        string res = "";

        for (int i = 0; i < numRows; ++ i) {

        	int k1 = i;
        	int k2 = n - i;

        	if (k1 != k2 && i != 0) {
        		while (true) {
        			if (k1 < s.size()) {
        				res += s[k1];
        				k1 += n;
        			}
        			if (k2 < s.size()) {
        				res += s[k2];
        				k2 += n;
        			}
        			if (k1 >= s.size() && k2 >= s.size()) 
        				break;
        		}
        	}
        	else {
        		while (k1 < s.size()) {
        			res += s[k1];
        			k1 += n;
        		}

        	}
        }
        return res;
    }
};

int main() {

	//Solution().convert("PAYPALISHIRING", 3);
	cout << Solution().convert("a", 2) << endl;

	return 0;
}



