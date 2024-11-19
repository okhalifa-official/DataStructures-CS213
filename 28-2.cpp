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
			Node* temp = current;
			while(temp){
				cout << temp -> value << "-";
				if(temp->next){
					cout << temp->next->value;
				}
				cout << " ";
				temp = temp->extra;
			}
			cout << "\n";
			current = current->next;
		}
		cout << "\n";
	}
	
	void sPrint(){
		Node* current = head;
		while(current){
			cout << current->value << " -> ";
			current = current->extra;
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
		Node* current = ll->getTail();
		int m;
		cin >> m;
		int rem = 1;
		Node* neg = nullptr;
		while(m--){
			cin >> x;
			Node* new_node = new Node(x);
			current->extra = new_node;
			current = current->extra;
			
			if(rem < 0){
				rem++;
			}
			if(rem == 0){
				neg->next = current;
				rem = 1;
			}
			if(x < 0){
				neg = current;
				rem = x;
			}
			
			
		}
	}
}

void fetch(LinkedList* ll, Node* s, Node* e){
	if(!ll->getHead()){
		ll->setHead(s);
		ll->setTail(e);
		e->next = nullptr;
		e->extra = nullptr;
		return;
	}
	e->next = ll->getHead();
	e->extra = ll->getHead();
	ll->setHead(s);
}

void CutPaste(LinkedList* original, LinkedList* ll){
	Node* current = original->getHead();
	while(current){
		Node* down = current;
		Node* neg = nullptr;
		int min = 0;
		while(down->extra){
			if(down->extra->value<min){
				min = down->extra->value;
				neg = down;
			}
			down = down->extra;
		}
		if(neg){
			Node* s = neg->extra;
			Node* e = s->next;
			neg->extra = e->extra;
			fetch(ll, s, e);
		}
		current = current->next;
	}
}

int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->print();
	LinkedList* l2 = new LinkedList();
	CutPaste(ll, l2);
	ll->print();
	cout << "\n\n\n";
	l2->sPrint();
	
	
	cout << endl << endl;
	
	return 0;
}

/*
10
12 13
34 -5 11 130 15 72 81 95 63 -2 14 33 13
56 9
32 26 93 -3 12 843 240 35 38
24 13
12 176 -3 145 340 404 121 -2 120 75 25 128 315
11 8
51 111 661 808 901 67 33 13
34 8
22 -1 56 33 -2 500 840 720
57 8
810 -3 121 110 230 17 61 98
350 5
38 609 351 618 340
172 5
411 137 -1 121 134
352 5
36 135 251 468 216
84 4
58 -1 168 51
*/
