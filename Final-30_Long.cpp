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
	int val2;
	CNode* next;
	CTNode* down;
	
	CNode(){
		val = 0;
		val2 = 0;
		next = nullptr;
		down = nullptr;
	}
	
	CNode(int value){
		val = value;
		val2 = 0;
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

CTNode* getLeafOfLevel(CTNode* curr, int max_level, int curr_level, int& n_leaf){
	if(n_leaf < 1)return nullptr;
	if(curr_level>max_level)return nullptr;
	if(!curr)return nullptr;
	//cout << curr->val << endl;
	
	if((!curr->rightChild) && (!curr->leftChild)){
		//curr = leaf
		n_leaf--;
		return curr;
	}
	
	CTNode* left = getLeafOfLevel(curr->leftChild, max_level, curr_level+1, n_leaf);
	CTNode* right = getLeafOfLevel(curr->rightChild, max_level, curr_level+1, n_leaf);
	
	if(left){
		left->rightChild = right;
		if(right)
			cout << left->val << "-" << left->rightChild->val << endl;

		return left;
	}
	return right;
}

void dispTree(CTNode* curr){
	if(!curr)return;
	cout << curr->val << endl;
	dispTree(curr->leftChild);
	dispTree(curr->rightChild);
}

void connectPosNodes(CTNode* aPos, CTNode* bPos, CTNode* FirstLeaf){
	CTNode* next = FirstLeaf;
	while(next){
		
		CTNode* curr1 = aPos;
		CTNode* curr2 = bPos;
		while(curr1 && curr2 && curr1 != next){
			if(next->val > curr1->val){
				curr1 = curr1->rightChild;
				curr2 = curr2->rightChild;
			}else{
				curr1 = curr1->leftChild;
				curr2 = curr2->leftChild;
			}
		}
		
		next = next->rightChild;
		if(curr1 && curr2){
			curr1->leftChild = curr2;
			cout << curr1->val << " connected to " << curr2->val << endl;
		}
	}
}

void getMax(CTNode* curr, int& maxi){
	if(!curr)return;
	maxi = curr->val;
	getMax(curr->rightChild, maxi);
}

int main(){
	
	BST* T = nullptr;
	LinkedList* ll = new LinkedList();
	int n, x;
	
	//Read Linked List
	//cout << "Enter number of linked list nodes: ";
	cin >> n;
	while(n--){
		int v1, v2;
		//cout << "Enter v1 and v2: ";
		cin >> v1 >> v2;
		ll->push(v1);
		ll->tail->val2 = v2;
		
		//Read tree
		
		T = new BST();
		//cout << "Enter number of tree nodes: ";
		int k;
		cin >> k;
		//cout << "Enter tree values: ";
		while(k--){
			cin >> x;
			T->insert(x);
		}
		
		ll->tail->down = T->root;
		T = nullptr;
	}
	
	//select tree by position
	int aPos, bPos;
	//cout << "Enter aPos: ";
	cin >> aPos;
	//cout << "Enter bPos: ";
	cin >> bPos;
	
	CNode* trav = ll->head;
	CNode* aPos_root = nullptr;
	CNode* bPos_root = nullptr;
	
	while(trav && (aPos>=0 || bPos>=0)){
		if(aPos==0){
			aPos_root = trav;
		}
		if(bPos==0){
			bPos_root = trav;
		}
		aPos--;bPos--;
		
		trav = trav->next;
	}
	
//	dispTree(aPos_root->down);
	int n_leaf = aPos_root->val2;
	int max_height = aPos_root->val;
	
	CTNode* aFirstLeaf = getLeafOfLevel(aPos_root->down, max_height, 0, n_leaf);
	cout << aFirstLeaf->val << endl;
	
	connectPosNodes(aPos_root->down,bPos_root->down, aFirstLeaf);
	
	//display max in connected nodes
	CTNode* conNodes = aFirstLeaf;
	while(conNodes){
		int maxi = conNodes->leftChild->val;
		getMax(conNodes->leftChild, maxi);
		cout << "Max in " << conNodes->val << " is " << maxi << endl;
		conNodes = conNodes->rightChild;
	}
	
	return 0;
}

/*
6
0 0
0
3 2
15
500 200 800 90 280 910 70 250 900 970 86 72 84 75 85
0 0
0
0 0
0
0 0
13
10 5 20 8 50 6 25 400 7 45 49 46 47
0 0
0
1
4
*/
