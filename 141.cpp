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
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;

        if (p == NULL)
        	return false;

        do {
        	q = q -> next;

        	if (q == NULL)
        		break;
        	else
        		q = q -> next;

        	p = p -> next;
        } while (p != NULL && q!= NULL && p != q);

        if (p == NULL || q == NULL)
        	return false;

        return true;

    }
};


int main() {



	return 0;
}