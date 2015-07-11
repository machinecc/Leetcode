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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = numCourses;

        if (n == 1)
        	return true;

        bool pr[n*n];
        fill(pr, pr + n * n, false);

        int degrees[n];
        memset(degrees, 0, n * sizeof(int));

        for (auto it = prerequisites.begin(); it != prerequisites.end(); ++ it) {
        	pr[ it->second * n + it -> first ] = true;
        }

        for (int i = 0; i < n; ++ i) {
        	for (int j = 0; j < n; ++ j) {
        		if (pr[j * n + i] == true)
        			degrees[i] += 1;
        	}
        }

        // cout << "degrees:" << endl;
        // for (int i = 0; i < n; ++ i)	
        // 	cout << i << " : " << degrees[i] << endl;
        // cout << endl << endl;


        bool visited[n];
        fill(visited, visited + n, false);



        vector<int> v;

        while (true) {
        	v.clear();

        	for (int i = 0; i < n; ++ i) {
        		if (visited[i] == false && degrees[i] == 0)
        			v.push_back(i);
        	}

        	if (v.size() == 0)
        		break;

        	for (auto it = v.begin(); it != v.end(); ++ it) {
        		visited[*it] = true;

        		for (int j = 0; j < n; ++ j) {
        			if (pr[(*it) * n + j] == true) {
        				degrees[j] -= 1;
        			}
        		}
        	}


        // 	printvector(v);
        // 	cout << endl;


        // 	        cout << "degrees:" << endl;
        // for (int i = 0; i < n; ++ i)	
        // 	cout << i << " : " << degrees[i] << endl;
        // cout << endl << endl;
        };

        bool ans = true;

        for (int i = 0; i < n; ++ i) {
        	if (visited[i] == false) {
        		ans = false;
        		break;
        	}
        }

        return ans;
    }
};



int main() {
	int numCourses = 10;

	vector<pair<int, int>> prerequisites = {{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}};

	cout << Solution().canFinish(numCourses, prerequisites) << endl;

	return 0;
}