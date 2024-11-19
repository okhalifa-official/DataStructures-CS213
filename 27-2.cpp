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

void connect(LinkedList* a, LinkedList* b){
	Node* cur1 = a->getHead();
	Node* cur2 = b->getHead();
	while(cur1 && cur2){
		if(cur1->value%2==1 && cur2->value%2==1){
			cur1->extra = cur2;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
}

bool isFullyConnected(Node* root, int n){
	Node* temp = root;
	int x = 1;
	while(temp->extra){
		temp=temp->extra;
		x++;
	}
	return x==n;
}

void copyTo(Node* root, LinkedList* other){
	Node* temp = root;
	while(temp){
		other->insert(temp->value);
		temp = temp->extra;
	}
}

int main(){
	
	int n = 6;
	LinkedList** ll = new LinkedList*[n];
	LinkedList* ll2 = new LinkedList();
	
	//read
	for(int i=0; i<n; i++){
		ll[i] = new LinkedList();
		read(ll[i]);
	}
	
	//connect
	for(int i=0; i<n-1; i++){
		connect(ll[i], ll[i+1]);
	}
	
	//copy
	Node* root = ll[0]->getHead();
	while(root){
		if(isFullyConnected(root,n)){
			copyTo(root, ll2);
		}
		root=root->next;
	}
	
	
	ll2->print();
	
	cout << endl << endl;
	
	return 0;
}

/*
9
15 25 50 40 65 20 300 491 42
9
50 11 25 5 23 283 0 505 0
9
210 29 810 12 17 27 15 5 11
9
33 180 340 126 113 19 50 13 7
9
215 31 65 160 380 130 0 407 215
9
180 70 35 260 480 270 80 17 320
*/
