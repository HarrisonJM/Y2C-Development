#pragma once

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

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

public:
	BinTree(); //Default

	BinTree(std::vector<std::pair<char,int>>* freqs); //requires fequencies to be passed in

	~BinTree();

	node Merge(node &n1, node &n2); //Merges two subtrees, takes two node paramters and creates a new Node which points to the two existing node	
	node SetRootNode(node &n1, node &n2); //Sets the root node.
	void PrintTree(); //Prints the Node Tree
	void preorderPrint(node * root);
	void postorderPrint(node * root);
};