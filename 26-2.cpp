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
	
	int getSize(){
		return size;
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
	
	Node* pop_front(){
		if(!head){
			return nullptr;
		}
		Node* temp = head;
		head = temp->next;
		temp->next = nullptr;
		return temp;
		size--;
	}
	
	void print(){
		Node* current = head;
		while(current){
			Node* temp = current;
			while(temp){
				cout << temp->value << "-";
				temp = temp->extra;
			}
			cout << "\n";
			current = current->next;
		}
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
	while(n){
		for(int i=0;i<3; i++){
			cin >> x;
			ll->insert(x);
			Node* current = ll->getTail();
			Node* temp = nullptr;
			for(int j=1; j<n; j++){
				cin >> x;
				Node* new_node = new Node(x);
				new_node->next = current;
				current->extra = new_node;
				current = current->extra;
				if(!temp)temp = current;
			}
			temp->next = current;
		}
		n-=3;
	}
}

bool palindrome(LinkedList* ll){
	LinkedList* other = new LinkedList();
	Node* curr = ll->getHead();
	for(int i=0; i<ll->getSize()/2; i++){
		other->push_front(curr->value);
		curr = curr->next;
	}
	if(ll->getSize()%2==1)curr = curr->next;
	while(curr){
		if(curr->value != other->pop_front()->value){
			return 0;
		}
		curr = curr->next;
	}
	return 1;
}

bool isMirror(LinkedList* ll){
	LinkedList* pal = new LinkedList();
	Node* current = ll->getHead();
	Node* temp = current;
	
	while(current){
		temp = current;
		for(int i=0; i<3; i++){
			temp = current->extra->next;
			pal->insert(temp->value);
			current = current->next;
		}
		for(int i=0; i<3; i++){
			if(current){
				if(temp->next){
					temp = temp->next;
					pal->insert(temp->value);
				}
			}else{
				pal->insert(temp->next->value);
				pal->insert(ll->getTail()->value);
				break;
			}
		}
	}
	
	//display new list
	/*
	current = pal->getHead();
	while(current){
		cout << current->value << " -> ";
		current = current->next;
	}
	cout << "\n";
	*/
	
	return palindrome(pal);
}


int main(){
	
	LinkedList* ll = new LinkedList();
	read(ll);
	//ll->print();
	cout << isMirror(ll) << "\n";
	
	
	cout << endl << endl;
	
	return 0;
}

/*
12
1 1 1 1 1 1 1 1 1 1 1 50 
2 2 2 2 2 2 2 2 2 2 2 40 
3 3 3 3 3 3 3 3 7 60 90 15
4 4 4 4 4 4 4 4 20 
5 5 5 5 5 5 5 5 25 
6 6 6 6 6 1 45 66 18 
7 7 7 7 7 45 
8 8 8 8 8 66 
9 9 7 20 25 18 
10 10 60 
11 11 90 
50 40 15
*/
