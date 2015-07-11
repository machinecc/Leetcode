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
    int minDistance(string word1, string word2) {
        if (word1.size() > word2.size())
        	swap(word1, word2);


        int n = word1.size();
        int m = word2.size();

        //cout << word1 << "   " << word2 << endl;
        //cout << n << "   " << m << endl;


        if (m == 0)
        	return 0;

        int** f = new int*[n+1];
        for (int i = 0; i <= n; ++ i)
        	f[i] = new int[m+1];

        
        for (int j = 0; j <= m; ++ j) 
        	f[0][j] = j;

        for (int i = 0; i <= n; ++ i)
        	f[i][0] = i;

        for (int i = 1; i <= n; ++ i) {
        	for (int j = 1; j <= m; ++ j) {

        		if (word1[i-1] == word2[j-1]) {
        			f[i][j] = f[i-1][j-1];
        		}
        		else {
        			f[i][j] = min( min(f[i-1][j-1], f[i-1][j]), f[i][j-1] ) + 1;
        			//cout << " i =  " << i << "   j = " << j << "     f[i][j] = " << f[i][j] << endl;
        		}
        	}
        }



        int mindist = INT_MAX;

        for (int j = 0; j <= m; ++ j) {
        	mindist = min(mindist, f[n][j] + m - j);
        }


        for (int i = 0; i <= n; ++ i)
        	delete [] f[i];
        delete [] f;

        return mindist;
    }
};


int main() {

	cout << Solution().minDistance("aihfk","hk") << endl;

	return 0;
}