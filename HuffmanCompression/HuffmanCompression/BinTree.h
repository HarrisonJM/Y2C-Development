#pragma once

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>

struct node
{
	node* _left;
	node* _right;
	int _freq;
	char _symbol;
	std::string _code;
};

class BinTree
{
private:
	node * RootNode;
	std::vector<node*>* list;

	void m_print(node * p, int indent);

public:
	BinTree(); //Default

	BinTree(std::vector<std::pair<char,int>>* freqs); //requires fequencies to be passed in

	~BinTree();

	node* Merge(node *n1, node *n2); //Merges two subtrees, takes two node paramters and creates a new Node which points to the two existing node	
	node * SetRootNode(node * n1, node * n2);
	void PrintTree(); //Prints the Node Tree	
};