#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;

        for (int i = 0; i < n; ++ i) {
        	if (p->next != NULL)
        		p = p -> next;
        	else {
        		return head -> next;
        	}
        }

        ListNode* q = head;

        while (p -> next != NULL) {
        	p = p -> next;
        	q = q -> next;
        }



        q -> next = q->next->next;
        return head;
    }
};


int main() {



	return 0;
}