#include<iostream>
using namespace std;
class InventoryTracker{
private:
    int totalquantity;
    double totalvalue;
public:
InventoryTracker(){
    totalquantity=0;
   totalvalue=0.0;
}
void addItem(int quant, double valu){
	totalquantity = totalquantity+ quant;
	totalvalue = totalvalue + valu;
}
void removeItem(int quant, double valu){
	totalquantity = totalquantity - quant;
	totalvalue = totalvalue -valu;
}
void displayInventory(){
	cout<<"THE TOTAL QUANTITY = "<<totalquantity<<endl;
	cout<<"THE TOTAL VALUE  =  "<<totalvalue<<endl;
}	
};
int main()
{
	InventoryTracker i;
	char choice;
	int quant;
	double valu;
	do{
   	cout<<"ENTER a FOR ADDITEM"<<endl;
	cout<<"ENTER r FOR DELETEITEM"<<endl;
	cout<<"ENTER d FOR DISPLAY ITEM"<<endl;
	cout<<"ENTER YOUR CHOICE"<<endl;
	cin>>choice;
	switch(choice){
		case 'a':
			cout<<"ENTER QUANTITY:"<<endl;
			cin>>quant;
			cout<<"ENTER  VALUE:"<<endl;
			cin>>valu;
			i.addItem(quant, valu);
		    break;
			
		case 'r':
			cout<<"ENTER QUANTITY :"<<endl;
			cin>>quant;
			cout<<"ENTER  VALUE:"<<endl;
			cin>>valu;
		    i.removeItem(quant,valu);
		   break;
		case'd':
			i.displayInventory();
			break;
		default:
			cout<<"INVALID"<<endl;
	}
}while (choice != 'd');
	return 0;	
}
