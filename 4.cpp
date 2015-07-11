#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> data = merge(nums1, nums2);

    	int count = data.size();

    	if (count % 2 != 0)
    		return data[(count-1)/2];
    	else 
    		return (data[count/2] + data[count/2 - 1])/2.0;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    	if (nums2.size() == 0)
    		return nums1;
    	else if (nums1.size() == 0)
    		return nums2;

    	vector<int> data;

    	int count = 0;

        int i = 0;
        int j = 0;

        while (count < nums1.size() + nums2.size()) {
        	if (nums1[i] <= nums2[j]) {
        		data.push_back(nums1[i]);
        		++ i;

        		if (i == nums1.size()) {
        			for (int idx = j; idx < nums2.size(); ++ idx)
        				data.push_back(nums2[idx]);

        			break;
        		}
        	}
        	else {
        		data.push_back(nums2[j]);
        		++ j;

        		if (j == nums2.size()) {
        			for (int idx = i; idx < nums1.size(); ++ idx) 
        				data.push_back(nums1[idx]);

        			break;
        		}
        	}
        	++ count;
        }

        return data;


    }
};


int main() {


	
	return 0;
}