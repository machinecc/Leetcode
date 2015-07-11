#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> data = nums;
        std::sort(data.begin(), data.end());
        
        vector<int> diffs;
        for (int i = 0; i < data.size(); ++i) {
            diffs.push_back(target - data[i]);
        }
        
        int val1 = 0;
        int val2 = 0;

        for (int i = 0; i < data.size(); ++ i) {
        	val1 = diffs[i];
        	if (binary_search(data.begin(), data.end(), val1) == true) {
        		val2 = target - val1;
        		break; 
        	}
        }


        int index1 = -1;
        int index2 = -1;
        for (int i = 0; i < nums.size(); ++ i) {
        	if (index1 == -1 && nums[i] == val1) {
        		index1 = i+1;
        	}
        	else if (nums[i] == val2) {
        		index2 = i+1;
        	}
        }

        
		vector<int> result;
		result.push_back(min(index1, index2));
		result.push_back(max(index1, index2));

		return result;        
    }
};

int main() {

	vector<int> nums;
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(0);
	//nums.push_back(7);

	vector<int> result = Solution().twoSum(nums, 0);

	for (int i = 0; i < result.size(); ++ i) {
		cout << result[i] << endl;
	}


	return 0;
}