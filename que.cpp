#include <iostream>

using namespace std;
/*basically queue is linked list bounded by rules like add at top(end) and delete at bottom(first)
	queue by using of simple functions
*/
class Node{
	public:
		int data;
		Node *next;
		Node(){
			next=NULL;
		}
};
class Queue{
	private:
	Node *end,*first;
	

	public:
	
	Queue(){
		end=NULL;
		first=NULL;
	}
	void enqueue(int value){
		Node *temp=new Node;
		temp->data=value;
		//if queue is empty
		if(end==NULL){
			end=temp;
			first=temp;
		}
		//if queue have is not empty
		else{
			temp->next=end;
			end=temp;
		}
	}
	int dequeue(){
		//if queue is empty
		int ret;
		if(end==NULL)return 0;
		//if queue have only one element
		else if(end->next==NULL){
			Node *temp=end;
			end=NULL;
			first=NULL;
		//return the value before delete
			ret=temp->data;
			delete temp;
		}
		//delete any other element
		else{
			Node *current=end;
			while(current->next!=first){
				current=current->next;
			}
			Node *temp=first;
			first=current;
			current->next=NULL;
			ret=temp->data;
			delete temp;			
		}
		return ret;
	}
	//check it out queue is empty or not
	bool isEmpty(){
		if(first==NULL)return true;
		return false;
	}
	//for size of queue simply countitems
	int size(){
		Node *current=end;
		int count=0;
		while(current!=NULL){
			current=current->next;
			count++;
		}
		//cout<<"items:"<<count<<endl;
		return count;
	}
	void display(){
		Node*current=end;
		while(current!=NULL){
			cout<<current->data<<"~";
			current=current->next;
		}
		cout<<endl;
	}
	
};





