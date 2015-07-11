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
	
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ans(0);
        ListNode* curr = &ans;

        while (head != NULL) {
            curr -> next = head;
            curr = curr -> next;

            int val = head->val;

            while (head && head->val == val)
                head = head -> next;
        }

        if (curr != NULL)
            curr->next = NULL;

        return ans.next;

    }
};


int main() {
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(1);
	ListNode* p3 = new ListNode(2);
	ListNode* p4 = new ListNode(2);



	p1 -> next = p2;
	p2 -> next = p3;
	p3 -> next = p4;

	ListNode* q = Solution().deleteDuplicates(p1);

	while (q != NULL) {
		cout << q->val << " -> ";
		q = q->next;
	}

	cout << endl;

	return 0;
}