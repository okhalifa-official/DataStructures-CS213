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
		void Display_RepeatedPath(int target){
			Node* curr = root;
			while(curr && curr->val != target){
				cout << curr->val << " ";
				if(target > curr->val){
					curr = curr->rightChild;
				}else{
					curr = curr->leftChild;
				}
			}
			if(curr){
				cout << curr->val << "\n";
				Node* found = curr;
				curr = root;
				Node* curr2 = found;
				while(curr!=found){
					cout << curr2->val << " ";
					if(target > curr->val){
						curr = curr->rightChild;
						curr2 = curr2->rightChild;
					}else{
						curr = curr->leftChild;
						curr2 = curr2->leftChild;
					}
				}
				cout << curr2->val << "\n";
			}
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
	
	void CopyFrontRecursion(Node* curr, int& n){
		if(!curr){
			return;
		}
		CopyFrontRecursion(curr->next, n);
		if(n>0){
			n--;
			Node* pnn = new Node(curr->value);
			pnn->next = head;
			head = pnn;
		}
	}
};

int main(){
	
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
	ll->CopyFrontRecursion(ll->getHead(),m);
	ll->print();
	
	return 0;
}
/*
test case algorithm

*/
/*
test case Prob1
77 80 10 20 30 22 43 60 70 68 30 60
-1
3
*/
