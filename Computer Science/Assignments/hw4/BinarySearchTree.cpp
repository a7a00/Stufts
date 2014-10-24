/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	// TODONE: Students write code here
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
	// walk tree in post-order traversal and delete
	post_order_delete(root);
}

void BinarySearchTree::post_order_delete(Node *node) {
	// TODONE: students write code here
	// (hint: use a post-order traversal to remove all nodes)
	if(node->left != NULL) post_order_delete (node -> left);
        if(node->right != NULL) post_order_delete(node -> right);
        delete node;
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source) {
	// use pre-order traversal to copy the tree
	root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree& BinarySearchTree::operator=
		(const BinarySearchTree &source) {
	// TODONE: Students write code here
	// check for self-assignment
	if(this == &source) return *this;
	// delete current tree if it exists
	if(root != NULL) post_order_delete(root);
	// use pre-order traversal to copy the tree
	root = pre_order_copy(source.root);
	/* don't forget to "*/return *this;//"
}

Node * BinarySearchTree::pre_order_copy(Node *node) {
	// TODONE: Students write code here
	// (hint: use a pre-order traversal to copy details from the
	// node to a new_node)
	if (node == NULL) return NULL;
	Node* temp = new Node();
	temp->data = node->data;
	temp->count = node->count;
	temp->left = pre_order_copy(node->left);
	temp->right = pre_order_copy(node->right);
	return temp;
}

int BinarySearchTree::find_min() {
	if (root == NULL) return INT_MIN;
	return find_min(root)->data;
}

Node *BinarySearchTree::find_min(Node *node) { //I forgot these had to be recursive...
	// TODONE: Students write code here
	//Node* temp = node; //Just in case there's a reference passing issue
	//while(temp->left != NULL) current = temp->left;
	//return temp;
	if(node->left == NULL) return node;
	else return find_min(node->left);
}

int BinarySearchTree::find_max() {
	// TODONE: Students write code here
	if (root == NULL) return INT_MIN;
        return find_max(root)->data;
}

Node *BinarySearchTree::find_max(Node *node) {
	// TODONE: Students write code here
	//Node* temp = node; //Just in case there's a reference passing issue
        //while(temp->left != NULL) temp = temp->left;
        //return temp;
	if(node->right == NULL) return node;
        else return find_max(node->right);
}

bool BinarySearchTree::contains(int value) {
	// TODONE: Students write code here
	return contains(root, value);
}

bool BinarySearchTree::contains(Node *node, int value) {
	// TODONE: Students write code here
	if(node == NULL) return false;
	else if(value == node->data) return true;
	else if(value < node->data) return contains(node->left, value);
	else if(value > node->data) return contains(node->right, value);
	else
	{
		std::cout << "YOU SCREWED UP BAD SOMEWHERE";
		return false;
	}
}

void BinarySearchTree::insert(int value) {
	insert(root,NULL,value);
}

void BinarySearchTree::insert(Node *node,Node *parent, int value) {
	// TODONE: Students write code here
	if(node == NULL)
	{
		node = new Node();
		node->data = value;
		node->count = 0;
		node->left = NULL;
		node->right = NULL;
		if(parent == NULL) root = node;
		else
		{
			if(parent->data < value) parent->right = node;
			else parent->left = node;
		}
	}
	if(node->data == value) (node->count)++;
	else
	{
		//if(node->left == NULL && node->right == NULL)
		//{
		//	if(node->data < value) insert(node->left, node, value);
		//	if(node->data > value) insert(node->right, node, value);
		//}
		if(value < node->data) insert(node->left, node, value);
		if(value > node->data) insert(node->right, node, value);
	}
}

	//KEEP THIS FOR LATER
	// TODOMAYBE: Students write code here
        //If we've reached the end (NULL), return the node
        //if(node->left == NULL && node->right == NULL) return
        //Recurse down the tree with 2 conditionals to see i we should go left or right.
        //Return the given node.


bool BinarySearchTree::remove(int value) {
	return remove(root,NULL,value);
}

bool BinarySearchTree::remove(Node *node, Node *parent, int value) {
	// TODONE: Students write code here
	// (cannot be a lazy removal)
	if(value == node->data)
	{
		(node->count)--;
		if(node->count == 0)
		{
			if(node->left == NULL && node->right == NULL)
			{
				delete node;
				char flag;
                                if(parent->left == node) flag = 'l';
                                else flag = 'r';
                                if(flag == 'l') parent->left = NULL;
                                else parent->right = NULL;
			}
			//When I wrote this, only God and I knew what I was doing. Now, only God knows.
			else if(node->left == NULL && node->right != NULL) //OK, what we're doing here is 
			//taking note of which side of the parent we're on, because the method doesn't know that.
			//We then reassign the pointer and delete the node.
			{
				char flag;
				if(parent->left == node) flag = 'l';
				else flag = 'r';
				if(flag == 'l') parent->left = node -> right;
				else parent->right = node -> right;
				delete node;
			}
			else if(node->left != NULL && node->right == NULL) //Sane here
			{
				char flag;
	                        if(parent->left == node) flag = 'l';
	                        else flag = 'r';
	                        if(flag == 'l') parent->left = node -> left;
	                        else parent->right = node -> left;
				delete node;
			}
			else if(node->left != NULL && node->right != NULL)
			{
				//Find minimum element in the right subtree
				Node* temp = find_min(node);
				//Replace the value to be removed with the value of the node we just found
				node->data = temp->data;
				node->count = temp->count;
				//Delete the node we found
				//remove(temp, find_parent(node, temp), temp->data);
				if(temp == (find_parent(node, temp))->left) (find_parent(node, temp))->left = NULL;
				else (find_parent(node, temp))->right = NULL;
				if(node->data < node->left->data)
				{
					int tempData = node->data;
					int tempCount = node->count;
					node->data = node->left->data;
					node->count = node->left->count;
					node->left->data = tempData;
					node->left->count = tempCount;
				}
				else if(node->data > node->right->data)//else if because we;ve only changed one of the 2 subtrees.
				{
					int tempData = node->data;
                                        int tempCount = node->count;
                                        node->data = node->right->data;
                                        node->count = node->right->count;
                                        node->right->data = tempData;
                                        node->right->count = tempCount;
				}
				delete temp;
				Node* balanced = NULL;
				balance(node, balanced);
				node = balanced;
			}
			return true;
		}
	}
        else if(node == NULL) return false;
        else if(value < node->data) return remove(node->left, node, value);
	else if(value > node->data) return remove(node->right, node, value);
	return false; //Not sure why this is being called, but seems to work.
}

void BinarySearchTree::balance(Node* node, Node* new_node)
{
	if(node->left != NULL) balance(node -> left, new_node);
        if(node->right != NULL) balance(node -> right, new_node);
	for(int i = 0; i < node->count; i++) insert(new_node, NULL, node->data);
	find_parent(root, node)->left = NULL;
	find_parent(root, node)->right = NULL;
        delete node;
}

int BinarySearchTree::tree_height() {
	return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) {
	//TODONE: Students write code here
	if(node == NULL) return -1;
	//if(node->left == NULL && node->right == NULL) return 0; //Should this be -1?
	if(tree_height(node->left) > tree_height(node->right)) return (tree_height(node->left) + 1);
	else return (tree_height(node->right) + 1);
}

// returns the total number of nodes
int BinarySearchTree::node_count() {
	return node_count(root);
}

int BinarySearchTree::node_count(Node *node) {
	// TODONE: Students write code here
	if(node == NULL) return 0;
	else return (node_count(node->left) + node_count(node->right) + 1);
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() {
	return count_total(root);
}

int BinarySearchTree::count_total(Node *node) {
	// TODONE: Students write code here
	if(node == NULL) return 0;
	else return (((node->data)*(node->count))+count_total(node->left)+count_total(node->right));
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() {
	printPretty(root, 1, 0, std::cout);
}

Node *BinarySearchTree::find_parent(Node *node,Node *child) {
	if (node==NULL) return NULL;

	// if either the left or right is equal to the child,
	// we have found the parent
	if (node->left==child || node->right == child) {
		return node;
	}

	// Use the binary search tree invariant to walk the tree
	if (child->data > node->data) {
		return find_parent(node->right,child);
	}
	else {
		return find_parent(node->left,child);
	}
}
