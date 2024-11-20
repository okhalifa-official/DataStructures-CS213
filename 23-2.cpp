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
	
	int getSize(){
		return size;
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
	for(int j=1; j<=n; j++){
		cin >> x;
		ll->insert(x);
		Node* temp = ll->getTail();
		for(int i=1; i<=j; i++){
			cin >> x;
			temp->extra = new Node(x);
			temp = temp->extra;
		}
	}
}

bool palindrome(LinkedList* ll){
	LinkedList* other = new LinkedList();
	Node* curr = ll->getHead();
	for(int i=0; i<ll->getSize()/2; i++){
		other->push_front(curr->value);
		curr = curr->next;
	}
	if(ll->getSize()%2==1)curr = curr->next;
	while(curr){
		if(curr->value != other->pop_front()->value){
			return 0;
		}
		curr = curr->next;
	}
	return 1;
}

bool makeMirror(LinkedList* ll, int target){
	LinkedList* pal = new LinkedList();
	Node* current = ll->getHead();
	while(current){
		Node* temp = current;
		while(temp && temp->value != target){
			temp = temp->extra;
		}
		if(temp){
			while(temp->extra){
				pal->insert(temp->extra->value);
				temp = temp->extra;
			}
		}
		current = current->next;
	}
	
	pal->print();
	return palindrome(pal);
}


int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->print();
	cout << makeMirror(ll, 91) << "\n";
	ll->print();
	
	
	cout << endl << endl;
	
	return 0;
}

/*

7
20 77 
24 15 81
50 42 36 17
70 13 21 91 30 
90 18 70 50 30 30
55 61 25 28 91 25 10
32 37 91 14 14 10 25 30

*/
