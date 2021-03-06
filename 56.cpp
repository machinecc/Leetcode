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


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
 };

bool lessthan(Interval& a, Interval& b) {
	if (a.start < b.start)
		return true;
	else if (a.start > b.start)
		return false;
	else
		return a.end < b.end;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
 		sort(intervals.begin(), intervals.end(), lessthan);

 		int n = intervals.size();

 		if (n == 1)
 			return intervals;

 		vector<Interval> ans;

 		int i = 0;
 		int p = -1;

 		while (i < n) {
 			if (i == 0) {
 				ans.push_back(intervals[i]);
 				p = 0;	
 			}
 			else {
 				Interval& prev_interval = ans[p];
 				Interval& curr_interval = intervals[i];

 				if (curr_interval.start > prev_interval.end) {
 					ans.push_back(curr_interval);
 					++ p;
 				}
 				else if (curr_interval.start == prev_interval.end) {
 					prev_interval.end = curr_interval.end;
 				}
 				else {
 					if (curr_interval.end <= prev_interval.end) {
 						// Do nothing
 					}
 					else {
 						prev_interval.end = curr_interval.end;
 					}
 				}
 			}

 			++ i;
 		}

 		return ans;


    }
};


int main() {

	vector<Interval> intervals = {Interval{1,3}, Interval{2,6}, Interval{8,10}, Interval{15,18}};

	vector<Interval> ans = Solution().merge(intervals);

	for (int i = 0; i < ans.size(); ++ i) {
		cout << "[" << ans[i].start << ',' << ans[i].end << "]" << endl;
	}

	return 0;
}