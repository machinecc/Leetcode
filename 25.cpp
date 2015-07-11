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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
        	return head;

        ListNode* left = head;
        ListNode* right = left;

        for (int i = 0; i < k - 1; ++ i) {
            if (right -> next == NULL)
                return head;
            else
                right = right -> next;
        }


        ListNode* prev = NULL;
        ListNode* next = NULL;



        while (left!= NULL && right != NULL) {
            next = right -> next;
        	right -> next = NULL;

            //cout << "left = " << left -> val << endl;
            //cout << "right = " << right -> val << endl;

            reversePair(left, left->next);

            if (prev != NULL)
                prev -> next = right;
            else {
                head = right;
            }

            prev = left;
            left->next = next;
            left = left -> next;
            right = left;

            for (int i = 0; i < k - 1; ++ i) {
                if (right == NULL || right -> next == NULL) {
                    return head; 
                }
                else
                    right = right -> next;
            }
        }

        return head;

    }


    void reversePair(ListNode* p, ListNode* q) {
        if (q == NULL)
            return;
        ListNode* next = q -> next;
        q -> next = p ;
        reversePair(q, next);
    }
};

int main() {

    ListNode* head = new ListNode(1);
    ListNode* p = head;

    p->next = new ListNode(2);
    p = p->next;

    p->next = new ListNode(3);
    p = p->next;
    
    ListNode* q = Solution().reverseKGroup(head, 3);
    while (q != NULL) {
        cout << q->val << ' ';
        q = q->next;
    }

    cout << endl;

	return 0;
}