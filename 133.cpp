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


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
	unordered_map<int, UndirectedGraphNode*> nodes;		

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (node == NULL)
    		return NULL;

    	UndirectedGraphNode* head = NULL;

		unordered_set<int> visited; 
		
		vector<UndirectedGraphNode*> que;
		que.push_back(node);
		int p = 0;

		while ( p < que.size() ) {
			UndirectedGraphNode* curr = que[p];

			UndirectedGraphNode* cp = get_cp(curr);

			if (p == 0)
				head = cp;

			if (visited.find(cp->label) == visited.end()) {

				for (int i = 0; i < curr->neighbors.size(); ++ i) {
					UndirectedGraphNode* sib = curr->neighbors[i];

					UndirectedGraphNode* cp_sib = get_cp(sib);

					cp->neighbors.push_back(cp_sib);

					if (visited.find(sib->label) == visited.end()) {
						que.push_back(sib);
					}
				}

				visited.insert(cp->label);

			}

			++p;
		}

		return head;
    }


    UndirectedGraphNode* get_cp(UndirectedGraphNode* node) {
    	if (nodes.find(node->label) != nodes.end())
    		return nodes[node->label];

    	UndirectedGraphNode* cp = new UndirectedGraphNode(node -> label);
    	nodes[node->label] = cp;

    	return cp;
    }
};


int main() {



	return 0;
}