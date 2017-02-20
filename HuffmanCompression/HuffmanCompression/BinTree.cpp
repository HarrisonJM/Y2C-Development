#include "BinTree.h"

using namespace std;

/// <summary>
/// Operation Functor used for sort() function
/// </summary>
/// <param name="i"></param>
/// <param name="j"></param>
/// <returns></returns>
bool compare(const node *i, const node *j)
{
	return i->_freq > j->_freq;
}

/// <summary>
/// Main constructor for BinaryTree, takes a pointer to a vector of pairs of char, int
/// Constructs the entire Binary tree using the vector it is given
/// </summary>
/// <param name="freqs">std::vector<std::pair<char, int>>*</param>
BinTree::BinTree(std::vector<std::pair<char, int>>* freqs)
{
	//Variables
	list = new std::vector<node*>;
	RootNode = new node;

	//iterators
	std::vector<std::pair<char, int>>::iterator it;	

	for (it = freqs->begin(); it != freqs->end(); ++it) //Fill up all nodes
	{
		//temporary nodes
		node *initnode = new node;
		//initilise temporary nodes
		initnode->_left = NULL;
		initnode->_right = NULL;
		initnode->_code = "";

		//Fill temporary nodes, with symbols and frequencies
		initnode->_freq = it->second;
		initnode->_symbol = it->first;
		
		list->push_back(initnode);

		//delete initnode;
	}

	std::vector<node*>::reverse_iterator iter, itersp; //end node iterators

	while (list->size() > 2)
	{
		node *tempnode = new node;
		iter = list->rbegin(); //iterator starting from end, lowest frequencies
		itersp = iter++;

		tempnode = Merge(*iter, *itersp);

		list->pop_back(); //remove just used nodes
		list->pop_back();
		list->push_back(tempnode); //push new node back onto vector

		std::vector<node*>::iterator nbeg, nend; //begin and end iterators for sort
		nbeg = list->begin();
		nend = list->end();

		sort(nbeg, nend, compare); //re-sorts list
	}

	iter = list->rbegin(); //iterator starting from beginning
	itersp = iter++;

	//Creates Root node
	if (list->size() == 2)
	{
		RootNode = SetRootNode(*iter, *itersp);
	}
	else if (list->size() == 1)
	{
		RootNode = *iter;
	}
	else
	{
		//There should be not 0 nor more than two nodes;
		std::cout << "Incorrect number of nodes. Exiting. Fundamental issue somewhere else." << std::endl;
		system("pause");
		exit(0);
	}	

	//delete list; //strange behaviour, deletes references to everything
}

/// <summary>
/// Destructor
/// </summary>
BinTree::~BinTree()
{
	for (int i = 0; i < list->size(); ++i)
	{
		delete &list[i];
	}

	delete RootNode;
}

/// <summary>
/// Merges two nodes based on their size
/// </summary>
/// <param name="n1"></param>
/// <param name="n2"></param>
/// <returns>node*</returns>
node* BinTree::Merge(node *n1, node *n2)
{
	node* newnode = new node;

	newnode->_freq = n1->_freq + n2->_freq;
	newnode->_symbol = '*';

	//largest left := 0

	if (n1->_freq > n2->_freq)
	{
		newnode->_left = n1;
		newnode->_right = n2;
	}
	else if (n1->_freq <= n2->_freq)
	{
		newnode->_left = n2;
		newnode->_right = n1;
	}

	return newnode;
}

/// <summary>
/// Sets the root node
/// </summary>
/// <param name="n1"></param>
/// <param name="n2"></param>
/// <returns>node*</returns>
node* BinTree::SetRootNode(node *n1, node *n2)
{

	node* root = Merge(n1, n2);

	return root;
}

/// <summary>
/// Public facing method for printing the Binary tree
/// </summary>
void BinTree::PrintTree()
{
	m_print(RootNode, 0);
}

/// <summary>
/// Uses recursion to print the frequencies stored in the binary tree.
/// </summary>
/// <param name="leaf"></param>
/// <param name="indent"></param>
void BinTree::m_print(node* leaf, int indent = 0)
{
	if (leaf != NULL)
	{
		if (leaf->_right) //Traverse right side
		{
			m_print(leaf->_right, indent + 4);
		}

		if (indent)
		{
			std::cout << std::setw(indent) << ' '; //pad with indent amount of spaces
		}

		if (leaf->_right)
		{
			std::cout << " /\n" << std::setw(indent) << ' '; //insert / for the left leaf
		}
		
		std::cout << leaf->_freq << "\n "; //print frequency

		if (leaf->_left)  //traverse left
		{
			std::cout << std::setw(indent) << ' ' << " \\\n";
			m_print(leaf->_left, indent + 4);
		}
	}
}