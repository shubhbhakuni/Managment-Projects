#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;
class hotel
{
int room_no;
char name[30];
char address[50];
char phone[10];
char aadhar[20];
public:
void main_menu();		
void add();			
void display(); 		
void rooms();		
void edit();			
int check(int);			
void modify(int);		
void delete_rec(int);		
};
void hotel::main_menu()
{
int choice;
while(choice!=5)
	{
cout<<"\n\t\t\t\t-------------";
cout<<"\n\t\t\t\t* MAIN MENU *";
cout<<"\n\t\t\t\t--------------";
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Customer Record";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;
switch(choice)
		{
case 1:	add();
break;
case 2: display();
break;
case 3: rooms();
break;
case 4:	edit();
break;
case 5: break;
default:
{
cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to continue....!!";
getch();
}
}
}
}
void hotel::add()
{
    int r,flag;
ofstream fout("Record.txt",ios::app);
cout<<"\n Enter Customer Detalis";
cout<<"\n ----------------------";
cout<<"\n\n Room no: ";
cin>>r;
flag=check(r);
     if(flag)
cout<<"\n Sorry..!!!Room is already booked";
   else
	{
room_no=r;
cout<<" Name: ";
cin>>name;
cout<<"Address: ";
cin>>address;
//cout<<"Name: ";
//cin>>name;
cout<<"Phone No: ";
cin>>phone;
cout<<"Aadhar no.";
cin>>aadhar;
		
fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is suceessfully booked...!!!";
}

cout<<"\n Press any key to continue.....!!";
getch();
fout.close();
}

void hotel::display()
{

ifstream fin("Record.txt",ios::in);
int r,flag;
cout<<"\n Enter room no: ";
cin>>r;

while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Cusromer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
cout<<"\n Aadhar n0:"<<aadhar;
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";
getch();
fin.close();
}
void hotel::rooms()
{
ifstream fin("Record.txt",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\t\tAadhar no.\n";
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;
cout<<"\t\t"<<aadhar;
}
cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();
}
void hotel::edit()
{
int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n Enter your choice: ";
cin>>choice;
cout<<"\n Enter room no: " ;
cin>>r;
switch(choice)
{
case 1:	modify(r);
break;
case 2:	delete_rec(r);
break;
default: cout<<"\n Wrong Choice.....!!";
}
cout<<"\n Press any key to continue....!!!";
getch();
}
int hotel::check(int r)
{
int flag=0;
ifstream fin("Record.txt",ios::in);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
flag=1;
break;
}
}
fin.close();
return(flag);
}
void hotel::modify(int r)
{
long pos,flag=0;
fstream file("Record.txt",ios::in|ios::out);
while(!file.eof())
{
pos=file.tellg();
file.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n : ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Name:";
cin>>name;
cout<<" Phone no: ";
cin>>phone;
cout<<"Aadhar no.:";
cin>>aadhar;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified....!!";
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();
}
void hotel::delete_rec(int r)
{
int flag=0;
char ch;
ifstream fin("Record.txt",ios::in);
ofstream fout("temp.txt",ios::out);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
   cout<<"\n Name: "<<name;
   cout<<"\n Address: "<<address;
   cout<<"\n Pone No: "<<phone;
   cout<<"\n Aadhar no: "<<aadhar;
   cout<<"\n\n Do you want to delete this record(y/n): ";
   cin>>ch;
if(ch=='n')
  fout.write((char*)this,sizeof(hotel));
flag=1;
}
else
fout.write((char*)this,sizeof(hotel));
}
fin.close();
fout.close();
if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";
else
{
remove("Record.txt");
rename("temp.txt","Record.txt");
}
}
void start()
{
system("color 0A");
system("cls");
cout<<"\n\t\t\t--------------------------";
cout<<"\n\t\t\t* HOTEL MANAGEMENT SYSTEM *";
cout<<"\n\t\t\t--------------------------";
Sleep(500);
      cout<<"\n\n\n\n\t\tMade By:";
Sleep(500);
      cout<<"\tShubh Bhakuni";
Sleep(500);
      cout<<"\n\t\t\t\tROLL NO:-BT/CS/2001/015";
Sleep(500);
     cout<<"\n\t\t\t\tCOURSE:-B.Tech (CSE)";
Sleep(500);
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
getch();
}
int pass()
  { system("color 0A");
system("cls");
              int j;
              char name1[10];
                v:
	    cout<<"enter  your 8 digit password\n";
		for(j=0;j<9;j++)
		{
		    name1[j]=getch();
		    cout<<'*';
			
		}
		name1[10]='\0';
		if(strcmp(name1,"shubh2002")==0)
		{
			
		}
		else
		{
		
		cout<<"\n wrong password \n";
		cout<<"you can't proceed\n";
	            goto v;
	             }
	         }
int main()
{
hotel h;
  pass();
       
start();
system("cls");
h.main_menu();
return 0;
}