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
	CTNode* findTarget(CTNode* curr, CTNode*& prev, int target, int rel){
		if(!curr)return nullptr;
		if(target == curr->val)return curr;
		
		if(rel < 1){
			if(target > prev->val){
				prev = prev->rightChild;
			}else{
				prev = prev->leftChild;
			}
		}
		if(target > curr->val){
			return findTarget(curr->rightChild, prev, target, rel-1);
		}else{
			return findTarget(curr->leftChild, prev, target, rel-1);
		}
	}
};

int calcHeight(CTNode* curr){
	if(!curr)return 0;
	
	int left = calcHeight(curr->leftChild);
	int right = calcHeight(curr->rightChild);
	
	if(left>right){
		return left+1;
	}else{
		return right+1;
	}
}

void DFS(CTNode* curr){
	if(!curr)return;
	DFS(curr->leftChild);
	cout << curr->val << ", ";
	DFS(curr->rightChild);
}

int main(){
	
	BST* T = nullptr;
	LinkedList* ll = new LinkedList();
	CNode* ltrav = ll->tail;
	for(int i=0; i<5; i++){
		if(!ltrav){
			ll->push(i+1);
			ltrav = ll->tail;
		}else{
			ltrav->downL = new CNode(i+1);
			ltrav = ltrav->downL;
		}
	}
	
	//read tree
	char cont = 'y';
	
	while(cont == 'y'){
		char atefhamneen = 'm';
		int nNode;
		cin >> nNode;
		T = new BST();
		int x;
		for(int i=0; i<nNode; i++){
			cin >> x;
			T->insert(x);
		}
		
		int targ;
		cin >> targ;
		CTNode* targNode = T->root;
		CTNode* GrandNode = T->root;
		targNode = T->findTarget(T->root, GrandNode, targ, 3);
		
		CTNode* GUncle;
		if(targ > GrandNode->val){
			GUncle = GrandNode->leftChild;
			atefhamneen = 'l';
			
		}else{
			GUncle = GrandNode->rightChild;
			atefhamneen = 'r';
		}
		
		cout << "Grand Uncle is " << GUncle->val << endl;
		int hguncle = calcHeight(GUncle);
		cout << "Height is " << hguncle << endl;
		
		if(hguncle<6){
			CNode* pnn = new CNode(targ);
			pnn->downT = GUncle;
			if(GrandNode->rightChild == GUncle){
				GrandNode->rightChild = nullptr;
			}else{
				GrandNode->leftChild = nullptr;
			}
			
			if(atefhamneen == 'r'){
				pnn->downL = ll->tail;
			}
			
			CNode* trav = ll->tail;
			for(int i=1; i<hguncle; i++){
				trav = trav->downL;
			}
			while(trav->next){
				trav = trav->next;
			}
			trav->next = pnn;
		}
		
		cin >> cont;
	}
	
	int row;
	cin >> row;
	CNode* trav = ll->tail;
	for(int i=1; i<row; i++){
		trav = trav->downL;
	}
	
	CNode* col = trav;
	while(col){
		cout << col->val << ", ";
		col = col->next;
	}
	cout << endl;
	
	col = trav->next;
	while(col){
		DFS(col->downT);
		if(col->downL){
			cout << "\nGranduncle was a right brother to my grandfather\n";
		}else{
			cout << "\nGranduncle was a left brother to my grandfather\n";
		}
		col = col->next;
	}
	
	return 0;
}

/*
test case
14
200 180 250 170 185 220 260 160 175 210 230 270 213 215
210
y
15
300 100 500 120 400 600 310 450 320 480 350 460 490 455 456
350
y
14
120 80 250 90 200 600 180 230 700 190 240 650 199 235
190
n

3
*/
