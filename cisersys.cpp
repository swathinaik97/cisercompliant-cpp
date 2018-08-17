#include<iostream> 
#include<stdlib.h>
using namespace std;
int choice, wardnum,ch;
char des[500],local[500], pin[7];
void display()
{
	cout<<"Enter your address or location details\n";
	cin>>local;
	cout<<"Enter your pincode\n";
	cin>>pin;
	cout<<"Enter your ward number\n";
	cin>>wardnum;
	cout<<"Enter description of your complaint\n";
	cin>>des;
}
	
class ciser//base
{
	int count;
	public:
	ciser()
	{
		count=0;
	}
	void calc(BBMP &b,BESCOM &e)
	{
		count=b.bcount+e.ecount;
		cout<<"No. of complaints registered=\t"<<count;
	}
	
};
class BBMP:public ciser
{	
	int trees;
	char day[10];
	float money;
	char name[50];
	char org[50];
	char jnc[50];
	char loc[100];
	int bcount;
	public: BBMP()
			{
			trees=0;money=0.0;
			bcount=0;
			}
		     
	             void readbbmp()
		    {
		    		system("clear");
				cout<<"\n\nWelcome to BBMP complaints category\n";
				do
				{
				cout<<"1.Garbage\n2.Trees\n3.Road\n4.End\n";
				cout<<"If you have complaints regarding any of these issues,enter your choice\n";
				cin>>choice;
				switch(choice)
				{
					case 1: garbage();
						    bcount++;
						    break;
					case 2:cout<<"\nEnter the approximate no. of trees cut\n";
						    cin>>trees;
						    tree(trees);
						    bcount++;
						   break;
					case 3: road();
							bcount++;
						    break;
					case 4:break;
					default:cout<<"Invalid choice\n";
						     break;
				}
				cout<<"Press 1 to continue\n";
				cin>>ch;
			}while(ch==1);
		}
		void garbage();
		void tree(int );
		void road();
				
};

void BBMP::garbage()
{
	cout<<"\t\tGARBAGE CATEGORY\t\t\n";
		cout<<"1.Irregular collection of garbage\t2.Charging for collection of garbage\n";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"Enter the day when the garbage is collected in a week(Mon-Sat)\n";
				   cin>>day;
				   break;
			case 2:cout<<"Enter the amount collected by the BBMP personnel and name of the personnel if known\n";
				    cin>>money>>name;
				    break;		
			default:cout<<"invalid choice\n";
		}		
		cout<<"Press 1 to continue\n";
		cin>>ch;
		
}	
 void BBMP::tree(int t)
{
	cout<<"\t\tTREE CATEGORY\t\t\n";
		cout<<"1.Many no. of trees cut\t2.Organisation responsible for cutting trees\n";
		cin>>choice;
		switch(choice)
		{
				case 1:if(t>=5)
					   display();
					   break;
				case 2:cout<<"Enter the name of the organisation\n";
				 	    cin>>org;
					    break;	
				default:cout<<"invalid choice\n";
		}
		cout<<"Press 1 to continue\n";
		cin>>ch;
		
}
void BBMP::road()
{
		cout<<"\t\tROAD CATEGORY\t\t\n";
			cout<<"1.Traffic light not functioning\t2.Improper parking area management\n";
			cin>>choice;
			switch(choice)
			{
				case 1:cout<<"Enter the junction name where the traffic light is not functioning\n";
					   cin>>jnc;
					   break;
				case 2:cout<<"Enter the locality where the parking area management is not maintained\n";
					    cin>>loc;
					   break;	
				default:cout<<"invalid choice\n";
			}
			cout<<"Press 1 to continue\n";
			cin>>ch;
				
}
class BESCOM:public ciser
{
	int ecount;
	int units;
	int hrs;
	public:
	void readbes()
	{
		BESCOM o;
		system("clear");
		float cbill;
		cout<<"Welcome to BESCOM complaints category\n";
		do
		{
			cout<<"1.Power theft\t2.Incorrect billing\nEnter your choice\n";
			cin>>choice;
			switch(choice)
			{
				case 1: power_supply();
						ecount++;
					    break;
				case 2: cout<<"Enter the no. of units consumed\n";
					     cin>>o.units;
					    cbill=bills(o);
					    cout<<"The correct amount to be paid is=\tWe will inform BESCOM about this issue.Thankyou for your patience\n"<<cbill;
					    ecount++;
					    break;
	
				default:cout<<"Invalid choice\n";
					break;
			}
			cout<<"Press 1 to continue\n";
			cin>>ch;
		}while(ch==1);
	}
	void power_supply()
	{
	display();
	cout<<"\nEnter the no. of hours load shedding occurs in your locality\n";
	cin>>hrs;
	}

	float bills(BESCOM e)
	{
		float amt;
		if(e.units<=50)
			amt=e.units*0.50;
		else if(e.units<=150)
			amt=25+((e.units-50)*0.75);
		else if(units <=250)
			amt=100+((e.units-150)*1.20);
		else
			amt=220+((e.units -250)*1.50);
		return amt;
	}

	void power_theft()
	{
	display();
	}
};
			
int main()
{

	BBMP b;
	BESCOM e;
	ciser c;
	c.calc(b,e);
	for(int i=0;i<=10;i++) cout<<"-";
	cout<<"WELCOME TO CISER(CIvil SERvice) COMPLAINT SYSTEM";
	for(int i=0;i<=10;i++) cout<<"-";
	do
	{
	system("clear");
		cout<<"\nChoose a civil service \n1)BBMP\n2)BESCOM\n";
		cin>>choice;
		if(choice==1)
			b.readbbmp();
		else 
			e.readbes();
	cout<<"Press 1 to continue\n";
	cin>>ch;
	}while(ch==1);
	return 0;
}	


