#include<iostream>
#include<fstream>
using namespace std;
 ciser c;
int main()
{
  c.xyz();
  }
  class ciser
 {
 	public: ciser ()
 		    {
 		    	cout<<"this is ciser";
 		    }
 		    void xyz()
 		    {
 		    fstream fp;
			  fp.open("file.txt",ios::app);
			  fp.seekp(0,ios::beg);
			  cout<<"enter name\n";
			  char name[20];
			  cin>>name;
			  fp.write((char *)&c,sizeof (ciser));
			  fp.close();
			  }
			 		    };
