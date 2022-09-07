#include "Board.h"
#include <iostream>
#include <stdlib.h>
#include <random>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;
Board::Board()
{

}
void Board::SetBoard()
{

	string line;
	string temp;
	int num;
	int col = 0;
	int row = 0;
	stringstream ss;
	ifstream myfile("DataSheet.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			ss.clear();
			ss << line;
			while (!ss.eof())
			{
				ss >> temp;
				if (stringstream(temp) >> num)
				{
					tiles[row][col].SetHolding(num);
					if (num != 0)
					{
						tiles[row][col].SetHardSet(true);
					}
					col++;
				}
			}
			if (line != "---------------------")
			{
				col = 0;
				row++;
			}			
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}
Board::~Board()
{

}
int Board::RandNum()
{
	//static int totalCount = 0;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(1, 9);
	//totalCount++;
	int num = distribution(generator);
	//cout << num << endl;
	return num;
	/*
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1,9);
	return dis(gen);
	*/
}
void Board::PrintComplete()
{
	system("CLS");
	cout << "   1 2 3   4 5 6   7 8 9" << endl;
	for (int row = 0; row < 9; row++)
	{
		if (row % 3 == 0)
		{
			cout << "  ----------------------" << endl;
		}
		cout << row + 1 << "";
		for (int col = 0; col < 9; col++)
		{
			if (col % 3 == 0)
			{
				cout << "| ";
			}
			if (tiles[row][col].GetHolding() == 0)
			{
				cout << " ";
			}
			else
			{
				tiles[row][col].Print();
			}
			cout << " ";
		}
		cout << endl;
	}
}
bool Board::CheckRow(int num, int row, int col)
{
	for (int x = 0; x < 9; x++)
	{
		if (num == tiles[row][x].GetHolding())
			return false;
	}
	return true;
}
bool Board::CheckCol(int num, int row, int col)
{
	for (int x = 0; x < 9; x++)
	{
		if (num == tiles[x][col].GetHolding())
			return false;
	}
	return true;

}
bool Board::CheckBox(int num, int row, int col)
{
	//box 1
	if (row < 3 && col < 3)
	{
		//cout << "CHECKING BOX 1" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (num == tiles[i][j].GetHolding())
				{
					return false;
				}
			}

		}
	}
	//box 2
	else if (row < 3 && col > 2 && col < 6)
	{
		//cout << "CHECKING BOX 2" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (num == tiles[i][j].GetHolding())
				{
					return false;
				}
			}

		}
	}
	//box 3
	else if (row < 3 && col > 5 && col < 9)
	{
		//cout << "CHECKING BOX 3" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (num == tiles[i][j].GetHolding())
				{
					return false;
				}
			}

		}
	}
	//box 4
	else if (row > 2 && row < 6 && col < 3)
	{
		//cout << "CHECKING BOX 4" << endl;
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (num == tiles[i][j].GetHolding())
				{
					return false;
				}
			}

		}
	}
	//box 5
	else if (row > 2 && row < 6 && col > 2 && col < 6)
	{
		//cout << "CHECKING BOX 5" << endl;
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (num == tiles[i][j].GetHolding())
				{
					return false;
				}
			}

		}
	}
	//box 6
	else if (row > 2 && row < 6 && col > 5 && col < 9)
	{
		//cout << "CHECKING BOX 6" << endl;
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (num == tiles[i][j].GetHolding())
				{
					return false;
				}
			}

		}
	}
	//box 7
	else if (row > 5 && row < 9 && col < 3)
	{
		//cout << "CHECKING BOX 7" << endl;
		for (int i = 6; i < 9; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (num == tiles[i][j].GetHolding())
				{
					return false;
				}
			}

		}
	}
	//box 8
	else if (row > 5 && row < 9 && col > 2 && col < 6)
	{
	//cout << "CHECKING BOX 8" << endl;
		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (num == tiles[i][j].GetHolding())
				{
					return false;
				}
			}

		}
	}
	//box 9
	else if (row > 5 && row < 9 && col > 5 && col < 9)
	{
	//cout << "CHECKING BOX 9" << endl;
		for (int i = 6; i < 9; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (num == tiles[i][j].GetHolding())
				{
					return false;
				}
			}

		}
	}
	return true;
}
bool Board::SetTile(int rowNum, int colNum)
{
	//advance position
	int row = rowNum;
	int col = colNum;
	if (col > 8)
	{
		col = 0;
		row++;
	}
	if (col < 0)
	{
		col = 8;
		row--;
	}
	//base case
	if (row < 0)
	{
		cout << "Generating failed, went outside of board" << endl;
		return false;
	}
	if (row == 9)
	{
		//cout << "done" << endl;
		return true;
	}	
	
	int used[9] = { 0 };
	bool numGood = true;
	bool boxFailed = false;
	//every box can be anything from 1-9 which is 9 possibilies so every box gets 9 tries to find a number, however a box might have been
	//something in the past that it can't be again therefor every box has (9 - history) tries to find a number
	int maxTries = 9 - tiles[row][col].GetHistory();
	for (int x = 0; x < maxTries+1; x++)
	{
		if (x == maxTries)
		{
			boxFailed = true;
			break;
		}
		//cout << x << endl;
		int num = 0;
		bool tryAgain = true;
		while (tryAgain)
		{
			num = RandNum();
			//cout << "Trying rand num " << num << endl;
			int index = 0;
			for (index = 0; index < 9; index++)
			{
				//the random number choosen can not have been already tried in both here or in the past
				if (num == used[index] || num == tiles[row][col].GetPast(index))
				{
					break;
				}
			}
			if (index == 9)
			{
				tryAgain = false;
			}
		}
		numGood = true;
		used[x] = num;
		if (!CheckRow(num, row, col))
		{
			numGood = false;
			//cout << "failed row check" << endl;
		}
		if (!CheckCol(num, row, col))
		{
			numGood = false;
			//cout << "failed col check" << endl;
		}
		if (!CheckBox(num, row, col))
		{
			numGood = false;
			//cout << "failed box check" << endl;
		}
		if (numGood)
		{
			tiles[row][col].SetHolding(num);
			tiles[row][col].SetPast(num);
			//PrintComplete();
			return SetTile(row, ++col);
		}		
	}	
	if(boxFailed)
	{
		//cout << "one failed go back" << endl;
		tiles[row][col].SetHolding(0);
		tiles[row][col].ResetHistory();
		return SetTile(row, --col);
	}
}
bool Board::Solve(int rowNum, int colNum,int direction)
{
	//advance position
	int row = rowNum;
	int col = colNum;
	if (col > 8)
	{
		col = 0;
		row++;
	}
	if (col < 0)
	{
		//cout << "Went back a row " << tiles[row][col].GetHolding() << endl;
		col = 8;
		row--;
	}
	//base case
	if (row < 0)
	{
		cout << "Solving failed, went outside of board" << endl;
		return false;
	}
	if (row == 9)
	{
		//cout << "done" << endl;
		return true;
	}
	if (tiles[row][col].GetHardSet() == true )
	{
		//cout << tiles[row][col].GetHolding() << endl;
		if (row == 0 && col == 0)
		{
			return Solve(row, ++col, 1);
		}
		if (direction == 1)
		{
			return Solve(row, ++col, 1);
		}
		else if (direction == 2)
		{
			return Solve(row, --col, 2);
		}
	}
	//int used[9] = { 0 };
	bool numGood = true;
	bool boxFailed = false;
	//every box can be anything from 1-9 which is 9 possibilies so every box gets 9 tries to find a number, however a box might have been
	//something in the past that it can't be again therefor every box has (9 - history) tries to find a number
	//int maxTries = 9 - tiles[row][col].GetHistory();
	for (int x = 1; x <= 10 ; x++)
	{
		//cout << x << endl;
		numGood = true;
		if (x == 10)
		{
			//cout << "out of tries" << endl;
			boxFailed = true;
			break;
		}
		//cout << num << endl;
		//cout << endl;
			for (int index = 0; index < 9; index++)
			{
				//the number choosen can not have been already tried in the past
				//cout << tiles[row][col].GetPast(index) << ": ";
				if (x == tiles[row][col].GetPast(index))
				{
				//	cout << "already tried" << endl;
					numGood = false;
					break;
				}
			}
			//cout << endl;
			//cout << numGood << endl;
			if (numGood)
			{
				if (!CheckRow(x, row, col))
				{
					numGood = false;
				}
				if (!CheckCol(x, row, col))
				{
					numGood = false;
				}
				if (!CheckBox(x, row, col))
				{
					numGood = false;
				}
				if (numGood)
				{
					tiles[row][col].SetHolding(x);
					tiles[row][col].SetPast(x);
					//PrintComplete();
					//cout << "and move on" << endl;
					
					return Solve(row, ++col, 1);
				}
			}
			//cout << x << endl;
	}
	if (boxFailed)
	{
		//cout << "Yup failed" << endl;
		tiles[row][col].SetHolding(0);
		tiles[row][col].ResetHistory();
		return Solve(row, --col, 2);
	}
	cout << "ummm: "<<boxFailed << endl;
}
void Board::CopyBoard(Board a)
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			tiles[row][col].SetHolding(a.tiles[row][col].GetHolding());
			if (tiles[row][col].GetHolding() != 0)
			{
				tiles[row][col].SetHardSet(true);
			}
			else {
				tiles[row][col].SetHardSet(false);
			}
		}
	}
}
void Board::DeleteBoxes(int num)
{
	int deleteCount = 0;
	int difficulty = num * 10;
	while (deleteCount < 64 && deleteCount < difficulty)
	{
		int randX = RandNum() - 1;
		int randY = RandNum() - 1;
		if (tiles[randX][randY].GetHolding() != 0)
		{
			tiles[randX][randY].SetHolding(0);
			tiles[randX][randY].SetHardSet(false);
			++deleteCount;
		}
	}
}
void Board::EditBox(int x, int y, int num)
{
	if (tiles[x][y].GetHardSet() == true)
	{
		cout << "Sorry this spot is holding something" << endl;
	}
	else
	{
		tiles[x][y].SetHolding(num);
		PrintComplete();
	}
}