//cards.cpp
//Authors: Madeleine Allen and Josh Andrews
//Implementation of the classes defined in cards.h

#include "cards.h"
#include "utility.h"
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstddef>
using namespace std;

Node *makeNewNode(int val)
{
	Node *p = new Node(val); // = (Node *)malloc(sizeof(Node));
	p->val = val;
	p->left = NULL;
	p->right = NULL;
	return p;
}

Node::Node(int value)
{
	val=value;
    left = NULL;
	right=NULL;
}

Node::~Node()
{
	//delete val;
	// if(left!=0)
	// {
	// 	delete left;
	// }
	// if(right!=0)
	// {
	// 	delete right;
	// }
}

void CardList::clear(Node *n) 
{
	delete n;
}

CardList::CardList()
{
	root=0;
}

CardList::~CardList()
{
	if(root!=NULL)
	{
		deleteNodes(root);
	}
}

void CardList::play(CardList &b)
{
	playTree(b);
}

void CardList::playTree(CardList &b)
{
	int count = 0;
	CardList aRemains = CardList("Alice");
	CardList bRemains = CardList("Bob");
	while (true)
	{
		if (b.root==NULL && this->root==NULL)
		{
			aRemains.printCards();
			bRemains.printCards();
			break;
		}
		if(count%2==0)
		{
			//p1 turn
			if(root==NULL)
			{
				count++;
				continue;
			}
			int v = this->minTree(root)->val;
			Node *newRoot = b.remove(v);
			if(newRoot!=NULL)
			{
				printf("Alice picked matching card %s\n", intToCardString(v).c_str());
				this->root = remove(v);
				b.root = newRoot;
				count++;
			} else {
				aRemains.insert(v);
				this->root = remove(v);
			}
		} else {
			if(b.root==NULL)
			{
				count++;
				continue;
			}
			int v = b.maxTree(b.root)->val;
			Node *newRoot = this->remove(v);
			if(newRoot!=NULL)
			{
				printf("Bob picked matching card %s\n", intToCardString(v).c_str());
				this->root=newRoot;
				b.root = b.remove(v);
				count++;
			} else {
				bRemains.insert(v);
				b.root = b.remove(v);
			}
		}
	}
}




void CardList::deleteNodesC(CardList &c)
{
	deleteNodes(c.root);
	delete c.root;
	c.root = NULL;
}

void CardList::deleteNodes(Node *root)
{	
	while(maxTree(root)->val!=minTree(root)->val)
	{
		int v = minTree(root)->val;
		root = remove(v);
	}
	Node *t = root;
	root = NULL;
	delete t;
	return;
}

void CardList::printCards()
{
	printf("\n%s's cards:\n",owner.c_str());
	printTree(root);
}

bool CardList::insert(int c)
{
	if (root == NULL)
	{
		root = new Node(c);
		return true;
	}
	return insertTree(c,root);
}

bool CardList::search(int c)
{
	return search1(root,c)!=NULL;
}

bool CardList::insertTree(int value, Node *&n)
{

	if(n->val == value)
	{
		return false;
	}
	if(value < n->val)
	{
		if(n->left==NULL)
		{
			Node *l= new Node(value);//= makeNewNode(value);
			n->left = l;
			return true;
		}
		return insertTree(value, n->left);
	}
	if(value > n->val)
	{
		if(n->right==NULL)
		{
			Node *r = new Node(value);
			n->right = r;
			return true;
		}
		return insertTree(value, n->right);
	}
	return false;//silence warnings;
}


Node* CardList::search1(Node *&node, int c)
{
	// BST is empty.
	if(node==NULL)
	{
		return NULL;
	}
	// found correct node.
	if(node->val ==c)
	{
		return node;
	}
	// node must be in left child if it exists. 
	if(c < node->val)
	{
		return search1(node->left, c);
	}
	// node must be in right child if it exists. 
	else if (c > node->val)
	{
		return search1(node->right, c);
	}

}

//was bool
Node* CardList::remove(int c)
{
	Node *n=search1(root,c);
	// node doesn't exist. 
	if(n==NULL)
	{
		return NULL;
	}
	return removeTree(root, c);
}


Node *CardList::removeTree(Node *&root, int data)
{
  // BST is empty. 
  if (root == NULL) 
  {
     return NULL;
  }
  // data is in left child. Rerun with root as left child. 
  if (data < root->val) 
  {  
      root->left = removeTree(root->left, data);
  } 
  // data is in right child. Rerun with root as right child.
  else if (data > root->val) 
  { 
      root->right = removeTree(root->right, data);
  } 
  else 
  {
  	 // case for leaf node.
     if (root->left == NULL && root->right == NULL) 
     {
        delete root;
        root = NULL;
     }
     //case for no left child.
     else if (root->left == NULL) 
     {
        Node *temp = root; 
        root = root->right;
        delete temp;
     }
     // case for no right child.
     else if (root->right == NULL) 
     {
        Node *temp = root; 
        root = root->left;
        delete temp;
     }
     else 
     {
        Node *temp = minTree(root->right);
        root->val = temp->val;
        root->right = removeTree(root->right, temp->val); 
     }
  }
  return root; // parent node can update reference
}



void CardList::printTree(Node *&n) //prints least to greatest
{
	// case for if BST is empty. 
	if (n==NULL)
	{
		return;
	}
	printTree(n->left);
	printf("%s\n", intToCardString(n->val).c_str());
	printTree(n->right);

}
Node *CardList::minTree(Node *&n)
{
	// if left child exists.
	if (n->left!=NULL)
	{
		return minTree(n->left);
	}
	// if no left child exists, current node must be lowest.
	else 
	{
		return n;
	}
}

Node *CardList::maxTree(Node *&n)
{
	// if right child exists.
	if (n->right!=NULL)
	{
		return maxTree(n->right);
	}
	// if no right child exists, currenct node must be largest. 
	else 
	{
		return n;
	}
}

