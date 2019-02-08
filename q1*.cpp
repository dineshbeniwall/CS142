#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
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
		
	void insert(int value){
		//it's time for create new node till now we create pointers which point towerds the node
		Node *temp = new Node;
		//give to the value
		temp->data=value;
		if(head==NULL){head=temp;}
		else{tail->next=temp;}
		//this time we also create tail we can see that tail and head both are same 
		tail=temp;			
		}
	void insertat(int value, int posi){
		//first reach where we wanna to add for this make a new pointer which move all the addresse of nodes
			Node *current=head;
		int i=1;
		if(i==1){
			Node * temp = new Node;
			temp->data=value;
			temp->next = current;
			head=temp;
			if(head->next==NULL){
				tail=head;			
			}
		}
		else{
			while(i<posi-1){
		//this way we go further
			i++;current=current->next;
			}
			Node * temp = new Node;
		temp->data=value;
		temp->next = current->next;
		current->next=temp;
	
		}	//than create a new one and insert the value inside the node
		 //give the address of current of to temp and we make it
	}

	void delet(){
		//so how we do, first we reach second last and
	//if linked list is empty and you still want to delete
		if(head==NULL)return;
	//if linked list have only one element
		else if(head->next==NULL){
			Node * temp;
			temp=head;
			head=NULL;
			tail=NULL;
			delete temp;	
		}
	//delete last element
		else{
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
	}
		//let's delete at any point
	void deletat(int posi){
		//same process first reach before delete position
		Node*current=head;
		int i=1;
	//if you want to delete from empty linked list
		if(head==NULL)return;
	//if you want to delete fist posi element
		else if(i==1){
			Node*temp;
		head=current->next;
		temp=current;
		delete temp;
		}
	//delete at any point
		else{
			while(i<posi-1){
			//this way we go further
			i++;current=current->next;
			}
			//now make a new pointer and store the wanted address
			Node*temp;
			temp=current->next;
			//add 1 and 3 together
			current->next=temp->next;
			temp->next=NULL;
			//now delete
			delete temp;
		}
		
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
		//cout<<count<<endl;
	return count;
	}
		//this is the time when we want to display all the stuff
	void display(){
		//so easy stuff understand by seeing below
		if(head==NULL){
			cout<<"queue/stack/linked list is empty"<<endl;
		}
		else{
			Node * current = head;
			while(current != NULL){
		    cout << current->data << "->";
		    current = current->next;
			}
			cout << endl;
		}
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

/*int main(){
    Linkedlist l1;
    l1.insert(1);
    l1.insert(2);
    //l1.insert(2);
	//l1.insert(4);
	//l1.insert(4);
	l1.insert(4);
	//l1.insert(5);
	l1.insert(5);
	l1.insert(6);
    l1.display();
	//l1.countitems();
    //l1.delet();
    //l1.display();
	//l1.countitems();
    l1.deletat(1);
	 l1.display();
	 //l1.insertat(8,1);
	l1.delet();
    l1.display();
	//l1.countitems();

  
	//l1.delrep();
   // l1.display();
	//l1.countitems();
  
  return 0;
}*/













