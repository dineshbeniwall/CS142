#include<iostream>
using namespace std;
			//link for all reqire psudo codes, and besic methods to approach
			//https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm
			// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ ]
			//a lot stuff to do in this chepter link above

//create node
class Node{
	public:
	int data;
	Node*left;
	Node*right;
	//constructor and this time temp->data=value === Node*temp(value)
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
};
//create clss of bts
class BiST{
	public:
	Node*root;
	BiST(){root=NULL;}
	//things to do
//insert
	void insert(int value){
		insert2(root,value);
	}
	void insert2(Node*curr,int value){
		//no root
		if(curr==NULL){root=new Node(value);}
		//root exist but data is less then root
		else if(value<curr->data){
			//pass to next one or create and add
			if(curr->left==NULL){
				curr->left=new Node(value);
			}
			//else pass
			else{insert2(curr->left,value);}
		}
		//root exist but data is more then root
		else{
			//same create or pass to next one
			if(curr->right==NULL){
				curr->right=new Node(value);
			}
			else{insert2(curr->right,value);}
		}
	}
//display
	void Display(){display(root);cout<<endl;}
	void display(Node*curr){
		//if empty tree
		if(root==NULL){cout<<"there is nothing to print"<<endl;}
		//so our tree send small to left and big to right w.r.t. root so last left element is smallest one 
		//idea is reach to last one print come back print go right print come back/
		else{
			if(curr==NULL)return;		
			else{
				//if below code didn't get try to wright
				display(curr->left);
				cout<<curr->data<<",";
				display(curr->right);		
			}
		}
	}
//search
	void Search(int value){search(root,value);}
	void search(Node*curr,int value){
		if(curr==NULL){cout<<"I am unable to find"<<endl;}
		else{
			if(value<curr->data){search(curr->left,value);}
			else if(value>curr->data){search(curr->right,value);}
			else{cout<<"we get the value"<<endl;}
		}
	}

};

int main(){
	BiST b1;
	b1.insert(1);
	b1.insert(2);
	b1.insert(7);
	b1.insert(9);
	b1.insert(10);
	b1.insert(3);	
	b1.insert(4);
	b1.insert(15);	
	b1.insert(34);
	b1.insert(65);	
	b1.insert(69);
	b1.insert(72);	
	b1.insert(42);
	b1.insert(21);
	b1.Display();
	b1.Search(15);
	b1.Search(16);
return 0;
}







