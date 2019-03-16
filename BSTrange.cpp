	#include<iostream>
using namespace std;
			// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ ]
			//a lot stuff to do in this chapter, link above
//***************//size of tree is called no. of elements 
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
//Display
//inorder (left,root,right) 
	void Displayin(){displayin(root);cout<<endl;}
	void displayin(Node*curr){
		//if empty tree
		if(root==NULL){cout<<"there is nothing to print"<<endl;}
		else{
			//go left and left.........print
			//come back print........go right
			//.......print right
			if(curr==NULL)return;		
			else{
				//if below code didn't get try to wright
				displayin(curr->left);
				cout<<curr->data<<",";
				displayin(curr->right);		
			}
		}
	}
//count all the elments in bts************************************************************best
	int count(){cout<<ct(root)<<endl;}
	int ct(Node*curr){
			int s=0;
			if(curr==NULL){return 0;}
			else{s=ct(curr->left)+1+ct(curr->right);}
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
// int rangeSearch(int k1, int k2) ->range search: given two values k1 and k2, print all the elements (or keys) x in 
//the BST such that k1 <= x <= k2. Also count the number of elements in the range from k1 to k2 and returns it. 
//??????????????????????????????????????a problem in count
	int rangeSearch(int k1,int k2){
		//for printing remains same as display but cout inside the if condition and also count++
		cout<<disnct(root,k1,k2,10)<<endl;
	}
	int disnct(Node*curr,int k1,int k2,int count){
		//if empty tree
		if(root==NULL){cout<<"tree is empty"<<endl;}
		else if(curr==NULL) return count;
		else {
			disnct(curr->left,k1,k2,count);
			if(k1<=curr->data and curr->data<=k2){
				count++;				
				cout<<curr->data<<",";			
			}
			disnct(curr->right,k1,k2,count);	
		}
		return count;			
	}
//time for calculate height of a tree  or subtree
//go to the every leaf and count also with it 
//put max of all counts
//ulltimtly present max=max of left and right subtree + 1 itself
//??????????????????????????what should i return???????????????????????????????????
	int height(int value){
		int maxh=0;
		Node*curr=Search(value);
		cout<<ht(curr,maxh)<<endl;
	}
	int ht(Node * curr,int maxh){
		if(curr==NULL)return 0;
		else{
			//maxh=max(ht(curr->left),ht(curr->right))+1;
			if(ht(curr->left,maxh)<ht(curr->right,maxh))maxh=ht(curr->right,maxh)+1;
			else maxh=ht(curr->left,maxh)+1;
		}
	return maxh;
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
	b1.insert(54);
	b1.insert(53);
	b1.insert(52);
	b1.insert(51);
	b1.insert(65);
	b1.insert(32);
	b1.insert(33);
	b1.insert(68);
	b1.Displayin();
	//b1.height(40);
	//b1.count();
	b1.rangeSearch(50,60);

	return 0;
}



