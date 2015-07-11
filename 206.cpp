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
    ListNode* reverseList_1(ListNode* head) {
    	stack<ListNode*> stk;

    	ListNode* p = head;

    	while (p != NULL) {
    		stk.push(p);
    		p = p -> next;
    	}


    	ListNode dummy(0);
    	p = &dummy;

    	while (!stk.empty()) {
    		p -> next = stk.top();
    		stk.pop();
    		p = p -> next;
    	}

    	if (head != NULL)
    		head -> next = NULL;

    	return dummy.next;
    }


    ListNode* reverseList(ListNode* head) {
    	ListNode* rhead = NULL;
    	ListNode* p = head;

    	while (p != NULL) {
    		ListNode* tmp = p -> next;
    		p -> next = rhead;
    		rhead = p;
    		p = tmp;
    	}

    	return rhead;
    }
};




int main() {



	return 0;
}