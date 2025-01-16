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
		bool Find_Value_And_Pathmax(int target){
			int total = 0;
			Node* max = root;
			Node* curr = root;
			while(curr && curr->val!=target){
				
				if(target > curr->val){
					if(curr == max){
						max = max->rightChild;
					}
					curr = curr->rightChild;
					
				}else{
					curr = curr->leftChild;
				}
				if(curr != max){
					total += curr->val;
				}
			}
			if(curr && max->val == total){
				return true;
			}
			return false;
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
	
	void FetchList(Node* newList){
		if(!head){
			head = newList;
			return;
		}
		Node* row = head;
		while(row->down){
			row=row->down;
		}
		row->down = newList;
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
	
	void PlaceShortestList(Node* list_trav, Node* curr_list, int& n, int& min, Node*& minList, Node*& minBack, Node* pback){
		if(!curr_list){
			minBack->down = minList->down;
			minList->down = head;
			head = minList;
			return;
		}
		if(!list_trav){
			if(n<min){
				min = n;
				minList = curr_list;
				minBack = pback;
			}
			n = 0;
			pback = curr_list;
			PlaceShortestList(curr_list->down, curr_list->down, n, min, minList, minBack, pback);
		}else{
			n++;
			PlaceShortestList(list_trav->next, curr_list, n, min, minList, minBack,pback);
		}
	}
};

int main(){
//	BST* bst = new BST();
//	int n = 0;
//	cin>>n;
//	while(n>-1){
//		bst->insert(n);
//		cin>>n;
//	}
//	cout << "Enter Target: ";
//	cin >> n;
//	cout << "\n= " << bst->Find_Value_And_Pathmax(n) << endl;
	
	LinkedList* ll = new LinkedList();
	
	//cin
	int t = 0;
	cin >> t;
	while(t--){
		LinkedList* new_list = new LinkedList();
		int n;
		cin >> n;
		while(n>0){
			new_list->insert(n);
			cin >> n;
		}
		ll->FetchList(new_list->getHead());
	}
	
	//function
	int x = 0;
	int min = 9999;
	LinkedList::Node* curr_row = ll->getHead();
	LinkedList::Node* minNode = ll->getHead();
	LinkedList::Node* minBack = nullptr;
	
	ll->PlaceShortestList(ll->getHead(),ll->getHead(),x,min, minNode, minBack, nullptr);
	
	//display
	cout << endl << endl;
	curr_row = ll->getHead();
	while(curr_row){
		LinkedList::Node* col = curr_row;
		while(col){
			cout << col->value << " -> ";
			col = col->next;
		}
		cout << endl;
		curr_row = curr_row->down;
	}
	
	return 0;
}
/*
test case algorithm
130
122
155
110
1620
50
115
160
2000
80
112
120
400
2400
70
90
390
450
2800
200
2500
250
220
260
270
-10
220
*/
/*
Problem 1
6
50 60 10 30 20 -1
15 25 5 -1
4 8 3 5 1 -1
14 1 15 10 -1
200 100 -1
10 10 20 -1
*/
