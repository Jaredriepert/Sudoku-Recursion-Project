#ifndef CELL_H_
#define CELL_H_
using namespace std;
class Cell
{
private:
	int holding;
public:
	Cell();
	~Cell();
	virtual void Print() = 0;
	int GetHolding() const;
	void SetHolding(int);
};
#endif // !CELL_H_
