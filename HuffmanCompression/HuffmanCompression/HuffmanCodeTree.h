#pragma once

#include <queue>
#include "BinTree.h"

/// <summary>
/// Struct used to store a functor for use in the pirority queue
/// </summary>
struct nodeCmp
{
	bool operator()(const node* a, const node* b)
	{
		return a->_freq > b->_freq; //sorts with highest frequency first
	}
};

/// <summary>
/// Class:			HuffmanCodeTree
/// Description:	Takes a vector<pair<char, int> and generates a series of huffman codes for compression
/// Constructors:	std::vector<std::pair<char, int>>* freqs
/// </summary>
class HuffmanCodeTree
{
private:
	//variables
	std::priority_queue<node*, std::vector<node*>, nodeCmp> *PQ;	
	node* root;

	//methods
	void BuildTree();
	void traverse(node* leaf, int indent);
	void BuildHuffmanCode(node * leaf, std::string code);

public:

	HuffmanCodeTree();
	HuffmanCodeTree(std::vector<std::pair<char, int>>* freqs);

	~HuffmanCodeTree();
	void PrintCodeTree();
};
