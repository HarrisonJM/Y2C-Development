#pragma once


class Cell
{
private:
	int cellVal;
	int x;
	int y;
	int possVal[8];

public:
	Cell();
	~Cell();

	Cell(int xpos, int ypos, int val);

	int getCellVal();
	void setCellVal(int val);

	void AddPossVal(int val);
	void RemovePossVal(int val);
	int* ReturnPossVal();
};