#include <iostream>

/*stack is basically a linked list bounded by rules , like add on the top and delete also on top.
	now stack by using basic functions
*/
using namespace std;
//first create a Node class
class Node{
	public:
		int data;
		Node *next;
		Node(){
			next=NULL;
		}
};
//so my class is stack
class Stack{
	public:
	Node *top;
	Stack(){
		top=NULL;
	}
	//add a value on the top of stack we call it push
	void push(int value){
		Node *temp=new Node;
		temp->data=value;
		if(top==NULL){
			top=temp;
		}
		else{
			temp->next=top;
			top=temp;
		}
	}
	//delete first element of stack we call it pop
	void pop(){
		//when stack is empty
		if(top==NULL)return;
		//when stack have only one element
		else if(top->next==NULL){
			Node *temp=top;
			top=NULL;
			delete temp;
		}
		//delete whenever you want but it is easy because every time delete first elemet
		else{
			Node *temp=top;
			top=temp->next;
			temp->next=NULL;
			delete temp;			
		}
	}
	//size of stack is directaly count the elements of stack
	void sizee(){
		Node *current=top;
		int count=0;
		while(current!=NULL){
			count++;
			current=current->next;
		}
		cout<<"size of queue :"<<count<<endl;
	}
	//display all the elements
	void display(){
		Node *current=top;
		while(current!=NULL){
			cout<<current->data<<"~";
			current=current->next;
		}
		cout<<endl;
	}
};

