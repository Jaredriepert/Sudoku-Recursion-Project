#ifndef BOX_H_
#define BOX_H_
#include "Cell.h"
class Box : public Cell
{
private:
	int past[10];
	int history;
	bool hardSet;
public:
	Box();
	Box(int);
	~Box();
	int GetPast(int) const;
	int GetHistory() const;
	bool GetHardSet() const;
	void PrintPast() const;
	void SetHardSet(bool);
	void ResetHistory();
	void SetPast(int);
	void Print();
};
#endif // !BOX_H_
