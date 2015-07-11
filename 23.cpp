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

struct Node {
	int val;
	int idx;

	Node(int _val, int _idx) : val(_val), idx(_idx) {

	}
};

bool comp(const Node& p, const Node& q) {
	return p.val > q.val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    	vector<Node> heap;
    	ListNode* p = NULL;
    	ListNode* head = NULL;

    	for (int i = 0; i < lists.size(); ++ i) {
    		if (lists[i] != NULL) {
    			heap.push_back(Node(lists[i]->val, i));
    			lists[i] = lists[i] -> next;
    		}
    	}

    	make_heap(heap.begin(), heap.end(), comp);

    	while (heap.size() > 0) {
    		Node node = heap.front();

    		pop_heap(heap.begin(), heap.end(), comp);
    		heap.pop_back();

    		if (p == NULL) {
    			p  = new ListNode(node.val);
    			head = p;
    		}
    		else {
    			p -> next = new ListNode(node.val);
    			p = p -> next;
    		}

    		if (lists[node.idx] != NULL) {
    			heap.push_back(Node(lists[node.idx]->val, node.idx));
    			push_heap(heap.begin(), heap.end(), comp);

    			lists[node.idx] = lists[node.idx] -> next;
    		}
    	}

        return head;
    }
};




int main() {
 

  return 0;




}