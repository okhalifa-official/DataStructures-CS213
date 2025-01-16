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
		void Display_Good_Right_Branch(Node* branch_root){
			if(!branch_root)return;
			Node* trav = branch_root;
			Node* target = nullptr;
			cout << endl;
			for(int i=0; i<2; i++){
				trav = branch_root;
				while(trav){
					if(i==0){
						if(trav->leftChild){
							if(target){
								return;
							}else{
								target = trav->leftChild;
							}
						}
					}else{
						cout << trav->val << ", ";
					}
					trav = trav->rightChild;
				}
			}
			Display_Good_Right_Branch(target);
		}
};

class LinkedList{
private:
	class Node{
	public:
		int value;
		Node* next;
		Node* down;
		
		Node(){
			value = 0;
			next = nullptr;
			down = nullptr;
		}
		Node(int v){
			value = v;
			next = nullptr;
			down = nullptr;
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
	
	void fetch(int v){
		Node* new_node = new Node(v);
		if(!head){
			head = tail = new_node;
			return;
		}
		Node* curr = tail;
		while(curr->down)curr = curr->down;
		curr->down = new_node;
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
	
	void disp(){
		Node* current = head;
		cout << "Displaying..\n";
		while(current){
			Node* trav = current;
			while(trav){
				cout << trav->value << "|";
				trav = trav->down;
			}
			cout << "\n";
			current = current->next;
		}
		cout << "\n";
	}
	
	void CutAndPaste(Node* curr, Node* prev, Node* trav){
		if(!prev){
			CutAndPaste(curr->next,curr,curr->next);
			return;
		}
		if(!curr){
			return;
		}
		if(!trav->down){
			trav->down = prev->down;
			prev->down = nullptr;
			CutAndPaste(curr->next,curr,curr->next);
			return;
		}
		CutAndPaste(curr,prev,trav->down);
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
	
	bst->Display_Good_Right_Branch(bst->root);
	
	//Problem 1
	LinkedList* ll = new LinkedList();
	int m;
	cin >> m;
	while(m--){
		cin >> x;
		ll->insert(x);
		while(x>-1){
			cin >> x;
			if(x<0)break;
			ll->fetch(x);
		}
	}
	
	ll->disp();
	ll->CutAndPaste(ll->getHead(), nullptr, ll->getHead());
	ll->disp();
	
	return 0;
}
/*
test case algorithm
20
130 155 500 160 600 400 390 450 200 395 180 250 399 170 220 260 165 210 230 270
*/

/*
test case Prob1
6
77 1 2 -1
80 10 11 12 13 14 -1
18 20 21 -1
25 30 31 32 -1
45 40 -1
22 50 51 -1
*/
