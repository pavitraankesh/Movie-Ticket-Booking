#include<fstream.h>
#include<conio.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char nsmovie[10][80];
char rtmovie[4][80]; //names,genres and languagues of now showing and releasing tomorrow movies
int i,choice1,choice2,choice3,choice4,choice5,choice6,choice7;
int ns[10][10][10];
int rt[4][4][4];     //normal, executive and premium seats per movie
int c=0;
class Movie              // class for movie details
{
	int no;
	int price;
	char category;
	char name[80];
	char location[20];
	public:
	void front();
	void Heading();
	void Display_Movie(char a[][80], int n);
	void Display_Show();
	void Seats();
	void Input();
	void Display();
	void Confirm();
};
void Movie::front()      //to display main heading
{
	cout<<"       MOVIESHOWS"<<endl<<"      ~~~~~~~~~~~~~~~~~~~"<<endl<<"  Entertainment~~~~Movies"<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}
void Movie::Heading()     //to display basic details of the movie
{
	cout<<endl<<"     Movie: "<<name<<endl<<"******************************************* ";
}
void Movie::Display_Movie(char a[][80], int n)  //to display list of movies available
{   do{
	clrscr();
	front();
	cout<<endl<<"Movies available: "<<endl<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<". "<<a[i]<<endl;
	}
	cout<<endl<<endl<<"Enter choice to select movie: ";
	cin>>choice2;
	strcpy(name,a[choice2-1]);
	if(choice2>n || choice2<1)
	{
	cout<<endl<<"Invalid choice.";getch();
	}
	}while(choice2>n || choice2<1);
 }
void Movie::Display_Show()       //to display show timings and locations
{
do{
int min[3]={30,15,45};
	char loc[3][20]={"LV Cinemas","Max Cinemas","Pix Cinemas"};
	clrscr();
	front();
	Heading();
	cout<<endl<<"AVAILABLE SHOWS: "<<endl<<endl<<"   TIME			LOCATION"<<endl;
	time_t now = time(0);
	char *dt = ctime(&now);   //read current time from the system
	char word[50];
   char time;
   char *t1;
   t1=&dt[11];
   char n1,n2;
   int count=0;
   while(count<3)
   {
   if(t1[1]==57)
   {
	  n2=char(48);
	  n1=t1[0]+1;
   }
   else if(t1[0]==50&&t1[1]==51)
   {
	  n1=n2=char(48);
   }
   else
   {
	  n1=t1[0];
	  n2=t1[1]+1;
   }
   cout<<count+1<<". "<<n1<<n2<<":"<<min[count]<<"		"<<loc[count]<<endl;
   t1[0]=n1;t1[1]=n2;
	count++;
   }             //to display show timings after current time
   cout<<endl<<"Enter choice: ";
   cin>>choice4;
   strcpy(location,loc[choice4-1]);
   if(choice4>3)
   { cout<<endl<<"Invalid choice.";getch();
   }
	}while(choice4>3 || choice4<1);
}
void Movie::Seats()          //to allocate seats
{  	no=0;
	do{
	clrscr();
	front();
	Heading();
	cout<<endl<<"Enter number of seats (Maximun 10): ";
	cin>>no;
	if(no>10||no<1)
	{ cout<<endl<<"Invalid entry. ";getch();}
	}while(no>10||no<1);
	do{
	clrscr();
	front();
	cout<<endl<<"CATEGORY OF SEATS: "<<endl<<endl<<"1. Normal "<<endl<<"  Rs.250 per seat"<<endl<<endl<<"2. Executive "<<endl<<"  Rs.280  per seat"<<endl<<endl<<"3. Premium"<<endl<<"  Rs.300  per seat";
	cout<<endl<<endl<<"Enter choice of category: ";
	cin>>choice5;
	if(choice1==1)
	{
	if(choice5==1)
	{category='N';price=no*250;c=ns[choice2-1][0][0];}
	else if(choice5==2)
	{category='E';price=no*280;c=ns[0][choice2-1][0];}
	else if(choice5==3)
	{category='P';price=no*300;c=ns[0][0][choice2-1];}
	}
	else if(choice1==2)
	{
	if(choice5==1)
	{category='N';price=no*250;c=rt[choice2-1][0][0];}
	else if(choice5==2)
	{category='E';price=no*280;c=rt[0][choice2-1][0];}
	else if(choice5==3)
	{category='P';price=no*300;c=rt[0][0][choice2-1];}
	}
	if(choice5>3||choice5<1)
	{ cout<<endl<<"Invalid choice. "; getch();}
	}while(choice5>3||choice5<1);
	clrscr();front();
	cout<<endl<<"Seats allocated: ";
	for(i=c+1;i<=c+no;i++)
	{
		cout<<category<<i<<"  ";
	}
	cout<<endl<<"Cost per seat: Rs."<<price/no<<endl<<"Total cost: Rs."<<price;
}
void Movie::Display()         //to read from the text file and display booking details
{
	clrscr();
	front();
	fstream f;
	f.open("MOVTEXT.txt",ios::in|ios::out);
	cout<<endl<<endl<<"BOOKING CONFIRMED!!"<<endl<<"******************************"<<endl<<endl;
	cout<<"Booking ID: "<<rand()%2000+1000<<endl;
	char line[50];
	while(!f.eof())
	{
		f.getline(line,50,'\n');
		cout<<line<<endl;
	}
	f.close();
	cout<<endl<<endl<<"*******************************"<<endl<<endl<<"THANK YOU FOR BOOKING WITH US! \n    ENJOY YOUR SHOW!";
	getch();
}
void Movie::Input()       //to write details of booking into a text file
{
	fstream f;
	f.open("MOVTEXT.txt",ios::in|ios::out|ios::trunc);
	f<<"Movie: "<<name<<"\nLocation: "<<location<<"\nAmount Paid: "<<price<<"\nSeats: ";
	for(i=c+1;i<=c+no;i++)
	{
		f<<category<<i<<"  ";
	}
	f.close();
}
void Movie::Confirm()       //to confirm booking of seats
{   if(choice1==1)
	{
	if(choice5==1)
	{ns[choice2-1][0][0]=ns[choice2-1][0][0]+no;}
	else if(choice5==2)
	{ns[0][choice2-1][0]=ns[0][choice2-1][0]+no;}
	else if(choice5==3)
	{ns[0][0][choice2-1]=ns[0][0][choice2-1]+no;}
	}
	else
	{  if(choice5==1)
	{rt[choice2-1][0][0]=rt[choice2-1][0][0]+no;}
	else if(choice5==2)
	{rt[0][choice2-1][0]=rt[0][choice2-1][0]+no;}
	else if(choice5==3)
	{rt[0][0][choice2-1]=rt[0][0][choice2-1]+no;}
	}
	Input();
	Display();
}
void main()
{
	for(i=0;i<10;i++)
	{
	for( int j=0;j<10;j++)
	{
		for(int k=0;k<10;k++)
		{
		ns[i][j][k]=0;
		if(i<4&&j<4&&k<4)
		rt[i][j][k]=0;
		}
	}
	}     //initialize number of seats booked to 0
	char details[80];
	ifstream f1;
	i=0;
	f1.open("ns.txt",ios::in);
	while(!f1.eof())
	{
		f1.getline(details,80,'\n');
		strcpy(nsmovie[i],details);
		i++;
	}
	f1.close();
	i=0;
	fstream f2;
	f2.open("rt.txt",ios::in);
	while(!f2.eof())
	{
		f2.getline(details,80,'\n');
		strcpy(rtmovie[i],details);
		i++;
	}
	f2.close();
	do{
	clrscr();
	Movie m;
	clrscr();
	m.front();
	do{
	clrscr();
	m.front();
	cout<<endl<<"MOVIES:-"<<endl<<"1. Now Showing"<<endl<<"2. Releasing tomorrow"<<endl<<endl<<"Enter choice: ";
	cin>>choice1;
	if(choice1==1)
	{
	m.Display_Movie(nsmovie,10);
	}
	else if(choice1==2)
	{
	m.Display_Movie(rtmovie,4);
	}
	else
	{ cout<<endl<<"Invalid choice.";getch(); };
	}while(choice1>2||choice1<1);
	m.Display_Show();
	m.Seats();
	cout<<endl<<endl<<"Enter 1 to confirm booking or enter 0 to exit: ";
	cin>>choice6;
	if(choice6==1)
	{
		m.Confirm();
	}
	clrscr();
	m.front();
	cout<<"Do you want to book again?"<<endl<<"1. Yes   2. No"<<endl<<"Enter choice: ";
	cin>>choice7;
	}while(choice7==1);   //loop to book again
}
