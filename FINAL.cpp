#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
void display2()
{
clrscr();
char a1[]="*********************************************************************************";
char a2[]="--------------------------WELCOME TO GURGAON LIBRARY-----------------------------";
char a3[]="*********************************************************************************";
int len=strlen(a1);
for(int i=0;i<len;i++)
{
	gotoxy(i,1);
	cout<<a1[i];
	gotoxy(i,3);
	cout<<a2[i];
	gotoxy(i,5);
	cout<<a3[i];
	delay(50);
}
}
void display()
{
puts("********************************************************************************");
puts("-------------------------WELCOME TO GURGAON LIBRARY-----------------------------");
puts("********************************************************************************");
}
class library
{
    public:
	int ddi,yyi,mmi,yyr,ddr,mmr;
	char auth[30];
	int id;
	char book[30];
}x[50];
void main()
{
	int flag1=0;
	int i=0,co=0,flag=0;
	char ch='n';
	ofstream f;
	display2();
	do{
      int ch2;
	if(flag1>0)
	{
	clrscr();	display();
	}
	puts(" \n1) ENTER A BOOK                   2) SEARCHING A BOOK");     
	puts(" \n3) NUMBER OF BOOKS                          ");
	cout<<"\n\nENTER YOUR CHOICE: ";
	cin>>ch2;
	clrscr();
	switch(ch2)
	{
	case 1:
	{
	 display();
       cout<<"ENTER BOOK: ";
	 gets(x[i].book);     puts(""); puts("");
	 cout<<"ENTER AUTHOR: ";
	 gets(x[i].auth); puts(""); puts("");
	 cout<<"ENTER ID: ";
	 cin>>x[i].id; puts(""); puts("");
	 cout<<"ENTER DATE OF ISSUE: ";
	 cin>>x[i].ddi; 
          puts(""); puts("");
	 cout<<"ENTER  MONTH OF ISSUE: ";
	 cin>>x[i].mmi;  
        puts(""); puts("");
	 cout<<"ENTER YEAR OF ISSUE: ";
	 cin>>x[i].yyi;     
        puts(""); puts("");
        if(x[i].mmi==2 && x[i].yyi%4==0 && x[i].ddi>29)
        {cout<<"INVALID DATE";}
        if(x[i].mmi==2 && x[i].yyi%4!=0 && x[i].ddi>28)        
        { cout<<"INVALID DATE";}
         if(x[i].mmi<7)
          if(x[i].mmi%2==0 && x[i].ddi>30)
         {cout<<"INVALID DATE";}
         if(x[i].mmi>7)
         { if(x[i].mmi%2==0 && x[i].ddi>31)
         cout<<"INVALID DATE";}
         if(x[i].mmi>12)
         {cout<<"INVALID DATE";}
         puts(""); puts("");                       
         cout<<"ENTER DATE OF RETURN: ";
	 cin>>x[i].ddr;     
         puts(""); puts("");
	 cout<<"ENTER MONTH OF RETURN: ";
	 cin>>x[i].mmr;   
         puts(""); puts("");
	 cout<<"ENTER YEAR OF RETURN: ";
	 cin>>x[i].yyr;   
         puts(""); puts("");
         {if(x[i].mmr==2 && x[i].yyr%4==0 && x[i].ddr>29)
         cout<<"INVALID DATE";}
         {if(x[i].mmr==2 && x[i].yyr%4!==0 && x[i].ddr>28)       
         cout<<"INVALID DATE";}
         if(x[i].mmr<7)
         { if(x[i].mmr%2==0 && x[i].ddr>30)
         cout<<"INVALID DATE";}
         if(x[i].mmr>7)
         { if(x[i].mmr%2==0 && x[i].ddr>31)
         cout<<"INVALID DATE";}
         if(x[i].mmr>12)
         {cout<<"INVALID DATE";}
         if(x[i].yyr< x[i].yyi)
         {cout<<"INVALID DATE";}
         if(x[i].yyr== x[i].yyi && x[i].mmr<x[i].mmi)
         {cout<<"INVALID DATE";}
         if(x[i].yyr== x[i].yyi && x[i].mmr=x[i].mmi &&      			   x[i].ddr<x[i].ddi)
         {cout<<"INVALID DATE";}
         puts(""); puts("");
  	 i++;co++;	 clrscr();
	 f.open("BOOKS.txt");
f<<x[i].book<<x[i].auth<<x[i].id<<x[i].ddi<<x[i].mmi<<x[i].yyi<<x[i].ddr<<x[i].mmr<<x[i].yyr;
	 f.close();
}
break;
case 2:{
display();
cout<<"ENTER THE NAME OF YOUR BOOK: ";
char str[30];
gets(str);
f.open("NBOOKS.txt");
f<<str;
f.close();
for(i=0;i<co;i++)
 {
	if(strcmp(str,x[i].book)==0)
	{
	 clrscr();
	 display();
	 cout<<"BOOK           : "<<x[i].book; puts(""); puts("");
	 cout<<"AUTHOR         : "<<x[i].auth; puts(""); puts("");
	 cout<<"ID             : "<<x[i].id; puts(""); puts("");
	 cout<<"DATE OF ISSUE  : "<<x[i].ddi;cout<<"/"<<x[i].mmi;cout<<"/"<<x[i].yyi;puts("");puts("");
	 cout<<"DATE OF RETURN : "<<x[i].ddr;cout<<"/"<<x[i].mmr;cout<<"/"<<x[i].yyr;puts("");puts("");
	 flag=0;break;
	}
	 else
	 flag=1;
}
if (flag==1)
	 cout<<"book not found"; getch();
	 clrscr();
}break;
case 3:
{
display();
cout<<"NUMBER OF BOOKS ARE:"<<co<<endl;
f.open("NBOOKS.txt");
f<<co;
f.close();
getch();
clrscr();
}
break;
default:
{
display();
puts("WRONG INPUT");
getch();
clrscr();
}
}
display();
cout<<"\nDO YOU WISH TO RE-EXECUTE?: ";
cin>>ch;flag1++;
}
while((ch=='y')||(ch=='Y'));
getch();
}
