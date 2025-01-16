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
		void FindAndDisplay(int v){
			Node* fast = root;
			Node* slow = root;
			int mvSlow = 0;
			while(fast->val != v && fast){
				if(mvSlow%2 == 0){
					cout << slow->val << ", ";
					if(v > slow->val)slow=slow->rightChild;
					else slow = slow->leftChild;
				}
				if(v > fast->val){
					fast = fast->rightChild;
				}else{
					fast = fast->leftChild;
				}
				mvSlow++;
				if(fast->val != v){
					if(v > fast->val){
						fast = fast->rightChild;
					}else{
						fast = fast->leftChild;
					}
					mvSlow++;
				}
			}
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
	
	void display(Node* curr, int n, int ct){
		if(!curr)return;
		if(ct == -n)ct*=-1;
		if(ct > 0){
			cout << curr->value << " -> ";
		}
		display(curr->next, n, ct-1);
		if(curr == head)cout << "\n";
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
	
	int v;
	cout << "Enter target value: ";
	cin >> v;
	
	bst->FindAndDisplay(v);
	
	//Problem 1
	LinkedList* ll = new LinkedList();
	int m;
	cout << "Enter number of nodes: ";
	cin >> m;
	
	while(m--){
		cin >> x;
		ll->insert(x);
	}
	
	int t;
	cout << "Enter Range size: ";
	cin >> t;
	ll->print();
	ll->display(ll->getHead(), t, t);
	
	return 0;
}
/*
test case algorithm
18
500 200 800 90 280 910 70 250 900 86 260 850 72 275 84 75 85 73
*/

/*
test case Prob1
12
77 80 10 20 30 22 43 60 70 68 30 60

3
*/
