#include <iostream>
#include "nodei.h"
using namespace std;

int main()
{
	int choice,n,m,position,i;
	NodeImplementation obj;
	while(1)
	{
		cout<<endl<<"1. Create List"<<endl;
		cout<<"2. Add at beginning"<<endl;
		cout<<"3. Add after"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Count"<<endl;
		cout<<"7. Reverse"<<endl;
		cout<<"8. Search"<<endl;
		cout<<"9. Show"<<endl;
		cout<<"10. InfoPart"<<endl;
		cout<<"11. RemovefirTOlast"<<endl;
		cout<<"12. SwapMthandNth"<<endl;
		cout<<"13. Quit"<<endl;
		cout<<"Enter ur choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"How many nodes u want:"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"Enter the element"<<endl;
					cin>>m;
					obj.createList(m);
				}
				break;
			case 2:
				cout<<"Enter the element"<<endl;
				cin>>m;
				obj.add_at_beg(m);
				break;
			case 3:
				cout<<"Enter the element"<<endl;
				cin>>m;
				cout<<"Enter the position after which this element is inserted"<<endl;
				cin>>position;
				obj.add_at_pos(position,m);
				break;
			case 4:
				cout<<"Enter the element for deletion"<<endl;
				cin>>m;
				obj.del(m);
				break;
			case 5:
				obj.display();
				break;
			case 6:
				cout<<"LIST Size is : "<<obj.count();
				break;
			case 7:
				obj.rev();
				break;
			case 8:
				cout<<"Enter the element to be searched"<<endl;
				cin>>m;
				if(obj.search(m))
					cout<<"Data has been Founded"<<endl;
				else
					cout<<"Sory!! data has not been Found in list!!"<<endl;
				break;
			case 9:
				{
					obj.dislayToWay();
					break;
				}
			case 10:
				{
					obj.infopartExchange();
					break;
				}
			case 11:
				{
					obj.removefirTOlast();
					break;
				}
			case 12:
				{
					cout<<"Enter the First Position : ";
					cin>>m;
					cout<<"Enter the Second Position : ";
					cin>>n;
					obj.swapNthMth(m,n);
					break;
				}
			case 13:
				{
					obj.show();
					break;
				}
			case 14:
				{
					exit(1);
				}
			default:
				cout<<"Wrong choice"<<endl;
		}
	}
	return 0;
}