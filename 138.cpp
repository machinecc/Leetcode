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



struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode* chead;

		unordered_map<RandomListNode*, RandomListNode*> copies;

		RandomListNode dummy = RandomListNode(0);
		RandomListNode* prev = &dummy;

		RandomListNode* p = head;

		while (p != NULL) {
			RandomListNode* cp = new RandomListNode(p->label);
			copies[p] = cp;

			prev -> next = cp;
			prev = cp;

			p = p -> next;
		}

		p = head;
		while (p != NULL) {
			RandomListNode* cp = copies[p];
			cp -> random = copies[p->random];
			p = p -> next;
		}

		return dummy.next;
    }
};

int main() {



	return 0;
}