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
		
		int checkPath(Node* trav1, Node* trav2, int target1, int target2){
			if(!trav1)return 0;
			if(!trav2)return 0;
			if(trav1->val == target1){
				if(trav2->val == target2){
					cout << trav2->val << " ";
					return 1;
				}else{
					return 0;
				}
			}
			
			int  pth = 0;
			
			if(target1 > trav1->val){
				pth = checkPath(trav1->rightChild, trav2->rightChild, target1, target2);
			}else{
				pth = checkPath(trav1->leftChild, trav2->leftChild, target1, target2);
			}
			if(pth == 1)
				cout << trav2->val << " ";
			return pth;
		}
		
		void Display_Pathof2_BasedOn_Pathof1(int target1, int target2){
			//geeb path1 #nodes
			int n_nodes = 1;
			Node* curr = root;
			while(curr && curr->val!=target1){
				n_nodes++;
				if(target1 > curr->val){
					curr = curr->rightChild;
				}else{
					curr = curr->leftChild;
				}
			}
			
			//fast slow pointer with diff n_nodes
			Node* slow = root;
			Node* fast = root;
			int mvSlow = 0;
			while(fast && fast->val != target2){
				for(int i=0; i<n_nodes; i++){
					if(mvSlow>=n_nodes){
						if(target2 > slow->val)
							slow = slow->rightChild;
						else
							slow = slow->leftChild;
					}
					if(!fast || fast->val==target2)
						break;
					if(target2 > fast->val)
						fast = fast->rightChild;
					else
						fast = fast->leftChild;
					mvSlow++;
				}
			}
			
			checkPath(root, slow, target1, target2);
		}
		
		void funct(int t1, int t2){
			Display_Pathof2_BasedOn_Pathof1(t1,t2);
			cout << endl;
		}
};

class LinkedList{
private:
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
	
	void CopyRecursion(Node* curr, int& n){
		if(!curr || n==0){
			return;
		}
		insert(curr->value);
		n--;
		CopyRecursion(curr->next, n);
	}
};

int main(){
	
	//Algorithm
	BST* bst = new BST();
	int n;
	cin>>n;
	while(n>0){
		bst->insert(n);
		cin >> n;
	}
	int t1, t2;
	cout << "Enter Target-1 and Target-2: ";
	cin >> t1 >> t2;
	
	bst->funct(t1,t2);
	
	//Problem 1
//	LinkedList* ll = new LinkedList();
//	int m;
//	cin >> m;
//	while(m>0){
//		ll->insert(m);
//		cin >> m;
//	}
//	
//	cout << "Enter N: ";
//	cin >> m;
//	ll->CopyRecursion(ll->getHead(),m);
//	ll->print();
	
	return 0;
}
/*
test case algorithm
500  
200    
800
90
280
910
70
250
900
950
86
260
850
1200
72
275 
960
1300
84
277 1100
75
85
276
980
73
990
1000
995
1020
-10

275
1000
*/

/*
test case Prob1
77 80 10 20 30 22 43 60 70 68 30 60
-1
3
*/
