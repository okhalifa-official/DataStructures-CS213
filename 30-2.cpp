#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
	Node* up1;
	Node* up2;
	
	Node(){
		value = 0;
		next = nullptr;
		up1 = nullptr;
		up2 = nullptr;
	}
	Node(int v){
		value = v;
		next = nullptr;
		up1 = nullptr;
		up2 = nullptr;
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
			cout << current->value << " ->\n";
			Node* temp = current->up1;
			while(temp){
				Node* tt = temp;
				while(tt){
					cout << tt->value << " -1> ";
					tt = tt->next;
				}
				cout << "\n";
				temp = temp->up1;
			}
			temp = current->up2;
			while(temp){
				Node* tt = temp;
				while(tt){
					cout << tt->value << " -2> ";
					tt = tt->next;
				}
				cout << "\n";
				temp = temp->up2;
			}
			current = current->next;
		}
		cout << "\n";
	}
	
	~LinkedList(){
		Node* current = head;
		tail = nullptr;
		while(current){
			head = current->next;
			delete [] current;
			current = head;
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
	
	Node* current = ll->getHead();
	Node* back = nullptr;
	while(current){
		n = -1;
		if(back){
			if(current->value > back->value){
				n = back->value;
			}
		}
		
		Node* UP1 = nullptr;
		Node* temp = current;
		Node* last1;
		for(int i=0; i<current->value; i++){
			int x;
			cin >> x;
			Node* newNode = new Node(x);
			temp->up1 = newNode;
			temp = temp->up1;
			if(i==0){
				UP1 = newNode;
			}
			if(n==-1){
				UP1->next = newNode;
			}else if(n>0){
				UP1->next = newNode;
				n--;
			}
		}
		last1 = temp;
		temp = current;
		for(int i=0; i<current->value; i++){
			int x;
			cin >> x;
			Node* newNode = new Node(x);
			temp->up2 = newNode;
			temp = temp->up2;
			if(i==0){
				UP1 = newNode;
			}
			UP1->next = newNode;
		}
		last1->next = temp;
		back = current;
		current = current->next;
	}
}

void connectUP(LinkedList* ll){
	Node* current = ll->getHead()->next;
	Node* prev = ll->getHead();
	while(current){
		
		if(current->value>prev->value){
			Node* l = prev->up2->next;
			Node* r = current->up1->next;
			l->next = r;
		}
		
		current=current->next;
		prev=prev->next;
	}
}

bool isMirror(Node* t, int size){
	int f = 1;
	if(size%2==1){
		f=-1;
	}
	int n = size/2;
	Node* current = t->up1;
	LinkedList* pal = new LinkedList();
	while(current){
		if(n){
			pal->push_front(current->value);
			n--;
		}else{
			if(f==-1){
				if(current->next){
					current=current->next;
				}else{
					current=current->up1;
				}
				f = 1;
			}
			if(current->value != pal->getHead()->value){
				return false;
			}else{
				Node* temp = pal->getHead();
				pal->setHead(temp->next);
				temp->next = nullptr;
				delete temp;
			}
		}
		
		if(current->up1){
			current=current->up1;
		}else{
			current=current->next;
		}
	}
	return true;
}

int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	connectUP(ll);
	ll->print();
	
	Node* s = ll->getHead();
	Node* current = s;
	Node* back = nullptr;
	int size = s->value+1;
	while(current){
		if(back){
			if(current->value < back->value){
				cout << s->value << " = ";
				cout << isMirror(s, size) << endl;
				s = current;
				size = s->value+1;
			}else{
				size += current->value - back->value + 2;
			}
		}
		back = current;
		if(!current->next){
			cout << s->value << " = ";
			cout << isMirror(s, size) << endl;
		}
		current = current->next;
	}
	
	cout << endl << endl;
	
	return 0;
}
/*
7
6 10 4 6 3 5 4
1 2 3 4 5 6
7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
1 2 3 4
5 6 7 5
1 2 3 4 3 2
7 8 9 10 11 1
1 2 3
4 5 6
1 2 3 4 5
6 7 8 9 10
1 2 3 4
5 6 7 8
*/
