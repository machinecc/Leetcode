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


class Stack {
public:
	queue<int> q1;
	queue<int> q2;


    // Push element x onto stack.
    void push(int x) {
    	q2.push(x);

    	while (!q1.empty()) {
    		q2.push(q1.front());
    		q1.pop();
    	}

    	queue<int> temp = q1;
    	q1 = q2;
    	q2 = temp;
    }

    // Removes the element on top of the stack.
    void pop() {
        q1.pop();
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};



int main() {



	return 0;
}