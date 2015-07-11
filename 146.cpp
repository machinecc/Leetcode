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
	int key;
	int value;

	ListNode* prev;
	ListNode* next;

	ListNode(int key, int value) : key(key), value(value), prev(NULL), next(NULL) {}
};


class LRUCache{
public:
	int capacity;
	

	ListNode dummy(0,0);
	ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> dict;



    LRUCache(int capacity) {
        this->capacity = capacity;

        dummy.next = NULL;
    }
    
    int get(int key) {
        if (head == NULL)
        	return -1;

        ListNode* p = head;

        bool found = false;

        while (p != NULL) {
        	if (p->key == key) {
        		found = true;
        		break;
        	}
        	p = p -> next;
        }

        if (found == false)
        	return -1;

        int value = p -> value;

        update_head(p);

        return p -> value;
    }

    void update_head(ListNode* p) {
    	if (p == head)
        	return;

        if (p -> prev != NULL)
        	p -> prev -> next = p -> next;

        if (p -> next != NULL)
        	p -> next -> prev = p -> prev;

        p -> prev = NULL;
        p -> next = head;

        head -> prev = p;
        head = p;
    }
    

    void set(int key, int value) {
        if ()
    }
};



int main() {



	return 0;
}