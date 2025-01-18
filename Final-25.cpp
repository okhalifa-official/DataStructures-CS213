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
		
		void First_Left_Display(int v){
			Node* curr = root;
			int isPrint = 0;
			while(curr && curr->val != v){
				if(isPrint)
					cout << curr->val << ", ";
				if(v > curr->val){
					curr = curr->rightChild;
				}else{
					curr = curr->leftChild;
					if(!isPrint)
						isPrint = 1;
				}
			}
			cout << curr->val << ", ";
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
	
	void displayHalf(Node* curr, int target, int ct, int& max_ct){
		if(!curr)return;
		if(curr->value == target){
			max_ct = ct;
			return;
		}
		
		displayHalf(curr->next, target, ct+1, max_ct);
		if(ct>=max_ct/2){
			cout << curr->value << ", ";
		}
	}
	
};

int main(){
	int x;
	//Algorithm
//	BST* bst = new BST();
//	int n;
//	cout << "Enter number of nodes: ";
//	cin >> n;
//	
//	while(n--){
//		cin >> x;
//		bst->insert(x);
//	}
//	
//	int v;
//	cout << "Enter target value: ";
//	cin >> v;
//	
//	bst->First_Left_Display(v);
	
	//Problem 1
	LinkedList* ll = new LinkedList();
	
	//read linked list 1
	int m;
	cout << "Enter number of nodes: ";
	cin >> m;
	
	while(m--){
		cin >> x;
		ll->insert(x);
	}
	
	int max_ct = 0;
	int target;
	cout << "Enter target: ";
	cin >> target;
	
	ll->displayHalf(ll->getHead(), target, 0, max_ct);
	cout << endl;
	
	return 0;
}
/*
test case algorithm
22
130 122 155 110 500 50 115 160 600 80 112 120 400 70 90 390 450 200 250 220 260 270
220
*/

/*
test case Prob1
12
77 80 10 20 30 22 43 60 70 68 33 40
70
*/
