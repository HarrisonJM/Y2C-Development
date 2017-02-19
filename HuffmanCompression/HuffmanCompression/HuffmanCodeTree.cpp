#include "HuffmanCodeTree.h"

HuffmanCodeTree::HuffmanCodeTree()
{
}

HuffmanCodeTree::HuffmanCodeTree(std::vector<std::pair<char, int>>* freqs)
{
	PQ = new std::priority_queue<node*, std::vector<node*>, nodeCmp>; //dynamic priority queue
	std::vector<std::pair<char, int>>::iterator iter;

	for (iter = freqs->begin(); iter != freqs->end(); ++iter)
	{
		node* tn = new node; //temp node
		tn->_code = "";
		tn->_freq = iter->second;
		tn->_symbol = iter->first;
		tn->_left = NULL;
		tn->_right = NULL;

		PQ->push(tn); //calling pop() will delete the node
	}

	BuildTree();
	BuildHuffmanCode(root, "");

	delete freqs;
}

HuffmanCodeTree::~HuffmanCodeTree()
{
}

void HuffmanCodeTree::BuildHuffmanCode(node* leaf, std::string code)
{
	if (leaf != NULL)
	{
		if (leaf->_left != NULL) //left is 0
		{
			code += '0';
			BuildHuffmanCode(leaf->_left, code);
		}

		if (leaf->_right != NULL)
		{
			code += '1';
			BuildHuffmanCode(leaf->_right, code);
		}

		if (leaf->_left == NULL && leaf->_right == NULL)
		{
			leaf->_code = code;
		}
	}

	return;
}

void HuffmanCodeTree::BuildTree()
{
	while (PQ->size() > 1)
	{
		node* tn = new node;
		node* tn2 = new node;
		node* leaf = new node;

		tn = PQ->top();	
		PQ->pop();

		tn2 = PQ->top();
		PQ->pop();

		leaf->_left = tn;
		leaf->_right = tn2;
		leaf->_freq = tn2->_freq + tn->_freq;

		PQ->push(leaf);
	}

	root = new node;

	root = PQ->top();
	PQ->pop();

	delete PQ;
}
