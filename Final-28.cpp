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
		void getLeaf(Node* curr, Node* grand, int relation_degree){
			if(!curr)return;
			if(!curr->rightChild && !curr->leftChild){
				cout << curr->val << " I'm a leaf ";
				if(curr->val > grand->val){
					if(grand->leftChild)
						cout << "& my uncle : " << grand->leftChild->val;
					else
						cout << "without uncle.";
				}else{
					if(grand->rightChild)
						cout << "& my uncle : " << grand->rightChild->val;
					else
						cout << "without uncle.";
				}
				cout << endl;
				return;
			}
			if(relation_degree==2){
				Node* newGrand = nullptr;
				if(curr->val > grand->val){
					newGrand = grand->rightChild;
				}else{
					newGrand = grand->leftChild;
				}
				getLeaf(curr->leftChild, newGrand, relation_degree);
				getLeaf(curr->rightChild, newGrand, relation_degree);
				return;
			}
			getLeaf(curr->leftChild, grand, relation_degree+1);
			getLeaf(curr->rightChild, grand, relation_degree+1);
		}
		void Display_Uncle(){
			Node* grand = root;
			Node* curr = root;
			int relation_degree = 0;
			getLeaf(curr, grand, relation_degree);
			cout << endl;
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
	
	Node* reverse(Node* curr, int target1, int target2, Node*& start, Node*& end, Node*& pre){
		if(!curr->next)return curr;
		
		if(curr->next->value == target1 || curr->next->value == target2){
			if(!start){
				start = curr->next;
			}else{
				end = curr->next;
				pre = curr;
				return curr;
			}
		}
		
		Node* next = reverse(curr->next, target1, target2, start, end, pre);
		if(next){
			if(curr == start){
				start->next->next = end;
				start->next = pre;
				return nullptr;
			}
			next->next = curr;
			return curr;
		}
		return nullptr;
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
	
	bst->Display_Uncle();
	
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
	LinkedList::Node* start = nullptr;
	LinkedList::Node* end = nullptr;
	LinkedList::Node* pre = nullptr;
	ll->reverse(ll->getHead(),t1,t2, start, end, pre);
	ll->print();
	
	return 0;
}
/*
test case algorithm
26
130 122 155 110 500 50 115 160 600 80 112 120 400 70 90 390 450 200 395 180 250 399 170 220 260 270
*/

/*
test case Prob1
12
77 80 10 20 30 22 43 60 70 68 30 60

80 70
*/
