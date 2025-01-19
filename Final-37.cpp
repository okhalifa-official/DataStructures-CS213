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
		
		void checkChildAndDisp(Node* curr, int& longest, int& longest_branch, int size, int branch, int& isDisp, char dir){
			if(!curr)return;
			if(curr->rightChild && curr->leftChild){
				isDisp = 0;
				return;
			}
			
			if(!curr->rightChild && !curr->leftChild){
				if(size>longest){
					longest = size;
					longest_branch = branch;
				}
			}
			
			if(dir == 'l' && curr->rightChild){
				if(size>longest){
					longest = size;
					longest_branch = branch;
				}
				checkChildAndDisp(curr->rightChild, longest, longest_branch, 1, branch+1, isDisp, 'r');
			}else if(dir == 'r' && curr->leftChild){
				if(size>longest){
					longest = size;
					longest_branch = branch;
				}
				checkChildAndDisp(curr->leftChild, longest, longest_branch, 1, branch+1, isDisp, 'l');
			}else{
				if(dir == 'm'){
					if(curr->rightChild){
						checkChildAndDisp(curr->rightChild, longest, longest_branch, size+1, branch, isDisp, 'r');
					}else{
						checkChildAndDisp(curr->leftChild, longest, longest_branch, size+1, branch, isDisp, 'l');
					}
				}else{
					if(dir == 'r'){
						checkChildAndDisp(curr->rightChild, longest, longest_branch, size+1, branch, isDisp, 'r');
					}else{
						checkChildAndDisp(curr->leftChild, longest, longest_branch, size+1, branch, isDisp, 'l');
					}
				}
				
			}
			
			if(branch == longest_branch && isDisp){
				cout << curr->val << " ";
			}
			if(branch == longest_branch-1 && isDisp==1){
				cout << curr->val << " ";
				isDisp = 2;
			}
			
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
	
	void DispIndex(Node* curr, int n, Node* start, Node* end, int total_prev, int total_after, int mv, int index){
		if(!end)return;
		
		if(mv>0){
			DispIndex(curr, n, start, end->next, total_prev, total_after, mv-1, index+1);
		}else{
			total_prev += curr->value;
			total_after += end->value;
			if(n+mv == 1){
				if(total_prev == total_after){
					cout << index-n << " ";
				}
				total_after -= curr->next->value;
				total_prev -= start->value;
				mv++;
				start = start->next;
			}
			DispIndex(curr->next, n, start, end->next, total_prev, total_after, mv-1, index+1);
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
	int longest = -n;
	
	while(n--){
		cin >> x;
		bst->insert(x);
	}
	
	int longest_branch = 0;
	int isDisp = 1;
	bst->checkChildAndDisp(bst->root, longest, longest_branch, 1, 0, isDisp, 'm');
	cout << endl;
	if(isDisp == 0){
		cout << "This tree is not 1 child tree\n";
	}
	
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
	
	int target;
	cout << "Enter size: ";
	cin >> target;
	
	ll->DispIndex(ll->getHead(), target, ll->getHead(), ll->getHead(),0,0, target, 0);
	cout << endl;
	
	return 0;
}
/*
test case algorithm
15
130 300 700 680 670 660 350 400 500 490 480 470 440 420 425
*/

/*
test case Prob1
15
80 40 25 45 20 80 15 35 10 70 20 30 25 45 12
3
*/
