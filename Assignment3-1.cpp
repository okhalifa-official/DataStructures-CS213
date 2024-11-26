#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
	
	Node(){
		value = 0;
		next = nullptr;
	}
	Node(int v){
		value = v;
		next = nullptr;
	}
	~Node(){
		delete [] next;
	}
};

class LinkedList{
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList(int v){
		Node* new_node = new Node(v);
		head = new_node;
		tail = new_node;
		size = 1;
	}
	LinkedList(){
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	
	Node* getHead(){
		return head;
	}
	
	Node* getTail(){
		return tail;
	}
	
	void setTail(Node* node){
		tail = node;
	}
	
	void setHead(Node* node){
		head = node;
	}
	
	void insert(int v){
		Node* new_node = new Node(v);
		if(!head){
			head = new_node;
			tail = new_node;
		}else{
			tail->next = new_node;
			tail = tail->next;
		}
		size++;
	}
	
	void push_front(int value){
		Node* newNode = new Node(value);
		if(!head){
			insert(value);
			return;
		}
		newNode->next = head;
		head = newNode;
		size++;
	}
	
	void print(){
		Node* current = head;
		while(current){
			cout << current->value << " -> ";
			current = current->next;
		}
		cout << "\n";
	}
	
	~LinkedList(){
		delete [] tail;
		delete [] head;
	}
};

void read(LinkedList* ll){
	int n;
	cin >> n;
	int x;
	while(n--){
		cin >> x;
		ll->insert(x);
	}
}

void removeDup(LinkedList* &a, LinkedList* &b){
	Node* aCurrent = a->getHead();
	Node* bCurrent = b->getHead();
	while(aCurrent->next&&bCurrent->next){
		if(aCurrent->next->value == bCurrent->next->value){
			Node* bTemp = bCurrent->next;
			bCurrent->next = bTemp->next;
			bTemp = nullptr;
			aCurrent = aCurrent->next;
			delete [] bTemp;
		}else{
			aCurrent = aCurrent->next;
			bCurrent = bCurrent->next;
		}
	}
}

int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	LinkedList* ll2 = new LinkedList();
	read(ll2);
	
	cout << "L1: ";ll->print();
	cout << "L2: ";ll2->print();
	
	removeDup(ll,ll2);
	cout << "L1: ";ll->print();
	cout << "L2: ";ll2->print();
	
	return 0;
}
