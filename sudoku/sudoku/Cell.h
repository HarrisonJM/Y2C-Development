#pragma once


class Cell
{
private:
	int cellVal;
	int possVal[8];

public:
	Cell();
	~Cell();

	int getCellVal();
	void setCellVal(int val);

	void AddPossVal(int val);
	void RemovePossVal(int val);
	int* ReturnPossVal();

};