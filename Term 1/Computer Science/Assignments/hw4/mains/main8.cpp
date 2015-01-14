// Test: max and min on empty tree: Creates empty tree, prints min/max.
/*
 * main8.cpp
 *
 *  Created on: Oct. 14, 2014
 *      Author: chrisgregg
 */
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
        BinarySearchTree bst;
        cout << "minimum: " << bst.find_min() << "\n";
        cout << "maximum: " << bst.find_max() << "\n";

        return 0;
}
