#include<iostream>
using namespace std;
struct adr{
	string street;
	string city;
	string state;
	int postalcode;
	
};
struct employee{
	string name;
	int age;
	string department;
	int salary;
	adr  adress;
};
employee arr[2];
int count=0;
void employeesearch(string n);
void displayemploy();
int addemploy();
int main()
 {
	string n;
	int choice;
	do{
	cout<<"press 1 to add employees"<<endl;
	cout<<"press 2 to display employees"<<endl;
	cout<<"press 3 to search"<<endl;
	cout<<"enter choice"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			addemploy();
			break;
			case 2:
				cout<<"display data:"<<endl;
				displayemploy();
			case 3:
				cout<<"input name to search"<<endl;
				cin>>n;
				employeesearch(n);
				break;
				default:
					cout<<"invalid"<<endl;
					break;
	}
	}
	while(choice!=4);
	return 0;
}
int addemploy()
{
	employee z;
	for(int i=0; i<2; i++) 
	{
		cout<<"enter the name"<<endl;
		cin>>z.name;
		cout<<"enter the age"<<endl;
		cin>>z.age;
		cout<<"enter the department"<<endl;
		cin>>z.department;
		cout<<"enter the salary"<<endl;
		cin>>z.salary;
		cout<<"enter the street"<<endl;
		cin>>z.adress.street;
		cout<<"enter the city"<<endl;
		cin>>z.adress.city;
		cout<<"enter the state"<<endl;
		cin>>z.adress.state;
		cout<<"enter the postalcode"<<endl;
		cin>>z.adress.postalcode;
	}
	 arr[count++]=z;
}
void displayemploy()
{
  for(int i=0; i<count; i++) 
  {
		cout<<"enter the name"<<arr[i].name<<endl;
		cout<<"enter the age"<<arr[i].age<<endl;
		cout<<"enter the department"<<arr[i].department<<endl;
		cout<<"enter the salary"<<arr[i].salary<<endl;
		cout<<"enter the street"<<arr[i].adress.street<<endl;
		cout<<"enter the city"<<arr[i].adress.city<<endl;
		cout<<"enter the state"<<arr[i].adress.state<<endl;
		cout<<"enter the postalcode"<<arr[i].adress.postalcode<<endl;
	}
}
void employeesearch(string n) 
{
		for(int k=0;k<=count;k++){
			if(arr[k].name==n)
				cout<<"enter the name"<<arr[k].name<<endl;
		cout<<"enter the age"<<arr[k].age<<endl;
		cout<<"enter the department"<<arr[k].department<<endl;
		cout<<"enter the salary"<<arr[k].salary<<endl;
		cout<<"enter the street"<<arr[k].adress.street<<endl;
		cout<<"enter the city"<<arr[k].adress.city<<endl;
		cout<<"enter the state"<<arr[k].adress.state<<endl;
		cout<<"enter the postalcode"<<arr[k].adress.postalcode<<endl;
	}
}
