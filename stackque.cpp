#include <iostream>
#include"que.cpp"
/*stack is basically a linked list bounded by rules , like add on the top and delete also on top.
	now stack by using queue
*/
using namespace std;

class Stack{
	public:
	//Node *top;
	Queue q1;
	/*Stack(){
		top=NULL;
	}*/
	void push(int value){
		//enter the value is same for both
		q1.enqueue(value);
		//top=q1.end;
	}
//method 1......................made two queue and do same stuff like stack
//do not know how to do with one element but i can do with two queues
//put all element in the new queue and delete last one and again put them again 
/*
	void pop1(){
		Node *temp=q2.end;
	//i need this for retransfaring {Node *temp=q2.end;}		
	//transter all in q2 and delete last one
	//after coming back from recurtion delete one from q1 and add from q2 in q1
		if(top->next==NULL){
			q2.enqueue(top->data);
			temp=q2.end;
			q2.dequeue();
			//q1.dequeue();
			q1.enqueue(temp->data);
			temp=temp->next; 
		}
		else{
			q2.enqueue(top->data);
			top=top->next;
			pop1();
			q1.dequeue();
			if(temp!=NULL){
				q1.enqueue(temp->data);
				temp=temp->next;
			}			
		}
	//we still have two problemes 1.one element remaning in q1 2.empty q2 for next time use make another function	
	}
	void pop(){
		pop1();
		//1.solved
		//q1.dequeue();
		//2.solved
		while(q2.first!=NULL){
			q2.dequeue();
		}
	}
*/
//method 2............use only same queue and take last element and put it top till first element and delete it
	int pop(int i){

		//if(i==(size()-1)){
		if(i ==size()){		
			q1.dequeue();
			return 0;
		}
		else{
			q1.enqueue(q1.dequeue());			
			pop(i+1);
		}
	}
//method 3 ...best ever 
/*		for(int i=0;i<q1.size()-1;i++){
			q1.enqueue(q1.dequeue());
		}
		return q1.dequeue();
	}*/
//need this one stop recurtion in pop function
	int size(){
		return q1.size();
	}
	//display all the elements
	void display(){
		q1.display();
	}
};

int main(){
	Stack s1;
	for(int i=1;i<5;i++){
		s1.push(i);	
	}
	s1.display();
	s1.size();
	s1.pop(1);
	s1.size();
	s1.display();
	s1.pop(1);
	s1.size();
	s1.display();
	s1.pop(1);
	s1.size();
	s1.display();
//	s1.pop();
//	s1.size();
//	s1.display();

return 0;
}
