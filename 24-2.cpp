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
	
	void print(int k){
		Node* current = head;
		Node* back = head;
		for(int i=0; i<k; i++){
			current=current->next;
		}
		//print current
		LinkedList* l = new LinkedList();
		Node* temp = current;
		while(temp){
			l->push_front(temp->value);
			temp = temp->extra;
		}
		temp = l->getHead();
		while(temp){
			cout << temp->value << " -> ";
			temp=temp->next;
		}
		cout << "\n";
		delete temp;
		
		while(current->next){
			current = current->next;
			back=back->next;
		}
		//print back
		LinkedList* r = new LinkedList();
		temp = back;
		while(temp){
			r->push_front(temp->value);
			temp = temp->extra;
		}
		temp = r->getHead();
		while(temp){
			cout << temp->value << " -> ";
			temp=temp->next;
		}
		cout << "\n";
		delete temp;
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
	for(int i=1; i<=n/2; i++){
		cin >> x;
		ll->insert(x);
		Node* current = ll->getTail();
		for(int j=0; j<i; j++){
			cin >> x;
			Node* newNode = new Node(x);
			current->extra = newNode;
			current = newNode;
		}
	}
	cin >> x;
	ll->insert(x);
	Node* current = ll->getTail();
	for(int j=0; j<n/2+1; j++){
		cin >> x;
		Node* newNode = new Node(x);
		current->extra = newNode;
		current = newNode;
	}
	for(int i=n/2; i>0; i--){
		cin >> x;
		ll->insert(x);
		Node* current = ll->getTail();
		for(int j=0; j<i; j++){
			cin >> x;
			Node* newNode = new Node(x);
			current->extra = newNode;
			current = newNode;
		}
	}
}


int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->print(2);
	
	
	cout << endl << endl;
	
	return 0;
}
