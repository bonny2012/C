//Lab 10 3D Tic-Tac-Toe
//Xin Zheng
//Nov 2, 2016
//Section 1

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

//define base class
class gameBoard
{
	protected:
		int INPUT;	

	public:
		char board[9];
		gameBoard()
		{		
			for(int i=0;i<9;i++)
				board[i]=' ';					
		}
		
	~gameBoard(){}
	
	void setX();
	void set0();
	bool isTaken();
	char isLine();
	void draw();
	bool inRange();
	void humanInput();
	void computerInput();
	char fTurn();
	char opponent(char);				
};

//set X
void gameBoard::setX()
{
	board[INPUT]='X';
}

//set 0
void gameBoard::set0()
{
	board[INPUT]='0';

}

//check if the location available
bool gameBoard::isTaken()
{	
	if(board[INPUT]!='0' && board[INPUT]!='X')
		return(false);
	else
		return(true);
}

//check winner's possiblity
char gameBoard::isLine()
{	if (board[0]=='X'&& board[1]=='X'&&board[2]=='X')
		return 'X';
	if (board[3]=='X' &&board[4]=='X' &&board[5]=='X')
		return 'X';
	if (board[6]=='X' &&board[7]=='X' &&board[8]=='X')
		return 'X';
	if (board[0]=='X' &&board[3]=='X' &&board[6]=='X')
		return 'X';
	if (board[1]=='X' &&board[4]=='X' &&board[7]=='X')
		return 'X';
	if(board[2]=='X' &&board[5]=='X' &&board[8]=='X')
		return 'X';	
	if(board[0]=='X' && board[4]=='X' &&board[8]=='X')
		return 'X';
	if(board[2]=='X' &&board[4]=='X' &&board[6]=='X')
		return 'X';
		
	if(board[0]=='0' &&board[1]=='0' &&board[2]=='0')
		return '0';
	if(board[3]=='0' &&board[4]=='0' &&board[5]=='0')
		return '0';
	else if(board[6]=='0' &&board[7]=='0' &&board[8]=='0')
		return '0';
	else if(board[0]=='0' &&board[3]=='0' &&board[6]=='0')
		return '0';
	else if(board[1]=='0' &&board[4]=='0' &&board[7]=='0')
		return '0';
	else if(board[2]=='0' &&board[5]=='0' &&board[8]=='0')
		return '0';
	else if(board[0]=='0' &&board[4]=='0' &&board[8]=='0')
		return '0';
	else if(board[2]=='0' &&board[4]=='0' &&board[6]=='0')
		return '0';
	
	for(int i=0; i<9; i++)
	{
		if(board[i] == ' ')
			return(' ');
	}
	return 'F';
			
}

// draw a board
void gameBoard::draw()
{
	
	cout<<"\n\t|\t|\n";
	cout<<"\t|\t|\n";
	cout << board[0] << "\t|" << board[1]<<"\t|"<<board[2]<<endl;
	cout<<"--------|-------|--------\n";
	cout<<"\t|\t|\n";
	cout<<board[3]<<"\t|"<<board[4]<<"\t|"<<board[5]<<endl;
	cout<<"--------|-------|--------\n";
	cout<<"\t|\t|\n";
	cout<<board[6]<<"\t|"<<board[7]<<"\t|"<<board[8]<<endl;
	cout<<"\t|\t|\n";
	
}

//check if the input valid
bool gameBoard::inRange()
{	
	if(INPUT<9 && INPUT> -1)
		return(true);
	else
		return(false);
}

//check if the location of human's input valiable and valid
void gameBoard::humanInput()
{
		
	do
	{		
		cout<<"Please enter a number(from 1-9) to input your \"X\". ";
		cin>>INPUT;
		INPUT=INPUT-1;
		
	}while(!inRange() || isTaken());		
	
}

//check if the location of computer's input available
void gameBoard::computerInput()
{		
	srand(time(NULL));
	INPUT=rand()%9;	
	while(isTaken())
	{
		INPUT=rand()%9;
	}

}

//Check who goes first with a random number
char gameBoard::fTurn()   
{  	
	srand(time(NULL));
	int Rand=rand()%2;
	
    if (Rand == 0)  
    {  
        cout << "You go first.\n";  
        return 'X';  
    }  
    else  
    {  
        cout << "\nMr.Smart will go first\n";  
        return '0';  
    }  
} 

 //function of taking turns to play 
char gameBoard::opponent(char piece)       
{  
    if (piece =='X')  
    {  
        return '0';  
    }  
    else  
    {  
        return 'X';  
    }  
} //end base class and functions definition



/*************************************start derived class*************************/
class Derived_gameBoard:public gameBoard
{	
	protected:
		int Xcounter;
		int Ocounter;
	public:
		gameBoard boards[3];
		void setX();
		void set0();
		char isFull();
		bool inRange();
		bool isTaken();
		void draw();	
		Derived_gameBoard(){Xcounter = 0; Ocounter = 0;}
		void humanInput();
		void computerInput();	
		void isLine();
		void winner();		
};
//check who wins.
void Derived_gameBoard::winner()
{
	cout<<"Your connection is "<<Xcounter<<" times."<<endl;
	cout<<"Mr Smart's connection is "<<Ocounter<<" times."<<endl;
	if (Xcounter>Ocounter)
		cout<<"Congratulations, you win!!";
	else  if(Xcounter<Ocounter)
		cout<<"Sorry, Mr.Smart wins the game, please work harder!";
	else
		cout<<"No one wins this time."<<endl;	
}
//check if the input between 0-26
bool Derived_gameBoard::inRange()
{	
	if(INPUT<27 && INPUT> -1)
		return(true);
	else
		return(false);
}
//draw 3D boards
void Derived_gameBoard::draw()
{
	 boards[0].draw();
	 boards[1].draw();
	 boards[2].draw();
}

//check if the whole board ocupied
char Derived_gameBoard::isFull()
{	
	for(int m=0;m<3;m++)
	{
		for(int i=0; i<9; i++)
		{
			if(boards[m].board[i] == ' ')
				return(' ');
		}
	}	
}

//set X in assigned location
void Derived_gameBoard::setX()
{	
	int boardNum = INPUT / 9;
	int cellNum = INPUT % 9;
	boards[boardNum].board[cellNum]='X';		
}

//set 0 in assigned location
void Derived_gameBoard::set0()
{
	int boardNum = INPUT / 9;
	int cellNum = INPUT % 9;	
	boards[boardNum].board[cellNum]='0';

}
//check if the spot available
bool Derived_gameBoard::isTaken()
{	
	int boardNum = INPUT / 9;
	int cellNum = INPUT % 9;
	
	if (boards[boardNum].board[cellNum]==' ')
		return (true);
	else
		return (false);	
}
//Human input a number
void Derived_gameBoard::humanInput()
{		
	do
	{		
		cout<<"Please enter a number(from 1-27) to input your \"X\". ";
		cin>>INPUT;
		INPUT=INPUT-1;
		
	}while(!inRange() || !isTaken());		
	
}

//computer input the number
void Derived_gameBoard::computerInput()
{		
	srand(time(NULL));
	INPUT=rand()%27;	
	while(!isTaken())
	{
		INPUT=rand()%27;
	}
}

//check winner's possiblity
void Derived_gameBoard::isLine()
{
	for(int m=0;m<3;m++)
	{
		if (boards[m].board[0]=='X'&& boards[m].board[1]=='X'&&boards[m].board[2]=='X')
			Xcounter++;
		if (boards[m].board[3]=='X' &&boards[m].board[4]=='X' &&boards[m].board[5]=='X')
			Xcounter++;
		if (boards[m].board[6]=='X' &&boards[m].board[7]=='X' &&boards[m].board[8]=='X')
			Xcounter++;
		if (boards[m].board[0]=='X' &&boards[m].board[3]=='X' &&boards[m].board[6]=='X')
			Xcounter++;
		if (boards[m].board[1]=='X' &&boards[m].board[4]=='X' &&boards[m].board[7]=='X')
			Xcounter++;
		if (boards[m].board[2]=='X' &&boards[m].board[5]=='X' &&boards[m].board[8]=='X')
			Xcounter++;	
		if(boards[m].board[0]=='X' &&boards[m].board[4]=='X' &&boards[m].board[8]=='X')
			Xcounter++;
		if(boards[m].board[2]=='X' &&boards[m].board[4]=='X' &&boards[m].board[6]=='X')
			Xcounter++;
			
		if(boards[m].board[0]=='0' &&boards[m].board[1]=='0' &&boards[m].board[2]=='0')
			Ocounter++;
		if(boards[m].board[3]=='0' &&boards[m].board[4]=='0' &&boards[m].board[5]=='0')
			Ocounter++;
		else if(boards[m].board[6]=='0' &&boards[m].board[7]=='0' &&boards[m].board[8]=='0')
			Ocounter++;
		else if(boards[m].board[0]=='0' &&boards[m].board[3]=='0' &&boards[m].board[6]=='0')
			Ocounter++;
		else if(boards[m].board[1]=='0' &&boards[m].board[4]=='0' &&boards[m].board[7]=='0')
			Ocounter++;
		else if(boards[m].board[2]=='0' &&boards[m].board[5]=='0' &&boards[m].board[8]=='0')
			Ocounter++;
		else if(boards[m].board[0]=='0' &&boards[m].board[4]=='0' &&boards[m].board[8]=='0')
			Ocounter++;
		else if(boards[m].board[2]=='0' &&boards[m].board[4]=='0' &&boards[m].board[6]=='0')
			Ocounter++;
	}
	
	//start 3D possiblility
	if(boards[0].board[0]=='0' &&boards[1].board[0]=='0' &&boards[2].board[0]=='0')
		Ocounter++;
	if(boards[0].board[1]=='0' &&boards[1].board[1]=='0' &&boards[2].board[1]=='0')
		Ocounter++;
	if(boards[0].board[2]=='0' &&boards[1].board[2]=='0' &&boards[2].board[2]=='0')
		Ocounter++;		
	if(boards[0].board[3]=='0' &&boards[1].board[3]=='0' &&boards[2].board[3]=='0')
		Ocounter++;
	if(boards[0].board[4]=='0' &&boards[1].board[4]=='0' &&boards[2].board[4]=='0')
		Ocounter++;
	if(boards[0].board[5]=='0' &&boards[1].board[5]=='0' &&boards[2].board[5]=='0')
		Ocounter++;
	if(boards[0].board[6]=='0' &&boards[1].board[6]=='0' &&boards[2].board[6]=='0')
		Ocounter++;
	if(boards[0].board[7]=='0' &&boards[1].board[7]=='0' &&boards[2].board[7]=='0')
		Ocounter++;
	if(boards[0].board[8]=='0' &&boards[1].board[8]=='0' &&boards[2].board[8]=='0')
		Ocounter++;
	if(boards[0].board[0]=='0' &&boards[1].board[4]=='0' &&boards[2].board[8]=='0')
		Ocounter++;
	if(boards[0].board[0]=='0' &&boards[1].board[1]=='0' &&boards[2].board[2]=='0')
		Ocounter++;
	if(boards[0].board[0]=='0' &&boards[1].board[3]=='0' &&boards[2].board[6]=='0')
		Ocounter++;
	if(boards[0].board[2]=='0' &&boards[1].board[1]=='0' &&boards[2].board[0]=='0')
		Ocounter++;
	if(boards[0].board[2]=='0' &&boards[1].board[4]=='0' &&boards[2].board[6]=='0')
		Ocounter++;
	if(boards[0].board[2]=='0' &&boards[1].board[5]=='0' &&boards[2].board[8]=='0')
		Ocounter++;
	if(boards[0].board[1]=='0' &&boards[1].board[4]=='0' &&boards[2].board[7]=='0')
		Ocounter++;
	if(boards[0].board[3]=='0' &&boards[0].board[4]=='0' &&boards[2].board[5]=='0')
		Ocounter++;
	if(boards[0].board[5]=='0' &&boards[1].board[4]=='0' &&boards[2].board[3]=='0')
		Ocounter++;
	if(boards[0].board[6]=='0' &&boards[1].board[3]=='0' &&boards[2].board[0]=='0')
		Ocounter++;
	if(boards[0].board[6]=='0' &&boards[1].board[4]=='0' &&boards[2].board[2]=='0')
		Ocounter++;
	if(boards[0].board[6]=='0' &&boards[1].board[7]=='0' &&boards[2].board[8]=='0')
		Ocounter++;
	if(boards[0].board[7]=='0' &&boards[1].board[4]=='0' &&boards[2].board[1]=='0')
		Ocounter++;
	if(boards[0].board[8]=='0' &&boards[1].board[5]=='X' &&boards[2].board[2]=='0')
		Ocounter++;
	if(boards[0].board[8]=='0' &&boards[1].board[4]=='0' &&boards[2].board[0]=='0')
		Ocounter++;
	if(boards[0].board[8]=='0' &&boards[1].board[7]=='0' &&boards[2].board[6]=='0')
		Ocounter++;
		
	if(boards[0].board[0]=='X' &&boards[1].board[0]=='X' &&boards[2].board[0]=='X')
		Xcounter++;
	if(boards[0].board[1]=='X' &&boards[1].board[1]=='X' &&boards[2].board[1]=='X')
		Xcounter++;
	if(boards[0].board[2]=='X' &&boards[1].board[2]=='X' &&boards[2].board[2]=='X')
		Xcounter++;
	if(boards[0].board[3]=='X' &&boards[1].board[3]=='X' &&boards[2].board[3]=='X')
		Xcounter++;
	if(boards[0].board[4]=='X' &&boards[1].board[4]=='X' &&boards[2].board[4]=='X')
		Xcounter++;
	if(boards[0].board[5]=='X' &&boards[1].board[5]=='X' &&boards[2].board[5]=='X')
		Xcounter++;	
	if(boards[0].board[6]=='X' &&boards[1].board[6]=='X' &&boards[2].board[6]=='X')
		Xcounter++;
	if(boards[0].board[7]=='X' &&boards[1].board[7]=='X' &&boards[2].board[7]=='X')
		Xcounter++;
	if(boards[0].board[8]=='X' &&boards[1].board[8]=='X' &&boards[2].board[8]=='X')
		Xcounter++;
	if(boards[0].board[0]=='X' &&boards[1].board[4]=='X' &&boards[2].board[8]=='X')
		Xcounter++;
	if(boards[0].board[0]=='X' &&boards[1].board[1]=='X' &&boards[2].board[2]=='X')
		Xcounter++;
	if(boards[0].board[0]=='X' &&boards[1].board[3]=='X' &&boards[2].board[6]=='X')
		Xcounter++;
	if(boards[0].board[2]=='X' &&boards[1].board[1]=='X' &&boards[2].board[0]=='X')
		Xcounter++;
	if(boards[0].board[2]=='X' &&boards[1].board[4]=='X' &&boards[2].board[6]=='X')
		Xcounter++;
	if(boards[0].board[2]=='X' &&boards[1].board[5]=='X' &&boards[2].board[8]=='X')
		Xcounter++;
	if(boards[0].board[1]=='X' &&boards[1].board[4]=='X' &&boards[2].board[7]=='X')
		Xcounter++;
	if(boards[0].board[3]=='X' &&boards[1].board[4]=='X' &&boards[2].board[5]=='X')
		Xcounter++;
	if(boards[0].board[5]=='X' &&boards[1].board[4]=='X' &&boards[2].board[3]=='X')
		Xcounter++;
	if(boards[0].board[6]=='X' &&boards[1].board[3]=='X' &&boards[2].board[0]=='X')
		Xcounter++;
	if(boards[0].board[6]=='X' &&boards[1].board[4]=='X' &&boards[2].board[2]=='X')
		Xcounter++;
	if(boards[0].board[6]=='X' &&boards[1].board[7]=='X' &&boards[2].board[8]=='X')
		Xcounter++;
	if(boards[0].board[7]=='X' &&boards[1].board[4]=='X' &&boards[2].board[1]=='X')
		Xcounter++;
	if(boards[0].board[8]=='X' &&boards[1].board[5]=='X' &&boards[2].board[2]=='X')
		Xcounter++;
	if(boards[0].board[8]=='X' &&boards[1].board[4]=='X' &&boards[2].board[0]=='X')
		Xcounter++;
	if(boards[0].board[8]=='X' &&boards[1].board[7]=='X' &&boards[2].board[6]=='X')
		Xcounter++;
	
}	// 98 ifs in total.
//start main function
int main()
{	
	Derived_gameBoard gb;
	
	const char human ='X'; 
	const char computer = '0';
	int Xcounter, Ocounter;	
	
	cout<<"Welcome to Tic-Tac-Toe game."<<endl;
	cout<<"You will play with me,Mr.Smart, my sign is \"0\",you sign is \"X\" "<<endl
		<<"Now, let us start";
		
	gb.draw();//draw the board		

	char turn = gb.fTurn();//choose who goes first
	//turn = human;
	
	do    
	{  
    switch(turn){
    		
       case human:  
       		gb.humanInput();       		
       		gb.setX();
       		cout<<"You played"<<endl;
       		turn = computer;
       		gb.draw();
        	break;
        	
      case  computer:
			gb.computerInput();
			gb.set0();
			cout<<"Mr.Smart played"<<endl;
 			turn = human;
 			gb.draw();
			break;         
    }
		                
	}while(gb.isFull()==' ');//check if the board is full 

	gb.isLine();
	
	gb.winner();
		
	return(0);
	
}


