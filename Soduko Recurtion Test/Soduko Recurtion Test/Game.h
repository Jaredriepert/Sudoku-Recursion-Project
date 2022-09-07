#ifndef GAME_H_
#define GAME_H_
#include "Board.h"
class Game
{
private:
	Board completeBoard;
	Board playerBoard;
public:
	Game();
	~Game();
	void GenBoard();
	void SetBoard();
	void SolveBoard();
	void SolvePlayer();
	void PrintComplete();
	void PrintPlayers();
	void SetPlayerBoard(int num);
	void Input();
};
#endif // !GAME_H_

