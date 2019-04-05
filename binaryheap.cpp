//Array
//Linked list
//Stack
//Queue
//BST
//Binary Heap

#include <iostream>
using namespace std;
/*rules of bineary heap........one it's a complete tree.......second....parent<both childrens or parent>both childrens
*/ 



class Binaryheap{	
	public:
	//it's a new array actually
	int* harr;
	//max size of array
	int msize;
	//current size of array
	int csize;

	Binaryheap(int msize){
		//constructors
		///when i write int [msize] it creare a that many boxes inside head and harr point to first box
		harr = new int[msize];
        	this->msize = msize;
        	csize = 0;
	}
	//why i put *a and *b becoz i want to swap arr[i],arr[parent], i put directly swap 10 and 9 and it find out add.
	void swap(int *a,int *b){
		int temp=*a;
		*a=*b;
		*b=temp;
	}
	int parent(int i){ return (i-1)/2;}
        int left(int i){ return (i*2)+1;}
    	int right(int i){ return (i*2)+2;}
	
	int getmin(){return harr[0];}//we know minimum is must be root
	
	void insert(int value){
		//three things
		//base case for heap overfelow
		if(msize<=csize){cout<<"you can't add more than max size";}
		else{
			//no rules should be broken
			//insert the key in the last 
			if(csize==0){harr[csize]=value;}
			//second min is top on the tree in other way parent< both childs
			else{
				harr[csize]=value;
				for(int i=csize;i!=0;i=(i-1)/2){
					//if(curr<parent){swap(harr[curr],harr[par]);}
					if(harr[i]<harr[(i-1)/2]){swap(&harr[i],&harr[(i-1)/2]);}
					else{break;}
				}
			}
		}
		csize++;
	}
	void display(){for(int i=0;i<csize;i++){cout<<harr[i]<<",";}cout<<endl;}
//so for delete we do some steps and then add them all together to make a complete delete function
//first extractmin......delete min element of tree(root) and return it
	int extractmin(int i){
		//replace root with last element then check for rule 2 of tree and apply reverse insert type fun.
		//base conditions
		if(csize==0){cout<<"tree is empty"<<endl;return 0;}
		//make it for return
		else if(csize==1){int r=harr[0];csize=csize-1;return r;}
		else{
			int r=harr[i];
			//replace root with last element
			harr[i]=harr[csize-1];
			//actually we can't delete a box in arry ........so
			MinHeapify(i);
			csize=csize-1;
			return r;
		}
		
	}
//this is basically top is highest and voilate 2nd rule of heap. So by recurtion we can arrenge them
//we can also arrenge them by for loop i tried for loop
	void MinHeapify(int i){ 
        // Compare with left and right 
        // Replace with the smallest.
        	for(i;i<(csize-2)/2;){
			if(harr[i]>harr[2*i+1] or harr[i]>harr[2*i+2]){
				if(harr[2*i+1]>harr[2*i+2]){swap(&harr[i],&harr[2*i+2]);i=2*i+2;}
				else{swap(&harr[i],&harr[2*i+1]);i=2*i+1;}
			}
			else{break;}
		}
   	} 
//// Algorithm for what happens when I reduce the value of an element indexed at i to new_val. You can assume new_val to be less than the present value of the element. 
	void decreasekey(int i,int new_val){
		harr[i]=new_val;
		//correct rule 2, same as insert
		for(i;i!=0;i=(i-1)/2){
			//if(curr<parent){swap(harr[curr],harr[par]);}
			if(harr[i]<harr[(i-1)/2]){swap(&harr[i],&harr[(i-1)/2]);}
			else{break;}
		}
	}

//second 
//third
	void deletekeyat(int keyat){
		//same as extract min just as extract min basically for root but delete for everyone
		decreasekey(keyat,harr[csize-1]);
		//till now by above step we confirm that all above no rule broken
		//now repair below broken rules and delete last one
		extractmin(keyat);
	}	


};

int main(){
	Binaryheap bh1(90);
	for(int i = 10; i >0 ; i--){
		//cout << "Inserting " << i << endl;
		bh1.insert(i);
		//bh1.display();
	}
	bh1.display();
   	bh1.extractmin(0);
   	bh1.display();
	/*bh1.extractmin(0);
   	bh1.display();
	bh1.extractmin(0);
   	bh1.display();
	bh1.extractmin(0);
   	bh1.display();*/
	bh1.decreasekey(3,1);
   	bh1.display();
    	bh1.deletekeyat(4);
        bh1.display();

return 0;
}















