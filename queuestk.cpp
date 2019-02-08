#include <iostream>
#include "st.cpp"
using namespace std;
/*basically queue is linked list bounded by rules like add at top(end) and delete at bottom(first)
	queue by using of stack
*/

class Queue{
	public:
	Node *end,*first;
	Stack s1,s2;
	Queue(){
		end=NULL;
		first=NULL;
	}
	//enter at top by stack functions
	void enqueue(int value){
		//void push(int value)
		s1.push(value);
		//update end and first
		end=s1.top;
		if(s1.top->next==NULL)first=s1.top;
	}
	//delete at the bottom 
	void dequeue(){
//use of two stack push all stuff in another till last one and delete and again push back same stack
	//method 1.......looop
/*		while(end!=first){
			s2.push(s1.top->data);
		//now delete but before update end 
			end=s1.top->next; 
			s1.pop();	
		}
		end=NULL;
		first=NULL;
		s1.pop();
		//bring them back
		while(s2.top!=NULL){
			s1.push(s1.top->data);
			end=s1.top;
			if(s1.top->next==NULL)first=s1.top;
		}
		}*/
	//method 2......recurtion
	if(end==NULL)return;
	else{
		if(s1.top->next==NULL){
			end=NULL;
			first=NULL;
			s1.pop();
		}
		else{		
			s2.push(s1.top->data);
			end=s1.top->next;			
			s1.pop();
			dequeue();
		//bring them back
			s1.push(s2.top->data);
			end=s1.top;
			if(s1.top->next==NULL)first=s1.top;
			s2.pop();
		}
	    }		
	}
	//check it out queue is empty or not
	bool isEmpty(){
		if(first==NULL)return true;
		return false;
	}
	//for size of queue simply countitems
	void size(){
		if(end==NULL){cout<<"Ha Ha fool"<<endl;}
		else{s1.sizee();}
	}
	//display queue elements
	void display(){
		if(end==NULL){cout<<"queue is empty, do you still want to delete nothing"<<endl;}
		else{s1.display();}
	}
};

int main(){
	Queue q1;
	
	for(int i=0;i<5;i++)
		q1.enqueue(i);
	q1.display();
	q1.size();
	q1.dequeue();
	q1.display();
	q1.size();
	q1.dequeue();
	q1.display();
	q1.size();
	q1.dequeue();
	q1.display();
	q1.size();
	q1.dequeue();
	q1.display();
	q1.size();
	q1.dequeue();
	q1.display();
	q1.size();
		
return 0;
}









