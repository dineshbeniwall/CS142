# include <iostream>
using namespace std;
/*stack is basically linked list but some resicted rules like add or delete only and only top
		now stack using arr */ 

class stack{
	public :
	int arr[50];
	int top;
	//construtor
	stack(){
		//because i start my array start form zero so inisialize the top
		top =-1;
	}
	//put the values
	void push(int value){
		//just simply put the values it's look like put before simply we add at first
		arr[++top] = value;
	}
	//delete the values
	void pop(){
		if(top<0){
			cout <<"there is nothing to delete" <<endl;
		}
		else{arr[top--];}
	}
	//display the array
	void Display(){
		for(int i=top;i>=0;i--){
			cout <<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.Display();
	s1.pop();
	s1.Display();
	s1.pop();
	s1.Display();
	s1.pop();
	s1.Display();
	s1.pop();
	s1.Display();
	s1.pop();
	s1.Display();
	s1.pop();
	s1.Display();

return 0;
}

















