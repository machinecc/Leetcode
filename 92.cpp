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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if (m == n)
    		return head;
        
        
        ListNode* left_anchor = NULL;
        ListNode* right_anchor = NULL;

        ListNode dummy(0);    
        dummy.next = head;

        ListNode* p;
        ListNode* prev;
        ListNode* q;

        for (int i = 1; i < n; ++ i) {

        	if (i == 1) {
        		p = head;
        		prev = &dummy;
        	}

        	if (i == m) {
        		left_anchor = prev;
        		right_anchor = p;
        		q = p -> next;
        	}
        	



        	ListNode* temp = q -> next;
        	q -> next = p;
        	p -> next = prev;
        	prev = p;
        	p = q;
        	q = temp;

        	if (i == n - 1) {
        		left_anchor -> next = p;
        		right_anchor -> next = q;
        	}
        }



        return dummy.next;
    }
};

int main() {
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(4);
	ListNode* p5 = new ListNode(5);

	p1 -> next = p2;
	//p2 -> next = p3;
	//p3 -> next = p4;
	//p4 -> next = p5;

	ListNode* p = Solution().reverseBetween(p1, 1, 2);

	while (p != NULL) {
		cout << p->val << " -> ";
		char ch;
		cin >> ch;
	}

	cout << endl;


	return 0;
}