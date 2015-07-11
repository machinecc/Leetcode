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


using namespace std;


class MinStack {
public:
	stack<int> stk;
	stack<int> minstk;

	int minval = INT_MAX;


    void push(int x) {
        stk.push(x);

        minval = min(minval, x);

        minstk.push(minval);
    }

    void pop() {
        stk.pop();

        minstk.pop();

        if (minstk.empty())
        	minval = INT_MAX;
        else
        	minval = minstk.top();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};

int main() {



	return 0;
}