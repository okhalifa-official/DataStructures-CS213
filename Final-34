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
			
			~Node(){
				delete [] leftChild;
				delete [] rightChild;
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
		
		Node* DFS(Node* curr){
			if(!curr)return nullptr;
			DFS(curr->leftChild);
			DFS(curr->rightChild);
			
			//e3mel ay haga hena
			
			return curr;
		}
		void removeBro(int t){
			Node* curr = root;
			Node* pback = nullptr;
			while(curr && curr->val!=t){
				if(t > curr->val){
					//right
					pback = curr;
					curr = curr->rightChild;
				}else{
					//left
					pback = curr;
					curr = curr->leftChild;
				}
			}
			if(curr){
				if(pback->rightChild->val != t){
					Node* temp = pback->rightChild;
					if((!temp->rightChild) && (!temp->leftChild)){
						pback->rightChild = nullptr;
						delete temp;
					}
				}else if(pback->leftChild->val != t){
					Node* temp = pback->leftChild;
					if((!temp->leftChild) && (!temp->rightChild)){
						pback->leftChild = nullptr;
						delete temp;
					}
				}
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
	
	void deleteSumLast(Node* curr, int& tot, int& del){
		if(!curr->next->next){
			tot = curr->value + curr->next->value;
			return;
		}
		deleteSumLast(curr->next, tot, del);
		if(del == 1){
			Node* temp = curr->next;
			curr->next = temp->next;
			temp->next = nullptr;
			del = 0;
		}
		if(curr->value == tot){
			del = 1;
			if(curr == head){
				Node* temp = curr;
				head = head->next;
				temp->next = nullptr;
			}
		}
	}
};


int main(){
	
	//Problem 1
	LinkedList* ll = new LinkedList();
	
	//cin
	int n;
	cin >> n;
	while(n>0){
		ll->insert(n);
		cin >> n;
	}
	
	//function
	int tot = 0;
	int del = 0;
	ll->deleteSumLast(ll->getHead(), tot, del);
	
	//display
	ll->print();
	
	return 0;
}

/*
problem 1
77 80 75 20 30 22 43 75 70 68 15 60 -1
*/
