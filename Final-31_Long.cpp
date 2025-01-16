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

CTNode* findMax(CTNode* curr){
	while(curr->rightChild && curr->rightChild->rightChild){
		curr = curr->rightChild;
	}
	return curr;
}

int DFStotal(CTNode* curr){
	if(!curr)return 0;
	
	int left = DFStotal(curr->leftChild);
	int right = DFStotal(curr->rightChild);
	
	return left + right + curr->val;
}

int CopyToLL(CTNode* curr, CTNode* curr_list, int f, int& ct, int& count_leaves){
	if(!curr){
		return -1;
	}
	if(!curr->leftChild && !curr->rightChild){
		count_leaves++;
		if(ct == f){
			ct++;
			return curr->val;
		}
		ct++;
	}
	
	if(curr->rightChild){
		curr_list->rightChild = new CTNode(curr->rightChild->val);
	}
	if(curr->leftChild){
		curr_list->leftChild = new CTNode(curr->leftChild->val);
	}
	
	int left = CopyToLL(curr->leftChild, curr_list->leftChild, f, ct, count_leaves);
	int right = CopyToLL(curr->rightChild, curr_list->rightChild, f, ct, count_leaves);
	
	if(left != -1){
		return left;
	}
	return right;
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
	
	CTNode* Pre_plargest = findMax(T->root);
	CTNode* plargest = Pre_plargest->rightChild;
	cout << "PLargest = " << plargest->val << endl;
	
	//get total of subtrees
	int total = DFStotal(plargest->leftChild);
	cout << "\nTotal = " << total << endl;
	cout << "Total - Plargest = " << total - plargest->val << endl;
	
	//cut and paste
	while(total != plargest->val){
		ll->push(plargest->val);
		ll->tail->down = plargest;
		Pre_plargest->rightChild = nullptr;
		
		Pre_plargest = findMax(T->root);
		plargest = Pre_plargest->rightChild;
		cout << "PLargest = " << plargest->val << endl;
		
		//get total of subtrees
		total = DFStotal(plargest->leftChild);
		cout << "\nTotal = " << total << endl;
		cout << "Total - Plargest = " << total - plargest->val << endl;
	}
	
	//copies with no leaf
	int f = 0;
	int prev = 0;
	
	while(prev != -1){
		int count_leaves = 0;
		int ct = 0;
		ll->push(plargest->val);
		ll->tail->down = new CTNode(plargest->val);
		prev = CopyToLL(plargest->leftChild ,ll->tail->down, f, ct, count_leaves);
		f++;
		ll->tail->val = prev;
		if(f == count_leaves)
			break;
	}
	
	CNode* trav = ll->head;
	cout << endl << "------------\nLinked List subtrees\n";
	while(trav){
		cout << trav->val << endl;
		trav = trav->next;
	}
	
	return 0;
}

/*
29
500
200
800
90
280
910
80
250
900
10000
85
850
1200
15000
83
950    
1700
10200
81
84
920
1000
10400
980
1100
10250
10600
970
1180
*/
