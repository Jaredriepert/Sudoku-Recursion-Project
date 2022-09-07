#include "Game.h"
#include "Board.h"
#include <iostream>
#include <string>
using namespace std;
Game::Game()
{

}
Game::~Game()
{

}
void Game::GenBoard()
{
	cout << "Generating board..." << endl;
	completeBoard.SetTile(0,0);
}
void Game::PrintComplete()
{
	completeBoard.PrintComplete();
}
void Game::SolveBoard()
{
	completeBoard.Solve(0,0);
}
void Game::SolvePlayer()
{
	playerBoard.Solve(0,0);
}
void Game::SetBoard()
{
	completeBoard.SetBoard();
}
void Game::PrintPlayers()
{
	playerBoard.PrintComplete();
}
void Game::SetPlayerBoard(int num)
{
	playerBoard.CopyBoard(completeBoard);
	playerBoard.DeleteBoxes(num);
}
void Game::Input()
{
	
	int x = 0;
	int y = 0;
	int num = 0;
	while (true)
	{
		x = 0;
		y = 0;
		num = 1;
		cout << "Please enter a cordinate and then a number to put there. ex. x y number: 2 5 4, enter 0 0 0 to to submit work" << endl << "enter: ";
		cin >> x;
		cin >> y;
		cin >> num;
		if (num >> 0 && num << 10)
		{
			playerBoard.EditBox(y-1,x-1, num);
		}
		else if(x == 0 && y == 0 && num == 0)
		{
			//finish here
		}
		else
		{
			cout << "That number is invalid, must be a number between 1-9" << endl;
		}
	}
}