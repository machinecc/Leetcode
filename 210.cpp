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
#include "common.h"


using namespace std;



class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> links(n, vector<int>());

        for (auto it = prerequisites.begin(); it != prerequisites.end(); ++ it) {
        	links[it->second].push_back(it->first);
        }

        int idegrees[n];
        memset(idegrees, 0, n * sizeof(int));

        for (int i = 0; i < n; ++ i) {
        	for (auto it = links[i].begin(); it != links[i].end(); ++ it)
        		idegrees[*it] += 1;
        }

        // for (int i = 0; i < n; ++ i) {
        // 	cout << i << ":    ";
        // 	for (int j = 0; j < links[i].size(); ++ j)
        // 		cout << links[i][j] << ' ';
        // 	cout << endl;
        // }


        // for (int i = 0; i < n; ++ i)
        // 	cout << "idegrees " << i << "  :  " << idegrees[i] << endl;
        // cout << endl;


        unordered_set<int> visited;
        vector<int> candidates;
        vector<int> ans;

        for (int i = 0; i < n; ++ i) {
        	if (idegrees[i] == 0 && visited.find(i) == visited.end())
        		candidates.push_back(i);
        }


        while (!candidates.empty()) {
        	for (auto it = candidates.begin(); it != candidates.end(); ++ it) {
        		visited.insert(*it);
        		ans.push_back(*it);

        		for (int i = 0; i < links[*it].size(); ++ i)
        			idegrees[links[*it][i]] -= 1;
        	}

        	candidates.clear();

        	for (int i = 0; i < n; ++ i) {
        		if (idegrees[i] == 0 && visited.find(i) == visited.end())
        			candidates.push_back(i);
        	}
        }

        if (visited.size() != n)
        	return vector<int>();
        else
        	return ans;



    }
};





int main() {
	int numCourses = 4;

	//vector<pair<int, int>> prerequisites = {{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}};
	vector<pair<int, int>> prerequisites = {{1,0}, {2,0}, {3,1}, {4,2}};

	vector<int> ans = Solution().findOrder(numCourses, prerequisites);

	printvector(ans);


	return 0;
}