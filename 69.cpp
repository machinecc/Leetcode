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
    int mySqrt(int x) {
    	if (x == 0)
    		return 0;

        int l = 1;
        int r = x;
        int ans = 0;

        while (true) {
        	int m = (l + r) / 2;
        	//cout << l << ' ' << m << ' ' << r << endl;

        	if (double(m) <= double(x) / double(m) &&  double(x) / double(m + 1) < double(m + 1)) {
        		ans = m;
        		break;
        	}

        	if (double(m) > double(x) / double(m)) {
        		r = m;
        		continue;
        	}

        	if (double(x) / double(m + 1) == double(m + 1)) {
        		ans = m + 1;
        		break;
        	}

        	if (double(x) / double(m + 1) > double(m + 1)) {
				l = m + 1;
				continue;
        	}
        }

        return ans;
    }
};


int main() {

	int ans = Solution().mySqrt(10240);
	cout << ans << endl;
	cout << ans * ans << endl;

	return 0;
}