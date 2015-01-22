//---------- test program code: main22.cpp ----------
// Test: remove root when root has no children
/*
 * main22.cpp
 *
 *  Created on: Oct. 19, 2014
 *      Author: chrisgregg
 */
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
        BinarySearchTree bst;

        bst.insert(12);
        bst.print_tree();
        cout << "Removing 12.\n";
        bst.remove(12);
        bst.print_tree();

        return 0;
}


