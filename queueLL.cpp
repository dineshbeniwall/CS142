#include <iostream>
#include "q1*.cpp"
using namespace std;
/*basically queue is linked list bounded by rules like add at top(end) and delete at bottom(first)
	queue by using of linked list
*/

class Queue{
	public:
	Node *end,*first;
	Linkedlist l1;
	Queue(){
		end=NULL;
		first=NULL;
	}
	//enter at top by using function of linked list
	void enqueue(int value){
		//void insertat(int value, int posi){
		l1.insertat(value,1);
		//end=new_head
		end=l1.head;
		//first=only one tail
		first=l1.tail;
	}
	//delete at the bottom using function of linked list
	void dequeue(){
		//void delet()
		l1.delet();
		//first=new_tail
		first=l1.tail;		
	}
	//check it out queue is empty or not
	bool isEmpty(){
		if(first==NULL)return true;
		return false;
	}
	//for size of queue simply countitems
	int size(){
		return l1.countitems();
	}
	//display queue elements
	void display(){
		l1.display();
	}
};

int main(){
	Queue q1;
	
	for(int i=0;i<5;i++)
		q1.enqueue(i);
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
		
return 0;
}









