#include<iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include<windows.h>
#include<string>
#include<fstream>
#include <conio.h>
using namespace std;
void PlaceCursor(int x,int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}
//This Function is  to make board
void make_Board(char ch[10][10],int n1,int n2)
{	
for(int i=0;i<10;i++)
{
	for(int j=0;j<10;j++)
	{
//		PlaceCursor(i,j);
		ch[i][j]=' ';			
	}
	HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[1][1]='T';
	SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[8][8]='F';
}	
	for(int i=0;i<9;i++)
   {	
		for(int j=0;j<9;j++)
	   {
	   	
	   	// The below if conditions are used to place the snakes and ladders on the board
             if(i<10 && i>4 &&j==5)
             {
//             	 PlaceCursor(i,j);
              	 ch[i][j]='H';
             }
        	else
        	{
	     	if(i==0 && j>5 && j<10)
           {
//             	PlaceCursor(i,j);
            	ch[i][j]='$';
	      	}	
		    else if(j==2&&i<5)
		   {
//				PlaceCursor(i,j);
				ch[i][j]='H';
		   } 						
 	   }   
   }	
   for(int i=0;i<10;i++)
   {	
	for(int j=0;j<10;j++)
	{		
	    if(i==n1/10&&j==n1%10) 	
		{
			ch[i][j]='X';
			}
		if(i==n2/10&&j==n2%10) 	
		{
			ch[i][j]='O';
		}		
	}
}	
}    
}
void display(char ch[10][10],int n1,int n2)   //This function is to display board
{
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);    //	This Function is to show the colour 
    cout<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	for( int i=0;i< 10;i++)
    {
		for(int j=0;j<10;j++)
	   {
if(ch[i][j]=='H')    
{
		SetConsoleTextAttribute
		(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // This Function is to show the colour ladder
		cout<<"| ";
		cout<<ch[i][j];
        cout<<" |";
}
else if(ch[i][j]=='X')
{
		SetConsoleTextAttribute
	    (hConsole, FOREGROUND_BLUE |FOREGROUND_RED| FOREGROUND_INTENSITY);    // This Function is to show the colour of the dice of Player 1
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
}
	else if(ch[i][j]=='O')
{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED|FOREGROUND_GREEN| FOREGROUND_INTENSITY);   // This Function is to show the colour of the dice of Player 2
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
}
else
{
	if(ch[i][j]=='$')
	{
SetConsoleTextAttribute
    (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);    // This Function is to show the colour of snake
cout<<"| ";
cout<<ch[i][j];
cout<<" |";
	}
	else{
SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
cout<<"| ";
cout<<ch[i][j];
cout<<" |";
	}
}
	   }
cout<<""<<endl;
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}
 PlaceCursor(92,25);  // This function toplace the score of palyer at a fix point
cout<<"    SCORE";
PlaceCursor(92,27);
   cout<<" Player 1 :"<<n1<<endl;
   PlaceCursor(92,28);
   cout<<" Player 2 :"<<n2<<endl;
}
void Players(int n,bool player1,bool computer)
{
	HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	PlaceCursor(90,20);
    cout<<"TURN";
    for(int i=21;i<40;i++)
     {
     	for(int j=90;j<130;j++)
     	{
     		if(i==21||i==24||i==29||j==90||(j==99&&i>=21&&i<=24)||j==108||i==39||j==129)
     		{
     			PlaceCursor(j,i);
     			SetConsoleTextAttribute
                (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
     			cout<<"%";
			 }
		 }
	 }
	 	PlaceCursor(98,20);
	 	cout<<"DICE INPUT";
	 if(n==1)
	 {
	 		    PlaceCursor(105,23);  // This is used to place the Dice rolled input at a fix point
     			SetConsoleTextAttribute
                (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // This Function is to show the colour of the dice rolled
                cout<<"1";    // It shows the value of dice rolled
	 }
	 else if(n==2)
	 {
	    	 	PlaceCursor(105,23);
               (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout<<"2";    // It shows the value of dice rolled
	 }
	else if(n==3)
	 {
	 	  	 	PlaceCursor(105,23);
                (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout<<"3";	// It shows the value of dice rolled
	 }
	else if(n==4)
	 {
	 	  	 	PlaceCursor(105,23);
               (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout<<"4";   // It shows the value of dice rolled
 	 }
	 else if(n==5)
	 {
	 		 	PlaceCursor(105,23);
				(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout<<"5";   // It shows the value of dice rolled
	 }
	 else if(n==6)
	 {
	 	   	 	PlaceCursor(105,23);
                (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout<<"6";
	 }
	 if(player1==true)
	 {
	 	PlaceCursor(92,23);
	 	cout<<"PLAYER1";  // This point indicates the the that its now player 1 turn
	 }
	 if(computer==true)
	 {
	 	PlaceCursor(91,23);
	 	cout<<"PLAYER2";    // This point indicates the the that its now player 2 turn
	 }
	 
	 // The given below points are show during game at the side of board
	 PlaceCursor(91,31);
	 cout<<"Main Menu(m)";
	 PlaceCursor(91,32);
	 cout<<"Save Game(s)";
	 PlaceCursor(91,33);
	 cout<<"Exit(e)";
}

// The given below function is made to make the boxes hollow from inside that are show at the side of board to show score,Dice input e.t.c
void hollow()
{
	for(int i=21;i<40;i++)
     {
     	for(int j=90;j<130;j++)
     	{
     			PlaceCursor(j,i);
     			cout<<" ";
		 }
	 }
}
void mainmenu();
void play()   //This Function is used to play the multiplayer game in easy mode
{
	
  ifstream inputFile;
  string fileName;
//  cout << "Enter the file name you want to open: ";
  getline(cin, fileName);
  inputFile.open(fileName.c_str());						
  int f=1,b=1;
	inputFile>>f>>b;
	inputFile.close();
	char arr[10][10];
	srand(time(NULL));
	bool player1=true;
	bool player2=false;
	int p1score=f;
	int p2score=b;
	char a;
	char s;
	int xdice;
	int hr=0,min=0,sec=0;
	while(p1score!=100||p2score!=100)
	{
		// To show the board when we start the game 
//		make_Board(arr,p1score-1,p2score-1);
//		display(arr,p1score,p2score);
		for(hr=0;hr<24;hr++)    // The loops to show the time
		{
			for(min=0;min<60;min++)
			{
				if(min%5==0)
				{
				   	xdice=rand()%2;
				    if(xdice==1)
				    {
					   swap(arr[1][1],arr[8][8]);
					   swap(arr[5][5],arr[10][10]);   	
					}
				}
				for(sec=0;sec<60;sec++)
				{
					if(kbhit()) 
					{
						a=getch();
						if(a=='s')   // This function will ask the user to enter the file name when (s) will be pressed to save the game
						{
						    ofstream inputFile;
    				        string fileName;
						    cout << "Enter the file name: ";
   						    getline(cin, fileName);
							inputFile.open(fileName.c_str());
							inputFile<<p1score<<endl;
							inputFile<<p2score<<endl;
						}
						else if(a=='m')
						{
							system("CLS");
							mainmenu();
						}
						else if(a=='r')  // This function will roll the dice when (r) key will pressed
						{
							hollow();  // This function is called to show the score board time board and other things like this at one side of the board
							int x;
							if(player1==true) 
							{
								x=rand()%6+1;   // This random function is used the generate the rndom value rolled dice
								Players(x,player1,player2);
								if(p1score+x<=100) 
								{
									p1score=p1score+x;   // Adds the score of player 1 with previous score
								}
//								PlaceCursor(110,26);
								PlaceCursor(110,26);  // Shows the score of player 1 at fix position
								cout<<"PLAYER (1)";
								PlaceCursor(110,27);   // Shows the score of player 1 at fix position
								cout<<"Score : "<<p1score;
								if(p1score==3)     // The given below if conditions check for ladders and snakes and place he dice at top of ladder or at bottom of snake 
								{
									p1score=43;
								} 
								else if(p1score==56) 
								{
									p1score=86;
								}
								if(p1score==9) 
								{
									p1score=7;
								}
								else if(p1score==12&&min%5==0&&xdice==1)
							   { 
								p1score=89;
							   }
							   else if(p1score==89&&min%5==0&&xdice==1)
							  {
								p1score=12;
							  }	
								if(p1score==100)
								{
									cout<<"Player 1 won the game"<<endl;
									Sleep(2000);
									exit(1);
								}
								make_Board(arr,p1score-1,p2score-1);
								display(arr,p1score,p2score);
							}
							
							// The given below elese condition is valid if its player 2 turn
							else if(player2==true)
							{
								x=rand()%6+1;
								Players(x,player1,player2);
								if(p2score+x<=100) 
								{
									p2score=p2score+x;
								}
								PlaceCursor(110,26);
								cout<<"PLAYER (2)";
								PlaceCursor(110,27);
								cout<<"Score : "<<p2score;
								if(p2score==3) 
								{
									p2score=43;
								} 
								else if(p2score==56) 
								{
									p2score=86;
								}
								if(p2score==9) 
								{
									p2score=7;
								}
								else if(p2score==12&&min%5==0&&xdice==1)
							   { 
								p2score=89;
							   }
							   else if(p2score==89&&min%5==0&&xdice==1)
							   {
								p2score=12;
							   }
								else if(p2score==100) 
								{
									cout<<"Player 2 won the game"<<endl;
									Sleep(2000);
									exit(1);
								}
								make_Board(arr,p1score-1,p2score-1);
								display(arr,p1score,p2score);
								}
								// If the value of rolled dice is not 6 then it will swap the turn players
								if(x!=6) 
								{
									swap(player1,player2);
								}
							}				
						}
				   }
				   if(min%5==0)
				   {
				   	    int xdice=rand()%2;
				   	    if(xdice==1)
				   	    {
				   	            swap(arr[1][1],arr[8][8]);	
						}
				   }
				    PlaceCursor(115,20);
					cout<<"TIME ELAPSED";
					PlaceCursor(110,23);   // It will place the time inside the box at the side of board
					cout<<hr<<":"<<min<<":"<<sec;
					Sleep(1000);
				}
			}
		}
		Sleep(1000);
		PlaceCursor(55,15);
	}










void make_Board1(char ch[10][10],int n1,int n2)
{	
for(int i=0;i<10;i++){
	
	for(int j=0;j<10;j++)
	{
		ch[i][j]=' ';			
	}
	HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[1][1]='T';
	SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[8][8]='F';
}	
	for(int i=0;i<9;i++)
   {	
		for(int j=0;j<9;j++)
	   {
             if(i<10 && i>4 &&j==5)
             {
              	ch[i][j]='H';
             }
        	else
        	{
	     	if(i==0 && j>5 && j<10)
           {
            	ch[i][j]='$';
	      	}	
		   else if(j==2&&i<5)
		   {
			  ch[i][j]='H';
		   }			
	   }  
   }	
   for(int i=0;i<10;i++){
	
	for(int j=0;j<10;j++){
			
	    if(i==n1/10&&j==n1%10) 	
		{
			ch[i][j]='X';
			}
		if(i==n2/10&&j==n2%10) 	
		{
			ch[i][j]='O';
		}		
	}
}	
}    
}
void display1(char ch[10][10],int n1,int n2)
{
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    cout<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	for( int i=0;i< 10;i++)
    {
		for(int j=0;j<10;j++)
	   {
    if(ch[i][j]=='H')    
    {
        SetConsoleTextAttribute
        (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
   }
   else if(ch[i][j]=='X')
   {
		SetConsoleTextAttribute
       (hConsole, FOREGROUND_BLUE |FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
   }
	else if(ch[i][j]=='O')
	{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED|FOREGROUND_GREEN| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
   else
   {
	if(ch[i][j]=='$')
	{	
        SetConsoleTextAttribute
        (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else
	{
        SetConsoleTextAttribute
       (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
        cout<<"| ";
        cout<<ch[i][j];
        cout<<" |";
	}
}
}
       cout<<""<<endl; 
       cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}
       PlaceCursor(92,25);
       cout<<"    SCORE";
       PlaceCursor(92,27);
       cout<<" PLAYER :"<<n1;
       PlaceCursor(92,28);
       cout<<" COMPUTER :"<<n2<<endl;
}
void Players1(int n,bool player1,bool computer)
{
	PlaceCursor(90,20);
    cout<<"TURN";
    for(int i=21;i<40;i++)
    {
     	for(int j=90;j<130;j++)
     	{
     		if(i==21||i==24||i==29||j==90||(j==99&&i>=21&&i<=24)||j==108||i==39||j==129)
     		{
     			PlaceCursor(j,i);
     			cout<<"%";
			 }
		 }
	}
	 	PlaceCursor(101,20);
	 	cout<<"DICE INPUT";
	 if(n==1)
	 {
	 	PlaceCursor(105,23);
        cout<<"1";
	 }
	 else if(n==2)
	 {
	    PlaceCursor(105,23);
        cout<<"2";
	 }
	else if(n==3)
	 {
	 	PlaceCursor(105,23);
        cout<<"3";	
	 }
	else if(n==4)
	 {
	 	PlaceCursor(105,23);
        cout<<"4";
	 }
	 else if(n==5)
	 {
	 	PlaceCursor(105,23);
        cout<<"5";
	 }
	 else if(n==6)
	 {
	    PlaceCursor(105,23);
        cout<<"6";
	 }
	 if(player1==true)
	 {
	 	PlaceCursor(92,23);
	 	cout<<"PLAYER";
	 }
	 if(computer==true)
	 {
	 	PlaceCursor(91,23);
	 	cout<<"COMPUTER";
	 }
	 PlaceCursor(91,31);
	 cout<<"Main Menu(m)";
	 PlaceCursor(91,32);
	 cout<<"Save Game(s)";
	 PlaceCursor(91,33);
	 cout<<"Exit(e)";
}
void hollow1()
{
	for(int i=21;i<40;i++)
     {
     	for(int j=90;j<130;j++)
     	{
     			PlaceCursor(j,i);
     			cout<<" ";
		 }
	 }
}
void play1()    // This function made to play with computer in easy mode
{
	  ifstream inputFile;
      string fileName;
//	  cout << "Enter the file name you want to open: ";
   	  getline(cin, fileName);
	  inputFile.open(fileName.c_str());				
	  int f=0,b=0;
	  inputFile>>f>>b;
	  inputFile.close();
	  char arr[10][10];
	  srand(time(NULL));
	  bool player1=true;
      bool computer=false;
      int hr=0,min=0,sec=0;
      int p1score=f;
      int computerscore=b;
      char a;
      int x;
      int xdice;
      while(p1score!=100||computerscore!=100)
      {
    	for(hr=0;hr<24;hr++)
    	{
    		for(min=0;min<60;min++)
    		{
    			if(min%5==0)
				{
				   	xdice=rand()%2;
				    if(xdice==1)
				    {
					   swap(arr[1][1],arr[8][8]);
					   swap(arr[5][5],arr[10][10]);   	
					}
				}
    			for(sec=0;sec<60;sec++)
    			{
    				hollow1();
    				if(kbhit())
    				{
    					a=getch();
    					if(a=='s')
						{
						    ofstream inputFile;
    				        string fileName;
    				        PlaceCursor(96,33);
						    cout << "Enter the file name: ";
   						    getline(cin, fileName);
							inputFile.open(fileName.c_str());
							inputFile<<p1score<<endl;
							inputFile<<computerscore<<endl;
						}
						else if(a=='m')
						{
							system("CLS");
							mainmenu();
						}
						else
						{
							if(player1==true)
    						{
								Players1(x,player1,computer);
					    		x=rand()%6+1;
    				   		    if(p1score+x<=100)	
    						    {
    						    	p1score=p1score+x;
								}
   								PlaceCursor(110,26);
  						  		cout<<"PLAYER ";
    							PlaceCursor(110,27);
    							cout<<"Score : "<<p1score;
    							if(p1score==3)
    							{
    								p1score=43;
								}
								else if(p1score==56)
								{
									p1score=86;
								}
								if(p1score==9)
    							{
					    			p1score=7;
								}
								else if(p1score==12&&min%5==0&&xdice==1)
							   { 
								p1score=89;
							   }
							   else if(p1score==89&&min%5==0&&xdice==1)
							  {
								p1score=12;
							  }
								if(p1score==100)
								{
									cout<<"Player 1 won the game"<<endl;
									exit(1);
								}
    							make_Board1(arr,p1score-1,computerscore-1);
    							display1(arr,p1score,computerscore);
   						        if(x!=6)
								{
									swap(player1,computer);
								}
								Sleep(1500);
								PlaceCursor(55,15);
    		
							}
						}
					}
					else if(computer==true)
    				{
						Players1(x,player1,computer);
//    					Sleep(1500);
    					x=rand()%6+1;
    				   if(computerscore+x<=100)	
    	   				{
    	    				computerscore=computerscore+x;
						}
    					PlaceCursor(110,26);
    					cout<<"COMPUTER";
   				 		PlaceCursor(110,27);
   				 		cout<<"Score : "<<computerscore;
    					if(computerscore==3)
    					{
    						computerscore=43;
						}
						else if(computerscore==56)
						{
							computerscore=86;
						}
						if(computerscore==9)
    					{
    						computerscore=7;
						}
						else if(computerscore==12&&min%5==0&&xdice==1)
						{
								computerscore=89;
						}
							else if(computerscore==89&&min%5==0&&xdice==1)
						{
								computerscore=12;
						}
						else if(computerscore==100)
						{
							cout<<"Computer won the game"<<endl;
							exit(1);
						}
    					make_Board1(arr,p1score-1,computerscore-1);
    					display1(arr,p1score,computerscore);
    					if(x!=6)
						{
							swap(player1,computer);
						}
						Sleep(1500);
//						PlaceCursor(55,15);
					}
					    if(min%5==0)
				       {
				   	    int xdice=rand()%2;
				   	      if(xdice==1)
				   	      {
				   	            swap(arr[1][1],arr[8][8]);	
						  }
				        }
					    PlaceCursor(115,20);
					    cout<<"TIME ELAPSED";
					    PlaceCursor(110,23);
					    cout<<hr<<":"<<min<<":"<<sec;
					    Sleep(1000);
				}
			}
		}
    					
	}
}
void make_Board2(char ch[15][15],int n1,int n2)
{	
for(int i=0;i<15;i++)
{	
	for(int j=0;j<15;j++)
	{
		PlaceCursor(i,j);
		ch[i][j]=' ';			
	}
	HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[1][1]='T';
	SetConsoleTextAttribute;
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[8][8]='F';
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[5][8]='R';
	SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[10][13]='W';
}	
	for(int i=0;i<15;i++)
   {	
		for(int j=0;j<15;j++)
	   {
             if(i<=9&&i>3&&j==5)
             {
             	PlaceCursor(i,j);
              	ch[i][j]='H';
             }
        	else
        	{
	     	if(i==0&&j>5&&j<15)
            {
           	    PlaceCursor(i,j);
            	ch[i][j]='$';
	      	}
			  if((i==3&&j>3&&j<=6)||(i==4&&j==6)||(j==6&&i>=4&&i<=10)||(j==6&&j<=10&&i==10))
			  {
			  	PlaceCursor(i,j);
			    ch[i][j]='$';	
			 }	
			 if(i>=4&&j==10&&i<=14)
			 {
			 	PlaceCursor(i,j);
			 	ch[i][j]='$';
			 }
		    if((j==0||j<=6&&i==14&&i>=4))
		    {
			   PlaceCursor(i,j);
			   ch[i][j]='$';
		    }		
	   }
   }	
   for(int i=0;i<15;i++)
   {
	
	for(int j=0;j<15;j++){
			
	    if(i==n1/15&&j==n1%15) 	
		{
			ch[i][j]='X';
		}
		if(i==n2/15&&j==n2%15) 	
		{
			ch[i][j]='O';
		}	
	}
}	
}
}
void display2(char ch[15][15],int n1,int n2)
{
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    cout<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	for( int i=0;i< 15;i++)
    {
		for(int j=0;j<15;j++)
	   {
    if(ch[i][j]=='H')    
    {
       SetConsoleTextAttribute
       (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
        cout<<" |";
    }
	else if(ch[i][j]=='X')
	{
	   SetConsoleTextAttribute
       (hConsole, FOREGROUND_BLUE |FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else if(ch[i][j]=='O')
	{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED|FOREGROUND_GREEN| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else if(ch[i][j]==' ')
	{						
	    SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED| FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
    else
    {
	if(ch[i][j]=='$')
	{
		SetConsoleTextAttribute
	    (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);		
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else
	{	
        SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );		
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
}
}
cout<<""<<endl;
cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}	
PlaceCursor(92,25);
cout<<"    SCORE";
PlaceCursor(92,27);
cout<<" Player 1 :"<<n1;
PlaceCursor(92,28);
cout<<" Player 2 :"<<n2<<endl;
}
void Players2(int n,bool player1,bool computer)
{
	PlaceCursor(90,20);
    cout<<"TURN";
    for(int i=21;i<40;i++)
     {
     	for(int j=90;j<130;j++)
     	{
     		if(i==21||i==24||i==29||j==90||(j==99&&i>=21&&i<=24)||j==108||(i==39||j==128))
     		{
     			PlaceCursor(j,i);
     			cout<<"%";
			 }
		 }
	 }
	 	    PlaceCursor(101,20);
	 	    cout<<"DICE INPUT";
	 if(n==1)
	 {
	 		PlaceCursor(105,23);
            cout<<"1";
	 }
	 else if(n==2)
	 {
	    	PlaceCursor(105,23);
            cout<<"2";
	 }
	else if(n==3)
	 {
	 	  	PlaceCursor(105,23);
            cout<<"3";	
	 }
	else if(n==4)
	 {
	 	  	PlaceCursor(105,23);
            cout<<"4";
	 }
	 else if(n==5)
	 {
	 	    PlaceCursor(105,23);
            cout<<"5";
	 }
	 else if(n==6)
	 {
	 	   	PlaceCursor(105,23);
            cout<<"6";
	 }
	 if(player1==true)
	 {
	 	PlaceCursor(92,23);
	 	cout<<"PLAYER1";
	 }
	 if(computer==true)
	 {
	 	PlaceCursor(91,23);
	 	cout<<"PLAYER2";
	 }
}
void hollow2()
{
	for(int i=21;i<40;i++)
     {
     	for(int j=90;j<110;j++)
     	{
     			PlaceCursor(j,i);
     			cout<<" ";
		 }
	 }
}
void play2()   // The Function is made to Play the multiplayer game in difficult mode
{
    ifstream inputFile;
    string fileName;
//    cout << "Enter the file name you want to open: ";
   	getline(cin, fileName);
	inputFile.open(fileName.c_str());						
	int f=1,b=1;
	inputFile>>f>>b;
	inputFile.close();
	char arr[15][15];
	srand(time(NULL));
	bool player1=true;
	bool player2=false;
	int p1score=f;
	int p2score=b;
	char a;
	char s;
	int xdice;
	int hr=0,min=0,sec=0;
	while(p1score!=100||p2score!=100)
	{
//		make_Board2(arr,p1score-1,p2score-1);
//		display2(arr,p1score,p2score);
		for(hr=0;hr<24;hr++)
		{
			for(min=0;min<60;min++)
			{
				if(min%5==0)
				{
				   	xdice=rand()%2;
				    if(xdice==1)
				    {
					   swap(arr[1][1],arr[8][8]);
					   swap(arr[5][8],arr[10][13]);   	
					}
				}
				for(sec=0;sec<60;sec++)
				{
					if(kbhit())
					{
						a=getch();
						if(a=='s')
						{
						    ofstream inputFile;
    				        string fileName;
						    cout << "Enter the file name: ";
   						    getline(cin, fileName);
							inputFile.open(fileName.c_str());
							inputFile<<p1score<<endl;
							inputFile<<p2score<<endl;
						}
						else if(a=='m')
						{
							system("CLS");
							mainmenu();
						}
						else if(a=='r')
						{
							hollow();
							int x;
							if(player1==true) 
							{
								x=rand()%6+1;
								Players2(x,player1,player2);
								if(p1score+x<=100) 
								{
									p1score=p1score+x;
								}
								PlaceCursor(110,26);
								cout<<"PLAYER (1)";
								PlaceCursor(110,27);
								cout<<"Score : "<<p1score;
										if(p1score==15) 
							{
									p1score=7;
							} else if(p1score==61) 
							{
								p1score=141;
							} else if(p1score==157) 
							{
								p1score=50;
							} else if(p1score==221) 
							{
								p1score=71;
							} else if(p1score==217) 
							{
								p1score=1;
							}
							else if(p1score==17&&min%5==0&&xdice==1)
							{
								p1score=129;
							}
							else if(p1score==129&&min%5==0&&xdice==1)
							{
								p1score=17;
							}
								
								if(p1score==100)
								{
									cout<<"Player 1 won the game"<<endl;
									Sleep(2000);
									exit(1);
								}
								make_Board2(arr,p1score-1,p2score-1);
								display2(arr,p1score,p2score);
							}
							else if(player2==true)
							{
								x=rand()%6+1;
								Players(x,player1,player2);
								if(p2score+x<=100) 
								{
									p2score=p2score+x;
								}
								PlaceCursor(110,26);
								cout<<"PLAYER (2)";
								PlaceCursor(110,27);
								cout<<"Score : "<<p2score;
									if(p2score==15) 
							{
									p2score=7;
							} else if(p2score==61) 
							{
								p2score=141;
							} else if(p2score==157) 
							{
								p2score=50;
							} else if(p2score==221) 
							{
								p2score=71;
							} else if(p2score==217) 
							{
								p2score=1;
							}
							else if(p2score==17&&min%5==0&&xdice==1)
							{
								p2score=129;
							}
							else if(p2score==129&&min%5==0&&xdice==1)
							{
								p2score=17;
							}
								else if(p2score==100) 
								{
									cout<<"Player 2 won the game"<<endl;
									Sleep(2000);
									exit(1);
								}
								make_Board2(arr,p1score-1,p2score-1);
								display2(arr,p1score,p2score);
								}
								if(x!=6) 
								{
									swap(player1,player2);
								}
							}				
						}
				   }
				                
				                PlaceCursor(115,20);
					            cout<<"TIME ELAPSED";
							    PlaceCursor(110,23);
							    cout<<hr<<":"<<min<<":"<<sec;
				             	Sleep(1000);
				}
			}
		}
//		Sleep(1000);
//		PlaceCursor(55,15);
}
void make_Board3(char ch[15][15],int n1,int n2)
{	
for(int i=0;i<15;i++)
{	
	for(int j=0;j<15;j++)
	{
		PlaceCursor(i,j);
		ch[i][j]=' ';			
	}
		HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[1][1]='T';
	SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[8][8]='F';
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[5][8]='R';
	SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	ch[10][13]='W';
}	
	for(int i=0;i<15;i++)
    {	
		for(int j=0;j<15;j++)
	   {
             if(i<=9&&i>3&&j==5)
             {
             	PlaceCursor(i,j);
              	ch[i][j]='H';
             }
        	else
        	{
	     	if(i==0&&j>5&&j<15)
            {
           	PlaceCursor(i,j);
            	ch[i][j]='$';
	      	}
			if((i==3&&j>3&&j<=6)||(i==4&&j==6)||(j==6&&i>=4&&i<=10)||(j==6&&j<=10&&i==10))
			{
			  	PlaceCursor(i,j);
			    ch[i][j]='$';	
			}	
			if(i>=4&&j==10&&i<=14)
			{
			 	PlaceCursor(i,j);
			 	ch[i][j]='$';
			}
		    if((j==0||j<=6&&i==14&&i>=4))
		    {
			PlaceCursor(i,j);
			ch[i][j]='$';
		    }		
	   }
   }	
   for(int i=0;i<15;i++)
   {
	
	for(int j=0;j<15;j++){
			
	    if(i==n1/15&&j==n1%15) 	// if the score is greater tha 15 than player 1 will move to next row
		{
			ch[i][j]='X';
			}
		if(i==n2/15&&j==n2%15) 	// if the score is greater tha 15 than player 2 will move to next row
		{
			ch[i][j]='O';
		}	
	}
}	
}
}
void display3(char ch[15][15],int n1,int n2)
{
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    cout<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	for( int i=0;i< 15;i++)
    {
		for(int j=0;j<15;j++)
	   {
    if(ch[i][j]=='H')    
    {
       SetConsoleTextAttribute
       (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
    }
	else if(ch[i][j]=='X')
	{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_BLUE |FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else if(ch[i][j]=='O')
	{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED|FOREGROUND_GREEN| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else if(ch[i][j]==' ')
	{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else if(ch[i][j]=='W')
	{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else if(ch[i][j]=='T')
	{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else if(ch[i][j]=='F')
	{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
	else if(ch[i][j]=='R')
	{
		SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
    else
    {
	if(ch[i][j]=='$')
	{
	    SetConsoleTextAttribute
        (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<<"| ";
        cout<<ch[i][j];
        cout<<" |";
	}
	else
	{		
        SetConsoleTextAttribute
        (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
		cout<<"| ";
		cout<<ch[i][j];
		cout<<" |";
	}
}
}
        cout<<""<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}	
       PlaceCursor(92,25);
       cout<<"    SCORE";
       PlaceCursor(92,27);
       cout<<"PLAYER:"<<n1;
       PlaceCursor(92,28);
       cout<<"COMPUTER:"<<n2<<endl;
}
void Players3(int n,bool player1,bool computer)
{
	PlaceCursor(90,20);
    cout<<"TURN";
    for(int i=21;i<30;i++)
     {
     	for(int j=90;j<110;j++)
     	{
     		if(i==21||i==24||i==29||j==90||(j==99&&i>=21&&i<=24)||j==108)
     		{
     			PlaceCursor(j,i);
     			cout<<"%";
			 }
		 }
	 }
	 	PlaceCursor(101,20);
	 	cout<<"DICE INPUT";
	    if(n==1)
	    {
	 		PlaceCursor(105,23);
            cout<<"1";
	    }
	    else if(n==2)
	    {
	    	PlaceCursor(105,23);
            cout<<"2";
	    }
	    else if(n==3)
	    {
	 	  	PlaceCursor(105,23);
     		cout<<"3";	
	    }
	    else if(n==4)
	    {
	 	  	PlaceCursor(105,23);
            cout<<"4";
	    }
	    else if(n==5)
	    {
	 		PlaceCursor(105,23);
    		cout<<"5";
	    }
	    else if(n==6)
	    {
	 	   	PlaceCursor(105,23);
     		cout<<"6";
	    }
	    if(player1==true)
	    {
	 	    PlaceCursor(92,23);
	 	    cout<<"PLAYER";
	    }
	    if(computer==true)
	    {
	 	   PlaceCursor(91,23);
	 	   cout<<"Computer";
	    }
}
void hollow3()
{
	for(int i=21;i<40;i++)
     {
     	for(int j=90;j<110;j++)
     	{
     			PlaceCursor(j,i);
     			cout<<" ";
		 }
	 }
}
void play3()       // The is made to play with computer in difficult mode
{
	ifstream inputFile;
    string fileName;
   	getline(cin, fileName);
	inputFile.open(fileName.c_str());				
	int f=0,b=0;
	inputFile>>f>>b;
	inputFile.close();
	char arr[15][15];
	srand(time(NULL));
	bool player1=true;
    bool computer=false;
    int hr=0,min=0,sec=0;
    int p1score=f;
    int computerscore=b;
    char a;
   	int x;
   	int xdice;
    while(p1score!=100||computerscore!=100)
    {
    	for(hr=0;hr<24;hr++)
    	{
    		for(min=0;min<60;min++)
    		{
    			if(min%5==0)
				{
				   	xdice=rand()%2;
				    if(xdice==1)
				    {
					   swap(arr[1][1],arr[8][8]);
					   swap(arr[5][8],arr[10][13]);   	
					}
				}
    			for(sec=0;sec<60;sec++)
    			{
    				make_Board3(arr,p1score-1,computerscore-1);
    				display3(arr,p1score,computerscore);
    				hollow3();
    				if(kbhit())
    				{
    					a=getch();
    					if(a=='s')
						{
						    ofstream inputFile;
    				        string fileName;
						    cout << "Enter the file name: ";
   						    getline(cin, fileName);
							inputFile.open(fileName.c_str());
							inputFile<<p1score<<endl;
							inputFile<<computerscore<<endl;
						}
						else if(a=='m')
						{
							system("CLS");
							mainmenu();
						}
						else
						{
							if(player1==true)
    						{
								Players1(x,player1,computer);
					    		x=rand()%6+1;
    				   		    if(p1score+x<=100)	
    						    {
    						    	p1score=p1score+x;
								}
   								PlaceCursor(55,12);
    							PlaceCursor(100,30);
  						  		cout<<"PLAYER ";
    							PlaceCursor(101,31);
    							cout<<"Score : "<<p1score;
    							if(p1score==15) 
							{
									p1score=7;
							} else if(p1score==61) 
							{
								p1score=141;
							} else if(p1score==157) 
							{
								p1score=50;
							} else if(p1score==221) 
							{
								p1score=71;
							} else if(p1score==217) 
							{
								p1score=1;
							}
							else if(p1score==17&&min%5==0&&xdice==1)
							{
								p1score=129;
							}
							else if(p1score==129&&min%5==0&&xdice==1)
							{
								p1score=17;
							}
								if(p1score==100)
								{
									cout<<"PLAYER WON"<<endl;
									exit(1);
								}
   						        if(x!=6)
								{
									swap(player1,computer);
								}
								Sleep(1500);
								PlaceCursor(55,15);
    		
							}
						}
					}
					else if(computer==true)
    				{
						Players1(x,player1,computer);
    					Sleep(1500);
    					x=rand()%6+1;
    				   if(computerscore+x<=100)	
    	   				{
    	    				computerscore=computerscore+x;
						}
			    	     	PlaceCursor(55,12);
    			   		    PlaceCursor(55,12);
    					    PlaceCursor(100,30);
    					    cout<<"COMPUTER";
   				 		    PlaceCursor(101,31);
   				 		    cout<<"Score : "<<computerscore;
    						if(computerscore==15) 
							{
									computerscore=7;
							} else if(computerscore==61) 
							{
								computerscore=141;
							} else if(computerscore==157) 
							{
								computerscore=50;
							} else if(computerscore==221) 
							{
								p1score=71;
							} else if(computerscore==217) 
							{
								computerscore=1;
							}
							else if(computerscore==17&&min%5==0&&xdice==1)
							{
								computerscore=129;
							}
							else if(computerscore==129&&min%5==0&&xdice==1)
							{
								computerscore=17;
							}
						    else if(computerscore==100)
					 	    {
							    cout<<"COMPUTER WON"<<endl;
							    exit(1);
						    }
    					    if(x!=6)
						    {
							    swap(player1,computer);
						    }
						        Sleep(1500);
						        PlaceCursor(55,15);
					        }
					              if(min%5==0)
							    {
							   	    int xdice=rand()%2;
							   	    if(xdice==1)
							   	    {
							   	            swap(arr[1][1],arr[8][8]);
											swap(arr[5][5],arr[10][10]);   	
									}
							    }
					             PlaceCursor(115,20);
					            cout<<"TIME ELAPSED";
							    PlaceCursor(110,23);
							    cout<<hr<<":"<<min<<":"<<sec;
				             	Sleep(1000);
//					            system("cls");
				   }
		    	}
		   }
    					
	   }
}
void mainmenu()
{
	HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	char arr[10][10];
	char arr1[15][15];
	char c;
	cout<<"****************************************"<<endl;

	cout<<"       n) for start game"<<endl;

	cout<<"       s) for save game"<<endl;

	cout<<"       l) for load game"<<endl;

	cout<<"       i) for instructions"<<endl;

	cout<<"       a) for settings"<<endl;

	cout<<"****************************************"<<endl;
	cin>>c;	
	if(c=='n')
	{
//		ofstream fout;
//		fout.open("input.txt");
//		fout<<int(1)<<endl;
//		fout<<int(1)<<endl;
//		fout.close();
		char choice,g;
        cout<<"        ****************************************"<<endl;
		cout<<"     Choose the difficulty level"<<endl;
		cout<<"s)   Computer mode"<<endl;
		cout<<"m)   Multiplayer mode"<<endl;
        cout<<"        ****************************************"<<endl;
		cin>>choice;
		if(choice=='s')
		{
			cout<<"h) For easy mode"<<endl;
			cout<<"d) For difficult mode"<<endl;
			cin>>g;
			if(g=='h')
			{
				system("cls");
				make_Board1(arr,1,1);
	            play1();
			}
			else if(g=='d')
			{
			    system("cls");
			    make_Board3(arr1,1,1);
			    play3();
			}
		}
		else if(choice=='m')
		{
				cout<<"h) For easy mode"<<endl;
			    cout<<"d) For difficult mode"<<endl;
			    cin>>g;
			if(g=='h')
			{
				system("cls");
				make_Board(arr,1,1);
	            play();
			}
			else if(g=='d')
			{
			    system("cls");
			    make_Board2(arr1,1,1);
			    play2();	
			}

		}	
	}
	else if(c=='l')
	{
		        char choice,g;
                cout<<"        ****************************************"<<endl;
		        cout<<"     Choose the difficulty level"<<endl;
		        cout<<"s)   Computer mode"<<endl;
		        cout<<"m)   Multiplayer mode"<<endl;
                cout<<"        ****************************************"<<endl;
		        cin>>choice;
		       if(choice=='s')
	           {
			    cout<<"h) For easy mode"<<endl;
			    cout<<"d) For difficult mode"<<endl;
			    cin>>g;
			    if(g=='h')
			    {
					int f,b;
				    ifstream inputFile;
    				string fileName;
					cout << "Enter the file name you want to open: ";
   					getline(cin, fileName);
					inputFile.open(fileName.c_str());
					inputFile>>f;
					inputFile>>f;
					system("cls");
				    make_Board1(arr,1,1);
	                play1();
			   }
			    else if(g=='d')
			    {
					int f,b;
				    ifstream inputFile;
    				string fileName;
				    cout << "Enter the file name you want to open: ";
   					getline(cin, fileName);
					inputFile.open(fileName.c_str());
					inputFile>>f;
					inputFile>>f;
			        system("cls");
			        make_Board3(arr1,1,1);
			        play3();
			    }
		    }
		        else if(choice=='m')
		        {
				cout<<"h) For easy mode"<<endl;
			    cout<<"d) For difficult mode"<<endl;
			    cin>>g;
				if(g=='h')
			    {
					int f,b;
				    ifstream inputFile;
    				string fileName;
					cout << "Enter the file name you want to open: ";
   					getline(cin, fileName);
					inputFile.open(fileName.c_str());
					inputFile>>f;
					inputFile>>f;
				    system("cls");
				    make_Board(arr,1,1);
	                play();
		    	}
			    else if(g=='d')
			    {
				
					int f,b;
				    ifstream inputFile;
    				string fileName;
					cout << "Enter the file name you want to open: ";
   					getline(cin, fileName);
					inputFile.open(fileName.c_str());
					inputFile>>f;
					inputFile>>f;
			        system("cls");
			        make_Board2(arr1,1,1);
			        play2();	
			    }
		   }		
	   }
	else if(c=='i')
	{
	    cout<<"a. Each player starts off the board at space 0. b.\n Decide who goes first by rolling a dice for each player.\n The player with highest dice number will takethe first turn.\n If both players get the same number, then roll the dice again.c.\n To take a turn player will roll a dice by pressing ‘R’.\n Display the number rolled on the screen and movethe game piece that many steps forward on the board.\n You should show the player’s game piece movingon the boardd.\n Take an extra turn if player roll a six. First, move the game piece forward six squares and then roll thedice again.\n If player lands on any snakes or ladders, follow the instructions above to move up or downand then roll again to take extra turn.\n As long as player keep rolling sixes, player can keep moving!e. Land exactly on the last square to win. \nThe first person to reach the highest square on the board wins,usually square 100.\n But there's a twist! If player roll too high, then his piece bounces off the lastsquare and moves back.\n He can only win by rolling the exact number needed to land on the last square.\nFor example, if you are on square 99 and roll a four, move your game piece to 100 (one move), then bounce back to 99, 98, 97 (two, three, then four moves.) If square 97 is a ladder base or snake head,climb or slide as usual.f.\n If a player fall through a trapdoor and find himself at the head of a snake or the base of a ladder, thesnake or ladder will have its normal effect.g.\n A player may fall through more than one trapdoor if more than one is encountered in the same turn.h.\n At one time a trapdoor can be in one of the two states: Active or Dormant.\n After 5 minutes toss a coin(using rand()) and if 1 comes then switch the state of the trap door.i. \n A player will not fall through the same trapdoor more than once (even if it is active).\nIf he returns toa trapdoor cell they have already fallen through, the cell will be treated as a normal space.  "<<endl;
	    mainmenu();
	}
}
void startpage()
{
	char ch;
    system("color 7C");
	cout<<"           \n\n          +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout<<"            ***** *     * ***** *   *  *****     *     ***** ***** ***** ***** *****      "<<endl;
    cout<<"            *     * *   * *   * *  *   *         *     *   * *   * *   * *     *   *       "<<endl;
	cout<<"            ***** *  *  * ***** ***    ****      *     ***** *   * *   * ****  *****       "<<endl;
    cout<<"                * *   * * *   * *  *   *         *     *   * *   * *   * *     * *        "<<endl;
	cout<<"            ***** *     * *   * *    * *****     ***** *   * ***** ***** ***** *   *      "<<endl;
	cout<<"\n\n\t        +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\n\t PROGRAMMED BY: " <<endl;
    cout<<"\n\t\t  ZEESHAN ";  Sleep(300);cout<<" ";Sleep(300); Sleep(300);cout<<" ";Sleep(300);cout<<"JAVAID"<<endl;
	Sleep(200);cout<<"\t\t\t AND";	
	cout<<"\n\t\t   TALHA ";  Sleep(300);cout<<" ";Sleep(300);cout<<"TANVEER"<<endl;
	cout<<"\n\t\t\t GAME STARTING";
	for(int i=0;i<4;i++)
	{
		Sleep(600);
		cout<<".";		
	}
	cout<<endl;
	cout<<"ENTER m for main menu"<<endl;
	cout<<"ENTER e for exit"<<endl;
	cin>>ch;
	if(ch=='m')
	{
		system("cls");
		system("color 7C");
		mainmenu();	
	}
	else if(ch=='e')
	{
		exit(1);
	}
}
int main()
{
	char arr[10][10];
	char arr1[15][15];
	int n1,n2;
    startpage();
  	PlaceCursor(50,50);
    cout<<" ";
}
