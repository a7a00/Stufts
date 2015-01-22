// Test: attempt to remove a node that doesn't exist in the tree
/* main29.cpp
 *
 *  Created on: Oct. 19, 2014
 *      Author: chrisgregg
 */
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
        int rand_ints[12]={5,3,6,11,-5,-2,15,4,4,9,14,8};

        BinarySearchTree bst;
        for (int i=0;i<12;i++) {
                cout << "Inserting " << rand_ints[i] << "\n";
                bst.insert(rand_ints[i]);
        }
        bst.print_tree();
        cout << "Removing 25.\n";
        bst.remove(25);
        bst.print_tree();

        return 0;
}

