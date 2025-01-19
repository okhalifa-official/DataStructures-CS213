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
		
		Node* FindTarget(Node* curr, int t){
			if(!curr)return nullptr;
			if(curr->val == t)return curr;
			
			if(t > curr->val){
				return FindTarget(curr->rightChild, t);
			}else{
				return FindTarget(curr->leftChild, t);
			}
		}
		
		void Display(Node* curr){
			if(!curr)return;
			cout << curr->val << ", ";
			Display(curr->leftChild);
			Display(curr->rightChild);
		}
		
		int isOneChild(Node* curr){
			if(!curr)return 1;
			if(curr->rightChild && curr->leftChild){
				return 0;
			}
			
			//return 1 if every non-leaf node has only 1 child
			return isOneChild(curr->leftChild) * isOneChild(curr->rightChild);
		}
		
		void DisplaySingle(int target){
			Node* trgnode = FindTarget(root, target);
			
			if(isOneChild(trgnode->leftChild)){
				Display(trgnode->leftChild);
			}else if(isOneChild(trgnode->rightChild)){
				Display(trgnode->rightChild);
			}
		}
		
};

class LinkedList{
public:
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
	
	void attachDown(int v){
		Node* new_node = new Node(v);
		if(!head){
			head = tail = new_node;
		}else{
			Node* curr = tail;
			while(curr->down){
				curr = curr->down;
			}
			curr->down = new_node;
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
	
	void RemoveTotal(Node* col, Node* row, int& total, Node* prevRow){
		if(!col)return;
		if(!row)return;
		if(prevRow == row)
			RemoveTotal(col->next,col->next, total, col->next);
		if(!col->next){
			total += row->value;
			RemoveTotal(col, row->down, total, row);
		}else{
			RemoveTotal(col, row->down, total, row);
			if(row->value == total){
				prevRow->down = row->down;
				row->down = nullptr;
			}
		}
	}
	
	void disp(){
		Node* curr = head;
		while(curr){
			Node* d = curr;
			while(d){
				cout << d->value << ", ";
				d = d->down;
			}
			cout << endl;
			curr = curr->next;
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
	
	int target;
	cout << "Enter Target: ";
	cin >> target;
	
	bst->DisplaySingle(target);
	cout << endl;
	
	//Problem 1
	LinkedList* ll = new LinkedList();
	
	//read linked list 1
	int m;
	cout << "Enter number of nodes: ";
	cin >> m;
	
	while(m--){
		int t;
		cin >> t;
		cin >> x;
		ll->insert(x);
		while(--t){
			cin >> x;
			ll->attachDown(x);
		}
	}
	int tot = 0;
	ll->RemoveTotal(ll->head, ll->head, tot, ll->head);
	ll->disp();
	cout << endl;
	
	return 0;
}
/*
test case algorithm
15
130 100 155 20 120 500 160 600 400 700 430 650 800 410 420

500
*/

/*
test case Prob1
6
3 77 1 27
6 80 10 27 12 27 14
3 18 20 21
4 25 30 27 32
2 45 40
3 12 5 10
*/
