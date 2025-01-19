#include <iostream>

using namespace std;

class BST{
	private:
		class Node{
			public:
			int val;
			Node* leftChild;
			Node* rightChild;
			
			Node(){
				val = 0;
				leftChild = nullptr;
				rightChild = nullptr;
			}
			Node(int val){
				this->val = val;
				leftChild = nullptr;
				rightChild = nullptr;
			}
		};
	public:
		Node* root;
		
		BST(){
			root = nullptr;
		}
		BST(int val){
			root = new Node(val);
		}
		
		void insert(int val){
			Node* curr = root;
			if(!curr){
				root = new Node(val);
				return;
			}
			Node* pnn = new Node(val);
			Node* pback = nullptr;
			while(curr){
				pback = curr;
				if(val > curr->val){
					curr = curr->rightChild;
				}else{
					curr = curr->leftChild;
				}
			}
			if(val > pback->val){
				pback->rightChild = pnn;
			}else{
				pback->leftChild = pnn;
			}
		}
		
		Node* DFS(Node* curr){
			if(!curr)return nullptr;
			DFS(curr->leftChild);
			DFS(curr->rightChild);
			
			//e3mel ay haga hena
			
			return curr;
		}
		
		int countLev(Node* curr, int Target, int lev){
			if(!curr)return 0;
			if(Target == lev)return 1;
			return countLev(curr->leftChild, Target, lev+1) + countLev(curr->rightChild, Target, lev+1);
		}
		
		int isGoodTree(int maxHeight){
			for(int i=1; i<=maxHeight; i++){
				if(countLev(root, i, 1) != i){
					cout << "Bad Tree\n";
					return 0;
				}
			}
			cout << "Good Tree\n";
			return 1;
		}
		
};

class LinkedList{
public:
	class Node{
	public:
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
	};
public:
	Node* head;
	Node* tail;
public:
	LinkedList(int v){
		Node* new_node = new Node(v);
		head = new_node;
		tail = new_node;
	}
	LinkedList(){
		head = nullptr;
		tail = nullptr;
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
	}
	
	void push_front(int value){
		Node* newNode = new Node(value);
		if(!head){
			insert(value);
			return;
		}
		newNode->next = head;
		head = newNode;
	}
	
	void print(){
		Node* current = head;
		while(current){
			cout << current->value << " -> ";
			current = current->next;
		}
		cout << "\n";
	}
	
	void DispHalf(Node* first, Node* second, int len, int ct){
		if(ct>=(len/2)){
			if(second){
				cout << second->value << " ";
				DispHalf(first, second->next, len, ct+1);
			}else if(ct>(len/2)){
				cout << first->value << " ";
				DispHalf(first->next, second, len, ct-1);
			}
		}else{
			DispHalf(first, second->next, len, ct+1);
		}
	}
	
};

int main(){
	int x;
	//Algorithm
	BST* bst = new BST();
	int n;
	cout << "Enter number of nodes: ";
	cin >> n;
	
	while(n--){
		cin >> x;
		bst->insert(x);
	}
	
	bst->isGoodTree(6);
	
	//Problem 1
	LinkedList* ll = new LinkedList();
	
	//read linked list 1
	int m;
	cout << "Enter number of nodes: ";
	cin >> m;
	int v = m;
	while(m--){
		cin >> x;
		ll->insert(x);
	}
	
	ll->DispHalf(ll->head, ll->head, v, 0);
	cout << endl;
	
	return 0;
}
/*
test case algorithm
21
130 100 155 20 120 500 10 110 160 600 13 159 400 520 700 12 16 158 510 650 800
*/

/*
test case Prob1
8
77 80 18 25 45 12 7 32
*/
