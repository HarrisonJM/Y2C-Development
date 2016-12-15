#pragma once


class Cell
{
private:
	int cellVal;

public:
	Cell();
	~Cell();

	Cell(int val);

	int getCellVal();
	void setCellVal(int val);

	int* ReturnPossVal();
};