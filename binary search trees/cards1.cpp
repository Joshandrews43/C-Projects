//cards.cpp
//Authors: Madeleine Allen 
//Implementation of the classes defined in cards.h

#include "cards.h"
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstddef>
using namespace std;
/*
enum Suit {c, d, s, h};
Suit identify(char *t)
*/

//constructor sets up empty tree
CardList::CardList(): root(0) {}

//destructor deletes all nodes
CardList::~CardList()
{
	clear(root);
}

//recursive helper for destructor
void CardList::clear(Node *n)
{
	if(n)
	{
		clear(n->left);
		clear(n->right);
		n=0;
		return;
	}
	return;
}

//insert value into tree
//return false if duplicate (will this work?)
bool CardList::insert(string value)
{
	if(!root) //empty tree
		//replace with == after overloading
	{
//		cout << "hey im the root " << value << endl;
		root = new Node(value);
		return true;
	}
	return insert(value, root);
}

int CardList::count() const
{
	return count(root);
}

int CardList::count(Node*n) const
{
	if(n)
	{
		return (1+count(n->left)+count(n->right));
	}
	return 0;
}

//recursive helper for insert (assume n is never "")
//can probably overload the < and > and == operators!
bool CardList::insert(string value, Node *n)
{
	Node* newnode= new Node(value);
//	newnode->card=value;
	newnode->left=nullptr;
	newnode->right=nullptr;

	if(!value.compare(n->card))
	{
		return false;
	}
	if(value < n->card)
	{
//		cout << "going left " <<value <<endl;
		if(n->left) //will this work with string values?
		{
			return insert(value, n->left);
		}
		else
		{
			n->left=newnode;
			newnode->parent=n;
			return true;
		}
	}
	else
	{
//		cout << "going right " << value  <<endl;
		if(n->right)
		{
			return insert(value, n->right);
		}
		else
		{
			n->right= newnode;
			newnode->parent=n;
			return true;
		}
	}
}

void CardList::print() const
{//i believe we want in-order traversal
	print(root);
}

void CardList::print(Node *n) const
{
	if(n)
	{
		print(n->left);
		cout << n->card << endl;
		print(n->right);
	}
}

bool CardList::contains(string value) const
{
	Node *tmp=root;
	while(tmp)
	{
		//if it is the current node
		if(!(tmp->card).compare(value))
		{
			return true;
		}
		else if (!(tmp->card > value))
		{
			tmp=tmp->right;
		}
		else if(tmp->card > value)
		{
			tmp=tmp->left;
		}
	}
	return false;
}


CardList::Node* CardList::search(Node *&node,string value)
{
	//UPDATE: 3/8 AT 7:31 PM I FIGURED IT OUT WE ALL GOOD FAM
	//yeah this search function is all wrong lol
	//might have messed this up on the evening of 3/8 pls revert back to version prior to that on github if things go wrong
//	Node *node = root;
//	Node* boy = node;
	cout << "value thats being passed into the function" << endl;
	cout << value << endl;
//	int go_left = 0;
//	int go_right =0;
	if(!(value.compare(node->card)))
	{
	//	cout << node->parent << endl;
//		cout << node->parent->card;
		cout << "what does this even do" << endl;
	//	cout << node->parent << endl;
//		cout << node->card << endl;
//		Node *boy = node->parent;
		cout << node->card;
		return node;
	}
	if(value < node->card)
	{
//		Node *boy = new Node;
//		boy=node->left;
		cout << "going left" << endl;	
		return search(*&node->left, value);
	}
	else
	//	else if ((!(value < node->card))&&(value.compare(node->card)))
	{
		cout << "going right" << endl;
//		Node *boy = new Node;
//		boy= node->right;
//		boy=node->right;
		return search(*&node->right, value);
	}
//	else if (!(value.compare(node->card)))
//	{
//		cout << "do we ever go in here" << endl;
//		return node;
//	}
//	return node;
}



void CardList::deleteValue(string value)
{
	Node *node, *p, *child, *pred;
	Node *temp= root;
	//node=c.search(c.root, value);
	cout << "seetttinggg node" << endl;	
	cout << "temp in delete value which should be root is" << *&temp << endl;
	if (temp == NULL)
	{
		cout << "uh oh we got a problemooooo " << endl;
	}

	cout << "root is" << root << endl;
	node=search(*&temp, value);
	cout << "node is set to" << node << endl;
	//leaf
	cout << "we have made it into the function past the search"<<endl;


	//leaf
	if(!(node->left && node->right)) //if 
	//if((l==0)&&(r==0))
	{
	cout <<"if its just a leaf we'll be here";
		if(node->parent)
		{
			p=node->parent;
		}
		if(node==p->left)
		{
			p->left=NULL;
		}
//		else
//		{	
//			p->right==NULL;
//		}
		node=NULL;
		return;
	}

//
//
	//two children
	//replace it with its predecessor
	if(node->left && node->right)
	{
		cout << "if the card has two children we will be here" <<endl;
		string value_pred= predecessor(node, value);
	//	string value_pred= temp->card;
		pred = search(node, value_pred);
		if(pred->parent->left == pred) 
			pred->parent->left = NULL;
		else if(pred->parent->right == pred) 
			pred->parent->right = NULL;
		node->card = pred->card;
		node = NULL;
		//delete pred;
		return;
	}
	//one child
	//replace it with its child and delete
//	cout << "if the card has just one child we will be here" << endl;
	if((node->right)||(node->left))
	{
		cout << "if the card has just one child we'll be here" <<endl;
		if(node->left) 
		{
			child = node->left;
		}
		else if(node->right)
		{
			child = node->right;
		}
		p = node->parent;
	
		if(p->left && p->left == node) {
			p->left = child;
		}
		else if (p->right && p->right == node) {
			p->right = child;
		}
		child->parent = p;
		//delete node;
		node=NULL;
		return;
	}
return;	
}


string CardList::successor(Node *a, string value)
{//precondition: a root and a value that we will find the next largest of
	Node *current;
	current = search(*&root, value);
	if(current==NULL)
	{
		return NULL;
	}
	if(current->right != NULL)
	{
		string mv = minValue(*&current->right);
		Node *tmp;
		tmp = search(*&root, mv);
		return tmp->card;
	}
	else
	{
		Node* successor = NULL;
		Node * prev = root;
		while(prev!=current)
		{
			if(current->card< prev->card)
			{
				successor = prev;
				prev = prev->left;
			}
			else
			{
				prev=prev->right;
			}
		}
		return successor->card;
	}
	
}

string CardList::predecessor(Node *b, string value)
{
	Node *current;
	current = search(*&root, value);
	if(current ==NULL)
	{
		return NULL;
	}
	if(current->left !=NULL)
	{
		string mv = maxValue(*&current->left);
		Node *tmp;
		tmp=search(*&root, mv);
		return tmp->card;
	}
	else
	{
		Node *s = NULL;
		Node *p= root;
		while(p!=current)
		{
			if(!(current->card < p->card))
			{
				s=p;
				p=p->right;
			}
			else
			{
				p=p->left;
			}
		}
		return s->card;
	}
}
string CardList::maxValue(Node *&root1) const
{
	Node *tmp= root1;
	while(tmp->right)
	{
		tmp=tmp->right;
	}
	return tmp->card;
}

string CardList::minValue(Node *&root1) const  //originally with no argument but trying one out
{
	Node *tmp= root1;
	while(tmp->left)
	{
		tmp=tmp->left;
	}
	return tmp->card;
	/*
	*/
}

bool operator <(string a, string b)
{
	//so there are several cases to this because ya girl is using strings which is not advisable
	//*****
	//if both are same suit
	//*****
	if(a[0]==b[0])
	{
//		cout <<"a[0] == b[0]" <<endl;
		//if they both  have numeric cards and the card number is less than 10
		if((isdigit(a[2]))&&(isdigit(b[2]))&&!(a.length()!=3))
		{
			//if a's integer is less than b's
			if((a[2]<b[2])&&!(b.length()!=3))
				{return true;}
			else
				{return false;}	
		}
		//***
		//if they have numeric cards and the card number is 10
		if((isdigit(a[2]))&&(isdigit(b[2]))&&!(a.length()!=4))
			{return false;}
		//***
		//if they both have ace/jack/king/queen
		if((a[3]=='a'||a[3]=='j'||a[3]=='q'||a[3]=='k')&&(b[3]=='a'||b[3]=='j'|| b[3]=='q'||b[3]=='k')){
			if(a[3]=='k')
				{return false;}
			if(a[3]=='a')
				{return true;}
			else if((a[3]=='j')&&(b[3]=='q' || b[3]=='k'))
				{return true;}
			else if((a[3]=='q')&&(b[3]=='k'))
				{return true;}
			else
				{return false;}
		}
		//***
		//if one has ace/jack/king/queen and one has a number
		if((a[0]=='a')&&(isdigit(b[0])))//if a is ace which is less than all of the numbers
			{return true;}
		if((a[0]=='j'||a[0]=='q'||a[0]=='k')&&(isdigit(b[0]))) //if a is j/q/k gr8r than the nums
			{return false;}
	}
	//*****	
	//if different suits
	else{
//		cout << "different suits" << endl;
		if(a[0]=='h')
		{return false;}
		if((a[0]=='c'))//a is clubs (smallest)
		{return true;}
		else if((a[0]=='d')&&(b[0]=='s'||b[0]=='h'))//a is d but b is s or h
		{return true;}
		else if((a[0]=='s')&&(b[0]=='h')) //a is s but b is h
		{return true;}
		else //a is h
		{return false;}
		
	}
	return true;
	//for some reason, c a and c k are out of order unless this "return true" is here. 
	//if you are having trouble on submit.cs later this is probably why tbh
}

void play_game(CardList &a, CardList &b)
{
	//alice starts at the location of her smollest card
	//find the smallest card for alice
	string alice_at = a.minValue(a.root);
	string bob_at = b.maxValue(b.root);
	
	int alice_cards = a.count(a.root);
	int bob_cards = b.count(b.root);

	if (bob_cards < alice_cards)
	{
		bob_cards = alice_cards;
	}
	else
	{
		alice_cards = bob_cards;
	}
	cout << alice_cards << " is alice_cards" << endl;
	cout << bob_cards << " is bob_cards" << endl;
	for(int i=0; i<alice_cards-1; i++)
	{
		if (b.contains(alice_at))
		{
			//announce it
			cout << "Alice picked matching card " << alice_at << endl;
			//delete both
			a.deleteValue(alice_at);
			b.deleteValue(alice_at);
			alice_at=a.minValue(a.root);
		}
		else
		{
			string hay= alice_at;
			alice_at= a.successor(a.root, hay);
		}
	
		if (a.contains(bob_at))
		{
			// announce it
			a.deleteValue(bob_at);
			b.deleteValue(bob_at);
			bob_at = b.minValue(b.root);
		}
		else
		{
			string bb = bob_at;
			bob_at = b.predecessor(b.root, bb);
		}
	}
	cout << endl;

	cout << alice_at << " is alice_ at" << endl;
	cout << bob_at << " is bob_at" <<endl;
	//print it at the end
	cout << "Alice's cards" << endl;
	a.print();
	cout << "Bob's cards" << endl;
	b.print();	

}
