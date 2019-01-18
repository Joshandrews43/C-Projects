//cards.h
//Authors: Madeleine Allen & Josh Andrews
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include<string>
using namespace std;


typedef struct Node
{
  int val;
  struct Node *left;
  struct Node *right;
  Node(int val);
  ~Node();
  void clear();
} Node;


class CardList 
{
	// Functions without comments are recursive helper functions or single line implementations. 
	public:
		CardList(string ownersName) : owner(ownersName), root(NULL) {}
		CardList();
		~CardList();

		// printCards - prints all cards in the BST.  
		void printCards();

		// insert - inserts value into the correct spot in the BST by calling insertTree.
		// PRE: c is an integer with a value determined by suit and value of the card.
		// POST: returns true if insertion was successful, false otherwise.
		bool insert(int c);

		// search - searches the BST for a value matching that of c.
		// PRE: c is an integer with a value determined by suit and value of the card.
		// POST: returns true if the value is found in the BST, false otherwise.
		bool search(int c);

		// remove - removes a node with a value matching c from the BST.
		// PRE: c is an integer with a value determined by suit and value of the card.
		// POST: returns a pointer to the node with the given value, if it exists. 
		// 		 returns NULL otherwise.
		Node *remove(int c);

		// play - a recursive function which calls itself and its helper function, playTree.
		//        until the game is over and no matches remain.
		// PRE: b is a CardList object with owner value of the player who's turn it is.
		// POST: all matches have been removed and the game is over. 
		void play(CardList &b);

		// deleteNodesC - recursive function which calls it's helper to free memory after
		// 				  the game is over.
		// PRE: c is a CardList with nodes to be deleted.  
		// POST: The CardList has had all of the memory previously allocated freed. 
		void deleteNodesC(CardList &c);
	private:
		void deleteNodes(Node *root);
		Node* search1(Node *&node, int c);
		string owner;
		Node *root;
		void clear(Node *n);
		bool insertTree(int value, Node *&n);
		Node *removeTree(Node *&n, int data);
		void printTree(Node *&n);

		// minTree - finds the minimum value in the BST.
		// PRE: n is a pointer to the root node of the BST.
		// POST: returns a pointer to the lowest value stored in the BST, NULL if empty.
		Node *minTree(Node *&n);

		// maxTree - finds the maximum value in the BST.
		// PRE: n is a pointer to the root node of the BST.
		// POST: returns a pointer to the highest value stored in the BST, NULL if empty.
		Node *maxTree(Node *&n);
		void playTree(CardList &b);
};


#endif
