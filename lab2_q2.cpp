#include<iostream>
using namespace std;

/*Implement Singly Linked List using C++. Make sure the following functions: 
insert(int data) - Adds a new element to the end of the linked list. 

insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  

Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   

delete() - Deletes the element at the end of the list. 

deleteAt(int pos) - Deletes the element(or node) at the position pos)

countItems() - Returns the number of items in the linked list. 

display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 

*/
class Node{
	public:
		//node have data
		int data;
		//pointer for next node
		Node *next;
		//last node is null and for that there is a Constructer. the feture of this coustructer is that is have same name as class and no need to call this it atomatic change the things inside a class
		Node(){
				next=NULL;
			}

};
class Linkedlist{
	public:
		//HEAD is basically which point towards the node
		Node *head,*tail;
		//construct which first give null values to head and tail
		Linkedlist(){
				head = NULL;
				tail = NULL;
			}		
		//all stuff  like new node and give values to it
/*adding*/		//also like that we create head and tail and set it like if wanna add something than it add in the end
	void insert(int value){
		//it's time for create new node till now we create pointers which point towerds the node
		Node *temp = new Node;
		//give to the value
		temp->data=value;
		//basically we did that ask to pointer and go to the object inside directed class and assine the value 
		//if it is first node than give temp to head yeeee 
		if(head==NULL){head=temp;}
		//so we create head now for second time we add it to tail but for first time it happane becoz if work and when else come we add temp to tail 
		else{tail->next=temp;}
		//this time we also create tail we can see that tail and head both are same 
		tail=temp;			
		}
		//next time it increase becoz tail and head are same

		//for this time iof wanna to add in the middle of the link 
	void insertat(int value, int posi){
		//first reach where we wanna to add for this make a new pointer which move all the addresse of nodes
			Node *current=head;
		int i=1;
		while(i<posi-1){
		//this way we go further
			i++;current=current->next;
		}
		//than create a new one and insert the value inside the node
		Node * temp = new Node;
		temp->data=value;
		//now let store the value of current and current+ so it adds
		//if current is not head than, new ka next have address of 3
		temp->next = current->next;
		current->next=temp; //give the address of current of to temp and we make it
	}
/*deleting*/
		//last one delete
	void delet(){
		//so how we do, first we reach second last and
		Node *current=head;
		 while(current->next != tail){
           		 current = current->next;
      		  }
        
		// than give the address of last to other pointer
		Node * temp;
		temp = current->next;
		//now make tail to second lasst
		tail=current;
		tail->next=NULL;
		delete temp;
	}
		//let's delete at any point
	void deletat(int posi){
		//same process first reach before delete position
		Node*current=head;
		int i=1;
		while(i<posi-1){
		//this way we go further
			i++;current=current->next;
		}
		//now make a new pointer and store the wanted address
		Node*temp;
		temp=current->next;
		//add 1 and 3 together
		current->next=temp->next;
		//now delete
		delete temp;
	}
	//let's count all the items linked
	int countitems(){
		//MAY BE SOME OTHER WAYS BUT I CAN COUNT ARROW
		int count=0;
		Node * current = head;
		while(current != NULL){
		    count++;
		    current = current->next;
		}
		cout<<"=> "<<count<<endl;
	}
		//this is the time when we want to display all the stuff
	void display(){
		//so easy stuff understand by seeing below
		Node * current = head;
		while(current != NULL){
		    cout << current->data << "->";
		    current = current->next;
		}
		cout << endl;
	}
//let's delete some repeted terms
	void delrep(){
//first check which term is repted and what's the position 
		Node *current=head;
		while(current->next != NULL){
			cout << "Current data "<< current->data  ;
			int s=current->data;
			int i=1;

			for(Node *nex=head;nex->next != NULL;nex=nex->next){
				
				

//than call the delete function......done
				if(nex->data==s and nex != current){
cout << "nex data "<< nex->data << ":" << nex << ":" << current << "--" << i <<endl ;

deletat(i);
}			i++;
			}
			current = current->next;
cout << endl;

		}
	}

};

int main(){
    Linkedlist l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(2);
	l1.insert(4);
	l1.insert(4);
	l1.insert(4);
	l1.insert(5);
	l1.insert(5);
	l1.insert(6);
    l1.display();
	//l1.countitems();
    //l1.delet();
    //l1.display();
	//l1.countitems();
    l1.deletat(3);
    l1.display();
	//l1.countitems();

   //l1.insertat(8,2);
	l1.delrep();
    l1.display();
	//l1.countitems();
  
  return 0;
}













