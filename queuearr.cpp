# include <iostream>
using namespace std;
/*queue is basically linked list but some resicted rules like add on the top and delete at the bottom    		            now queue using arr */ 

class Queue{
	public :
	int arr[50];
	int end,first;
	//construtor
	Queue(){
		//because i start my array start form zero so inisialize 
		end =-1;
		first=-1;
	}
	//put the values
	void enqueue(int value){
		//just simply put the values it's look like put before simply we add at first
		if(end==-1){
			arr[++first]=value;
		}
		arr[++end] = value;
	}
	//delete the values
	void dequeue(){
		if(end<first){
			cout <<"there is nothing to delete" <<endl;
		}
		else{
			arr[first++];			
		}
	}
	//display the array
	void Display(){
		for(int i=end;i>=first;i--){
			cout <<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	Queue q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	q1.Display();
	q1.dequeue();
	q1.Display();
	q1.dequeue();
	q1.Display();
	q1.dequeue();
	q1.Display();
	q1.dequeue();
	q1.Display();
	q1.dequeue();
	q1.Display();
	q1.dequeue();
	q1.Display();
	q1.dequeue();
	q1.Display();
	
return 0;
}

















