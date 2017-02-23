#include "HuffmanCodeTree.h"

HuffmanCodeTree::HuffmanCodeTree()
{
}

/// <summary>
/// Constructor for HuffmanCodeTree. Builds the entire huffman binary tree and then
/// fills the end nodes with their respetive huffman codes
/// </summary>
/// <param name="freqs"></param>
HuffmanCodeTree::HuffmanCodeTree(std::vector<std::pair<char, int>>* freqs)
{
	PQ = new std::priority_queue<node*, std::vector<node*>, nodeCmp>; //dynamic priority queue
	std::vector<std::pair<char, int>>::iterator iter;

	for (iter = freqs->begin(); iter != freqs->end(); ++iter) //Iterate over vector and fill priority queue
	{
		node* tn = new node; //temp node
		tn->_code = "";
		tn->_freq = iter->second;
		tn->_symbol = iter->first;
		tn->_left = NULL;
		tn->_right = NULL;

		PQ->push(tn); //calling pop() will delete the node
	}

	m_BuildTree();
	m_BuildHuffmanCode(root, "");

	delete freqs;
}

HuffmanCodeTree::~HuffmanCodeTree()
{
	delete root; //node has a destructor
}

/// <summary>
/// Builds huffman code from the tree built earlier.
/// Must be supplied with a blank string or ""
/// </summary>
/// <param name="leaf"></param>
/// <param name="code"></param>
void HuffmanCodeTree::m_BuildHuffmanCode(node* leaf, std::string code)
{
	if (leaf != NULL)
	{
		if (leaf->_left != NULL) //left is 0
		{
			code += '0'; //add 0 if going left
			m_BuildHuffmanCode(leaf->_left, code);
		}

		if (leaf->_right != NULL)
		{
			code.pop_back(); //pop off last character due to recursion
			code += '1'; //1 for going right

			m_BuildHuffmanCode(leaf->_right, code);
		}

		if (leaf->_left == NULL && leaf->_right == NULL)
		{
			leaf->_code = code; //When the end node is reached, set its code to that gathered
		}
	}

	return;
}

/// <summary>
/// Builds the Huffman tree using the priority queue
/// </summary>
void HuffmanCodeTree::m_BuildTree()
{
	while (PQ->size() > 1)
	{
		node* tn = new node;
		node* tn2 = new node; //temp nodes

		node* leaf = new node; //new node

		tn = PQ->top();	
		PQ->pop(); //can only access other items in queue from the front
													  
		tn2 = PQ->top();							  
		PQ->pop();									  
		
		//The first item taken off the top of the queue is always the lowest, so no checkign is needed
		//in the case of equal frequencies, no preference
		leaf->_left = tn;							  
		leaf->_right = tn2;							  
		leaf->_freq = tn2->_freq + tn->_freq; //Add frequencies together for new node
		
		PQ->push(leaf); //push new node into queue to be sorted and placed
	}

	root = new node;

	//Last node is the root
	root = PQ->top();
	PQ->pop();

	//No longer needed
	delete PQ;
}

/// <summary>
/// Outward facing method
/// </summary>
void HuffmanCodeTree::PrintCodeTree()
{
	if (root->_left == NULL && root->_right == NULL)
	{
		std::cout << "Tree is empty!" << std::endl;
	}
	else
	{
		m_Traverse(root, 0);
	}
}

/// <summary>
/// Method used to actually traverse tree
/// </summary>
/// <param name="leaf"></param>
/// <param name="indent"></param>
void HuffmanCodeTree::m_Traverse(node* leaf, int indent = 0)
{
	if (leaf != NULL)
	{
		if (leaf->_right) //Traverse right side
		{
			m_Traverse(leaf->_right, indent + 4);
		}

		if (indent)
		{
			std::cout << std::setw(indent) << ' '; //pad with indent amount of spaces
		}

		if (leaf->_right)
		{
			std::cout << " /\n" << std::setw(indent) << ' '; //insert / for the left leaf
		}

		std::cout << leaf->_code << "\n "; //print frequency

		if (leaf->_left)  //traverse left
		{
			std::cout << std::setw(indent) << ' ' << " \\\n";
			m_Traverse(leaf->_left, indent + 4);
		}
	}
}
