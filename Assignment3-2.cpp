#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
	
	Node(){
		value = 0;
		next = nullptr;
	}
	Node(int v){
		value = v;
		next = nullptr;
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

void GetSum(Node* start, Node* end, LinkedList* ll){
	Node* s = ll->getHead();
	Node* e = nullptr;
	while(s && s->value != start->value){s=s->next;}
	e = s;
	while(e && e->value != end->value){e=e->next;}
	int total = 0;
	while(s && s->next != e){
		total += s->next->value;
		s=s->next;
	}
	cout << total << "\n";
}

void TraverseRange(LinkedList* a, LinkedList* b){
	Node* s = a->getHead();
	Node* e = s->next;
	while(e){
		GetSum(s,e,b);
		s = s->next;
		e = e->next;
		if(e){
			e = e->next;
			s = s->next;
		}
	}
}


int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	LinkedList* ll2 = new LinkedList();
	read(ll2);
	
	cout << "L1: ";ll->print();
	cout << "L2: ";ll2->print();
	TraverseRange(ll,ll2);
	
	
	return 0;
}
