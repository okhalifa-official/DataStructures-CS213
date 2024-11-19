#include <iostream>

using namespace std;

struct Node{
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
	~Node(){
		delete [] next;
	}
};

class LinkedList{
	Node* head;
	Node* extra;
	int v1;
	int v2;
public:
	LinkedList(int v){
		Node* new_node = new Node(v);
		head = new_node;
		v1=0;
		v2=4;
	}
	LinkedList(){
		head = nullptr;
		v1=0;
		v2=4;
	}
	
	Node* getHead(){
		return head;
	}
	
	void setHead(Node* node){
		head = node;
	}
	
	void insert(Node* new_node){
		if(!head){
			head = new_node;
			extra = head;
			v1++;
			return;
		}else if(!head->next){
			head->next = new_node;
			head->next->down = new_node;
		}else{
			head->next->down->next = new_node;
			head->next->down = new_node;
		}
		if(v1-v2/2+2<(v2/2)){
			extra = extra->next;
		}
		v1++;
	}
	
	
	void print(){
		Node* current = head;
		while(current){
			cout << current->value << " -> ";
			current = current->next;
		}
		cout << "\n";
	}
	
	void AttachAndCut(Node* pnn){
		insert(pnn);
		if(v1==v2){
			extra->next->down = head;
			extra->next->next->down = head->next->down;
			head = extra->next;
			extra->next = nullptr;
			extra->down = nullptr;
			extra = head;
			v2 += 2;
			v1 /= 2;
		}
	}
	
	~LinkedList(){
		Node* temp = head;
		while(head){
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};

int main(){
	
	LinkedList* ll = new LinkedList();
	int x;
	while(cin>>x){
		Node* new_node = new Node(x);
		ll->AttachAndCut(new_node);
		ll->print();
	}
	cout << endl << endl;
	
	return 0;
}
