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
	
	void push_front(Node* value){
		if(!head){
			head = value;
			tail = value;
			return;
		}
		value->extra = head;
		head = value;
		size++;
	}
	
	void print(){
		Node* current = head;
		while(current){
			Node* temp = current;
			while(temp){
				cout << temp->value << "-";
				if(temp->next){
					cout << temp->next->value;
				}
				cout << " -> ";
				temp = temp->extra;
			}
			cout << "\n";
			current = current->next;
		}
		cout << "\n";
	}
	
	void Special_Display(){
		int n = 0;
		int x = 0;
		LinkedList* stack = new LinkedList();
		Node* current = head;
		while(current){
			Node* newNode = new Node(current->value);
			newNode->next = current->next;
			stack->push_front(newNode);
			current = current->extra;
			n++;
		}
		current = stack->getHead();
		
		while(current){
			x = 0;
			Node* temp = current;
			while(temp && x<n){
				cout << temp->value << " ";
				temp = temp->next;
				x++;
			}
			cout << "\n";
			current = current->extra;
			n--;
		}
	}
	
	~LinkedList(){
		tail = nullptr;
		Node* current = head;
		while(current){
			head = head->extra;
			current->next = nullptr;
			current->extra = nullptr;
			delete current;
			current = head;
		}
	}
};


void read(LinkedList* ll){
	int n;
	cin >> n;
	int x;
	Node* prev = ll->getHead();
	Node* ably = nullptr;
	for(int j=0; j<n; j++){
		cin >> x;
		ll->insert(x);
		if(j>0){
			ably = prev->extra;
			ably->next = ll->getTail();
			ably = ably->extra;
		}
		Node* current = ll->getTail();
		for(int i=0; i<n-j-1; i++){
			cin >> x;
			Node* newNode = new Node(x);
			current->extra = newNode;
			current = current->extra;
			if(j>0){
				ably->next = current;
				ably = ably->extra;
			}
		}
		if(j>0){
			prev = prev->next;
		}else{
			prev = ll->getHead();
		}
	}
}

int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->Special_Display();
	
	
	cout << endl << endl;
	
	return 0;
}
/*
7
12 34 50 11 130 15 72
56 32 26 93 51 12
24 12 176 74 145
11 51 111 661
34 22 10
57 810
350
*/
