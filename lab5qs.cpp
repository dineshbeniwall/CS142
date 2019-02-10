#include<iostream>
using namespace std;

//first attempt of partion is failed
/*
int part(int*arr,int pivot,int size){
	int v=arr[pivot];
	//cout << size - pivot - 1 << " : " << pivot  << endl;
	if(size > pivot){
	for(int i=(size-pivot-1);i<pivot;){
		//cout<<pivot;
		if(arr[i]>arr[pivot]){
			int temp=arr[i];
			for(int j=i;j<size;j++){
			arr[j]=arr[j+1];
			}
			arr[size]=temp;
			int count=0;
			for(int i=0;arr[i]!=v;i++){
				count++;
			}
			//int pp=pivot;
			pivot=count;
			if(arr[i]>arr[pivot]){i=i;}
			else{i++;}
		}
		else{i++;}
	}
	}
	return pivot;	
}
*/
//second suggation

int part(int *arr,int low,int high){
	
	int pivot=arr[high];
	int pi=low;
	//we go along array if a[i] is less equal to then put at 1 ,2,3 position as partitionindex place
	for(int i=low;i<high;i++){
		if(arr[i]<=pivot){
		swap(arr[i],arr[pi]);
		pi++;
		}
	}
	//after all done
	swap(arr[pi],arr[high]);
	return pi;
}

//quickshort function
void QS(int *arr,int low,int high){
	if(low<high){
		//what is pivot==number in array at end and partition ''index'' 	from which we compare
		//int pivot=a[endd];
		//call partition function
		int pivot=part(arr,low,high);
		//recursive function
		QS(arr,low,pivot-1);
		QS(arr,pivot+1,high);
	}
}
void print(int *arr,int n){	
	for(int i=0;i<n;i++){
	cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main(){
	int arr[50]={7,1,8,6,5,2,3,9,4};
	int n=9;
	/*cout<<"first enter the size and then elements"<<endl;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}*/
	//part(arr,0,n-1);
	QS(arr,0,n-1);
	print(arr,n);
return 0;
}

