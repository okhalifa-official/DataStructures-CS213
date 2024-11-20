#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
	Node* down1;
	Node* down2;
	
	Node(){
		value = 0;
		next = nullptr;
		down1 = nullptr;
		down2 = nullptr;
	}
	Node(int v){
		value = v;
		next = nullptr;
		down1 = nullptr;
		down2 = nullptr;
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
	
	void attach(Node* node){
		if(!head){
			head = node;
			tail = node;
			size++;
			return;
		}
		tail->next = node;
		tail = tail->next;
		size++;
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

void cutConnect(LinkedList* a, LinkedList* b, LinkedList* l2){
	
	//get before middle node
	Node* dummy = new Node(0);
	dummy->next = a->getHead();
	Node* fast = a->getHead();
	Node* slow = dummy;
	while(fast->next){
		fast=fast->next;
		if(fast)fast=fast->next;
		slow=slow->next;
	}
	
	//connect
	Node* temp = b->getHead();
	Node* prev = b->getHead();
	Node* current = prev->next;
	slow->next->down1 = current;
	while(current->next){
		current=current->next;
		prev=prev->next;
	}
	slow->next->down2 = prev;
	
	//cut and paste
	Node* mid = slow->next;
	slow->next = mid->next;
	mid->next = nullptr;
	l2->attach(mid);
	
	temp->next = current;
	prev->next = nullptr;
	
	dummy->next = nullptr;
	delete dummy;
}


int main(){
	int n = 6;
	LinkedList** ll = new LinkedList*[n];
	LinkedList* l2 = new LinkedList();
	for(int i=0; i<n; i++){
		ll[i] = new LinkedList();
		read(ll[i]);
	}
	for(int i=0; i<n; i++){
		ll[i]->print();
	}
	for(int i=0; i<n; i+=2){
		cutConnect(ll[i], ll[i+1], l2);
	}
	cout << "\n";
	
	for(int i=0; i<n; i++){
		ll[i]->print();
	}
	
	cout << "\n";
	l2->print();
	
	cout << endl << endl;
	
	return 0;
}

/*

9
12 25 50 40 65 20 300 491 42
9
50 19 200 80 35 283 0 505 0
9
210 29 810 12 17 27 15 5 11
9
33 180 340 126 113 19 50 13 7
9
215 31 65 160 380 130 0 407 215
9
180 70 35 260 480 270 80 17 320

*/
