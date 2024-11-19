#include <iostream>

using namespace std;

struct Node{
	int value;
	int k;
	Node* next;
	Node* down;
	
	Node(){
		value = 0;
		k = 0;
		next = nullptr;
		down = nullptr;
	}
	Node(int v, int kth){
		value = v;
		k = kth;
		next = nullptr;
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
		Node* new_node = new Node(v, 0);
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
	
	void insert(int v, int k){
		Node* new_node = new Node(v, k);
		if(!head){
			head = new_node;
			tail = new_node;
		}else{
			tail->next = new_node;
			tail = tail->next;
		}
		size++;
	}
	
	void print(){
		Node* current = head;
		while(current){
			cout << current->value << "/";
			if(current->down){
				cout << current->down->value;
			}
			cout << "(" << current->k << ") -> ";
			current = current->next;
		}
		cout << "\n";
	}
	
	void AttachAndPoint(Node* pnn, int k){
		if(!head){
			head = pnn;
			tail = pnn;
			return;
		}
		Node* current = head;
		Node* back = head;
		for(int i=0; i<k; i++){
			current = current->next;
		}
		while(current){
			current = current->next;
			back = back->next;
		}
		tail->next = pnn;
		tail = tail->next;
		pnn->down = back;
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
	int k;
	while(n--){
		cin >> x;
		cin >> k;
		Node* pnn = new Node(x,k);
		ll->AttachAndPoint(pnn,k);
	}
}

int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	ll->print();
	int v,k;
	cin >> v >> k;
	Node* pnn = new Node(v,k);
	ll->AttachAndPoint(pnn,3);
	ll->print();
	cout << endl << endl;
	
	return 0;
}
