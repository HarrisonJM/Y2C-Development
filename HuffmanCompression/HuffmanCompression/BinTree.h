#pragma once

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>

/// <summary>
/// the node struct that is used for building the binary tree
/// </summary>
struct node
{
	node* _left;
	node* _right;
	int _freq;
	char _symbol;
	std::string _code;

	~node()
	{
		if (_left != NULL)
		{
			delete _left;
		}

		if (_right != NULL)
		{
			delete _right;
		}
	}
};

/// <summary>
/// BinTree Class for task 2
/// </summary>
class BinTree
{
private:
	//Variables
	node * RootNode;
	std::vector<node*>* list;

	//methods
	void m_print(node * p, int indent);

public:
	//Constructos/destructors
	BinTree(std::vector<std::pair<char, int>>* freqs); //requires fequencies to be passed in
	~BinTree();

	//methods
	node* Merge(node *n1, node *n2); //Merges two subtrees, takes two node paramters and creates a new Node which points to the two existing node	
	node * SetRootNode(node * n1, node * n2);
	void PrintTree(); //Prints the Node Tree	
};