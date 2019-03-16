	#include<iostream>
using namespace std;
			// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ ]
			//a lot stuff to do in this chapter, link above
//***************//size of tree is called no. of elements 
//***************//delete a node
//????????????????????????????what if you want to delete a value but that doesn't exist in tree
	//method...in display whenever display replace it by count
//create node
class Node{
	public:
	int data;
	Node*parent;
	Node*left;
	Node*right;
	//constructor and this time temp->data=value === Node*temp(value)
	Node(int value){
		data=value;
		parent=NULL;
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
				curr->left->parent=curr;
			}
			//else pass
			else{insert2(curr->left,value);}
		}
		//root exist but data is more then root
		else{
			//same create or pass to next one
			if(curr->right==NULL){
				curr->right=new Node(value);
				curr->right->parent=curr;
			}
			else{insert2(curr->right,value);}
		}
	}
//Display 2d
//inorder (left,root,right) 
	void Display(){
		int count=-1;	
		display(root,count);cout<<endl;
	}
	void display(Node*curr,int count){
		//if empty tree

	if(root==NULL){cout<<"there is nothing to print"<<endl;}
		
		else{
			if(curr->left==NULL and curr->right!=NULL){
				//give spaces & print & go to nest line
				for(int i=0;i<=count;i++){cout<<"	";}
				cout<<curr->data<<endl;
				//go to right
				display(curr->right,++count);
			}
			else if(curr->left!=NULL and curr->right==NULL){
				display(curr->left,++count);
				count=count-1;
				for(int i=0;i<=count;i++){cout<<"	";}
				cout<<curr->data<<endl;
			}
			else if(curr->left==NULL and curr->right==NULL){
				//give spaces & print & go to next line
				for(int i=0;i<=count;i++){cout<<"	";}
				cout<<curr->data<<endl;
				//cout<<"@"<<count<<"@";
			}		
			else{
				display(curr->left,++count);
				//give spaces & print & go to next line
				count=count-1;
				for(int i=0;i<=count;i++){cout<<"	";}
				cout<<curr->data<<endl;
				//cout<<"@"<<count<<"@";
				display(curr->right,++count);
						
			}
		}
	}
//size
//what's the problem in if i replace print by count??????????????????????????????????????????
//answer......problem in printing count
//method 2
	int size(){Size(root);}
	int Size(Node*curr){
			int s=0;
			if(curr==NULL){return 0;}
			else{s=Size(curr->left)+1+Size(curr->right);}
		return s;
	}
//node search
//simple can be understand
	Node* Search(int value){
		search(root,value);
	}		
	Node* search(Node* curr,int value){
		if(value==curr->data or curr==NULL)return curr;
		else{
			if(value>curr->data){
				search(curr->right,value);	
			}
			else search(curr->left,value);
			}
	}
//find min from given node
	Node* findmin(int value){
		fn(Search(value));	
	}
	Node* fn(Node*curr){
		if(curr->left==NULL){return curr;}
		else fn(curr->left);
	}	
//replace with parent
//we were given only one value and we have to replace it with it's parent if and only if it has no silbings
//it does not care what happen to rest behind them all just like simple replace no other things to do 
	//find two pointers of given interchenges	
	void replace_at_parent(int value){
			//if you want to replace a value that doesn't exist inside tree than put a if else condition
			Node*curr=Search(value);
			Node*temp=curr->parent;
			if(temp->left==NULL and temp->parent->right==temp){
				//replace right child to parent
				curr->parent=temp->parent;
				temp->parent->right=curr;
				delete temp;
			}
			else if(temp->left==NULL and temp->parent->left==temp){
				curr->parent=temp->parent;
				temp->parent->left=curr;
				delete temp;		
			}	
			else if(temp->right==NULL and temp->parent->right==temp){
				curr->parent=temp->parent;
				temp->parent->right=curr;
				delete temp;
			}
			else if(temp->right==NULL and temp->parent->left==temp){
				curr->parent=temp->parent;
				temp->parent->left=curr;
				delete temp;
			}
	}
//here comes the best part of programme delete the node
//delete the node and put just bigger one or smaller one value of node
	void delet(int value){
		//delete leaf
		Node*curr=Search(value);
		if(curr==NULL){cout<<"given value doesn't exist in tree"<<endl;}
		else{
			if(curr->left==NULL and curr->right==NULL){
				if(curr->parent->left==curr){
					curr->parent->left=NULL;			
					delete curr;
				}
				else{curr->parent->right=NULL;delete curr;}
			}	
			
			//delete two child node
			//three stage 1.find the delere one node by search
			//2.find smallest elemnt right side of element
			//3.replace with this one (basically we replace it)
			else if(curr->left!=NULL and curr->right!=NULL){
				Node*temp=findmin(curr->right->data);
				curr->data=temp->data;
					//delete temp;
			//we can not directly delete temp because it may have more children
			//that's sure that if it have children then they must be right side
			//now repalace with parent but with two cases..............
				if(temp->right==NULL){
					//means it have no children
					if(temp->parent->left==temp){temp->parent->left=NULL;delete temp;}
					else{temp->parent->right=NULL;delete temp;}
				}
				//else it have childrens
				else{
					if(temp->parent->right==temp){
						//replace right child to parent
						temp->right->parent=temp->parent;
						temp->parent->right=temp->right;
						delete temp;
					}
					else{
						temp->right->parent=temp->parent;
						temp->parent->left=temp->right;
						delete temp;
					}
				}		
			}
			else{
			//delete one child node
			//same as replace at parent
				if(curr->left==NULL and curr->parent->right==curr){
					//replace right child to parent
					curr->right->parent=curr->parent;
					curr->parent->right=curr->right;
					delete curr;
				}
				else if(curr->left==NULL and curr->parent->left==curr){
					curr->right->parent=curr->parent;
					curr->parent->left=curr->right;
					delete curr;	
				}	
				else if(curr->right==NULL and curr->parent->right==curr){
					curr->right->parent=curr->parent;
					curr->parent->right=curr->right;
					delete curr;
				}
				else if(curr->right==NULL and curr->parent->left==curr){
					curr->left->parent=curr->parent;
					curr->parent->left=curr->left;
					delete curr;
				}
			}
		}
	}


};

int main(){
	BiST b1;
	b1.insert(40);
	b1.insert(20);
	b1.insert(60);
	b1.insert(10);
	b1.insert(30);
	b1.insert(50);	
	b1.insert(70);
	b1.insert(65);
	b1.insert(75);
	b1.insert(5);
	b1.insert(15);
	b1.insert(25);
	b1.insert(35);
	b1.insert(45);
	b1.insert(55);	
	b1.insert(1);
	b1.insert(7);
	b1.insert(17);
	b1.insert(21);
	b1.insert(34);
	b1.insert(36);
	b1.insert(32);
	b1.insert(33);
	b1.insert(54);
	b1.insert(68);
	//b1.Display();
	//b1.delet(30);
	b1.Display();
	//cout<<b1.Search(1)<<endl;
	//cout<<b1.findmin(10)->data<<endl;
	//cout<<b1.size()<<endl;
return 0;
}



