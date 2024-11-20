#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
	Node* up;
	Node* down;
	
	Node(){
		value = 0;
		next = nullptr;
		up = nullptr;
		down = nullptr;
	}
	Node(int v){
		value = v;
		next = nullptr;
		up = nullptr;
		down = nullptr;
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
			cout << current->value << " [ ";
			Node* temp = current;
			while(temp->up){
				cout << temp->up->value << " ";
				temp = temp->up;
			}
			cout << "] - [ ";
			temp = current;
			while(temp->down){
				cout << temp->down->value << " ";
				temp = temp->down;
			}
			cout << "]\n";
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

void Remove(LinkedList* ll, int value){
	Node* current = ll->getHead();
	while(current){
		Node* temp = current;
		while(temp->up){
			if(temp->up->value == value){
				Node* t = temp->up;
				temp->up = t->up;
				t->up = nullptr;
				delete t;
				return;
			}
			temp = temp->up;
		}
		temp = current;
		while(temp->down){
			if(temp->down->value == value){
				Node* t = temp->down;
				temp->down = t->down;
				t->down = nullptr;
				delete t;
				return;
			}
			temp = temp->down;
		}
		current = current->next;
	}
}

void read(LinkedList* ll){
	int n;
	cin >> n;
	int x;
	while(n--){
		int k;
		cin >> x;
		ll->insert(x);
		cin >> k;
		Node* curr = ll->getTail();
		for(int i=0; i<k; i++){
			cin >> x;
			curr->up = new Node(x);
			curr = curr->up;
		}
		curr = ll->getTail();
		for(int i=0; i<k; i++){
			cin >> x;
			curr->down = new Node(x);
			curr = curr->down;
		}
	}
}


int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->print();
	
	int x;
	while(cin >> x){
		Remove(ll, x);
		ll->print();
	}
	
	cout << endl << endl;
	
	return 0;
}

/*

4
-10 1
20   
22
-13 2
23 40
33 12
-7 4
42 17 41 18
25 90 0 0  
-9 1
80   
43

*/
