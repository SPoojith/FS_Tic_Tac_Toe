#include<iostream>
#include<algorithm>
#include<iterator>
#include<chrono>
#include<fstream>
#include<conio.h>
#include<string.h>
#define s4 "\t \t"
using namespace std;
using namespace std::chrono;

char board[3][3]={' ',' ',' ',
				  ' ',' ',' ',
				  ' ',' ',' ',
				  };


int turn =1;

char mark= 'O';

int input;

class student{
	public:
	void printinputmatrix();
	int check();
	void ini();
	int addmark();
	void printboard();
	void display();
		int won= 0;

	int ch;
	char name[100];
	int validinput = 0;
	int a;
	int b;
	char wname[100];
	char data[100];
	char lname[100];
	char wt[100];
	char p1[10];
	char p2[10];
	long int t1;
	long int t2;	
	fstream o1;
	fstream o2;
	fstream o3;
	fstream o4;
	fstream temp;
};


int main()
{
	student s;
	int won= 0;

	int ch;
	char name[100];
	int validinput = 0;
	int a;
	int b;
	char wname[100];
	char data[100];
	char lname[100];
	char wt[100];
	char p1[10];
	char p2[10];
	long int t1;
	long int t2;	
	fstream o1;
	fstream o2;
	fstream o3;
	fstream o4;
	fstream temp;
	while(1)
	{
		cout<<endl<<endl<<"*!*!*!*!*!*!*! Welcome to TIC-TAC-TOE Game *!*!*!*!*!*!*!*!*"<<endl<<endl;
		cout<<"\t1.Play against a friends\n\n\t2.Play against Computer\n\n\t3.Game History\n\n\t4.Delete record from winnerslist\n\n\t5.update record from winnerslist\n\n\t6.Exit\n\n\tEnter your choice : ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
			case 1 :
			{
				
				cout<<"\tEnter Player one name : ";
				cin>>p1;
				cout<<"\tEnter Player two name : ";
				cin>>p2;
				auto start=chrono::high_resolution_clock::now();
				o1.open("playerlist.txt",ios::out | ios::app);
				o1<<"\n"<<p1<<"|"<<p2<<"|";
				o1.close();
		
		
				for(int i=0;i<9;i++)
				{
					system("cls");
					s.printboard();
					s.printinputmatrix();
					if(turn)
						{
							cout<<endl<<"\t"<<p1<<"  your Turn (symbol: O)"<<endl;
						}
					else
						{
							cout<<endl<<"\t"<<p2<<"  your Turn (symbol: X)"<<endl;
						}
		
					cout<<endl<<"  Enter the position from Input Matrix to mark on Markingboard :";
					cin>>input;
					while(input<0 || input>9)
						{
							cout<<"\tInvalid Input,pls re-input within range (0-9) \n";
							cin>>input;
						}
	
					if(turn) mark='O';
						else mark='X';
					validinput=s.addmark();
					if( !validinput)
						{
							i--;
							continue;
						}
						
		
					won=s.check();
					if(won)
						{
							s.printboard();
							if(turn)
				 				{
									cout<<endl<<endl<<"*!*!*!*!*!*! "<<p1<<" you won *!*!*!*!*!*! \n";
								
									o2.open("playerlist.txt",ios::in);
									a=strlen(p1)+strlen(p2)+4;
									o2.seekg(-a,ios::end);
									o2.getline(name,100,'|');
									cout<<endl<<"  "<<name<<" is the winner(imported from winnersdata.txt)\n";
									o2.close();
									auto stop=chrono::high_resolution_clock::now();
									auto duration=chrono::duration_cast<seconds>(stop-start);
									t1=duration.count();
									o3.open("winnersdata.txt",ios::out | ios::app);
									o3<<"\n"<<p1<<"|"<<p2<<"|"<<t1<<"|";
									o3.close();
									cout<<endl<<"----------This game summary-----------"<<endl;
									cout<<endl<<"\t Player 1 --> "<<p1<<endl;
									cout<<endl<<"\t Player 2 --> "<<p2<<endl;
									cout<<endl<<"  "<<p1<<" you took "<<duration.count()<<" seconds to beat "<<p2<<endl;
										
								}
							else 
								{
									cout<<endl<<endl<<"*!*!*!*!*!*! "<<p2<<" you won *!*!*!*!*!*! \n";
									o2.open("playerlist.txt",ios::in);
									a=strlen(p1)+3;
									o2.seekg(-a,ios::end);
									o2.getline(name,100,'|');
									cout<<endl<<"  "<<p2<<" is the winner(imported from winnersdata.txt)\n";
									o2.close();
									auto stop1=chrono::high_resolution_clock::now();
									auto duration=chrono::duration_cast<seconds>(stop1-start);
									t2=duration.count();
									o3.open("winnersdata.txt",ios::out|ios::app);
									o3<<"\n"<<p2<<"|"<<p1<<"|"<<t2<<"|";
									o3.close();	
									cout<<endl<<"----------This game summary-----------"<<endl;
									cout<<endl<<"\t Player 1 --> "<<p1<<endl;
									cout<<endl<<"\t Player 2 --> "<<p2<<endl;
									cout<<endl<<"  "<<p2<<" you took "<<duration.count()<<" seconds to beat "<<p1<<endl;
										
								}	
							s.ini();
							getch();
							break;
						}
					if(i==8)
						{
							system("cls");
							s.printboard();
							cout<<endl<<endl;
							cout<<"*!*!*!*!*!*!*!*! Match Draw *!*!*!*!*!*!*!*!\n"<<endl<<endl;
							s.ini();
						}
					turn=!turn;
				}
					break;
			}
			
			case 2:
			{
				
				
				cout<<"\tEnter Player name : ";
				cin>>p1;
				
				
				auto start=chrono::high_resolution_clock::now();
				o1.open("playerlist.txt",ios::out | ios::app);
				o1<<"\n"<<p1<<"|"<<"computer"<<"|";
				o1.close();
		
		
				for(int i=0;i<9;i++)
				{
					system("cls");
					s.printboard();
					s.printinputmatrix();
					if(turn)
						{
							cout<<endl<<"\t"<<p1<<"  your Turn (symbol: O)"<<endl;
							cout<<endl<<"  Enter the position from Input Matrix to mark on Markingboard :";
							cin>>input;
						}
					else
						{
							cout<<endl<<"\t"<<"computer"<<"  your Turn (symbol: X)"<<endl;
							cout<<endl<<"  Enter the position from Input Matrix to mark on Markingboard :";
							if(board[1][1]==' ') input=5;
								else if(board[0][0]==' ') input=1;
								else if(board[0][2]==' ') input=3;
								else if(board[2][1]==' ') input=8;
								else if(board[1][2]==' ') input=6;
								else if(board[0][1]==' ') input=2;
								else if(board[1][0]==' ') input=4;							
								else if(board[2][0]==' ') input=7;						
								else input=9;
						}
					while(input<0 || input>9)
						{
							cout<<"\tInvalid Input,pls re-input within range (0-9) \n";
							cin>>input;
						}
	
					if(turn) mark='O';
						else mark='X';
					validinput=s.addmark();
					if( !validinput)
						{
							i--;
							continue;
						}
						
		
					won=s.check();
					if(won)
						{
							s.printboard();
							if(turn)
				 				{
									cout<<endl<<endl<<"*!*!*!*!*!*! "<<p1<<" you won *!*!*!*!*!*! \n";
								
									o2.open("playerlist.txt",ios::in);
									a=strlen(p1)+8+4;
									o2.seekg(-a,ios::end);
									o2.getline(name,100,'|');
									cout<<endl<<"  "<<name<<" is the winner(imported from winnersdata.txt)\n";
									o2.close();
									auto stop=chrono::high_resolution_clock::now();
									auto duration=chrono::duration_cast<seconds>(stop-start);
									t1=duration.count();
									o3.open("winnersdata.txt",ios::out | ios::app);
									o3<<"\n"<<p1<<"|"<<"computer"<<"|"<<t1<<"|";
									o3.close();
									cout<<endl<<"----------This game summary-----------"<<endl;
									cout<<endl<<"\t Player 1 --> "<<p1<<endl;
									cout<<endl<<"\t Player 2 --> "<<"computer"<<endl;
									cout<<endl<<"  "<<p1<<" you took "<<duration.count()<<" seconds to beat "<<"computer"<<endl;
										
								}
							else 
								{
									cout<<endl<<endl<<"*!*!*!*!*!*! "<<"computer"<<" won *!*!*!*!*!*! \n";
									
									auto stop1=chrono::high_resolution_clock::now();
									auto duration=chrono::duration_cast<seconds>(stop1-start);
									t2=duration.count();
									o3.open("winnersdata.txt",ios::out|ios::app);
									o3<<"\n"<<"computer"<<"|"<<p1<<"|"<<t2<<"|";
									o3.close();	
									cout<<endl<<"  "<<"computer"<<" is the winner(imported from winnersdata.txt)\n";
									cout<<endl<<"----------This game summary-----------"<<endl;
									cout<<endl<<"\t Player 1 --> "<<p1<<endl;
									cout<<endl<<"\t Player 2 --> "<<"computer"<<endl;
									cout<<endl<<"  "<<"computer"<<" took "<<duration.count()<<" seconds to beat "<<p1<<endl;
								}	
							s.ini();
							getch();
							break;
						}
					if(i==8)
						{
							system("cls");
							s.printboard();
							cout<<endl<<endl;
							cout<<"*!*!*!*!*!*!*!*! Match Draw *!*!*!*!*!*!*!*!\n"<<endl<<endl;
							s.ini();
						}
					turn=!turn;
				}
					
				
				break;
			}
			case 3:
			{  
				string line;
				o4.open("winnersdata.txt",ios::in);
				temp.open("temp.txt",ios::out|ios::app);
				while(getline(o4,line))
				{

				
					if(!line.empty())
					{
						temp<<line<<endl;
					}
					
				}
				o4.close();
				temp.close();
				remove("winnersdata.txt");
				rename("temp.txt","winnersdata.txt");
				o4.open("winnersdata.txt",ios::in);
				int game=1,c=0;
				while(getline(o4,line))
				{
					c++;
				}				
				o4.close();
				o4.open("winnersdata.txt",ios::in);
				cout<<endl<<"*!*!*!*!*!*!*!* Game History *!*!*!*!*!*!*!*!*!*!*"<<endl;
				while(!o4.eof() && game<=c)
				{
						o4.getline(wname,100,'|');
						o4.getline(lname,100,'|');
						o4.getline(wt,100,'|');
						cout<<endl<<"game "<<game<<":"<<wname<<" won against "<<lname<<" in "<<wt<<" seconds"<<endl;
						game++;
					
				}
				o4.close();	
				break;
			}
			
			case 4:
			{
				char dname[100];
				int w=0;
				int t=0;
				int position;
				string line;
				o4.open("winnersdata.txt",ios::in);
				temp.open("temp.txt",ios::out|ios::app);
				cout<<" 	Enter the winner's name to delet from the winnersdata : ";
				cin>>dname;
				while(getline(o4,line))
				{
					position=line.find(dname);
				
					if(position!=0)
					{
						temp<<line<<endl;
					}
					
				}
				o4.close();
				temp.close();
				o4.open("winnersdata.txt",ios::in);
				while(getline(o4,line))
				{
					w++;					
				}
				w--;
				temp.open("temp.txt",ios::in);
				while(getline(temp,line))
				{
					t++;
				}
				t--;
				if(w==t)
				{
					cout<<"\n!*!*!no record found!*!*!"<<endl;
				}
				else{
					cout<<"\n*!*!*!*!*!*!record delet successfully*!*!*!*!*!*!*!*!"<<endl;
				}
				o4.close();
				temp.close();
				remove("winnersdata.txt");
				rename("temp.txt","winnersdata.txt");
						
				break;
			}
			
			case 5 :
				{
						char dname[100];
				int w=0;
				int t=0;
				int position;
				string line;
				o4.open("winnersdata.txt",ios::in);
				temp.open("temp.txt",ios::out|ios::app);
				cout<<" 	Enter the winner's name to update from the winnersdata : ";
				cin>>dname;
				while(getline(o4,line))
				{
					position=line.find(dname);
				
					if(position!=0)
					{
						temp<<line<<endl;
					}
					if(position==0){
						string deli="|";
						int start =0;
						int end=line.find(deli);
						int c=0;
						while(end!=-1){
							c++;
							if(c==1){
								cout<<"   "<<line.substr(start,end-start)<<" : player 1 name "<<endl;
							}
							if(c==2){
								cout<<"   "<<line.substr(start,end-start)<<" : player 2 name "<<endl;
							}
							if(c==3){
								cout<<"   "<<line.substr(start,end-start)<<" : time taken"<<endl;
							}
						start=end+deli.size();
						end=line.find(deli,start);
						}
						
						cout<<"enter player 1 to update"<<endl;
						cin>>p1;
						cout<<"enter player 2  to update"<<endl;
						cin>>p2;
						cout<<"enter time to update"<<endl;
						cin>>t1;
						temp<<"\n"<<p1<<"|"<<p2<<"|"<<t1<<"|";
						break;			
					}
					
				}
				o4.close();
				temp.close();
				o4.open("winnersdata.txt",ios::in);
				while(getline(o4,line))
				{
					w++;					
				}
				w--;
				temp.open("temp.txt",ios::in);
				while(getline(temp,line))
				{
					t++;
				}
				t--;
				if(w==t)
				{
					cout<<"\n!*!*!no record found!*!*!"<<endl;
				}
				else{
					cout<<"\n*!*!*!*!*!*!record updated successfully*!*!*!*!*!*!*!*!"<<endl;
				}
				o4.close();
				temp.close();
				remove("winnersdata.txt");
				rename("temp.txt","winnersdata.txt");
					break;
				}
						
			default: exit(0);
		}
	cout<<endl<<endl;
	}
	s.printinputmatrix();
	getch();
	return 0;
}



void student::printinputmatrix(){
	cout<<endl<<endl<<"---------------Input Matrix--------------\n "<<endl;
	cout<<s4<<" 1 | 2 | 3 "<<endl;
	cout<<s4<<"---+---+---"<<endl;
	cout<<s4<<" 4 | 5 | 6 "<<endl;
	cout<<s4<<"---+---+---"<<endl;
	cout<<s4<<" 7 | 8 | 9 "<<endl;

}
void student:: printboard(){
	cout<<endl<<endl<<"--------------Marking board-----------------\n"<<endl;
	cout<<s4<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
	cout<<s4<<"---+---+---"<<endl;
	cout<<s4<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
	cout<<s4<<"---+---+---"<<endl;
	cout<<s4<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
	
}
int student:: addmark(){
	for(int i=0,k=1;i<3;i++)
	{
		for(int j=0;j<3;j++,k++)
		{
			if(k==input)
			{
				if(board[i][j] == ' ')
				{
					board[i][j] =mark;
					return 1;
				}
				else{
					cout<<"\tinvalid input,press enter to continue";
					getch();
					return 0;
				}
			}
		}
	}
}

int student:: check(){
		//row
	if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark)
		return 1;
	if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark)
		return 1;
	if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark)
		return 1;
		//col
	if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark)
		return 1;
	if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark)
		return 1;
	if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark)
		return 1;
		//daigonal
	if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
		return 1;
	if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
		return 1;
return 0;
}

void student:: ini()
	{
			board[0][0] =' ';
			board[0][1] =' ';
			board[0][2] =' ';
			board[1][0] =' ';
			board[1][1] =' ';
			board[1][2] =' ';
			board[2][0] =' ';
			board[2][1] =' ';
			board[2][2] =' ';
						  
	}

