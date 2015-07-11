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
#include "common.h"


using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* p = head;

        while (p) {
        	if (p->val == val) {
        		prev->next = p->next;
        		delete p;
        		p = prev -> next;
        	}
        	else {
        		prev = prev -> next;
        		p = p -> next;	
        	}
        }

        return dummy.next;
    }
};




int main() {



	return 0;
}