#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
using std::endl;
// definition global variables
const char PLAYER_1 = 'X';
const char PLAYER_2 = 'O';
const int MAX_SIZE = 3;
int Position;
char Game[MAX_SIZE][MAX_SIZE];
bool turn = 0, playWith, winner = 0;

// start of the functions 
// this function initialize the game 
void start_game()
{
	int num = 1;
	cout << "Welcome to Tic Tac Toe !\n";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			Game[i][j] = num + '0';
			num++;
		}
	}
}
// print the board 
void Print()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		cout << " ";
		for (int j = 0; j < MAX_SIZE; ++j)
		{
			cout << " " << Game[i][j] << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}

// checker function check if there is a winner or not
void check(int& r, int& colum)
{
	int sum1 = 0, sum22 = 0, sum23 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0, sum7 = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (Game[r][i] == 'X')
			sum1++;
		if (Game[i][colum] == 'X')
			sum22++;
		if (Game[r][i] == 'O')
			sum2++;
		if (Game[i][colum] == 'O')
			sum23++;
		if (Game[i][i] == 'X')
			sum4++;
		if (Game[i][i] == 'O')
			sum5++;
		if (Game[i][MAX_SIZE - i - 1] == 'X')
			sum6++;
		if (Game[i][MAX_SIZE - i - 1] == 'O')
			sum7++;
	}
	if (sum1 == MAX_SIZE || sum4 == MAX_SIZE || sum6 == MAX_SIZE || sum22 == MAX_SIZE) {
		cout << "Player X is the winner .\n";
		winner = true;
	}
	else if (sum2 == MAX_SIZE || sum5 == MAX_SIZE || sum7 == MAX_SIZE || sum23 == MAX_SIZE) {
		cout << "Player O is the winner .\n";
		winner = true;
	}
	else {
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			for (int j = 0; j < MAX_SIZE; ++j)
			{
				if (Game[i][j] == 'X' || Game[i][j] == 'O')
					sum3++;
				else
					return;
			}
		}
		if (sum3 == 9)
			cout << "It's a tie .\n";
	}
}
// level one playing with the computer 
void playWithComputer()
{
	int row, column;
	char choice = '2';
	bool l = 0;
	cout << "Enter 1 for \" x\" or 0 for \"O\"::";
	bool x_or_o = true;
	while (choice != '1' && choice != '0')
	{
		cin >> choice;
		if (choice == '1')
			x_or_o = true;
		else if (choice == '0')
			x_or_o = false;
		else
			cout << "Error enter 1 or 0.\n";
	}
	if (x_or_o)
	{
		turn = 0;
		l = 1;
	}
	else
		turn = 1;

	while (!winner) {
		if (turn)
		{
			for (int i = 0; (i < MAX_SIZE) && turn; i++)
			{
				for (int j = 0; (j < MAX_SIZE) && turn; j++)
				{
					if (Game[i][j] != 'X' && Game[i][j] != 'O') {
						row = i;
						column = j;
						if (l)
							Game[row][column] = PLAYER_2;
						else
							Game[row][column] = PLAYER_1;
						turn = 0;
						Print();
						check(row, column);
					}
				}
			}
		}
		else if (!turn)
		{
			cout << "Enter the position:: ";
			cin >> Position;
			row = (Position - 1) / MAX_SIZE;
			column = (Position - 1) % MAX_SIZE;
			if (Game[row][column] != 'X' && Game[row][column] != 'O' && row <= 2 && column <= 2) {

				if (l)
					Game[row][column] = PLAYER_1;
				else
					Game[row][column] = PLAYER_2;
				turn = 1;
				check(row, column);
			}
			else
				cout << "error enter a valid number in the board.\n";
		}

	}
}
// the logic function that deal with the flow of the game who playes first and the way of the game 
void logic()
{
	int row, column;
	cout << "Enter 1 to play with player or 0 play with computer:: ";
	cin >> playWith;
	if (playWith) {
		cout << "\n";
		char choice = '2';
		cout << "Enter 1 for \" x\" or 0 for \"O\"::";
		bool x_or_o = true;
		while (choice != '1' && choice != '0')
		{
			cin >> choice;
			if (choice == '1')
				x_or_o = true;
			else if (choice == '1')
				x_or_o = false;
			else
				cout << "Error enter 1 or 0.\n";
		}
		if (x_or_o)
			turn = 0;
		else
			turn = 1;
	}
	while (!winner) {
		if (playWith)
		{

			cout << "Enter the position:: ";
			cin >> Position;
			row = (Position - 1) / MAX_SIZE;
			column = (Position - 1) % MAX_SIZE;
			if (row <= 2 && column <= 2) {
				if (turn && Game[row][column] != 'X' && Game[row][column] != 'O')
				{
					Game[row][column] = PLAYER_2;
					turn = 0;
				}
				else if (!turn && Game[row][column] != 'X' && Game[row][column] != 'O')
				{
					Game[row][column] = PLAYER_1;
					turn = 1;
				}
				else
					cout << "\nError enter a valid number.\n";
			}
			else
				cout << "error enter a valid number in the board.\n";
		}
		else if (!playWith)
		{
			playWithComputer();
		}
		else
			cout << "Please Enter 1 for two player or 0 for 1 player versus computer.\n";
		Print();
		check(row, column);
	}
}
// this function is the game function it doesn't do any thing it just do the thing that the main function do we can remove it and take all the code on it and put them in the main function 
void Play()
{
	bool want = 1;
	while (want)
	{
		start_game();
		Print();
		logic();
		cout << "Enter 1 to repeat the game and 0 to stop the game.\n";
		cin >> want;
		winner = 0;
	}
	cout << "Thank you for playing with us.\n";
}
// the main function 
int main()
{
	Play();
	return 0;
}