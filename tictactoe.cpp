//this program is the source code for tictactoeBNG game 
//it asks user how many players will play (min1, max 2)

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class TicTacToe
{
protected :
	
	string table[3][3];

public :

	string getrowcol(int r,int c){ return table[r][c]; }

void ask()
{
	cout<<"Enter which box do you want to fill (enter Row and Column numbers)"<<endl;
}

void display()
{
	for(int i=0;i<3;++i)
	{
		for(int k=0;k<3;++k)
		{
		cout<<"   ";

		if(table[i][k]!="X"&&table[i][k]!="O")
			cout<<"-";
		else cout<<table[i][k];
		
		cout<<"   ";
		}
	cout<<endl;
	}

}

bool checkforttt (string a)//this function checks whether the player did tictactoe  takes te last played letter and checks 
{
int k;
int i;
int counter=0;



	for(i=0;i<3;++i)
	{
	counter=0;
		for(k=0;k<3;++k)
		{
		if(table[i][k]==a)
		++counter;
		}
	if(counter==3)
	return 1;
	}

	counter=0;

	for(i=0;i<3;++i)
	{
	counter=0;
		for(k=0;k<3;++k)
		{
		if(table[k][i]==a)
		++counter;
		}
	if(counter==3)
	return 1;
	}

	counter=0;

	for(i=0,k=0;k<3&&i<3;++k,++i)
	{
	if(table[k][i]==a)
	++counter;
	}
	if(counter==3)
	return 1;

	counter=0;
	for(i=2,k=0;k<3&&i>0;++k,--i)
	{
	if(table[i][k]==a)
		++counter;
	}
	if(counter==3)
	return 1;
else return 0;

}

bool checkforplace(int r,int c)//this function checks if the user entered valid entry
{
	if(table[r][c]=="X"||table[r][c]=="O")
		return 0;
	else    return 1;
}


};//end the base class

class oneplayer :public TicTacToe{
protected:
	string playerLetter ;
	string computerLetter;
public :
	string getPlayerLetter(){return playerLetter;}
	string getComputerLetter(){return computerLetter;}

void choose()//player chooses which letter to play with
{
string a;
cout<<"Which letter do you want to play with ?(enter ""X"" or ""O"")"<<endl;
cin>>a;
	while(a!="X"&&a!="O")
	{
	cout<<"invalid input please enter X or O"<<endl;
	cin>>a;

	}
playerLetter=a;

if(a=="X")
	computerLetter="O";
else    computerLetter="X";
}


void enternumber(int r,int c)
{
r-=1;
c-=1;

	if(checkforplace(r,c))
		table[r][c]=playerLetter;
	else cout<<"invalid entry place is taken please try again"<<endl;
}

void playcomputer()
{
	while (1)
	{
	int r=rand()%3;
	int c=rand()%3;
		if(checkforplace(r,c))
		{
		table[r][c]=computerLetter;
		break;
		}
	}
}


};

class twoPlayer :public TicTacToe {
protected:
	string player1;
	string player2;

public:

	string getPlayer1Letter(){return player1;}
	string getPlayer2Letter(){return player2;}
void choose()//player chooses which letter to play with
{
string a;
cout<<"Player1 which letter do you want to play with ?(enter ""X"" or ""O"")"<<endl;
cin>>a;
	while(a!="X"&&a!="O")
	{
	cout<<"invalid input please enter X or O"<<endl;
	cin>>a;

	}
player1=a;

if(a=="X")
	player2="O";
else    player2="X";

cout<<"Player2 got the "<<getPlayer2Letter()<<" letter"<<endl;
}

void enternumber(string pl,int r,int c)
{
r-=1;
c-=1;

	if(checkforplace(r,c))
		table[r][c]=pl;
	else cout<<"invalid entry place is taken please try again"<<endl;
}

};


int main()
{
	srand(time(NULL));
int p;

cout<<"-----------------------------------------------"<<endl;
cout<<"Enter 1 to play against computer "<<endl<<"Enter 2 to play with another player"<<endl;
cout<<"-----------------------------------------------"<<endl;
cin>>p;


if(p==1)
{
	int r,c;
	oneplayer a;
	a.choose();
	a.display();
		while(1)
		{
		a.ask();
		cin>>r>>c;
		a.enternumber(r,c);
		a.display();
			if(a.checkforttt(a.getPlayerLetter()))
			{
			cout<<"Player "<<a.getPlayerLetter()<<" has won congrats"<<endl;
			break;
			}
		cout<<"------computer plays-----"<<endl;
		a.playcomputer();
		a.display();
		if(a.checkforttt(a.getComputerLetter()))
			{
			cout<<"Player "<<a.getComputerLetter()<<" has won congrats"<<endl;
			break;
			}

		}
}


if(p==2)
{
	int r,c;
	twoPlayer a;
	a.choose();
	a.display();
	cout<<"Player1 starts the game "<<endl<<endl;
		while(1)
		{

		cout<<"------Player1 plays-----"<<endl;
		a.ask();
		cin>>r>>c;
		a.enternumber(a.getPlayer1Letter(),r,c);
		a.display();
			if(a.checkforttt(a.getPlayer1Letter()))
			{
			cout<<"Player "<<a.getPlayer1Letter()<<" has won congrats"<<endl;
			break;
			}
		cout<<"------Player2 plays-----"<<endl;
		a.ask();
		cin>>r>>c;
		a.enternumber(a.getPlayer2Letter(),r,c);
		a.display();
		if(a.checkforttt(a.getPlayer2Letter()))
			{
			cout<<"Player "<<a.getPlayer2Letter()<<" has won congrats"<<endl;
			break;
			}

		}

}

}
//all rights reserved by BNG corp

