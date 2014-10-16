#include "BSTree.h"


BST::BST()
{
	root = NULL;	
}

BST::~BST()
{
	postDelete(root);
}

//
// Insert: public version of Insert takes a value only and
// 	   inserts in the tree at the root
//
void BST::unbalancedInsert(int v)
{
	root = unbalancedInsert(root, v);
}

//
// Insert: private version inserts a value at any subtree
//         given by the 'root' of that tree
//
//   returns: the current tree NOW WITH the value inserted
//   note: ALWAYS adds a leaf
//
BSTNode* BST::unbalancedInsert(BSTNode* r, int v)
{
	//Base Case for recursion:
	//We have reached the end of the
	//tree and we are at NULL. We
	//create a node with the correct
	//information and return a pointer
	//to the new data. This return sets
	//the value for the parent which made
	//the function call

	if(r == NULL)
	{
		r = new BSTNode;
		r->value = v;
		r->left = NULL;
		r->right = NULL;
		return r;
	}

	//notice we asked NULL first so that
	//r->left and r->right will not seg fault

	else if(v < r->value)
	{
		r->left = unbalancedInsert(r->left, v);
		return r;

	}

	else
	{
		r->right = unbalancedInsert(r->right, v);
		return r;


	}
}


//****************** inorder *****************//

void BST::inOrder()
{
	inOrder(root);		// calls the next one
}


void BST::inOrder(BSTNode* root)
{
	//TODO: your code here
	if(root->left != NULL) inOrder(root -> left);
	cout << root -> value << " ";
	if(root->right != NULL) inOrder(root -> right);
}



//****************** postorder *****************//



void BST::postOrder()
{	
	postOrder(root);	// calls the next one
}

void BST::postOrder(BSTNode* root)
{
	//TODO: your code here --- if you want
	if(root->left != NULL) postOrder(root -> left);
        if(root->right != NULL) postOrder(root -> right);
	cout << root -> value << " ";
}
void BST::postDelete(BSTNode* root)
{
        if(root->left != NULL) postDelete(root -> left);
        if(root->right != NULL) postDelete(root -> right);
        delete root;
}


//****************** preorder *****************//



// print the tree in preOrder using the next function
// Question to ponder: can we do this without a helper function?
void BST::preOrder()
{
	preOrder(root);		// calls the next one (really needed?)
}

//
// preOrder traversal using a stack of our own, not
// the one from the compiler

void BST::preOrder(BSTNode* root)
{
	//preorder with a stack
	//TODO: stack defined here:
	stack<BSTNode*> s;
	s.push(root);
	//TODO: your code here
	while(!(s.empty()))
	{
		BSTNode * current = s.top();
		cout << current -> value << " ";
		s.pop(); //Turns out you have to do this BEFORE you push onto the stack.
		if(current -> right != NULL) s.push(current -> right);
		if(current -> left != NULL) s.push(current -> left);
	}
}



//****************** levelorder *****************//



void BST::levelOrder()
{
	levelOrder(root);
}


void BST::levelOrder(BSTNode* root)
{

	//TODO: Use a queue, declare it here
	queue<BSTNode*> q;
	q.push(root);
	//TODO: your code here
	while(!(q.empty()))
	{
		BSTNode * current = q.front();
		cout << current -> value << " ";
		q.pop();
		if(current -> left != NULL) q.push(current -> left);
                if(current -> right != NULL) q.push(current -> right);
	}
}
