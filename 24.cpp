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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
        	return head;

        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* prev = NULL;
        //ListNode* next = 

        while (left!= NULL && right != NULL) {
        	if (prev != NULL)
        		prev -> next = right;

        	left->next = right->next;
        	right->next = left;

        	if (prev == NULL) 
        		head = right;
        	
        	prev = left;
        	left = left->next;
        	if (left != NULL)
        		right = left -> next;	
        }

        return head;

    }
};

int main() {



	return 0;
}