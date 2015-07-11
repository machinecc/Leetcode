#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


bool operator < (const ListNode& l1, const ListNode& l2) {
	return l1.val < l2.val;
}



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        	return l2;

        if (l2 == NULL)
        	return l1;

        ListNode* p;
        ListNode* head;

        if (*l1 < *l2) {
        	p = l1;
        	head = l1;
        	l1 = l1->next;
        }
        else {
        	p = l2;
        	head = l2;
        	l2 = l2 -> next;
        }

        while (l1 != NULL && l2 != NULL) {
        	if (*l1 < *l2) {
        		p -> next = l1;
        		p = p -> next;
        		l1 = l1 -> next;
        	}
        	else {
        		p -> next = l2;
        		p = p -> next;
        		l2 = l2 -> next;
        	}
        }

        if (l1 == NULL) {
        	p -> next = l2;
        }
        else {
        	p -> next = l1;
        }

        return head;
    }
};


void print(ListNode* head) {
	while (head != NULL) {
		cout << head->val << "  ->  ";
		head = head -> next;
	}

	cout << endl;
}

int main() {
	//ListNode l1[5] = {ListNode(0), ListNode(2), ListNode(4), ListNode(6), ListNode(8)};
	//ListNode l2[5] = {ListNode(1), ListNode(3), ListNode(5), ListNode(7), ListNode(9)};

	ListNode l1[2] = {ListNode(0), ListNode(2)};
	ListNode l2[2] = {ListNode(1), ListNode(3)};

	int k = 1;
	for (int i = 0; i < k; ++ i) {
		l1[i].next = &(l1[i+1]);
	}

	//print(l1);

	//cout << l1[0].next->val << endl;

	for (int i = 0; i < k; ++ i) {
		l2[i].next = &(l2[i+1]);
	}


	ListNode* head = Solution().mergeTwoLists(l1, l2);

	print(head);


	return 0;
}