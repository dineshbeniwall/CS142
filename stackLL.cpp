#include <iostream>
#include "q1*.cpp"

/*stack is basically a linked list bounded by rules , like add on the top and delete also on top.
	now stack using linkd list
*/
using namespace std;

class Stack{
	public:
	Node *top;
	Linkedlist l1;
	Stack(){
		top=NULL;
	}
	//add a value on the top of stack we call it push
	void push(int value){
		//void insertat(int value, int posi){
		l1.insertat(value,1);
		//top = new_head
		top=l1.head;
	}
	//delete first element of stack we call it pop
	void pop(){
		//void deletat(int posi)
		l1.deletat(1);
		//update head
		top=l1.head;
	}
	//check if stack is empty or not
	bool isEmpty(){
		if(top==NULL)return true;
		return false;
	}
	//size of stack is directaly count the elements of stack
	int size(){
		return l1.countitems();
	}
	//display all the elements
	void display(){
		l1.display();
	}
};

int main(){
	Stack s1;

	for(int i=0;i<5;i++)
		s1.push(i);
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	
	
return 0;
}









