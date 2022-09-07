#include "Box.h"
#include <iostream>
using namespace std;
Box::Box()
{
	history = 0;
	past[9] = { 0 };
	hardSet = false;
}
Box::Box(int num)
{
	SetHolding(num);
	history = 0;
	past[9] = { 0 };
	if (num != 0)
	{
		hardSet = true;
	}
	else
	{
		hardSet = false;
	}
}
Box::~Box()
{

}
bool Box::GetHardSet() const
{
	return hardSet;
}
int Box::GetPast(int index) const
{
	return past[index];
}
int Box::GetHistory() const
{
	return history;
}
void Box::ResetHistory()
{
	history = 0;
	for (int i = 0; i < 10; i++)
	{
		past[i] = 0;
	}
}
void Box::SetPast(int num)
{
	past[history] = num;
	history++;
}
void Box::SetHardSet(bool b)
{
	hardSet = b;
}
void Box::Print()
{
	cout << GetHolding();
}
void Box::PrintPast() const
{
	for (int i = 0; i < 9; i++)
	{
		cout << past[i] << ", ";
	}
	cout << endl;
}