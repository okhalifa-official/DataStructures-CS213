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
		int countLeaves(Node* curr, int ct){
			if(!curr)return ct;
			if(!curr->rightChild && !curr->leftChild)return ct+1;
			
			ct = countLeaves(curr->leftChild, ct);
			ct = countLeaves(curr->rightChild, ct);
			
			return ct;
		}
		
		int removeNthLeaf(Node* curr, int n, int ct){
			if(!curr)return ct;
			if(!curr->rightChild && !curr->leftChild)return ct+1;
			
			ct = removeNthLeaf(curr->leftChild, n, ct);
			if(ct == n){
				cout << "Removing node: " << curr->leftChild->val << endl;
				curr->leftChild = nullptr;
				return -1;
			}
			if(ct != -1){
				ct = removeNthLeaf(curr->rightChild, n, ct);
				if(ct == n){
					cout << "Removing node: " << curr->rightChild->val << endl;
					curr->rightChild = nullptr;
					return -1;
				}
			}
			return ct;
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
	
	void DisplayBetweenTarget(Node* curr, int t1, int t2, int isDisp){
		int temp = isDisp;
		if(!curr)return;
		if(isDisp){
			if(curr->value == t1 || curr->value == t2){
				return;
			}else{
				
			}
		}
		if(curr->value == t1 || curr->value == t2){
			temp = 1;
		}
		DisplayBetweenTarget(curr->next, t1, t2, temp);
		if(isDisp){
			cout << curr->value << ", ";
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
	
	int n_leaf = bst->countLeaves(bst->root, 0);
	cout << n_leaf << endl;
	bst->removeNthLeaf(bst->root,n_leaf/2+1,0);
	
	//Problem 1
	LinkedList* ll = new LinkedList();
	int m;
	cout << "Enter number of nodes: ";
	cin >> m;
	
	while(m--){
		cin >> x;
		ll->insert(x);
	}
	
	int t1,t2;
	cout << "Enter target-1 and 2: ";
	cin >> t1 >> t2;
	ll->print();
	ll->DisplayBetweenTarget(ll->getHead(),t1,t2,0);
	cout << endl;
	
	return 0;
}
/*
test case algorithm
23
130 122 155 110 500 50 115 160 600 80 112 120 400 70 90 390 450 200 395 250 399 220 260 270
*/

/*
test case Prob1
12
77 80 10 20 30 22 43 60 70 68 30 60

80 70
*/
