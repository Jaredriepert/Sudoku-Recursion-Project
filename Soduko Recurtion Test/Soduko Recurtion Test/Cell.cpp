#include "Cell.h"
Cell::Cell()
{
	holding = 0;
}
Cell::~Cell()
{

}
void Cell::SetHolding(int num)
{
	holding = num;
}
int Cell::GetHolding() const
{
	return holding;
}