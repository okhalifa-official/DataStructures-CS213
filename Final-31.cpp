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
		
		int stepsToTarget(int target1, Node* curr1){
			if(curr1->val == target1){
				return 1;
			}
			if(target1 > curr1->val){
				return stepsToTarget(target1, curr1->rightChild) + 1;
			}else{
				return stepsToTarget(target1, curr1->leftChild) + 1;
			}
		}
		
		void Display_Pathof2_BasedOn_Pathof1(int target1, int target2, Node* curr2, int& back_steps){
			//rooh l target 2 el awel b recursion
			if(!curr2){
				return;
			}
			if(curr2->val == target2){
				Node* curr1 = root;
				back_steps = stepsToTarget(target1, curr1);
			}else{
				if(target2 > curr2->val){
					Display_Pathof2_BasedOn_Pathof1(target1, target2, curr2->rightChild, back_steps);
				}else{
					Display_Pathof2_BasedOn_Pathof1(target1, target2, curr2->leftChild, back_steps);
				}
			}
			if(back_steps>0){
				cout << curr2->val << " ";
				back_steps--;
			}
		}
		
		void funct(int t1, int t2){
			Node* temp = root;
			int back_steps = 0;
			Display_Pathof2_BasedOn_Pathof1(t1,t2,temp,back_steps);
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
	LinkedList* ll = new LinkedList();
	int m;
	cin >> m;
	while(m>0){
		ll->insert(m);
		cin >> m;
	}
	
	cout << "Enter N: ";
	cin >> m;
	ll->CopyRecursion(ll->getHead(),m);
	ll->print();
	
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
