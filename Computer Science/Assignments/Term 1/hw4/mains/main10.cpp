// Test: tree_height(): Prints height of empty tree (should be negative 1)
/*
 * main10.cpp
 *
 *  Created on: Oct. 14, 2014
 *      Author: chrisgregg
 */
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
        BinarySearchTree bst;
        cout << "Tree height: " << bst.tree_height() << "\n";

        return 0;
}

