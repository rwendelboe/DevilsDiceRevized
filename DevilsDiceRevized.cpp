#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>

using namespace std;

void score(int ynumber)
{
	ifstream Win_Loss_File;
	int Wins;
	int Losses;
	Win_Loss_File.open("gamestat.txt");
	if(Win_Loss_File.fail())
	{
		cout << "File failed to open..." << endl;
		return;
	}
	Win_Loss_File>>Wins>>Losses;
	if (ynumber >= 100)
	{
		Wins += 1;
	}
	else
	{
		Losses +=1;
	}
	Win_Loss_File.close();
	ofstream results;
	results.open("gamestat.txt");
	cout<<"W: " <<Wins<<"  L: "<<Losses;
	results <<Wins<<"  "<<Losses;
}

int sixsideddie()
{
	return (rand()%6)+1;
}
void printmenu(int die, bool player_turn,int ynumber, int dnumber, int ytempnumber, int dtempnumber)
{
	Sleep(800);	
	cout<<setw(31)<<"Devil's Dice\n";
	cout<<"\n";
	if(player_turn == true)
	{
		cout<<setw(18)<<"***\n";
	}
	else
	{
		cout<<setw(39)<<"***\n";
	}
	cout<<setw(19)<<"  you  "<<setw(22)<<"devil\n";
	cout<<setw(19)<<"  ---  "<<setw(22)<<"-----\n";
	

	for(int i=100;i>=0;i-=5)
	{
		cout<<setw(10) << "";
		if(ytempnumber >=i && ytempnumber <(i+5))
			cout<< setw(3)<<ytempnumber<<">";
		else
			cout<<setw(4)<< " ";
		cout<<"--"<<setw(3)<<i;
		if(ynumber >=i && ynumber <(i+5))
			cout<<"<"<<setw(3)<<ynumber;
		else
			cout<<setw(4)<<" ";
		cout<<"   ";
		if(i==90)
			cout<<"Die";
		else if(i==75 || i==85)
			cout<<"---";
		else if(i== 80)
			cout<<"|"<<die<<"|";
		else
			cout<<setw(3)<<" ";
		if(dtempnumber >=i && dtempnumber <i+5)
			cout<<setw(3)<<dtempnumber<<">";
		else
			cout<<setw(4)<<" ";
		cout<<i<<setw(3)<<"--";
		if(dnumber >=i && dnumber <(i+5))
			cout<<"<"<<setw(3)<<dnumber<<endl;
		else
			cout<<setw(4)<<" "<<endl;
	}

}
int main()
{
	int ytempnumber =0;
	int dtempnumber =0;
	int ynumber =0;
	int dnumber=0;
	srand(time(0));
	int Devilsdecision = 1;
	char choice;
	
	printmenu(0, true, ynumber, dnumber, ytempnumber,dtempnumber);
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"Your turn:   "<<"Pass(p), Roll(r), or forfeit (f)\n";
	cin>>choice;
	while(choice != 'n')
	{
		while(choice!='f' && choice != 'q')
		{	
			
			if (choice == 'r')
			{
				int x= sixsideddie();
				printmenu(x, true, ynumber, dnumber, ytempnumber, dtempnumber);
				ytempnumber += x;
			if (x==1)
			{
			choice ='p';
			ytempnumber=0;
			}
			else
			{

			printmenu(x,true,ynumber, dnumber, ytempnumber, dtempnumber);
			}
			}
		if (choice == 'p')
		{
			ynumber+=ytempnumber;
			ytempnumber=0;
			if (ynumber >=100)
			{
				cout<<"You Won!!!!!!"<<endl;
				score(ynumber);
				choice='q';
			}
			while(Devilsdecision ==1)
			{
			int x= sixsideddie();
			printmenu(x, false, ynumber, dnumber, ytempnumber, dtempnumber);
			dtempnumber+=x;
			if (x==1)
			{
				Devilsdecision=5;
				dtempnumber=0;
				
			}
			else 
			{
			Devilsdecision= rand()%2;
			if (Devilsdecision == 0)
			{
				dnumber +=dtempnumber;
				dtempnumber=0;
				if(dnumber>=100)
				{
					cout<<"The Devil Won!!!!!!"<<endl;
					score(ynumber);
					choice='q';
				}
				printmenu(x, true, ynumber, dnumber, ytempnumber, dtempnumber);
			}

			}
			
			}
				Devilsdecision = 1;
		}
		if(choice != 'q')
		{
			cout<<"\n";
			cout<<"\n";
			cout<<"\n";
			cout<<"Your turn:   "<<"Pass(p), Roll(r), or forfeit (f)\n";
			cin>>choice;
		}
		}
		 if(choice == 'f')
		{
			dnumber = ynumber+1;
			score(ynumber);
		 }
		 cout<<"Would You Like To Play Again? (y/n)"<<endl;
		 cin >> choice;
		 printmenu(0, true, ynumber =0, dnumber=0, ytempnumber=0,dtempnumber=0);
		 
	}
	return 0;
}