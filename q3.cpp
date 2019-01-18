#include<iostream>
using namespace std;

/*revers a linked list*/
//first create a linked list by the same way
class Node{
	public:
	Node *next;
	int data;
	Node(){next = NULL;}
};

class Linkedlist{
	public:
	Node *head;
	Node *tail;
	Linkedlist(){head=NULL;tail=NULL;}
	
	void insert(int value){
		Node *temp=new Node;
		temp->data=value;
		if(head==NULL){head=temp;}
		else{tail->next=temp;}
		tail=temp;
	}
	void insertat(int value, int posi){
		Node *current=head;
		int i=1;
		while(i<posi-1){
			i++;current=current->next;
		}
		Node * temp = new Node;
		temp->data=value;
		temp->next=current->next;
		current->next=temp;		
	}
	
//there is two things print reverse or revers linked list
//first try print reverse
	//may be we can do it by recurtion
/*???????????????revdisplay(current=current->next)=========error*/

	//Node *current=head;
	void revdisplay(Node * current){
		if(current -> next==NULL){cout<<current -> data<<"~";}
		else{
			//current=current -> next;
			revdisplay(current -> next);
			cout<< current->data<<"~";		
		}
	}
	void revdisplay2(Node *d1){
		cout<<"reverse LL ";
		revdisplay(d1);
		cout<<endl;
	}

//second reverse linked list
	void invert2(Node*d1,Node*d2){
		invert(d1,d2);
		tail=d1;
		d1->next=NULL;
	}

	void invert(Node *p1,Node *p2){

//method 2 by recurtion 
//two pointers and one should be last and another one just before and pass last next value to another last
		
		if(p2==NULL){head=p1;}
		else{
			invert(p2,p2->next);
			p2->next=p1;
		}
		
	}
//!= not =!
	void display(){
		Node * current = head;
		while(current != NULL){
		    cout << current->data << "->";
		    current = current->next;
		}
		cout << endl;
	}
};

int main(){
	Linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert(7);
	//l1.insertat(10,5);
	l1.display();
	l1.invert2(l1.head,l1.head->next);
	l1.display();
	l1.revdisplay2(l1.head);
	
	
return 0;
}


























