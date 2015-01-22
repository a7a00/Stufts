/*
 * main.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: chrisgregg
 */

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void print_tree_details(BinarySearchTree &bst) {
	bst.print_tree();
	cout << "\n";
	cout << "min: " << bst.find_min() << "\n";
	cout << "max: " << bst.find_max() << "\n";
	cout << "nodes: " << bst.node_count() << "\n";
	cout << "count total: " << bst.count_total() << "\n";
	cout << "tree height: " << bst.tree_height() << "\n";
	cout << "\n";
}

int main() {
	int values[14] = {4,2,11,15,9,1,-6,5,3,15,2,5,13,14};
	BinarySearchTree bst;
	for (int i=0;i<14;i++) {
		cout << "Inserting " << values[i] << " into the tree.\n";
		bst.insert(values[i]);
	}
	cout << "Original tree " <<
			"(asterisks denote a count of more than 1):\n";
	print_tree_details(bst);

	// make a copy with copy constructor
	BinarySearchTree bst_copy_constructor = bst;
	//bst_copy_constructor.print_tree();

	// make a copy with assignment overload
	BinarySearchTree bst_copy_1;
	bst_copy_1 = bst;

	cout << "Removing 9 from original tree:\n";
	bst.remove(9); // remove a node with no children
	print_tree_details(bst);

	bst = bst_copy_1;

	cout << "Removing 1 from original tree:\n";
	bst.remove(1); // remove a node with one child
	print_tree_details(bst);

	bst = bst_copy_1;

	cout << "Removing 11 from original tree:\n";
	bst.remove(11); // remove a node with one child
	print_tree_details(bst);

	bst = bst_copy_1;

	cout << "Removing 5 from original tree " <<
			"(should still have one 5):\n";
	bst.remove(5); // remove a node with one child
	print_tree_details(bst);

	// check if the tree contains values
	bst = bst_copy_1;
	for (int i=-10;i<20;i++) {
		cout << "Tree " << (bst.contains(i) ?
				"contains " :
				"does not contain ")
				<< "the value " << i << "\n";
	}

	cout << "\nFinished!\n";
	return 0;
}
