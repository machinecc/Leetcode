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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* pre = &dummy;
        ListNode* anchor = head;

        while (anchor != NULL && anchor -> val < x) {
            pre = anchor;
            anchor = anchor -> next;
        }

        if (anchor == NULL)
            return head;
        else
            anchor = pre;



        ListNode* p = anchor -> next;

        while (p != NULL) {
            if (p->val < x) {
                pre -> next = p -> next;
                p -> next = anchor -> next;
                anchor -> next = p;
                p = pre -> next;
                anchor = anchor -> next;
            }
            else {
                pre = p;
                p = p -> next;
            }
        }

        return dummy.next;
    }
};


int main() {



	return 0;
}