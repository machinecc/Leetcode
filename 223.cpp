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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int d1 = intersecton(A, C, E, G);
        int d2 = intersecton(B, D, F, H);

        int area1 = area(A, B, C, D);
        int area2 = area(E, F, G, H);

        // cout << "area1 = " << area1 << endl;
        // cout << "area2 = " << area2 << endl;
        // cout << "d1 = " << d1 << endl;
        // cout << "d2 = " << d2 << endl;


        return area1 + area2 - d1 * d2;
    }

    int intersecton(int a1, int a2, int b1, int b2) {
    	
    	int d = min(a2, b2) <= max(a1, b1) ? 0 : min(a2, b2) - max(a1, b1);

    	return d;
    }

    int area(int x1, int y1, int x2, int y2) {
    	return (y2 - y1) * (x2 - x1);
    }
};




int main() {
	cout << Solution().computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1) << endl;


	return 0;
}