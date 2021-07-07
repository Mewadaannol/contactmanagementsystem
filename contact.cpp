	                                 //Contact management system Using C++ And File handling


#include<conio.h>
#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;


class contact 
{
   private:
     string fname ,lname, number;
   public:
   
     void add_contact();
     void showdata();
     void search();
     void welcome();
     void updation();
     void  deletion();
};
contact d;       //CLASS OBJECT
ifstream fin;    // READ STREAM OBJECT
ofstream fout;   //WRITE STREAM OBJECT


void contact::welcome()
{
	cout<<"\t\t\t\t\t\t\t\t\t**********************************************"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t phone contact book"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t**********************************************"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t======================="<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPrepared By:-"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Mr. Anmol rajput"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Branch : CSE-2"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Year 2018-2022"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t======================="<<endl;
	cout<<endl<<endl<<" <<<- for menu press any key ->>>>>:- ";
	getch();
}
void contact::add_contact()
{
     
     system("cls");
     l:
     cout<<"\n\t\t\t\t\t\t=====================================================================";
     cout<<"\n\t\t\t\t\t\t\t\t\t<-add contact details->";
     cout<<"\n\t\t\t\t\t\t=====================================================================";
     cout<<"\n\n\t\t\t\t\t\t\t\t enter contact first name:";
     cin>>fname;
     cout<<"\t\t\t\t\t\t\t\t enter contact last name:";
     cin>>lname;
     cout<<"\t\t\t\t\t\t\t\t enter number:";
     cin>>number;
     if(number.length()!=10)
     {
	    cout<<"number length is not ten or above"<<endl;
	    cout<<"please add number again"<<endl;      
        goto l;
     }
    else
    {
	    cout<<"contact is added sucssesfully........."<<endl;
	    fout.open("contacts.txt", ios::app | ios::out);
        fout<<" "<<fname<<" "<<lname<<" "<<number<<"\n";
        fout.close();
		 
    } 
    
}

void contact::showdata()
{
    
    system("cls");
    int total=0;
    cout<<"\n\t\t\t\t\t\t=====================================================================";
    cout<<"\n\t\t\t\t\t\t\t\t<-all record of contact list->";
    cout<<"\n\t\t\t\t\t\t=====================================================================";
    fin.open("contacts.txt",ios::in);
    if(!fin)
    {
      cout<<"\n\t\t\t No data available file empty.........";
      fin.close();
    }
    else
    {
    
	   fin >> fname >> lname >> number;
       while(!fin.eof())
       {
          
		  cout<< "\n\t\t\t\t\t\t|Serial No:-"<<total++<<"\t\t\t\t\t\t\t\t\t|"<<endl;
		  cout<<"\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|";
		  cout<< "\n\t\t\t\t\t\t|Full name:";
          cout<<fname<<" "<<lname<<"\t\t\t\t\t\t\t\t|"<<endl;
		  cout<<"\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|";
		  cout<< "\n\t\t\t\t\t\t|number:";
          cout<<number<<"\t\t\t\t\t\t\t\t|"<<endl;
		  fin >> fname >> lname >> number;
       }
       if(total == 0)
       {
       	  cout<< "\n\t\t record not match in contact list......";
	   }
    }
    fin.close();
}

void contact::search()
{
    string nams;
    system("cls");
    bool found=false;
    fin.open("contacts.txt", ios::in);
    cout<<"\n\t\t\t\t\t\t=====================================================================";
	cout<<"\n\t\t\t\t\t\t\t\t\t<-search record of contact list->";
	cout<<"\n\t\t\t\t\t\t=====================================================================";
   
    if(!fin)
    {
     
      cout<<"\n\t\t\t No data available file is Empty......."; 
    }
    else
    {
           
	    cout<<"\n\n\t\t\t\t\t\t\t\tenter name you want to search:";
        cin>>nams;
        fin >> fname >> lname >> number;
        while(!fin.eof())
        {
            if(nams==fname)
            {
                
				cout<<"\n\t\t\t\t\t\t\t|  Number finded-->"<<"\t\t\t\t\t\t|";
            	cout<<"\n\t\t\t\t\t\t\t| Full name:"<<fname<<" "<<lname<<"\t\t\t\t\t\t|"; 
				cout<<"\n\t\t\t\t\t\t\t|  number: "<<number<<"\t\t\t\t\t\t|"<<endl;
            	fin >> fname >> lname >> number;
            	found=true;
            }
        	fin >> fname >> lname >> number;
        }
        if(found==false)
        {
	        cout<<"number is not exsits in contact list.........."<<endl;
        }
        fin.close();
    }
    
}

void contact::updation()
{
	system("cls");
	string num;
	bool found=false;
	fin.open("contacts.txt",ios::in);
	cout<<"\n\t\t\t\t\t\t=====================================================================";
	cout<<"\n\t\t\t\t\t\t\t\t\t<-Update record of contact list->";
	cout<<"\n\t\t\t\t\t\t=====================================================================";
   
	if(!fin)
	{
		cout<<"no record available in list"<<endl;
	}
	
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter the name for update:";
	cin>>num;
	fout.open("new_contacts.txt", ios::out | ios::app);
	while(fin >> fname >> lname >> number)
	{
		if(fname!=num)
		{
			
			fout<<" "<<fname<<" "<<lname<<" "<<number<<"\n";
		}
		if(fname==num)
		{
			
			l:
			cout<<"\n\t\t\t\t\t\t\tPlease Enter The New Details of Contact: "<<endl;
			cout<<"\n\n\t\t\t\t\t\t\t\t enter contact first name:";
            cin>>fname;
            cout<<"\t\t\t\t\t\t\t\t enter contact last name:";
            cin>>lname;
            cout<<"\t\t\t\t\t\t\t\t enter number:";
            cin>>number;
            if(number.length()!=10)
            {
	            cout<<"number length is not ten or above"<<endl;
	            cout<<"please add number again"<<endl;
	            goto l; 
					   
            }
            else
            {
                
			    cout<<endl<<endl<<"\t Contact Successfully Updated...";
			    fout<<" "<<fname<<" "<<lname<<" "<<number<<"\n";
				found=true;
            }
           
       	}
		
	} 
	fout.close();
	fin.close();
	remove("contacts.txt");
	rename("new_contacts.txt","contacts.txt");
	if(found==false)
	{
	   cout<<endl<<endl<<"Contact Not Found...";
    }
}
  


void contact::deletion()
{
	system("cls");
	string p;
	int check=0;
	cout<<"\n\t\t\t\t\t\t=====================================================================";
	cout<<"\n\t\t\t\t\t\t\t\t\t<-<-delete record of contact list->->";
	cout<<"\n\t\t\t\t\t\t=====================================================================";
    fin.open("contacts.txt",ios::in);
	if(!fin)
	{
		cout<<"no record available in list"<<endl;
	}

	cout<<"\n\n\t\t\t\t\t\t\t\tenter the name you want to delete\t:-";
    cin>>p;
	fout.open("new_contacts.txt",ios::app | ios::out);
	while(fin >> fname >> lname >> number)
	{
		
		if(p==fname)
	    {
	        cout<<"number deleted......";
	        check++;
	    }
	    if(p!=fname)
		{
			fout<<" "<<fname<<" "<<lname<<" "<<number<<"\n";
		       
		}
    } 	 
	if(check==0)
	{
	    cout<<"\n\t\t\t\t\t not found........";
	}

	fout.close();
	fin.close();
	remove("contacts.txt");
	rename("new_contacts.txt","contacts.txt");
  

} 


int main()
{
   system("cls");
   d.welcome();
   int c;
   do{
        
		 cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------"<<endl;
         cout<<"\t\t\t\t\t\t\t\t\t\tPhone Book Menu"<<endl;
         cout<<"\t\t\t\t\t\t--------------------------------------------------------------------"<<endl;
         cout<<"\t\t\t\t\t\t\t\t\t\t  1. for add contact"<<endl;
	      cout<<"\t\t\t\t\t\t\t\t\t\t  2. for search"<<endl;
	      cout<<"\t\t\t\t\t\t\t\t\t\t  3. for showall contact"<<endl;
	      cout<<"\t\t\t\t\t\t\t\t\t\t  4. for update contact"<<endl;
         cout<<"\t\t\t\t\t\t\t\t\t\t  5. for delete contact"<<endl;
	      cout<<"\t\t\t\t\t\t\t\t\t\t  0. for exit"<<endl;
	      cout<<"\n\n\t\t\t\t\t\t\t\t  enter your choice :";
	      cin>>c;
	      
	      switch(c)
	      {
	            case 1:
	               d.add_contact();
	               break;
	            case 2:
	               d.search();
	               break;
	            case 3:
	               d.showdata();
	               break;
	            case 4:
	               d.updation();
	               break;
               case 5:
                  d.deletion();
                  break;
	            case 0:
	               exit(0);
	               break;
	            case 6:
	               cout<<"envalid argument";
	      };
	      int opt;
		  cout<<"\n\n\n\t\t\tYou want to perform aanother task:";
		  cout<<"\n\n\t\t\t\t\t[1] For Main Menu"<<"\n\t\t\t\t\t[0] Exit:-";
		  cout<<"\n\t\t\t\t\tenter your choice:-";
		  cin>>opt;
 
		  switch (opt)
		  {
 			 case 1:
				continue;
 		
			case 0:
				exit(0);
				break;
			default:
				cout<<"envalid choice............";
 		
		 }
      }while(c!=0);

return 0;
}
