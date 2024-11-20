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

void AttachAfterMax(LinkedList* ll, Node* pnn){
	if(!ll->getHead()){
		ll->setHead(pnn);
		ll->setTail(pnn);
		ll->getHead()->extra = pnn;
		return;
	}
	Node* max = ll->getHead()->extra;
	if(pnn->value>max->value){
		ll->getTail()->next = pnn;
		ll->setTail(pnn);
		ll->getHead()->extra = pnn;
	}else{
		pnn->next = max->next;
		max->next = pnn;
		if(max==ll->getTail()){
			ll->setTail(pnn);
		}
	}
}

int main(){
	LinkedList* ll = new LinkedList();
	int x;
	while(cin >> x){
		Node* pnn = new Node(x);
		AttachAfterMax(ll, pnn);
		ll->print();
	}
	
	
	cout << endl << endl;
	
	return 0;
}
