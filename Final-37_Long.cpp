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
	CNode* down;
	CTNode* down1;
	CTNode* down2;
	
	CNode(){
		val = 0;
		next = nullptr;
		down = nullptr;
		down1 = nullptr;
		down2 = nullptr;
	}
	
	CNode(int value){
		val = value;
		next = nullptr;
		down = nullptr;
		down1 = nullptr;
		down2 = nullptr;
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
	
	CNode* attachDown(int val){
		CNode* curr = tail;
		while(curr->down){
			curr = curr->down;
		}
		curr->down = new CNode(val);
		return curr->down;
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

CTNode* findTarget(CTNode* curr, int target, CTNode*& parent, CTNode* pback){
	if(!curr)return nullptr;
	if(curr->val == target){
		parent = pback;
		return curr;
	}
	
	if(target > curr->val){
		return findTarget(curr->rightChild, target, parent, curr);
	}else{
		return findTarget(curr->leftChild, target, parent, curr);
	}
}

int calcNodes(CTNode* curr){
	if(!curr)return 0;
	
	return calcNodes(curr->leftChild) + calcNodes(curr->rightChild) + 1;
}

CTNode* DFScalcNodes(CTNode* curr, CTNode*& prev, int n, CTNode* pback){
	if(!curr)return nullptr;
	
	if(calcNodes(curr) == n){
		prev = pback;
		return curr;
	}
	
	CTNode* ret = nullptr;
	pback = curr;
	ret = DFScalcNodes(curr->leftChild,prev,n,pback);
	if(!ret)
		ret = DFScalcNodes(curr->rightChild,prev,n,pback);
		
	return ret;
}

void DFS(CTNode* curr){
	if(!curr)return;
	
	DFS(curr->leftChild);
	DFS(curr->rightChild);
	cout << curr->val << " ";
}

int main(){
	
	BST* T = new BST();
	LinkedList* ll = new LinkedList();
	
	
	//read
	int n;
	cin >> n;
	int x;
	while(n--){
		T->root = nullptr;
		cin >> x;
		ll->push(x);
		
		int n_node = 0;
		cin >> n_node;
		while(n_node--){
			cin >> x;
			T->insert(x);
		}
		if(T){
			ll->tail->down1 = T->root;
			T->root = nullptr;
		}
		cin >> n_node;
		while(n_node--){
			cin >> x;
			T->insert(x);
		}
		if(T){
			ll->tail->down2 = T->root;
		}
	}
	
	int firstTime = 1;
	char cont = 'y';
	while(cont == 'y'){
		int pos_val;
		cin >> pos_val;
		
		CNode* pos = ll->head;
		while(pos && pos_val--){
			pos = pos->next;
		}
		
		int target;
		cin >> target;
		int sib = 1;
		CTNode* Tparent = nullptr;
		CTNode* Tnode = findTarget(pos->down1, target, Tparent, nullptr);
		if(!Tnode){
			Tnode = findTarget(pos->down2, target, Tparent, nullptr);
			sib = 0;
		}
		cout << "Found\n";
		int Nsub = calcNodes(Tnode);
		CTNode* sibTreeParent = nullptr;
		CTNode* sibTree = nullptr;
		if(sib){
			//right
			sibTree = DFScalcNodes(pos->down2, sibTreeParent, Nsub,nullptr);
		}else{
			//left
			sibTree = DFScalcNodes(pos->down1, sibTreeParent, Nsub,nullptr);
		}
		
		cout << Nsub << endl << sibTreeParent->val << endl << Tparent->val << endl;
		
		//add to new node
		CNode* felakher = ll->tail;
		if(firstTime>0){
			ll->push(Nsub);
			felakher = ll->tail;
		}else{
			felakher = ll->attachDown(Nsub);
		}
		felakher->down1 = Tnode;
		felakher->down2 = sibTree;
		
		if(Tnode == Tparent->rightChild){
			Tparent->rightChild = nullptr;
		}else{
			Tparent->leftChild = nullptr;
		}
		
		if(sibTree == sibTreeParent->rightChild){
			sibTreeParent->rightChild = nullptr;
		}else{
			sibTreeParent->leftChild = nullptr;
		}
		firstTime--;
		cin >> cont;
	}
	
	int min = 9999;
	int prevMin = -1;
	CNode* travDown = ll->tail;
	while(travDown){
		min = 9999;
		CNode* trav = ll->tail;
		CNode* pmin = ll->tail;
		while(trav){
			if(trav->val < min && trav->val > prevMin){
				min = trav->val;
				pmin = trav;
			}
			trav = trav->down;
		}
		cout << "Displaying Subtree of: " << pmin->val << endl;
		DFS(pmin->down1);
		cout << endl;
		DFS(pmin->down2);
		cout << endl;
		
		prevMin = min;
		travDown = travDown->down;
	}
	
	return 0;
}

/*
test case
4

0
0 0

1
8
300 200 400 100 250 230 260 280
7
80 60 90 40 85 120 84

2
7
300 200 400 100 250 230 260
7
80 60 90 40 65 120 84

3
14
50 30 70 20 40 60 80 10 5 15 3 7 20 25
9
80 60 90 40 86 120 84 87 110



1
250
y

2
250
y

3
10
n
*/
