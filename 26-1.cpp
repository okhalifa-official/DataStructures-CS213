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

void cutFlipAndReturn(LinkedList* ll, int val){
	Node* s = nullptr;
	Node* e = nullptr;
	Node* mid = nullptr;
	
	//target at first - edge case
	Node* dummy = new Node(0);
	dummy->next = ll->getHead();
	Node* current = dummy;
	
	int ind = -1;
	while(current->next){
		if(current->next->value == val){
			if(!s){
				s=current;
				mid=s;
			}else{
				if(e)e->extra = current;
				e=current;
				if(ind>0){
					mid = mid->extra;
				}else{
					if(!mid->extra)mid->extra = e;
				}
				ind*=-1;
			}
		}
		current = current->next;
	}
	
	Node* temp = s;
	Node* h;
	Node* t;
	
	s=s->next;
	temp->next = e->next->next;
	
	e->next->next = mid->next;
	h = mid->next->next;
	t = mid;
	mid->next->next = s;
	mid->next = nullptr;
	
	temp = h;
	while(temp){
		cout << temp->value << " -> ";
		temp = temp->next;
	}
	cout << "\n";
	
	dummy->next = nullptr;
	delete dummy;
}


int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->print();
	cutFlipAndReturn(ll,10);
	ll->print();
	
	
	cout << endl << endl;
	
	return 0;
}

/*
22
15 70 33 10 12 10 40 31 17 10 50 10 60 80 36 10 10 14 6 10 2 8
*/
