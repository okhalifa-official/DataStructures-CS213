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
	
	void insertList(LinkedList* ll){
		Node* dummy = new Node(0);
		dummy->next = head;
		Node* current1 = dummy;
		Node* current2 = ll->getHead();
		while(current1->next){
			if(current2->value <= current1->next->value){
				Node* newNode = new Node(current2->value);
				newNode->next = current1->next;
				current1->next = newNode;
				current2 = current2->next;
				if(!current2)return;
			}
			current1=current1->next;
		}
		dummy->next = nullptr;
		delete dummy;
		while(current2){
			insert(current2->value);
			current2=current2->next;
		}
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

int main(){
	
	LinkedList* ll = new LinkedList();
	LinkedList* l2 = new LinkedList();
	read(ll);
	read(l2);
	ll->print();
	l2->print();
	ll->insertList(l2);
	ll->print();
	l2->print();
	
	
	cout << endl << endl;
	
	return 0;
}
