#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
	Node* extra;
	
	Node(){
		value = 0;
		next = nullptr;
		extra = nullptr;
	}
	Node(int v){
		value = v;
		next = nullptr;
		extra = nullptr;
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
		tail = nullptr;
		Node* temp = head;
		while(head){
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};

void cutAndReplace(LinkedList* ll){
	//create dummies
	Node* current = ll->getHead();
	for(int i=0; i<4; i++){
		Node* dummy = new Node(-9999);
		dummy->next = ll->getHead();
		ll->setHead(dummy);
	}
	Node* prev = ll->getHead();
	Node* left = current;
	Node* right = current;
	while(current->next){
		if(current->next->value > right->next->value){
			left = right;
			right = current;
			right->next->extra = prev;
		}
		prev = prev->next;
		current=current->next;
	}
	//delete the dummies
	for(int i=0; i<4; i++){
		Node* dummy = ll->getHead();
		ll->setHead(dummy->next);
		dummy->next = nullptr;
		delete dummy;
	}
	
	left->extra = left->next;
	left->next->extra->extra = left->next->extra->next;
	left->next->extra->next = right->next->next;
	ll->getTail()->next = left->next;
	ll->setTail(right->next);
	ll->getTail()->next = nullptr;
	
	Node* temp = left->next;
	left->next = ll->getHead();
	ll->setHead(temp->extra->extra);
}

void read(LinkedList* ll){
	int n;
	cin >> n;
	int x;
	while(n--){
		cin >> x;
		ll->insert(x);
	}
}


int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->print();
	cutAndReplace(ll);
	ll->print();
	
	
	cout << endl << endl;
	
	return 0;
}
