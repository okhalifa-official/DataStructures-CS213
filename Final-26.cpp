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
		
		Node* Display(Node* curr, int condition){
			if(!curr)return nullptr;
			Node* next = nullptr;
			if(condition > 0){
				next = Display(curr->rightChild, condition);
			}else{
				next = Display(curr->leftChild, condition);
			}
			if(!next){
				cout << curr->val << endl;
				if(condition > 0){
					if(curr->leftChild){
						next = Display(curr->leftChild, -1);
					}
				}else{
					if(curr->rightChild){
						next = Display(curr->rightChild, 1);
					}
				}
			}
			
			return curr;
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
	
	void Display(Node* curr1, Node* curr2, int isDisp){
		if(!curr1 || !curr2)return;
		
		if(isDisp == 1){
			cout << curr2->value << " ";
		}
		
		if(isDisp == -1){
			if(curr1->next && curr1->next->value == -1){
				Display(curr1->next, curr2->next, isDisp*-1);
			}else{
				Display(curr1->next, curr2->next, isDisp);
			}
		}
		if(isDisp == 1){
			if(curr2->next && curr2->next->value == -1){
				Display(curr1->next, curr2->next, isDisp*-1);
			}else{
				Display(curr1->next, curr2->next, isDisp);
			}
		}
		
		if(isDisp == -1){
			cout << curr1->value << " ";
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
//	bst->Display(bst->root, 1);
	
	//Problem 1
	LinkedList* ll = new LinkedList();
	LinkedList* ll2 = new LinkedList();
	
	//read linked list 1
	int m;
	cout << "Enter number of nodes: ";
	cin >> m;
	
	while(m--){
		cin >> x;
		ll->insert(x);
	}
	
	//read linked list 2
	cout << "Enter number of nodes: ";
	cin >> m;
	
	while(m--){
		cin >> x;
		ll2->insert(x);
	}
	
	ll->Display(ll->getHead(), ll2->getHead(), -1);
	
	return 0;
}
/*
test case algorithm
34
130 122 155 110 500 50 115 160 900 80 112 120 880 70 870 885 600 875
620 610 630 628 850 627 750 625 700 760 710 770 705 715 775 720
*/

/*
test case Prob1
17
70 80 -1 20 30 30 43 60 90 -1 66 39 15 -1 44 11 50
17
99 18 90 75 40 33 -1 71 83 38 14 -1 32 94 -1 21 13
*/
