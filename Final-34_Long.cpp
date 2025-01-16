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
	int getHeight(CTNode* curr){
		if(!curr)return 0;
		int r = getHeight(curr->rightChild)+1;
		int l = getHeight(curr->leftChild)+1;
		
		if(r>l)return r;
		else return l;
	}
	
	void FindTarget(int t1, int t2, LinkedList* LShort, LinkedList* LLong){
		int isSep = 1;
		CTNode* pback1 = nullptr;
		CTNode* pback2 = nullptr;
		
		//find t1
		CTNode* curr = root;
		while(curr && curr->val != t1){
			pback1 = curr;
			if(curr->val == t2){
				isSep = 0;
			}
			if(t1 > curr->val){
				curr = curr->rightChild;
			}else{
				curr = curr->leftChild;
			}
		}
		CTNode* targetNode1 = nullptr;
		if(curr){
			targetNode1 = curr;
		}
		
		//find t2
		curr = root;
		while(curr && curr->val != t2){
			pback2 = curr;
			if(curr->val == t1){
				isSep = 0;
			}
			if(t2 > curr->val){
				curr = curr->rightChild;
			}else{
				curr = curr->leftChild;
			}
		}
		CTNode* targetNode2 = nullptr;
		if(curr){
			targetNode2 = curr;
		}
		
		if(isSep == 1){
			cout << "They are separate\n";
		}else{
			cout << "They are not separate\n";
		}
		
		//get height of subtrees
		int h1, h2;
		h1 = h2 = 0;
		
		CTNode* temp = targetNode1;
		h1 = getHeight(temp);
		temp = targetNode2;
		h2 = getHeight(temp);
		
		//cut subtrees to linked list
		if(h1 > 4){
			LLong->push(t1);
			LLong->tail->down = targetNode1;
		}else{
			LShort->push(t1);
			LShort->tail->down = targetNode1;
		}
		
		if(h2 > 4){
			LLong->push(t2);
			LLong->tail->down = targetNode2;
		}else{
			LShort->push(t2);
			LShort->tail->down = targetNode2;
		}
		
		//cut from tree
		if(t1 > pback1->val){
			pback1->rightChild = nullptr;
		}else{
			pback1->leftChild = nullptr;
		}
		
		if(t2 > pback2->val){
			pback2->rightChild = nullptr;
		}else{
			pback2->leftChild = nullptr;
		}
	}
	
	void DeleteNodes(CTNode* curr){
		if(!curr){
			return;
		}
		DeleteNodes(curr->rightChild);
		DeleteNodes(curr->leftChild);
		curr->rightChild = nullptr;
		curr->leftChild = nullptr;
		delete curr;
	}
};

void DFS(CTNode* curr){
	if(!curr)return;
	
	DFS(curr->rightChild);
	DFS(curr->leftChild);
	if(!(curr->rightChild || curr->leftChild)){
		cout << curr->val << " ";
	}
}

int main(){
	
	BST* T = new BST();
	LinkedList* LShort = new LinkedList();
	LinkedList* LLong = new LinkedList();
	
	char isRead = 'y';
	
	while(isRead == 'y'){
		//read
		cout << "Enter number of nodes: ";
		int n, x;
		cin >> n;
		while(n--){
			cin >> x;
			T->insert(x);
		}
		
		//find 2 target values
		cout << "Enter 2 Target Values: ";
		int t1, t2;
		cin >> t1 >> t2;
		T->FindTarget(t1,t2,LShort,LLong);
		
		T->DeleteNodes(T->root);
		cout << "Continue?(y)es  (n)o\n->";
		cin >> isRead;
	}
	
	//display leaves
	cout << "\nLShort:";
	CNode* curr = LShort->head;
	while(curr){
		cout << "\n";
		DFS(curr->down);
		curr = curr->next;
	}
	
	cout << "\nLLong:";
	curr = LLong->head;
	while(curr){
		cout << "\n";
		DFS(curr->down);
		curr = curr->next;
	}
	
	return 0;
}

/*
test case
34
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
755
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
450
550
430
560

750 1200
n
*/

/*
output
LShort:
1700 1100 980 920 
LLong:
755 720 560 430
*/
