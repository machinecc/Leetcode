#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;


class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {    	
		vector<int>& data = nums;


		//vector<int>& data = nums;        
		sort(data.begin(), data.end());

		int resval = INT_MAX;
		int minval = INT_MAX;


		int n = data.size();

		for (int i = 0; i < n - 2; ++ i) {
			int a = data[i];

			int p = i + 1;
			int q = n - 1;

			while (p < q) {
				int val = a + data[p] + data[q];
				if (abs(val - target) < minval) {
					minval = abs(val - target);
					resval = val;
				}

				if (val < target) {
					++ p;
				}
				else if (val > target) {
					-- q;				
				}
				else if (val == target) {					
					++p;
					break;
				}
			}

			if (minval == 0)
				break;
		}
		return resval;
    }
};


int main() {
	//vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> nums = {1, 2, 3, 0, -1, -2, -3};
	//vector<int> nums = {1, 10, 100, 0, -1, -10, -100};

	/*
	for (auto it = result.begin(); it != result.end(); ++ it)
	{
		for (auto p = (*it).begin(); p != (*it).end(); ++ p)
			cout << (*p) <<  ' ';
		cout << endl;
	}
	*/

	cout << Solution().threeSumClosest(nums, 1) << endl;

	//cout << (nums == data) << endl;


	return 0;
}