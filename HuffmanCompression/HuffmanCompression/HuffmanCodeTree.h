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
/// Description:	Takes a vector of pairs of char, int and generates a series of huffman codes for compression
/// Constructors:	std::vector<std::pair<char, int>>* freqs
/// </summary>
class HuffmanCodeTree
{
private:
	//variables
	std::priority_queue<node*, std::vector<node*>, nodeCmp> *PQ;	
	node* root;

	//methods
	void m_BuildTree();
	void m_Traverse(node* leaf, int indent);
	void m_BuildHuffmanCode(node * leaf, std::string code);

public:
	//Constructors/destructors
	HuffmanCodeTree();
	HuffmanCodeTree(std::vector<std::pair<char, int>>* freqs);

	~HuffmanCodeTree();

	//Methods
	void PrintCodeTree();
};
