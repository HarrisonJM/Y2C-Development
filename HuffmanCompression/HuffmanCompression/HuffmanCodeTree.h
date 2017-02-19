#pragma once

#include <queue>
#include "BinTree.h"

struct nodeCmp
{
	bool operator()(const node* a, const
		node* b)
	{
		return a->_freq > b->_freq; //sorts with highest frequency first
	}
};

class HuffmanCodeTree
{
private:
	//variables
	std::priority_queue<node*, std::vector<node*>, nodeCmp> *PQ;	
	node* root;

	//methods
	void BuildTree();

public:

	HuffmanCodeTree();
	HuffmanCodeTree(std::vector<std::pair<char, int>>* freqs);

	~HuffmanCodeTree();

	void BuildHuffmanCode(node * leaf, std::string code);

};
