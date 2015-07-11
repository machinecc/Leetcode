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
#include <cassert>


using namespace std;


struct Node {
	int id;
	int val;
	Node* left;
	Node* right; 

	Node() : id(-1), val(-1), left(NULL), right(NULL) {
	}
};


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        if (n <= 1)
        	return n;

        Node* nodes = new Node[n];

        for (int i = 0; i < n; ++ i)
        	nodes[i].id = i;

        for (int i = 0; i < n; ++ i) {
        	if (i - 1 >= 0 && ratings[i] > ratings[i-1])
        		nodes[i-1].right = &nodes[i];

        	if (i + 1 < n && ratings[i] > ratings[i+1])
        		nodes[i+1].left = &nodes[i];
       	}

       	for (int i = 0; i < n; ++ i) {
       		if (i == 0 && nodes[i+1].left == NULL)
       			nodes[i].val = 1;
       		else if (i == n-1 && nodes[i-1].right == NULL)
       			nodes[i].val = 1;
       		else if (nodes[i-1].right == NULL && nodes[i+1].left == NULL)
       			nodes[i].val = 1;
       	}


   //     	for (int i = 0; i < n; ++ i) {
   //     		cout << i << ':' << endl;
   //     		cout << nodes[i].val << endl;
   //     		if (nodes[i].left == NULL)
   //     			cout << 0 << ' ';
   //     		else
   //     			cout << 1 << ' ';

			// if (nodes[i].right == NULL)
   //     			cout << 0 << ' ';
   //     		else
   //     			cout << 1 << ' ';

   //     		cout << endl << endl;
   //     	}

       	for (int i = 0; i < n; ++ i) {

       		if (nodes[i].val == 1) {
       			if (nodes[i].left != NULL)
       				traverse(nodes[i].left, 2);
       			if (nodes[i].right != NULL)
       				traverse(nodes[i].right, 2);
       		}
       	}


        //cout << nodes.size() << endl;

       	int sum = 0;
       	for (int i = 0; i < n; ++ i)
       		sum += nodes[i].val;

       	delete[] nodes;

        return sum;
    }

    void traverse(Node* p, int val) {

     	if (p == NULL)
    		return;

    	if (p->val < val) {
    		p->val = val;
    		traverse(p->left, val + 1);
    		traverse(p->right, val + 1);
    	}    	

    }
};

int main() {
	vector<int> ratings = {1,2,2};

	cout << Solution().candy(ratings) << endl;

	return 0;
}