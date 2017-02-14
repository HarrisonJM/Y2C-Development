#include "BinTree.h"

using namespace std;

//Operation Functor used for sort() function
bool compare(const node &i, const node &j)
{
	return i._freq > j._freq;
}

BinTree::BinTree(std::vector<std::pair<char, int>>* freqs)
{
	//Variables
	std::vector<node>* list = new std::vector<node>;
	RootNode = new node;

	//iterators
	std::vector<std::pair<char, int>>::iterator it;
	std::vector<node>::reverse_iterator iter, itersp; //end node iterators
	std::vector<node>::iterator nbeg, nend; //begin and end iterators for sort

	//temporary nodes
	node tempnode;
	node initnode;

	//initilise temporary nodes
	initnode._left = NULL;
	initnode._right = NULL;
	initnode._code = "";

	for (it = freqs->begin(); it != freqs->end(); ++it) //Fill up all nodes
	{
		//Fill temporary nodes, with symbols and frequencies
		initnode._freq = it->second;
		initnode._symbol = it->first;
		
		list->push_back(initnode);
	}

	while (list->size() > 2)
	{
		iter = list->rbegin(); //iterator starting from end, lowest frequencies
		itersp = iter++;

		tempnode = Merge(*iter, *itersp);

		list->pop_back(); //remove just used nodes
		list->pop_back();
		list->push_back(tempnode); //push new node back onto vector

		nbeg = list->begin();
		nend = list->end();

		sort(nbeg, nend, compare); //re-sorts list
	}

	iter = list->rbegin(); //iterator starting from beginning
	itersp = iter++;

	//Creates Root node
	if (list->size() == 2)
	{
		*RootNode = SetRootNode(*iter, *itersp);
	}
	else if (list->size() == 1)
	{
		*RootNode = *iter;
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

node BinTree::Merge(node &n1, node &n2) //pointer to pointer?
{
	//node* newnode = new node;

	//newnode->_freq = n1._freq + n2._freq;

	////largest left := 0

	//if (n1._freq > n2._freq)
	//{
	//	newnode->_left = &n1;
	//	newnode->_right = &n2;
	//}
	//else if (n1._freq <= n2._freq)
	//{
	//	newnode->_left = &n2;
	//	newnode->_right = &n1;
	//}

	//return *newnode;

	node newnode;

	newnode._freq = n1._freq + n2._freq;

	//largest left := 0

	if (n1._freq > n2._freq)
	{
		newnode._left = &n1;
		newnode._right = &n2;
	}
	else if (n1._freq <= n2._freq)
	{
		newnode._left = &n2;
		newnode._right = &n1;
	}

	return newnode;
}

node BinTree::SetRootNode(node &n1, node &n2)
{
	//node root;

	//if (n1._freq > n2._freq)
	//{
	//	root._left = &n1;
	//	root._right = &n2;
	//}
	//else if (n1._freq <= n2._freq)
	//{
	//	root._left = &n2;
	//	root._right = &n1;
	//}

	//return root;

	node root = Merge(n1, n2);

	return root;
}

void BinTree::PrintTree(node* root)
{
	if (root != NULL)
	{
		PrintTree(root->_left); // Print items in left subtree.

		PrintTree(root->_right); // Print items in right subtree.

		std::cout << "S:" << root->_symbol << " F:" << root->_freq << " ";
	}
}

node * BinTree::getRootNode()
{
	return RootNode;
}
