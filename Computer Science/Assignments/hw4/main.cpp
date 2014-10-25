// Test: mega-remove of 100 random int tree: removes 95 ints in tree, prints
/*
 * main21.cpp
 *
 *  Created on: Oct. 14, 2014
 *      Author: chrisgregg
 */
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
        int rand_ints[100]={84, 49, -62, 95, 75, 18, -56, -27, -73, 42,
                        80, 5, 35, 15, 64, -99, 3, 100, -36, -64,
                        23, -24, -70, -2, -52, -62, 64, -97, 49,
                        -33, 27, 31, -11, 55, 71, -66, 67, -69,
                        -87, -43, -94, -66, 74, -91, 47, 3, -98,
                        54, 90, -34, -7, -11, 58, 17, 80, 27, 93,
                        73, -65, 55, 90, 76, 55, 41, -45, -28, -34,
                        55, 0, 40, -63, -59, -48, -73, 17, -18, -39,
                        98, 23, -16, 89, 98, 87, -59, -77, -95, -18,
                        -11, 76, 17, 48, -59, 35, 58, 31, 13, -98,
                        -70, 21, -87};

        BinarySearchTree bst;
        for (int i=0;i<100;i++) {
                cout << "Inserting " << rand_ints[i] << "\n";
                bst.insert(rand_ints[i]);
        }
	//bst.print_tree();
        cout << "Node count: " << bst.node_count() << "\n";
        for (int i=0;i<95;i++) {
                cout << "Removing " << rand_ints[i] << "\n";
                if (rand_ints[i]==87) {
                        cout << "About to remove root!\n";
			//cout << "Node count: " << bst.node_count() << "\n";
                        bst.print_tree();
                }
                bst.remove(rand_ints[i]);
		//cout << "Node count: " << bst.node_count() << "\n";
        }
        bst.print_tree();

        cout << "Finished!\n";
        return 0;
}

