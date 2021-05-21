#ifndef AVL_H_
#define AVL_H_

#include <iostream> 
#include <ctime>
#include <iomanip>

template<typename T>
class AVLTree
{
public:
    class Node
    {
        //data, templated
        T data;
        Node *right_child;
        Node *left_child;
        Node *parent;
		//height from bottom of tree
        int height;
    public:
    	//default constructor
    	Node();
		// Constructor initializing the data.
		Node(T t);
		//destructor
		//~Node(); not sure why this ruins things
		// Calculate the balance point.
		int getBalance();
		// Get the actual data.
		T getData();
		// Get the height.
		int getHeight();
		// Get the left subtree.
		Node *getLeftChild();
		// Get the node's parent.
		Node *getParent();
		// Get the right subtree.
		Node *getRightChild();
		// Remove the node's parent.
		void removeParent();
		// Set the left subtree.
		Node *setLeftChild(Node *newLeft);
		// Set the right subtree.
		Node *setRightChild(Node *newRight);
		// Set the node's height.
		int updateHeight();
		
    };
private:
	//a pointer to the root
  	Node *root;
 	//a pointer to the node with the lowest value
  	Node* lowest;
  	//a pointer to the node with the highest value
  	Node* highest;
  	//add pointer to lowest node and highest node
public:
  	//default constructor for empty tree
  	AVLTree();
  	//parametrized constructor with one value t 
  	AVLTree(T t);
  	//destructot
  	~AVLTree();
  	//get height
  	int getHeight();
  	//std::exception insert(const T& t);
  	bool insert(const T& t);
  	//returns lowest value
  	T getLowest();
  	//returns highest value
  	T getHighest();
  	//std::exception remove(const T& t);
  	bool remove(const T& t);
  	void print();
private:
  	// Balance the tree
	void balanceAtNode(Node *n);
	// returns a pointe to node containing the data.
	// nullptr if not in tree
	Node *findNode(const T& t);
	// Rotate the subtree left.
	void rotateLeft(Node *n);
	// Rotate the subtree left.
	void rotateRight(Node *n);
	// Set the root.
	void setRoot(Node *n);
	void printSubtree(Node *subtree, int depth,int offset, bool first);
	int spacing(int offset);
};


#endif