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

CTNode* findMin(CTNode* curr){
	while(curr->leftChild){
		curr = curr->leftChild;
	}
	return curr;
}

void CopyToLL(CTNode* curr, CTNode* curr_list){
	if(!curr)return;
	
	if(curr->rightChild){
		curr->rightChild->val += 10;
		curr_list->rightChild = new CTNode(curr->rightChild->val);
	}
	if(curr->leftChild){
		curr->leftChild->val += 10;
		curr_list->leftChild = new CTNode(curr->leftChild->val);
	}
	
	CopyToLL(curr->leftChild, curr_list->leftChild);
	CopyToLL(curr->rightChild, curr_list->rightChild);
}

void DFS(CTNode* curr, int t){
	if(!curr)return;
	
	DFS(curr->leftChild, t);
	cout << curr->val << " was " << curr->val - (t*10) << endl;
	DFS(curr->rightChild, t);
	
	
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
	CTNode* psmallest = T->root;
	psmallest = findMin(psmallest);
	cout << "\nPSmallest = " << psmallest->val << endl;
	
	//copy to linked list
	while(psmallest->rightChild){
		psmallest->rightChild->val += 10;
		ll->push(psmallest->rightChild->val);
		ll->tail->down = new CTNode(ll->tail->val);
		CTNode* temp = psmallest->rightChild;
		CopyToLL(temp, ll->tail->down);
		psmallest = findMin(temp);
		cout << "\nPSmallest = " << psmallest->val << endl;
	}
	
	//select subtree
	cout << "Select subtree: ";
	int t;
	cin >> t;
	CNode* trav = ll->head;
	for(int i=0; i<t-1; i++){
		trav = trav->next;
	}
	cout << endl;
	if(trav){
		DFS(trav->down, t);
	}
	cout << endl;
	
	return 0;
}

/*
36
795
790
800
780
794
910
50
793
900
10000
750
850
1200
15000
700
765
950
1700
10200
680
720
920
1000
10400
400
980
1100
10250
10600
500
970
1180
450
550
430
560

2
*/
