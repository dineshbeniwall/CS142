#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    Node * prev;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};

class DLL{
    public:
    Node * head,*tail;
    DLL(){
        head = NULL;
	tail = NULL;
    }
    void insert(int value){
        // Create a new node
        Node * temp = new Node(value);
	//may be no need of temp->data=value becoz we already done in defination of node
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. same processer as last linked list 
		tail->next=temp;
		temp->prev=tail;
            }
	tail=temp;
    }
//now display the inserted values
    void display(){
        Node *current = head;
        Node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< "~"; 
            // Store the current in last (to catch the tail to print in reverse)
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;
        cout << "Print in reverse order : ";
        while(last!=NULL){
            cout <<last->data<< "~";
            // Move backwards 
            last = last->prev;
        }
        cout << endl;   
    }
    void InsertAt(int value, int posi){
        //make a new node
	Node *temp = new Node(value);
	//three step - reach that posi
//????????????	for(Node *current=head,int i=1;i<posi-1;i++,current=current->next){
		//there is nothing to write
//	}
	int i=1;
	Node *current=head;
	while(i<posi-1){
		current=current->next;
		i++;
	}
	//back bonding
	current->next->prev=temp;
	temp->prev=current;
	//front connection
	temp->next=current->next;
	//final dissconnection
	current->next=temp;
    }
//delete at any posi
    void DeleteAt(int posi){
	//reach the posi-1
	int i=1;
	Node *current=head;
	while(i<posi-1){
		current=current->next;
		i++;
	}
	//store the address of crimial node
	Node *temp=current->next;
	//break the connection and same time add the connections between posi-1 and posi+2 reverse steps of last del
	current->next=current->next->next;
	current->next->prev=current;
	temp->next=NULL;
	temp->prev=NULL;
	delete temp;	
}
// Deletes the last element.
    void Del(){
        //reach the last posi 
	Node *current=head;
	while(current->next->next != NULL){
		current=current->next;
	}
	//store the address of last one, if we broke the connection then we lost it not delete it
	Node *temp;
	temp = current->next;
	//break the connection
	current->next->prev=NULL;
	current->next=NULL;
	//finally delete
	delete temp; 
    }
// Counts the Number of items.
    void CountItems(){
        Node *current=head;
	int count=1;
	while(current->next!=NULL){
		current=current->next;
		count++;
	}
	cout<<"Numbers of items : "<<count<<endl;
    }

};

int main(){
    DLL dll1;
    for(int i= 1; i < 11; i++){
        dll1.insert(i);
    }
    dll1.display();
	dll1.CountItems();
	dll1.InsertAt(5,3);
	dll1.display();
	dll1.CountItems();
	dll1.Del();
	dll1.display();
	dll1.CountItems();
	dll1.DeleteAt(6);
	dll1.display();
	dll1.CountItems();
return 0;
}
