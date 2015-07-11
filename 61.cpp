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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (head == NULL)
    		return head;

    	int n = 1;
		ListNode* tail = head;

		while (tail -> next != NULL) {
			tail = tail -> next;
			++ n;
		}

		k = k % n;

		ListNode* p = head;
		for (int i = 1; i < n - k; ++ i)
			p = p -> next;


		tail -> next = head;
		head = p -> next;
		p -> next = NULL;

		return head;
    }
};


int main() {



	return 0;
}