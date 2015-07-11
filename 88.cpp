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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if ( n == 0 )
        	return;

        if ( m == 0 ) {
        	nums1 = nums2;
        	return;
        }


        int c = m + n - 1;
        int p = m - 1;
        int q = n - 1;


        while (p >=0  && q >= 0 && c >= 0) {
        	if (nums1[p] > nums2[q]) {
        		nums1[c] = nums1[p];
        		-- c;
        		-- p;
        	}
        	else {
        		nums1[c] = nums2[q];
        		-- c;
        		-- q;
        	}
        }

        if (q >= 0) {
        	for ( ; q >= 0; -- q) {
        		nums1[c] = nums2[q];
        		-- c;
        	}
        }

        if (p >= 0) {
        	for (; p >= 0; -- p) {
        		nums1[c] = nums1[p];
        		-- c;
        	}
        }
    }
};


int main() {
	vector<int> nums1 = {2,4,6,0,0};
	int m = 1;
	vector<int> nums2 = {1,3};
	int n = 1;

	Solution().merge(nums1, 3, nums2, 2);


	for (int i = 0; i < nums1.size(); ++ i)
		cout << nums1[i] << ' ';
	cout << endl;


	return 0;
}