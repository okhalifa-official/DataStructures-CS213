#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
	Node* extra;
	Node* left;
	Node* right;
	
	Node(){
		value = 0;
		next = nullptr;
		extra = nullptr;
		left = nullptr;
		right = nullptr;
	}
	Node(int v){
		value = v;
		next = nullptr;
		extra = nullptr;
		left = nullptr;
		right = nullptr;
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
	
	Node* pop_front(){
		if(!head){
			return nullptr;
		}
		Node* temp = head;
		head = temp->next;
		temp->next = nullptr;
		return temp;
		size--;
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

Node* popLeftAndRight(LinkedList* ll, int target){
	Node* prev = ll->getHead();
	Node* current = prev->next;
	while(current->next && current->next->value != target){
		current->extra = prev;
		prev = current;
		current = current->next;
	}
	
	Node* mid = current->next;
	current->next = mid->next;
	mid->left->extra->next = mid;
	mid->next = mid->right->next;
	mid->right->next = nullptr;
	Node* s = mid->left;
	
	return s;
}

void connect(LinkedList* ll, int target, int l, int r){
	Node* prev = ll->getHead();
	Node* curr = prev;
	for(int i=0; i<l; i++){
		curr = curr->next;
	}
	while(curr && curr->value!=target){
		prev=prev->next;
		curr=curr->next;
	}
	curr->left = prev;
	prev = curr;
	for(int i=0; i<r; i++){
		prev = prev->next;
	}
	curr->right = prev;
}


int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->print();
	connect(ll, 20, 2, 3);
	Node* s = popLeftAndRight(ll, 20);
	while(s){
		cout << s->value << " -> ";
		s=s->next;
	}
	cout << "\n";
	ll->print();
	
	
	
	cout << endl << endl;
	
	return 0;
}

/*
14
33 17 7 9 10 13 5 30 20 60 2 8 14 6
*/
