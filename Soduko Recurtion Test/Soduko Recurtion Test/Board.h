#ifndef BOARD_H_
#define BOARD_H_
#include "Box.h"
class Board : public Box
{
private:
	Box tiles[9][9];
public:
	Board();
	~Board();
	void PrintComplete();
	int RandNum();	
	bool CheckRow(int num, int row, int col);
	bool CheckCol(int num, int row, int col);
	bool CheckBox(int num, int row, int col);
	bool SetTile(int row, int col);
	bool Solve(int row, int col,int direction = 1);
	void SetBoard();
	void CopyBoard(Board a);
	void DeleteBoxes(int num);
	void EditBox(int x, int y, int num);
};
#endif // !BOARD_H_

