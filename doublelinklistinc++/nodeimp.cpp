#include <iostream>
#include "nodei.h"
using namespace std;

NodeImplementation::NodeImplementation()
{
	this->SIZE=0;
	this->START=NULL;
}
void NodeImplementation::createList(int d)
{
	if(this->START==NULL)
	{
		Node *temp=new Node();
		temp->DATA=d;
		temp->NEXT=NULL;
		temp->PERV=NULL;
		this->START=temp;
		this->SIZE++;
	}
	else
	{
		Node *move=this->START;
		while(move->NEXT!=NULL)
		{
			move=move->NEXT;
		}
		Node *temp=new Node();
		temp->DATA=d;
		temp->PERV=move;
		temp->NEXT=NULL;
		move->NEXT=temp;
		this->SIZE++;
	}
}
void NodeImplementation::add_at_beg(int d)
{
	if(this->START==NULL)
	{
		this->createList(d);
	}
	else
	{
		Node *temp=new Node();
		temp->DATA=d;
		temp->NEXT=this->START;
		temp->PERV=NULL;
		this->START=temp;
		this->SIZE++;
	}
}
void NodeImplementation::add_at_pos(int pos,int d)
{
	if(this->SIZE==0 && pos==1)
	{
		this->createList(d);
	}
	else if(pos==this->SIZE+1)
	{
		this->createList(d);
	}
	else if(pos>1 && pos<=this->SIZE)
	{
		
		Node *move=this->START;
		for(int i=1;i<pos-1;i++)
		{
			move=move->NEXT;
		}
		Node *temp=new Node();
		temp->DATA=d;
		temp->NEXT=move->NEXT;
		temp->PERV=move;
		move->NEXT->PERV=temp;
		move->NEXT=temp;
	}
	else
	{
		cout<<"Insertion not possible You gave Wrong Position!!!"<<endl;
	}
}
void NodeImplementation::del(int d)
{
	if(this->START==NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	else if(this->START->DATA==d)
	{
		this->START=this->START->NEXT;
		this->SIZE--;
	}
	else 
	{
		Node *move=this->START;
		Node *temp;
		Node *p;
		while(move->NEXT!=NULL)
		{
			if(move->NEXT->DATA==d)
			{
				temp=move->NEXT;
				move->NEXT=move->NEXT->NEXT;
				move->NEXT->PERV=move;
				delete temp;
				this->SIZE--;
				cout<<"***Data has been DELETED***"<<endl;
				return ;
			}
			move=move->NEXT;
		}
		cout<<"***Data has not been Found***"<<endl;
	}
}
void NodeImplementation::display()
{
	if(this->START==NULL)
	{	cout<<"***List is Empty***"<<endl; }
	else
	{
		Node *move=this->START;
		while(move!=NULL)
		{
			cout<<move->DATA<<" ";
			move=move->NEXT;
		}
	}	
}
int  NodeImplementation::count()
{
	return this->SIZE;
}
void NodeImplementation::rev()
{
	if(this->START==NULL)
	{
		cout<<"List is Empty!!!!"<<endl;
	}
	else if(this->SIZE==1)
	{
		cout<<"***There is only one node nothing to swap***"<<endl;
	}
	else
	{
		Node *pos1,*pos2,*pos3;
		pos1= this->START;
		pos2=pos1->NEXT;
		pos3=pos2->NEXT;
		pos1->NEXT=NULL;
		pos1->PERV=pos2;
		pos2->NEXT=pos1;
		pos2->PERV=NULL;
		while(pos3!=NULL)
		{
			pos1=pos2;
			pos2=pos3;
			pos3=pos3->NEXT;
			pos2->NEXT=pos1;
			pos1->PERV=pos2;

		}
		this->START=pos2;
	}
}
bool NodeImplementation::search(int d)
{
	if(this->START==NULL)
	{
		cout<<"List is empty!!!"<<endl;
		return false;
	}
	else
	{
		Node *move=this->START;
		while(move!=NULL)
		{
			if(move->DATA==d)
			{
				return true;
			}
			move=move->NEXT;
		}
		return false;
	}
}
void NodeImplementation::removefirTOlast()
{
	if(this->START==NULL)
	{
		cout<<"list is Empty**!!!"<<endl;
	}
	else if(this->SIZE==1)
	{
		cout<<"There is only one element in the list so cannot Remove"<<endl;
	}
	else
	{
		Node *move=this->START;
		Node *fn=this->START;
		Node *ln;
		while(move->NEXT->NEXT!=NULL)
		{
			move=move->NEXT;
		}
		ln=move->NEXT;
		fn->PERV=move;
		move->NEXT=fn;
		ln->PERV=NULL;
		ln->NEXT=this->START->NEXT;
		this->START=ln;
		fn->NEXT=NULL;
	}
}
void NodeImplementation::removelasttofir()
{
	this->removefirTOlast();
}
void NodeImplementation::infopartExchange()
{
	if(this->START==NULL)
	{
	    cout<<"List is Empty!!!"<<endl;
	}
	else
	{
		int fn,ln;
		Node *move=this->START;
		fn=this->START->DATA;
		while(move->NEXT!=NULL)
		{
			move=move->NEXT;
		}
		ln=move->DATA;
		move->DATA=fn;
		this->START->DATA=ln;
	}
}
int  NodeImplementation::checkOcurance(int d)
{
	if(this->START==NULL)
	{
		cout<<"list is Empty!!!!"<<endl;
		return 0;
	}
	else
	{
		int ocr=0;
	Node *move=this->START;
	while(move!=NULL)
	{
		if(move->DATA==d)
		{
			ocr++;
		}
		move=move->NEXT;
	}
	return ocr;
	}
}
void NodeImplementation::swapNthMth(int m,int n)
{
	if(this->START==NULL)
	{
		cout<<"List is Empty!!!"<<endl;
	}
	else if((m<1 || m>this->SIZE )||(n<1 ||n>this->SIZE))
	{
		cout<<"Sorry you gave Wrong Positions"<<endl;
	}
	else if(m==n)
	{
		cout<<"Both positions are same!!!"<<endl;
	}
	else
	{
		int i=1;
		Node *mth,*nth,*t1,*t2,*t3;
		Node *move=this->START;
		if(m>n)
		{
			while(i<m-1)
			{
				if(i==n-1)
				{
					nth=move->NEXT;
					t1=move;
					t2=move->NEXT->NEXT;
				}
				move=move->NEXT;
				i++;
			}
			mth=move->NEXT;
			t3=move->NEXT->NEXT;
			t1->NEXT=mth;
			mth->PERV=t1;
			mth->NEXT=t2;
			t2->PERV=mth;
			t2->NEXT->NEXT=nth;
			nth->PERV=t2->NEXT;
			nth->NEXT=t3;
			t3->PERV=nth;
		}
		else
		{
			while(i<n-1)
			{
				if(i==m-1)
				{
					mth=move->NEXT;
					t1=move;
					t2=move->NEXT->NEXT;
				}
				move=move->NEXT;
				i++;
			}
			nth=move->NEXT;
			t3=move->NEXT->NEXT;
			t1->NEXT=nth;
			nth->PERV=t1;
			nth->NEXT=t2;
			t2->PERV=nth;
			t2->NEXT->NEXT=mth;
			mth->PERV=t2->NEXT;
			mth->NEXT=t3;
			t3->PERV=mth;
		}
	}
}
void NodeImplementation::countNUmberGroups()
{
	if(this->START==NULL)
	{
		cout<<"List is Empty!!!!"<<endl;
	}
	else
	{
		Node *move;
		move=this->START;
		int nonzero,even,odd;
		nonzero=even=odd=0;
		while(move!=NULL)
		{
			if(move->DATA>=1)
			{
				nonzero++;
			}
			if((move->DATA%2)==0)
			{
				even++;
			}
			if((move->DATA%2)==1)
			{
				odd++;
			}
			move=move->NEXT;
		}
		cout<<"Even Numbers     : "<<even<<endl;
		cout<<"Odd Numbers      : "<<odd<<endl;
		cout<<"Non-Zero Numbers : "<<nonzero<<endl;
	}
}
void NodeImplementation::Staticstics()
{
	if(this->START==NULL)
	{
		cout<<"List is Empty!!!!"<<endl;
	}
	else
	{
		int sum,avg,max,min;
		sum=avg=0;
		Node *move=this->START;
		max=move->DATA;
		min=move->DATA;
		while(move!=NULL)
		{
			if(move->DATA > max)
			{
				max=move->DATA;
			}
			if(move->DATA<min)
			{
				min=move->DATA;
			}
			sum+=move->DATA;
			move=move->NEXT;
		}
		avg=sum/this->SIZE;
		cout<<"Max : "<<max<<endl;
		cout<<"Min : "<<min<<endl;
		cout<<"sum : "<<sum<<endl;
		cout<<"avg : "<<avg<<endl;
	}
}
void NodeImplementation::dislayToWay()
{
	if(this->START==NULL)
	{	cout<<"***List is Empty***"<<endl; }
	else
	{
		Node *move=this->START;
		cout<<"0"<<"  :  "<<move->DATA<<"  :  "<<move->NEXT->DATA<<endl;
		move=move->NEXT;
		while(move->NEXT!=NULL)
		{
			cout<<move->PERV->DATA<<"  :  "<<move->DATA<<"  :  "<<move->NEXT->DATA<<endl;
			move=move->NEXT;
		}
	}
}
void NodeImplementation::show()
{
	Node *move=this->START;
	for(int i=1;i<=this->SIZE;i++)
	{
		cout<<move->DATA;
		move=move->NEXT;
	}
}