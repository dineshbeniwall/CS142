#include<iostream>
#include<cstring>
using namespace std;

/*Q1 : 
Write a class House which has the following data and functions : (you may add other function members to help you with the program) 
1. Name of the house (Data)
2. Address 
3. Rooms 
4. Setup  // Asks for entry of data to house)
5. Display // Displays the details of house - Name, Address, Rooms, Total area of the house (Sum of rooms), Also displays like "3 Bedroom, 1 Kitchen and 2 Bathroom. " - This should use the displays of the address and room class.
6. CopyHouse  // Takes input as a name and a another object of house as input and and copies all the details of the house except the name

Address itself is a class; which stores the following data and functions
1. House Number (CString)
2. City (Cstring)
3. Zipcode (Number)
4. Setup // Asks the user to enter data for address and sets the address
5. Display // Displays the address 

Room also is a class, which store the following data and functions
1. Length
2. Breadth
3. Height 
4. Purpose // Cstring to store "Kitchen, Bathroom, Bedroom etc"
5. Setup // Asks the user to enter data for rooms and sets the room
*/
class House{
	public:
	class Address{
		public:
		int zipcode;
		char str1[20]="city",str2[50]="house number";
		void setup(){cout<<"put the house number";cin>>str2;
			     cout<<"put the city";cin>>str1;
			     cout<<"write zipcode";cin>>zipcode;
			cout<<str2<<","<<str1<<","<<zipcode;		
		}
	};
	class rooms{
		public:
		int length,breadth,height,room;
		int setup(){cout<<"put the values of length,breadth,height and numbers of rooms"<<endl;cin>>length>>breadth>>height>>room;}
		char str1[10]="Kitchen";char str2[10]="Bathroom";char str3[10]="Bedroom";
		double area=room*(length*breadth);
		void print(){cout<<"number of rooms:"<<room<<",area of house:"<<area<<" and 1"<<str1<<", 2"<<str2<<(room-3)<<str3;}			
	};
	
};
int main(){
	House aasheerwad;
	cout<<aasheerwad<<endl;
return 0;
}










