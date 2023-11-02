#include <iostream>
#include <stdio.h>	/* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

/**
 * Moves the console cursor to the specified position (x, y).
 *
 * @param x - The horizontal position for the cursor.
 * @param y - The vertical position for the cursor.
 */
void PlaceCursor(int x, int y)
{
	COORD c = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/**
 * Initializes the game board represented as a 2D character array and places game elements.
 *
 * @param board - The 2D character array representing the game board.
 * @param player1Pos - The position of player 1 on the board.
 * @param player2Pos - The position of player 2 on the board.
 */
void make_Board(char board[10][10], int player1Pos, int player2Pos)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = ' ';
		}

		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

		board[1][1] = 'T';
		board[8][8] = 'F';
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			// Place game elements like snakes, ladders, and more
			if (i < 10 && i > 4 && j == 5)
			{
				board[i][j] = 'H';
			}
			else
			{
				if (i == 0 && j > 5 && j < 10)
				{
					board[i][j] = '$';
				}
				else if (j == 2 && i < 5)
				{
					board[i][j] = 'H';
				}
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// Place player pieces on the board
			if (i == player1Pos / 10 && j == player1Pos % 10)
			{
				board[i][j] = 'X';
			}
			if (i == player2Pos / 10 && j == player2Pos % 10)
			{
				board[i][j] = 'O';
			}
		}
	}
}

/**
 * Displays the game board along with player positions and scores.
 *
 * @param board - The 2D character array representing the game board.
 * @param player1Score - The score of Player 1.
 * @param player2Score - The score of Player 2.
 */
void display(char board[10][10], int player1Score, int player2Score)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// Set console text attributes for different elements
			if (board[i][j] == 'H')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "| " << board[i][j] << " |"; // Display ladder
			}
			else if (board[i][j] == 'X')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "| " << board[i][j] << " |"; // Display Player 1's position
			}
			else if (board[i][j] == 'O')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "| " << board[i][j] << " |"; // Display Player 2's position
			}
			else
			{
				if (board[i][j] == '$')
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "| " << board[i][j] << " |"; // Display snake
				}
				else
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout << "| " << board[i][j] << " |"; // Display other elements
				}
			}
		}
		cout << "" << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	}

	PlaceCursor(92, 25);
	cout << "    SCORE";

	PlaceCursor(92, 27);
	cout << " Player 1: " << player1Score << endl;

	PlaceCursor(92, 28);
	cout << " Player 2: " << player2Score << endl;
}

/**
 * Displays player turn and dice input on the game board.
 *
 * @param diceValue - The value of the dice rolled (1 to 6).
 * @param isPlayer1Turn - Indicates if it's Player 1's turn (true/false).
 * @param isComputerTurn - Indicates if it's the computer's turn (true/false).
 */
void Players(int diceValue, bool isPlayer1Turn, bool isComputerTurn)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE;

    // Display the "TURN" label
    PlaceCursor(90, 20);
    cout << "TURN";

    // Draw a border for the turn indicator
    for (int i = 21; i < 40; i++) {
		for (int j = 90; j < 130; j++)
		{
			if (i == 21 || i == 24 || i == 29 || j == 90 || (j == 99 && i >= 21 && i <= 24) || j == 108 || i == 39 || j == 129)
			{
				PlaceCursor(j, i);
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "%";
			}
		}
    }

    // Display the "DICE INPUT" label
    PlaceCursor(98, 20);
    cout << "DICE INPUT";

    // Display the dice roll value
    PlaceCursor(105, 23);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << diceValue;

    // Display the current player's turn
    if (isPlayer1Turn) {
		PlaceCursor(92, 23);
		cout << "PLAYER 1";
    } else if (isComputerTurn) {
		PlaceCursor(91, 23);
		cout << "PLAYER 2";
    }

    // Display main menu and save game options
    PlaceCursor(91, 31);
    cout << "Main Menu (m)";
    PlaceCursor(91, 32);
    cout << "Save Game (s)";
    PlaceCursor(91, 33);
    cout << "Exit (e)";
}

/**
 * Clears the content inside the hollow boxes on the game board.
 */
void clearHollowBoxes()
{
	for (int i = 21; i < 40; i++)
	{
		for (int j = 90; j < 130; j++)
		{
			PlaceCursor(j, i);
			cout << " ";
		}
	}
}

void mainmenu();

/**
 * Multiplayer game in easy mode.
 */
void play()
{
	ifstream inputFile;
	string fileName;
	getline(cin, fileName);
	inputFile.open(fileName.c_str());
	int f = 1, b = 1;
	inputFile >> f >> b;
	inputFile.close();

	char arr[10][10];
	srand(time(NULL));
	bool player1 = true;
	bool player2 = false;
	int p1score = f;
	int p2score = b;
	char a;
	char s;
	int xdice;
	int hr = 0, min = 0, sec = 0;

	while (p1score != 100 || p2score != 100)
	{
		for (hr = 0; hr < 24; hr++)
		{
			for (min = 0; min < 60; min++)
			{
				if (min % 5 == 0)
				{
					xdice = rand() % 2;
					if (xdice == 1)
					{
						swap(arr[1][1], arr[8][8]);
						swap(arr[5][5], arr[10][10]);
					}
				}
				for (sec = 0; sec < 60; sec++)
				{
					if (kbhit())
					{
						a = getch();
						if (a == 's')
						{
							ofstream inputFile;
							string fileName;
							cout << "Enter the file name: ";
							getline(cin, fileName);
							inputFile.open(fileName.c_str());
							inputFile << p1score << endl;
							inputFile << p2score << endl;
						}
						else if (a == 'm')
						{
							system("CLS");
							mainmenu();
						}
						else if (a == 'r')
						{
							hollow();
							int x;
							if (player1 == true)
							{
								x = rand() % 6 + 1;
								Players(x, player1, player2);
								if (p1score + x <= 100)
								{
									p1score = p1score + x;
								}
								PlaceCursor(110, 26);
								PlaceCursor(110, 26);
								cout << "PLAYER (1)";
								PlaceCursor(110, 27);
								cout << "Score : " << p1score;
								if (p1score == 3)
								{
									p1score = 43;
								}
								else if (p1score == 56)
								{
									p1score = 86;
								}
								if (p1score == 9)
								{
									p1score = 7;
								}
								else if (p1score == 12 && min % 5 == 0 && xdice == 1)
								{
									p1score = 89;
								}
								else if (p1score == 89 && min % 5 == 0 && xdice == 1)
								{
									p1score = 12;
								}
								if (p1score == 100)
								{
									cout << "Player 1 won the game" << endl;
									Sleep(2000);
									exit(1);
								}
								make_Board(arr, p1score - 1, p2score - 1);
								display(arr, p1score, p2score);
							}
							else if (player2 == true)
							{
								x = rand() % 6 + 1;
								Players(x, player1, player2);
								if (p2score + x <= 100)
								{
									p2score = p2score + x;
								}
								PlaceCursor(110, 26);
								cout << "PLAYER (2)";
								PlaceCursor(110, 27);
								cout << "Score : " << p2score;
								if (p2score == 3)
								{
									p2score = 43;
								}
								else if (p2score == 56)
								{
									p2score = 86;
								}
								if (p2score == 9)
								{
									p2score = 7;
								}
								else if (p2score == 12 && min % 5 == 0 && xdice == 1)
								{
									p2score = 89;
								}
								else if (p2score == 89 && min % 5 == 0 && xdice == 1)
								{
									p2score = 12;
								}
								else if (p2score == 100)
								{
									cout << "Player 2 won the game" << endl;
									Sleep(2000);
									exit(1);
								}
								make_Board(arr, p1score - 1, p2score - 1);
								display(arr, p1score, p2score);
							}
							if (x != 6)
							{
								swap(player1, player2);
							}
						}
					}
				}
				if (min % 5 == 0)
				{
					int xdice = rand() % 2;
					if (xdice == 1)
					{
						swap(arr[1][1], arr[8][8]);
					}
				}
				PlaceCursor(115, 20);
				cout << "TIME ELAPSED";
				PlaceCursor(110, 23);
				cout << hr << ":" << min << ":" << sec;
				Sleep(1000);
			}
		}
		Sleep(1000);
		PlaceCursor(55, 15);
	}
}

/**
 * Initialize the game board with characters and positions.
 *
 * @param ch The game board array to initialize.
 * @param n1 The position of the first player.
 * @param n2 The position of the second player.
 */
void make_Board1(char ch[10][10], int n1, int n2)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			ch[i][j] = ' ';
		}
	}

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	ch[1][1] = 'T';
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	ch[8][8] = 'F';

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i < 10 && i > 4 && j == 5)
			{
				ch[i][j] = 'H';
			}
			else
			{
				if (i == 0 && j > 5 && j < 10)
				{
					ch[i][j] = '$';
				}
				else if (j == 2 && i < 5)
				{
					ch[i][j] = 'H';
				}
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == n1 / 10 && j == n1 % 10)
			{
				ch[i][j] = 'X';
			}
			if (i == n2 / 10 && j == n2 % 10)
			{
				ch[i][j] = 'O';
			}
		}
	}
}

/**
 * Display the game board with player and computer scores.
 *
 * @param ch The game board array to display.
 * @param n1 The score of the player.
 * @param n2 The score of the computer.
 */
void display1(char ch[10][10], int n1, int n2)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (ch[i][j] == 'H')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "| ";
				cout << ch[i][j];
				cout << " |";
			}
			else if (ch[i][j] == 'X')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "| ";
				cout << ch[i][j];
				cout << " |";
			}
			else if (ch[i][j] == 'O')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "| ";
				cout << ch[i][j];
				cout << " |";
			}
			else
			{
				if (ch[i][j] == '$')
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "| ";
					cout << ch[i][j];
					cout << " |";
				}
				else
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout << "| ";
					cout << ch[i][j];
					cout << " |";
				}
			}
		}
		cout << "" << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	}

	PlaceCursor(92, 25);
	cout << "    SCORE";
	PlaceCursor(92, 27);
	cout << " PLAYER :" << n1;
	PlaceCursor(92, 28);
	cout << " COMPUTER :" << n2 << endl;
}

/**
 * Display player's turn, dice input, and game options.
 *
 * @param n The value rolled on the dice.
 * @param player1 True if it's the player's turn, false otherwise.
 * @param computer True if it's the computer's turn, false otherwise.
 */
void Players1(int n, bool player1, bool computer)
{
	PlaceCursor(90, 20);
	cout << "TURN";

	for (int i = 21; i < 40; i++)
	{
		for (int j = 90; j < 130; j++)
		{
			if (i == 21 || i == 24 || i == 29 || j == 90 || (j == 99 && i >= 21 && i <= 24) || j == 108 || i == 39 || j == 129)
			{
				PlaceCursor(j, i);
				cout << "%";
			}
		}
	}

	PlaceCursor(101, 20);
	cout << "DICE INPUT";

	if (n >= 1 && n <= 6)
	{
		PlaceCursor(105, 23);
		cout << n;
	}

	if (player1)
	{
		PlaceCursor(92, 23);
		cout << "PLAYER";
	}

	if (computer)
	{
		PlaceCursor(91, 23);
		cout << "COMPUTER";
	}

	PlaceCursor(91, 31);
	cout << "Main Menu (m)";
	PlaceCursor(91, 32);
	cout << "Save Game (s)";
	PlaceCursor(91, 33);
	cout << "Exit (e)";
}

/**
 * Clear and make the hollow boxes from inside used for showing score, time, etc.
 */
void hollow1()
{
	for (int i = 21; i < 40; i++)
	{
		for (int j = 90; j < 130; j++)
		{
			PlaceCursor(j, i);
			cout << " ";
		}
	}
}

/**
 * Play a game with the computer in easy mode.
 */
void play1()
{
	ifstream inputFile;
	string fileName;

	// Get the saved game state from a file
	getline(cin, fileName);
	inputFile.open(fileName.c_str());
	int p1score = 0;
	int computerscore = 0;
	inputFile >> p1score >> computerscore;
	inputFile.close();

	char arr[10][10];
	srand(time(NULL));
	bool player1 = true;
	bool computer = false;
	int hr = 0, min = 0, sec = 0;
	char a;
	int x;
	int xdice;

	while (p1score != 100 || computerscore != 100)
	{
		for (hr = 0; hr < 24; hr++)
		{
			for (min = 0; min < 60; min++)
			{
				if (min % 5 == 0)
				{
					xdice = rand() % 2;
					if (xdice == 1)
					{
						swap(arr[1][1], arr[8][8]);
						swap(arr[5][5], arr[10][10]);
					}
				}
				for (sec = 0; sec < 60; sec++)
				{
					hollow1();

					if (kbhit())
					{
						a = getch();
						if (a == 's')
						{
							ofstream inputFile;
							string fileName;
							PlaceCursor(96, 33);
							cout << "Enter the file name: ";
							getline(cin, fileName);
							inputFile.open(fileName.c_str());
							inputFile << p1score << endl;
							inputFile << computerscore << endl;
						}
						else if (a == 'm')
						{
							system("CLS");
							mainmenu();
						}
						else
						{
							if (player1 == true)
							{
								x = rand() % 6 + 1;
								Players1(x, player1, computer);
								if (p1score + x <= 100)
								{
									p1score = p1score + x;
								}
								PlaceCursor(110, 26);
								cout << "PLAYER ";
								PlaceCursor(110, 27);
								cout << "Score : " << p1score;
								if (p1score == 3)
								{
									p1score = 43;
								}
								else if (p1score == 56)
								{
									p1score = 86;
								}
								if (p1score == 9)
								{
									p1score = 7;
								}
								else if (p1score == 12 && min % 5 == 0 && xdice == 1)
								{
									p1score = 89;
								}
								else if (p1score == 89 && min % 5 == 0 && xdice == 1)
								{
									p1score = 12;
								}
								if (p1score == 100)
								{
									cout << "Player 1 won the game" << endl;
									exit(1);
								}
								make_Board1(arr, p1score - 1, computerscore - 1);
								display1(arr, p1score, computerscore);

								if (x != 6)
								{
									swap(player1, computer);
								}
								Sleep(1500);
								PlaceCursor(55, 15);
							}
						}
					}
					else if (computer == true)
					{
						Players1(x, player1, computer);
						x = rand() % 6 + 1;
						if (computerscore + x <= 100)
						{
							computerscore = computerscore + x;
						}
						PlaceCursor(110, 26);
						cout << "COMPUTER";
						PlaceCursor(110, 27);
						cout << "Score : " << computerscore;
						if (computerscore == 3)
						{
							computerscore = 43;
						}
						else if (computerscore == 56)
						{
							computerscore = 86;
						}
						if (computerscore == 9)
						{
							computerscore = 7;
						}
						else if (computerscore == 12 && min % 5 == 0 && xdice == 1)
						{
							computerscore = 89;
						}
						else if (computerscore == 89 && min % 5 == 0 && xdice == 1)
						{
							computerscore = 12;
						}
						else if (computerscore == 100)
						{
							cout << "Computer won the game" << endl;
							exit(1);
						}
						make_Board1(arr, p1score - 1, computerscore - 1);
						display1(arr, p1score, computerscore);

						if (x != 6)
						{
							swap(player1, computer);
						}
						Sleep(1500);
					}

					if (min % 5 == 0)
					{
						xdice = rand() % 2;
						if (xdice == 1)
						{
							swap(arr[1][1], arr[8][8]);
						}
					}

					PlaceCursor(115, 20);
					cout << "TIME ELAPSED";
					PlaceCursor(110, 23);
					cout << hr << ":" << min << ":" << sec;
					Sleep(1000);
				}
			}
		}
	}
}

/**
 * Create the game board with a given size and player positions.
 *
 * @param ch 2D character array representing the game board.
 * @param n1 Position of player 1 on the board.
 * @param n2 Position of player 2 on the board.
 */
void make_Board2(char ch[15][15], int n1, int n2)
{
	// Clear the board and initialize player positions
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			PlaceCursor(i, j);
			ch[i][j] = ' ';
		}
	}

	// Initialize console colors
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

	// Set special characters on the board
	ch[1][1] = 'T';
	ch[8][8] = 'F';
	ch[5][8] = 'R';
	ch[10][13] = 'W';

	// Draw ladder and snake elements on the board
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i <= 9 && i > 3 && j == 5)
			{
				PlaceCursor(i, j);
				ch[i][j] = 'H';
			}
			else
			{
				if (i == 0 && j > 5 && j < 15)
				{
					PlaceCursor(i, j);
					ch[i][j] = '$';
				}
				if ((i == 3 && j > 3 && j <= 6) || (i == 4 && j == 6) ||
					(j == 6 && i >= 4 && i <= 10) || (j == 6 && j <= 10 && i == 10))
				{
					PlaceCursor(i, j);
					ch[i][j] = '$';
				}
				if (i >= 4 && j == 10 && i <= 14)
				{
					PlaceCursor(i, j);
					ch[i][j] = '$';
				}
				if ((j == 0 || (j <= 6 && i == 14 && i >= 4)))
				{
					PlaceCursor(i, j);
					ch[i][j] = '$';
				}
			}
		}
	}

	// Set player positions on the board
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i == n1 / 15 && j == n1 % 15)
			{
				ch[i][j] = 'X'; // Player 1
			}
			if (i == n2 / 15 && j == n2 % 15)
			{
				ch[i][j] = 'O'; // Player 2
			}
		}
	}
}

/**
 * Display the game board with player positions.
 *
 * @param ch 2D character array representing the game board.
 * @param n1 Position of player 1 on the board.
 * @param n2 Position of player 2 on the board.
 */
void display2(char ch[15][15], int n1, int n2)
{
	// Initialize console settings
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (ch[i][j] == 'H')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "| " << ch[i][j] << " |";
			}
			else if (ch[i][j] == 'X')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "| " << ch[i][j] << " |";
			}
			else if (ch[i][j] == 'O')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "| " << ch[i][j] << " |";
			}
			else if (ch[i][j] == ' ')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "| " << ch[i][j] << " |";
			}
			else
			{
				if (ch[i][j] == '$')
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "| " << ch[i][j] << " |";
				}
				else
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout << "| " << ch[i][j] << " |";
				}
			}
		}
		cout << "" << endl;
	}

	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	// Display player scores
	PlaceCursor(92, 25);
	cout << "    SCORE";
	PlaceCursor(92, 27);
	cout << " Player 1: " << n1;
	PlaceCursor(92, 28);
	cout << " Player 2: " << n2 << endl;
}

/**
 * Display player turn and dice input.
 *
 * @param n The value of the rolled dice.
 * @param player1 Indicates if it's player 1's turn.
 * @param computer Indicates if it's the computer's turn.
 */
void Players2(int n, bool player1, bool computer)
{
	// Display the turn indicator and decoration
	PlaceCursor(90, 20);
	cout << "TURN";

	for (int i = 21; i < 40; i++)
	{
		for (int j = 90; j < 130; j++)
		{
			// Draw decorative elements
			if (i == 21 || i == 24 || i == 29 || j == 90 || (j == 99 && i >= 21 && i <= 24) || j == 108 || (i == 39 || j == 128))
			{
				PlaceCursor(j, i);
				cout << "%";
			}
		}
	}

	// Display the dice input indicator
	PlaceCursor(101, 20);
	cout << "DICE INPUT";

	// Display the value of the rolled dice
	PlaceCursor(105, 23);
	cout << n;

	// Display the current player's turn
	if (player1)
	{
		PlaceCursor(92, 23);
		cout << "PLAYER 1";
	}
	if (computer)
	{
		PlaceCursor(91, 23);
		cout << "COMPUTER";
	}
}

/**
 * Clears a rectangular area on the console screen, creating a hollow space.
 */
void hollow2()
{
	for (int i = 21; i < 40; i++)
	{
		for (int j = 90; j < 110; j++)
		{
			PlaceCursor(j, i);
			cout << " ";
		}
	}
}

/**
 * Plays a multiplayer game in difficult mode.
 */
void play2()
{
	ifstream inputFile;
	string fileName;
	//    cout << "Enter the file name you want to open: ";
	getline(cin, fileName);
	inputFile.open(fileName.c_str());
	int player1Score = 1;
	int player2Score = 1;
	inputFile >> player1Score >> player2Score;
	inputFile.close();
	char board[15][15];
	srand(time(NULL));
	bool player1Turn = true;
	bool player2Turn = false;
	char key;
	int dice;
	int xDice;
	int hours = 0;
	int minutes = 0;
	int seconds = 0;

	while (player1Score != 100 || player2Score != 100)
	{
		//		make_Board2(board, player1Score - 1, player2Score - 1);
		//		display2(board, player1Score, player2Score);

		for (hours = 0; hours < 24; hours++)
		{
			for (minutes = 0; minutes < 60; minutes++)
			{
				if (minutes % 5 == 0)
				{
					xDice = rand() % 2;
					if (xDice == 1)
					{
						swap(board[1][1], board[8][8]);
						swap(board[5][8], board[10][13]);
					}
				}
				for (seconds = 0; seconds < 60; seconds++)
				{
					if (kbhit())
					{
						key = getch();
						if (key == 's')
						{
							ofstream outputFile;
							string outputFileName;
							cout << "Enter the output file name: ";
							getline(cin, outputFileName);
							outputFile.open(outputFileName.c_str());
							outputFile << player1Score << endl;
							outputFile << player2Score << endl;
						}
						else if (key == 'm')
						{
							system("CLS");
							mainmenu();
						}
						else if (key == 'r')
						{
							hollow2();
							int diceRoll;
							if (player1Turn)
							{
								diceRoll = rand() % 6 + 1;
								Players2(diceRoll, player1Turn, player2Turn);
								if (player1Score + diceRoll <= 100)
								{
									player1Score += diceRoll;
								}
								PlaceCursor(110, 26);
								cout << "PLAYER (1)";
								PlaceCursor(110, 27);
								cout << "Score : " << player1Score;
								if (player1Score == 15)
								{
									player1Score = 7;
								}
								else if (player1Score == 61)
								{
									player1Score = 141;
								}
								else if (player1Score == 157)
								{
									player1Score = 50;
								}
								else if (player1Score == 221)
								{
									player1Score = 71;
								}
								else if (player1Score == 217)
								{
									player1Score = 1;
								}
								else if (player1Score == 17 && minutes % 5 == 0 && xDice == 1)
								{
									player1Score = 129;
								}
								else if (player1Score == 129 && minutes % 5 == 0 && xDice == 1)
								{
									player1Score = 17;
								}
								if (player1Score == 100)
								{
									cout << "Player 1 won the game" << endl;
									Sleep(2000);
									exit(1);
								}
								// make_Board2(board, player1Score - 1, player2Score - 1);
								// display2(board, player1Score, player2Score);
							}
							else if (player2Turn)
							{
								diceRoll = rand() % 6 + 1;
								Players2(diceRoll, player1Turn, player2Turn);
								if (player2Score + diceRoll <= 100)
								{
									player2Score += diceRoll;
								}
								PlaceCursor(110, 26);
								cout << "PLAYER (2)";
								PlaceCursor(110, 27);
								cout << "Score : " << player2Score;
								if (player2Score == 15)
								{
									player2Score = 7;
								}
								else if (player2Score == 61)
								{
									player2Score = 141;
								}
								else if (player2Score == 157)
								{
									player2Score = 50;
								}
								else if (player2Score == 221)
								{
									player2Score = 71;
								}
								else if (player2Score == 217)
								{
									player2Score = 1;
								}
								else if (player2Score == 17 && minutes % 5 == 0 && xDice == 1)
								{
									player2Score = 129;
								}
								else if (player2Score == 129 && minutes % 5 == 0 && xDice == 1)
								{
									player2Score = 17;
								}
								else if (player2Score == 100)
								{
									cout << "Player 2 won the game" << endl;
									Sleep(2000);
									exit(1);
								}
								// make_Board2(board, player1Score - 1, player2Score - 1);
								// display2(board, player1Score, player2Score);
							}
							if (diceRoll != 6)
							{
								swap(player1Turn, player2Turn);
							}
						}
					}
				}
				if (minutes % 5 == 0)
				{
					int xDice = rand() % 2;
					if (xDice == 1)
					{
						swap(board[1][1], board[8][8]);
					}
				}
				PlaceCursor(115, 20);
				cout << "TIME ELAPSED";
				PlaceCursor(110, 23);
				cout << hours << ":" << minutes << ":" << seconds;
				Sleep(1000);
			}
		}
		// Sleep(1000);
		// PlaceCursor(55, 15);
	}
}

/**
 * Initialize and display the game board for two players.
 *
 * @param ch The game board represented as a character array.
 * @param n1 The position of player 1 on the board.
 * @param n2 The position of player 2 on the board.
 */
void make_Board3(char ch[15][15], int n1, int n2)
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			PlaceCursor(i, j);
			ch[i][j] = ' ';
		}

		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		ch[1][1] = 'T';
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		ch[8][8] = 'F';
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		ch[5][8] = 'R';
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		ch[10][13] = 'W';
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i <= 9 && i > 3 && j == 5)
			{
				PlaceCursor(i, j);
				ch[i][j] = 'H';
			}
			else
			{
				if (i == 0 && j > 5 && j < 15)
				{
					PlaceCursor(i, j);
					ch[i][j] = '$';
				}
				if ((i == 3 && j > 3 && j <= 6) || (i == 4 && j == 6) || (j == 6 && i >= 4 && i <= 10) || (j == 6 && j <= 10 && i == 10))
				{
					PlaceCursor(i, j);
					ch[i][j] = '$';
				}
				if (i >= 4 && j == 10 && i <= 14)
				{
					PlaceCursor(i, j);
					ch[i][j] = '$';
				}
				if ((j == 0 || (j <= 6 && i == 14 && i >= 4)))
				{
					PlaceCursor(i, j);
					ch[i][j] = '$';
				}
			}
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i == n1 / 15 && j == n1 % 15)
			{
				ch[i][j] = 'X';
			}
			if (i == n2 / 15 && j == n2 % 15)
			{
				ch[i][j] = 'O';
			}
		}
	}
}

/**
 * Display the game board with player and computer scores.
 *
 * @param ch The game board represented as a character array.
 * @param n1 The score of Player.
 * @param n2 The score of Computer.
 */
void display3(char ch[15][15], int n1, int n2)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (ch[i][j] == 'H')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "| " << ch[i][j] << " |";
			}
			else if (ch[i][j] == 'X')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "| " << ch[i][j] << " |";
			}
			else if (ch[i][j] == 'O')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "| " << ch[i][j] << " |";
			}
			else if (ch[i][j] == ' ' || ch[i][j] == 'W' || ch[i][j] == 'T' || ch[i][j] == 'F' || ch[i][j] == 'R')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "| " << ch[i][j] << " |";
			}
			else if (ch[i][j] == '$')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "| " << ch[i][j] << " |";
			}
			else
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "| " << ch[i][j] << " |";
			}
		}
		cout << "" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	}

	PlaceCursor(92, 25);
	cout << "    SCORE";
	PlaceCursor(92, 27);
	cout << "PLAYER: " << n1;
	PlaceCursor(92, 28);
	cout << "COMPUTER: " << n2 << endl;
}

/**
 * Display the current player's turn and dice input on the game board.
 *
 * @param n The value rolled on the dice.
 * @param player1 True if it's Player's turn, False for Computer's turn.
 * @param computer True if it's Computer's turn, False for Player's turn.
 */
void Players3(int n, bool player1, bool computer)
{
	PlaceCursor(90, 20);
	cout << "TURN";

	for (int i = 21; i < 30; i++)
	{
		for (int j = 90; j < 110; j++)
		{
			if (i == 21 || i == 24 || i == 29 || j == 90 || (j == 99 && i >= 21 && i <= 24) || j == 108)
			{
				PlaceCursor(j, i);
				cout << "%";
			}
		}
	}

	PlaceCursor(101, 20);
	cout << "DICE INPUT";

	if (n >= 1 && n <= 6)
	{
		PlaceCursor(105, 23);
		cout << n;
	}

	if (player1)
	{
		PlaceCursor(92, 23);
		cout << "PLAYER";
	}

	if (computer)
	{
		PlaceCursor(91, 23);
		cout << "Computer";
	}
}

/**
 * Clear a hollow region on the game board.
 */
void hollow3()
{
	for (int i = 21; i < 40; i++)
	{
		for (int j = 90; j < 110; j++)
		{
			PlaceCursor(j, i);
			cout << " ";
		}
	}
}

/**
 * Play the game against the computer in difficult mode.
 */
void play3()
{
	ifstream inputFile;
	string fileName;
	getline(cin, fileName);
	inputFile.open(fileName.c_str());
	int f = 0, b = 0;
	inputFile >> f >> b;
	inputFile.close();
	char arr[15][15];
	srand(time(NULL));
	bool player1 = true;
	bool computer = false;
	int hr = 0, min = 0, sec = 0;
	int p1score = f;
	int computerscore = b;
	char a;
	int x;
	int xdice;
	while (p1score != 100 || computerscore != 100)
	{
		for (hr = 0; hr < 24; hr++)
		{
			for (min = 0; min < 60; min++)
			{
				if (min % 5 == 0)
				{
					xdice = rand() % 2;
					if (xdice == 1)
					{
						swap(arr[1][1], arr[8][8]);
						swap(arr[5][8], arr[10][13]);
					}
				}
				for (sec = 0; sec < 60; sec++)
				{
					make_Board3(arr, p1score - 1, computerscore - 1);
					display3(arr, p1score, computerscore);
					hollow3();
					if (kbhit())
					{
						a = getch();
						if (a == 's')
						{
							ofstream inputFile;
							string fileName;
							cout << "Enter the file name: ";
							getline(cin, fileName);
							inputFile.open(fileName.c_str());
							inputFile << p1score << endl;
							inputFile << computerscore << endl;
						}
						else if (a == 'm')
						{
							system("CLS");
							mainmenu();
						}
						else
						{
							if (player1 == true)
							{
								Players1(x, player1, computer);
								x = rand() % 6 + 1;
								if (p1score + x <= 100)
								{
									p1score = p1score + x;
								}
								PlaceCursor(55, 12);
								PlaceCursor(100, 30);
								cout << "PLAYER ";
								PlaceCursor(101, 31);
								cout << "Score : " << p1score;
								if (p1score == 15)
								{
									p1score = 7;
								}
								else if (p1score == 61)
								{
									p1score = 141;
								}
								else if (p1score == 157)
								{
									p1score = 50;
								}
								else if (p1score == 221)
								{
									p1score = 71;
								}
								else if (p1score == 217)
								{
									p1score = 1;
								}
								else if (p1score == 17 && min % 5 == 0 && xdice == 1)
								{
									p1score = 129;
								}
								else if (p1score == 129 && min % 5 == 0 && xdice == 1)
								{
									p1score = 17;
								}
								if (p1score == 100)
								{
									cout << "PLAYER WON" << endl;
									exit(1);
								}
								if (x != 6)
								{
									swap(player1, computer);
								}
								Sleep(1500);
								PlaceCursor(55, 15);
							}
						}
					}
					else if (computer == true)
					{
						Players1(x, player1, computer);
						Sleep(1500);
						x = rand() % 6 + 1;
						if (computerscore + x <= 100)
						{
							computerscore = computerscore + x;
						}
						PlaceCursor(55, 12);
						PlaceCursor(55, 12);
						PlaceCursor(100, 30);
						cout << "COMPUTER";
						PlaceCursor(101, 31);
						cout << "Score : " << computerscore;
						if (computerscore == 15)
						{
							computerscore = 7;
						}
						else if (computerscore == 61)
						{
							computerscore = 141;
						}
						else if (computerscore == 157)
						{
							computerscore = 50;
						}
						else if (computerscore == 221)
						{
							p1score = 71;
						}
						else if (computerscore == 217)
						{
							computerscore = 1;
						}
						else if (computerscore == 17 && min % 5 == 0 && xdice == 1)
						{
							computerscore = 129;
						}
						else if (computerscore == 129 && min % 5 == 0 && xdice == 1)
						{
							computerscore = 17;
						}
						else if (computerscore == 100)
						{
							cout << "COMPUTER WON" << endl;
							exit(1);
						}
						if (x != 6)
						{
							swap(player1, computer);
						}
						Sleep(1500);
						PlaceCursor(55, 15);
					}
					if (min % 5 == 0)
					{
						int xdice = rand() % 2;
						if (xdice == 1)
						{
							swap(arr[1][1], arr[8][8]);
							swap(arr[5][5], arr[10][10]);
						}
					}
					PlaceCursor(115, 20);
					cout << "TIME ELAPSED";
					PlaceCursor(110, 23);
					cout << hr << ":" << min << ":" << sec;
					Sleep(1000);
				}
			}
		}
	}
}

/**
 * Display the main menu and provide options to start a new game, load a game, or access instructions.
 */
void mainmenu()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char arr[10][10];
	char c;
	cout << "****************************************" << endl;
	cout << "n) for start game" << endl;
	cout << "s) for save game" << endl;
	cout << "l) for load game" << endl;
	cout << "i) for instructions" << endl;
	cout << "a) for settings" << endl;
	cout << "****************************************" << endl;
	cin >> c;
	if (c == 'n')
	{
		char choice, g;
		cout << "****************************************" << endl;
		cout << "Choose the difficulty level" << endl;
		cout << "s) Computer mode" << endl;
		cout << "m) Multiplayer mode" << endl;
		cout << "****************************************" << endl;
		cin >> choice;
		if (choice == 's')
		{
			cout << "h) For easy mode" << endl;
			cout << "d) For difficult mode" << endl;
			cin >> g;
			if (g == 'h')
			{
				system("cls");
				make_Board1(arr, 1, 1);
				play1();
			}
			else if (g == 'd')
			{
				system("cls");
				make_Board3(arr, 1, 1);
				play3();
			}
		}
		else if (choice == 'm')
		{
			cout << "h) For easy mode" << endl;
			cout << "d) For difficult mode" << endl;
			cin >> g;
			if (g == 'h')
			{
				system("cls");
				make_Board(arr, 1, 1);
				play();
			}
			else if (g == 'd')
			{
				system("cls");
				make_Board2(arr, 1, 1);
				play2();
			}
		}
	}
	else if (c == 'l')
	{
		char choice, g;
		cout << "****************************************" << endl;
		cout << "Choose the difficulty level" << endl;
		cout << "s) Computer mode" << endl;
		cout << "m) Multiplayer mode" << endl;
		cout << "****************************************" << endl;
		cin >> choice;
		if (choice == 's')
		{
			cout << "h) For easy mode" << endl;
			cout << "d) For difficult mode" << endl;
			cin >> g;
			if (g == 'h')
			{
				int f, b;
				ifstream inputFile;
				string fileName;
				cout << "Enter the file name you want to open: ";
				getline(cin, fileName);
				inputFile.open(fileName.c_str());
				inputFile >> f;
				inputFile >> f;
				system("cls");
				make_Board1(arr, 1, 1);
				play1();
			}
			else if (g == 'd')
			{
				int f, b;
				ifstream inputFile;
				string fileName;
				cout << "Enter the file name you want to open: ";
				getline(cin, fileName);
				inputFile.open(fileName.c_str());
				inputFile >> f;
				inputFile >> f;
				system("cls");
				make_Board3(arr, 1, 1);
				play3();
			}
		}
		else if (choice == 'm')
		{
			cout << "h) For easy mode" << endl;
			cout << "d) For difficult mode" << endl;
			cin >> g;
			if (g == 'h')
			{
				int f, b;
				ifstream inputFile;
				string fileName;
				cout << "Enter the file name you want to open: ";
				getline(cin, fileName);
				inputFile.open(fileName.c_str());
				inputFile >> f;
				inputFile >> f;
				system("cls");
				make_Board(arr, 1, 1);
				play();
			}
			else if (g == 'd')
			{
				int f, b;
				ifstream inputFile;
				string fileName;
				cout << "Enter the file name you want to open: ";
				getline(cin, fileName);
				inputFile.open(fileName.c_str());
				inputFile >> f;
				inputFile >> f;
				system("cls");
				make_Board2(arr, 1, 1);
				play2();
			}
		}
	}
	else if (c == 'i')
	{
		cout << "a. Each player starts off the board at space 0." << endl;
		cout << "b. Decide who goes first by rolling a dice for each player." << endl;
		cout << "The player with the highest dice number will take the first turn." << endl;
		cout << "If both players get the same number, then roll the dice again." << endl;
		cout << "c. To take a turn, a player will roll a dice by pressing 'R'." << endl;
		cout << "Display the number rolled on the screen and move the game piece that many steps forward on the board." << endl;
		cout << "You should show the player's game piece moving on the board." << endl;
		cout << "d. Take an extra turn if you roll a six." << endl;
		cout << "First, move the game piece forward six squares and then roll the dice again." << endl;
		cout << "If you land on any snakes or ladders, follow the instructions to move up or down and then roll again to take an extra turn." << endl;
		cout << "As long as you keep rolling sixes, you can keep moving!" << endl;
		cout << "e. Land exactly on the last square to win." << endl;
		cout << "The first person to reach the highest square on the board wins, usually square 100." << endl;
		cout << "But there's a twist! If you roll too high, your piece bounces off the last square and moves back." << endl;
		cout << "You can only win by rolling the exact number needed to land on the last square." << endl;
		cout << "For example, if you are on square 99 and roll a four, move your game piece to 100 (one move), then bounce back to 99, 98, 97 (two, three, then four moves)." << endl;
		cout << "If square 97 is a ladder base or snake head, climb or slide as usual." << endl;
		cout << "f. If you fall through a trapdoor and find yourself at the head of a snake or the base of a ladder, the snake or ladder will have its normal effect." << endl;
		cout << "g. You may fall through more than one trapdoor if more than one is encountered in the same turn." << endl;
		cout << "h. At one time, a trapdoor can be in one of two states: Active or Dormant." << endl;
		cout << "After 5 minutes, toss a coin (using rand()) and if 1 comes, then switch the state of the trap door." << endl;
		cout << "i. A player will not fall through the same trapdoor more than once (even if it is active)." << endl;
		cout << "If you return to a trapdoor cell you have already fallen through, the cell will be treated as a normal space." << endl;
		mainmenu();
	}
}
/**
 * Display the start page with an introductory message and options to proceed.
 */
void startpage()
{
	char ch;
	system("color 7C");
	cout << "           \n\n          +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "            ***** *     * ***** *   *  *****     *     ***** ***** ***** ***** *****      " << endl;
	cout << "            *     * *   * *   * *  *   *         *     *   * *   * *   * *     *   *       " << endl;
	cout << "            ***** *  *  * ***** ***    ****      *     ***** *   * *   * ****  *****       " << endl;
	cout << "                * *   * * *   * *  *   *         *     *   * *   * *   * *     * *        " << endl;
	cout << "            ***** *     * *   * *    * *****     ***** *   * ***** ***** ***** *   *      " << endl;
	cout << "\n\n\t        +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "\n\t PROGRAMMED BY: " << endl;
	cout << "\n\t\t  SHAHBAZ ";
	Sleep(300);
	cout << " ";
	Sleep(300);
	Sleep(300);
	cout << " ";
	Sleep(300);
	cout << "RAZA" << endl;
	cout << "\n\t\t\t GAME STARTING";
	for (int i = 0; i < 4; i++)
	{
		Sleep(600);
		cout << ".";
	}
	cout << endl;
	cout << "ENTER m for main menu" << endl;
	cout << "ENTER e for exit" << endl;
	cin >> ch;
	if (ch == 'm')
	{
		system("cls");
		system("color 7C");
		mainmenu();
	}
	else if (ch == 'e')
	{
		exit(1);
	}
}
int main()
{
	char arr[10][10];
	char arr1[15][15];
	int n1, n2;
	startpage();
	PlaceCursor(50, 50);
	cout << " ";
}
