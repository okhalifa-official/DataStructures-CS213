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
			Node* temp = current->extra;
			while(temp){
				cout << temp->value << " ";
				if(temp->next){
					temp=temp->next;
					cout << " / ";
				}
				else temp = temp->extra;
			}
			current = current->next;
			cout << "\n";
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
	cin >> x;
	ll->insert(x);
	for(int i=2; i<=n; i++){
		Node* current = ll->getTail();
		for(int k=0; k<i; k++){
			cin>>x;
			current->next = new Node(x);
			if(current==ll->getTail())ll->setTail(current->next);
			current=current->next;
			for(int j=0; j<i-1; j++){
				cin>>x;
				current->extra = new Node(x);
				current = current->extra;
			}
			
		}
	}
}

void connect(LinkedList* ll){
	Node* current = ll->getHead();
	Node* prev = current;
	current = current->next;
	int n = 0;
	while(current){
		Node* l = prev;
		Node* r = current;
		int a = -1;
		int b = -1;
		while(a!=n){
			while(l->extra){
				l=l->extra;
			}
			a++;
			if(l->next)l=l->next;
		}
		if(l!=r){
			while(b!=n){
				while(r->extra){
					r=r->extra;
				}
				b++;
				if(b!=n)r=r->next;
			}
			l->next=r;
		}
		n++;
		prev=current;
		current = current->next;
	}
}


int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->print();
	connect(ll);
	ll->print();
	
	
	cout << endl << endl;
	
	return 0;
}
/*
5
0
1 1 1 1
2 2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
*/
