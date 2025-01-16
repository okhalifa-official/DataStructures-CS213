#include <iostream>

using namespace std;

struct CTNode{
	int val;
	CTNode* leftChild;
	CTNode* rightChild;
	
	CTNode(int value){
		val = value;
		leftChild = nullptr;
		rightChild = nullptr;
	}
	
	CTNode(){
		val = 0;
		leftChild = nullptr;
		rightChild = nullptr;
	}
};

struct CNode{
	int val;
	CNode* next;
	CTNode* down;
	
	CNode(){
		val = 0;
		next = nullptr;
		down = nullptr;
	}
	
	CNode(int value){
		val = value;
		next = nullptr;
		down = nullptr;
	}
};

class LinkedList{
public:
	CNode* head;
	CNode* tail;
	
	LinkedList(){
		head = tail = nullptr;
	}
	
	void push(int val){
		CNode* pnn = new CNode();
		if(!head){
			head = tail = pnn;
			return;
		}
		tail->next = pnn;
		tail = pnn;
	}
};

class BST{
public:
	CTNode* root;
	
	BST(){
		root = nullptr;
	}
	void insert(int val){
		if(!root){
			root = new CTNode(val);
			return;
		}
		CTNode* pnn = new CTNode(val);
		CTNode* curr = root;
		CTNode* pback = nullptr;
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
	
	//Extra Functions
	int findHeight(CTNode* trav, CTNode* target){
		if(!trav)return 0;
		if(trav == target)return -1;
		
		int right = findHeight(trav->rightChild, target);
		int left = findHeight(trav->leftChild, target);
		
		if(right>left){
			return right + 1;
		}else{
			return left + 1;
		}
	}
	
	CTNode* FindConsecutiveNodes(CTNode* curr, int h, int& f){
		if(!curr)return nullptr;
		int nchild = 0;
		if(curr->rightChild)nchild++;
		if(curr->leftChild)nchild++;
		if(nchild == 1){
			int ngchild = 0;
			if(curr->rightChild){
				if(curr->rightChild->leftChild)ngchild++;
				if(curr->rightChild->rightChild)ngchild++;
			}else{
				if(curr->leftChild->leftChild)ngchild++;
				if(curr->leftChild->rightChild)ngchild++;
			}
			if(ngchild == 1){
				CTNode* trav = root;
				if(findHeight(trav, curr) < h+1){
					cout << endl << curr->val << endl;
					if(curr->rightChild)
						cout << curr->rightChild->val << endl;
					else
						cout << curr->leftChild->val << endl;
					f = 1;
					return curr;
				}
			}
		}
		CTNode* left = FindConsecutiveNodes(curr->leftChild, h+1, f);
		CTNode* right = nullptr;
		if(f == 0){
			right = FindConsecutiveNodes(curr->rightChild, h+1, f);
		}
		if(left)return left;
		return right;
	}
};

void CopyToLL(CTNode* curr, CTNode* curr_list){
	if(!curr){
		return;
	}
	if(curr->leftChild){
		curr_list->leftChild = new CTNode(curr->leftChild->val);
	}
	if(curr->rightChild){
		curr_list->rightChild = new CTNode(curr->rightChild->val);
	}
	
	CopyToLL(curr->leftChild, curr_list->leftChild);
	CopyToLL(curr->rightChild, curr_list->rightChild);
}

int main(){
	
	BST* T = new BST();
	LinkedList* ll = new LinkedList();
	
	//read
	cout << "Enter number of nodes: ";
	int n, x;
	cin >> n;
	while(n--){
		cin >> x;
		T->insert(x);
	}
	
	int f = 0;
	CTNode* root_subtree = T->FindConsecutiveNodes(T->root,0,f);
	
	//copy to linked list
	ll->push(root_subtree->val);
	ll->tail->down = new CTNode(root_subtree->val);
	CopyToLL(root_subtree, ll->tail->down);
	
	//copy sub of sub to linked list
	if(root_subtree->rightChild){
		ll->push(root_subtree->rightChild->val);
		ll->tail->down = new CTNode(root_subtree->rightChild->val);
		CopyToLL(root_subtree->rightChild, ll->tail->down);
	}else{
		ll->push(root_subtree->leftChild->val);
		ll->tail->down = new CTNode(root_subtree->leftChild->val);
		CopyToLL(root_subtree->leftChild, ll->tail->down);
	}
	
	//cut subtree of node and paste in new node
	if(root_subtree->val > T->root->val){
		//right
		ll->push(T->root->rightChild->val);
		ll->tail->down = T->root->rightChild;
		T->root->rightChild = nullptr;
	}else{
		//left
		ll->push(T->root->leftChild->val);
		ll->tail->down = T->root->leftChild;
		T->root->leftChild = nullptr;
	}
	
	//display largest node in subtrees
	CNode* trav = ll->head;
	cout << "\n";
	while(trav){
		CTNode* sub_trav = trav->down;
		while(sub_trav->rightChild){
			sub_trav = sub_trav->rightChild;
		}
		cout << sub_trav->val << endl;
		trav = trav->next;
	}
	
	
	return 0;
}

/*
15
500
200
800
90
280
910
70
250
900
970
86
72
84
75
85
*/
