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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* h = NULL;
	ListNode* last = NULL;

    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head ->next == NULL)
        	return head;

        ListNode* p = head;
        ListNode* prev = NULL;
        int mark = 0;
        int val;
        while (p != NULL) {
        	if (mark == 0) {
        		val = p -> val;
        		++ mark;
        		prev = p;
        		p = p -> next;
        	}
        	else if (p -> val == val) {
        		++ mark;
        		p = p -> next;
        	}
        	else if (mark == 1) {
        		push(prev);
        		mark = 0;
        	}
        	else if (mark > 1) {
        		mark = 0;
        	}
        }

        if (mark == 1 && prev != NULL)
        	push(prev);

        if (last != NULL)
        	last -> next = NULL;

        return h;
    }



    void push(ListNode* q) {
    	if (last == NULL) {
    		h = q;
    		last = q;
    	}
    	else {
    		last -> next = q;
    		last = last -> next;
    	}
    }
};


int main() {
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(1);
	//ListNode* p3 = new ListNode(2);
	//ListNode* p4 = new ListNode(2);



	p1 -> next = p2;
	//p2 -> next = p3;
	//p3 -> next = p4;

	ListNode* q = Solution().deleteDuplicates(p1);

	while (q != NULL) {
		cout << q->val << " -> ";
		q = q->next;
	}

	cout << endl;

	return 0;
}