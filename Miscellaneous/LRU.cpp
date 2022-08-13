// LRU Cache Implementation Using Linked List and Map

#include<bits/stdc++.h>
using namespace std;

class DLLNode {
public:
	int key;
	int value;
	DLLNode* next;
	DLLNode* prev;
	DLLNode(int key, int value) {
		this->key = key;
		this->value = value;
		this->prev = NULL;
		this->next = NULL;
	}
};

unordered_map<int, DLLNode*> cache;
int size;
int capacity;
DLLNode* head = new DLLNode(-1, -1);
DLLNode* tail = new DLLNode(-1, -1);

void addNodeAtHead(DLLNode *node) {
	node->prev = head;
	node->next = head->next;
	head->next->prev = node;
	head->next = node;
	return;
}

void removeNode(DLLNode* node) {
	DLLNode* prev = node->prev;
	DLLNode* next = node->next;
	prev->next = next;
	next->prev = prev;
}

int removeFromTail() {
	DLLNode* temp = tail->prev;
	removeNode(temp);
	return temp->key;
}

void moveToHead(DLLNode* node) {
	cout<<"Accessed the key "<<node->key<<endl;
	removeNode(node);
	addNodeAtHead(node);
}

int get(int k) {
	if(cache.count(k) == 0) {
		cout<<"Value is not present in the cache"<<endl;
		return INT_MIN;
	}
	DLLNode* node = cache[k];
	moveToHead(node);
	return node->value;
}

void put(int k, int v) {
	if(cache.count(k) == 0) {
		// key is not there
		DLLNode* node = new DLLNode(k, v);
		cache[k] = node;
		cout<<"Added a key "<<k<<endl;
		addNodeAtHead(node);
		capacity++;
		if(capacity > size) {
			int removeKey = removeFromTail();
			cout<<"As the cache is full we need to remove the key "<<removeKey<<endl;
			capacity--;
			cache.erase(removeKey);
		}
	} else {
		// key is already present
		DLLNode* node = cache[k];
		node->value = v;
		moveToHead(node);
	}
}

int main(int argc, char const *argv[]) {
  
	cout<<"Please enter the size of the cache\n";
	cin>>size;
	cout<<"Size of cache is "<<size<<endl;
	head->next = tail;
	tail->prev=  head;
	int q;
	cin>>q;
	while(q--) {
		char ch;
		int k, v;
		cin>>ch;
		if(ch == 'p') {
			cin>>k>>v;
			put(k, v);
		} else {
			cin>>k;
			int v = get(k);
			cout<<"Value for key "<<k<<" is "<<v<<endl;
		}
	}

	return 0;
}
