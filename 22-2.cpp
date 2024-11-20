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


void read(LinkedList* ll){
	int n;
	cin >> n;
	int x;
	while(n--){
		cin >> x;
		ll->insert(x);
	}
}

void CutPaste(LinkedList* a, LinkedList* b){
	Node* target1 = a->getHead();
	Node* target2 = a->getTail();
	
	Node* temp = b->getHead();
	while(temp && temp->value != target1->value){
		temp=temp->next;
	}
	Node* s = temp->next;
	Node* current = temp;
	Node* prev = temp;
	temp = temp->next;
	while(temp && temp->value != target2->value){
		Node* t = temp;
		temp = temp->next;
		t->next = prev;
		prev = t;
	}
	current->next = temp;
	target2->next = prev;
	s->next = nullptr;
}


int main(){
	int n = 5;
	LinkedList** ll = new LinkedList* [n];
	for(int i=0; i<n; i++){
		ll[i] = new LinkedList();
		read(ll[i]);
	}
	for(int i=0; i<n; i++){
		ll[i]->print();
	}
	
	int a,b;
	cin>>a>>b;
	
	CutPaste(ll[a],ll[b]);
	for(int i=0; i<n; i++){
		ll[i]->print();
	}
	
	cout << endl << endl;
	
	return 0;
}
/*
7
14 32 10 6 41 20 30
6
37 15 23 43 44 28
9
21 21 14 130 38 50 30 46 0
5
33 129 134 130 12
6
210 0 0 260 380 130
*/
