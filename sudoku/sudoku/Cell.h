#pragma once


class Cell
{
private:
	int cellVal;
	int xpos;
	int ypos;

public:
	Cell();
	~Cell();

	Cell(int val);
	Cell(int x, int y);

	int getCellVal();
	void setCellVal(int val);

	int getxPos();
	void setxPos(int x);
	int getyPos();
	void setypos(int y);


	int* ReturnPossVal();
};