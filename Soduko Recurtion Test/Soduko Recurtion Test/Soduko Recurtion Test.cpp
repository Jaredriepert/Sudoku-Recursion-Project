#include <iostream>
#include "Game.h"
#include "Board.h"
using namespace std;
int main()
{
	Game game;	
	cout << "Welcome to Sidiko!" << endl;
	cout << "Do you wnat to play or do you have a board to solve?" << endl;
	cout << "(1) - Play!" << endl << "(2) - Solve!" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Alright lets PLAY!" << endl;
		cout << "Please select a difficulty level" << endl;
		cout << "(1) - Very Easy" << endl << "(2) - Still Easy" << endl << "(3) - Normal" << endl << "(4) - Good Choice" << endl << "(5) - Hard" << endl << "(6) - Very Hard" << endl << "(7) - Possibly Impossible" << endl;
		int difficulty = 0;
		cin >> difficulty;
		game.GenBoard();
		game.PrintComplete();
		cout << endl;
		game.SetPlayerBoard(difficulty);
		game.PrintPlayers();
		game.Input();
	}
	if (choice == 2)
	{
		game.SetBoard();
		game.SolveBoard();
		game.PrintComplete();
	}
	return 0;
}