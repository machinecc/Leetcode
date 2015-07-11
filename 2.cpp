#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = addTwoNodes(l1, l2, 0);

        return head;

    }

    ListNode* addTwoNodes(ListNode* l1, ListNode* l2, int additive) {
        if (l1 == NULL && l2 == NULL) {
            if (additive == 0){
                return NULL;
            }
            else {
                ListNode* res = new ListNode(1);
                return res;
            }
        }

        ListNode* res;

        if (l1 == NULL) {
            res = new ListNode(l2->val + additive);
        }
        else if (l2 == NULL) {
            res = new ListNode(l1->val + additive);
        }
        else {
            res = new ListNode(l1->val + l2->val + additive);
        }

        int k = 0;

        if (res -> val >= 10) {
            res -> val -= 10;
            k = 1;
        }

        if (l1 == NULL) {
            res -> next =  addTwoNodes(NULL, l2->next, k);
        }
        else if (l2 == NULL) {
            res -> next =  addTwoNodes(l1->next, NULL, k);
        }
        else {
            res -> next =  addTwoNodes(l1->next, l2->next, k);
        }

        return res;
    }
};



ListNode* make_list(int vals[], int count) {
    ListNode* prev = NULL;
    ListNode* head = NULL;

    for (int i = 0; i < count; ++ i) {
        ListNode* node = new ListNode(vals[i]);

        if (prev != NULL) {
            prev -> next = node;
        }
        else {
            head = node;
        }

        prev = node;
    }

    return head;
}

void print(ListNode* head) {
    while (head != NULL) {
        cout << head -> val << endl;
        head = head -> next;
    }
}


int main() {
    int val1[] = {2, 4, 3};
    int val2[] = {0};

    ListNode* head1 = make_list(val1, 3);
    ListNode* head2 = make_list(val2, 1);

    ListNode* result = Solution().addTwoNumbers(head1, head2);

    print(result);


	return 0;
}