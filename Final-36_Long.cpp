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
	int count;
	CNode* next;
	CNode* downL;
	CTNode* downT;
	
	CNode(){
		val = 0;
		count = 0;
		next = nullptr;
		downL = nullptr;
		downT = nullptr;
	}
	
	CNode(int value){
		val = value;
		count = 0;
		next = nullptr;
		downL = nullptr;
		downT = nullptr;
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
		CNode* pnn = new CNode(val);
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
	
};

int countSubTree(CTNode* curr){
	if(!curr)return 0;
	return countSubTree(curr->leftChild) + countSubTree(curr->rightChild) + 1;
}

void DispLeaf(CTNode* curr){
	if(!curr)return;
	if(!curr->rightChild && !curr->leftChild){
		cout << curr->val << ", ";
	}
	DispLeaf(curr->leftChild);
	DispLeaf(curr->rightChild);
}
void DispLeafRev(CTNode* curr){
	if(!curr)return;
	if(!curr->rightChild && !curr->leftChild){
		cout << curr->val << ", ";
	}
	DispLeaf(curr->rightChild);
	DispLeaf(curr->leftChild);
}

int findTarget(CTNode* curr, int target){
	if(!curr)return 0;
	if(curr->val == target)return 1;
	if(target > curr->val){
		return findTarget(curr->rightChild, target);
	}else{
		return findTarget(curr->rightChild, target);
	}
}

void DispPathTarget(CTNode* curr, int target){
	if(!curr)return;
	cout << curr->val << ", ";
	if(curr->val == target)return;
	
	if(target > curr->val){
		DispPathTarget(curr->rightChild, target);
	}else{
		DispPathTarget(curr->leftChild, target);
	}
}

int main(){
	
	BST* T = nullptr;
	LinkedList* ll = new LinkedList();
	int x;
	
	char cont = 'y';
	while(cont == 'y'){
	//read list
		CNode* lastDown = nullptr;
		for(int i=0; i<3; i++){
			cin >> x;
			if(!lastDown){
				ll->push(x);
				lastDown = ll->tail;
			}else{
				lastDown->downL = new CNode(x);
				lastDown = lastDown->downL;
			}
		}
		
	//read tree
		T = new BST();
		int n;
		cin >> n;
		while(n--){
			cin >> x;
			T->insert(x);
		}
		int ctLeft=0, ctRight=0;
		ctLeft = countSubTree(T->root->leftChild);
		ctRight = countSubTree(T->root->rightChild);
		
		lastDown->downT = T->root;
		lastDown->count = 1;
		
		if(ctLeft < ctRight){
			ll->tail->downT = T->root->leftChild;
			ll->tail->count = ctLeft;
			ll->tail->downL->downT = T->root->rightChild;
			ll->tail->downL->count = ctRight;
		}else{
			ll->tail->downT = T->root->rightChild;
			ll->tail->count = ctRight;
			ll->tail->downL->downT = T->root->leftChild;
			ll->tail->downL->count = ctLeft;
		}
		lastDown->downT->rightChild = nullptr;
		lastDown->downT->leftChild = nullptr;
		
		cin >> cont;
	}
	
	CNode* travL = ll->head;
	while(travL){
		DispLeaf(travL->downT);
		travL = travL->next;
		cout << endl;
	}
	travL = ll->head;
	while(travL){
		DispLeafRev(travL->downL->downT);
		travL = travL->next;
		cout << endl;
	}
	
	travL = ll->head;
	while(travL){
		int target = travL->downL->downL->downT->val;
		CNode* curr = ll->head;
		while(curr){
			if(curr!=travL){
				if(findTarget(curr->downT, target)){
					DispPathTarget(curr->downT, target);
					cout << endl;
				}else if(findTarget(curr->downL->downT, target)){
					DispPathTarget(curr->downL->downT, target);
					cout << endl;
				}
			}
			curr = curr->next;
		}
		travL = travL->next;
	}
	
	return 0;
}

/*
test case
1
2
3

n_nodes
nodes
*/
