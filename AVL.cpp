
template <typename T>
class AVLTree
{
    //node of the tree
    class Node
    {
        //data, templated
        T data;
        Node *right_child;
        Node *left_child;
        Node *parent;
        int height;
    public:
        //default constructor
        Node();
		// Constructor initializing the data.
		Node(T t);
		// Calculate the balance point.
		int getBalance();
		// Get the actual data.
		int getData();
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
    public:
    //default constructor for empty tree
    BST();
    //parametrized constructor with one value t 
    BST(T t);
    //get height
    int getHeight();
    std::exception insert(T t);
    std::exception remove(T t);

    private:
    // Balance the tree
	void balance(Node *n);
	// Find the node containing the data.
	Node *findNode(T t);
	// Rotate the subtree left.
	void rotateLeft(Node *n);
	// Rotate the subtree left.
	void rotateRight(Node *n);
	// Set the root.
	void setRoot(Node *n);
};

//constructor for node
template<typename T>
AVLTree::Node::Node(){
    data = T t();
    height = 0;
    parent=nullptr;
    left=nullptr;
    right=nullptr;
}

// Constructor initializing the data.
template<typename T>
AVLTree::Node::Node(T data) {
  this.data = data;
  height = 0;
  parent = nullptr;
  left_child = nullptr;
  right_child = nullptr;
}
// Calculate the balance factoP: left.height-r.height
template<typename T>
int AVLTree::Node::getBalance() {

  // If we don't have a left subtree, check the
  // right.
  int result;
  if (left_child == nullptr)

	// If neither subtree exists, return zero.
	if (right_child == nullptr)
	  result = 0;

	// Otherwise, the right subtree exists so make
	// it's height negative and subtract one.
	else
	  result = -right_child->height-1;

  // Otherwise, we have a left subtree so if we
  // don't have a right one, return the left's
  // height plus one.
  else if (right_child == nullptr)
	result = left_child->height+1;

  // Otherwise, both subtrees exist so subtract
  // them to return the difference.
  else
	result = left_child->height-right_child->height;
  return result;
}

// Get the actual data.
template <typename T>
T AVLTree::Node::getData() {
  return data;
} 

// Get the height.
template<typename T>
int AVLTree::Node::getHeight() {
  return height;
}

// Get the left subtree.
template<typename T>
AVLTree::Node *AVLTree::Node::getLeftChild() {
  return left_child;
}

// Get the right subtree.
template<typename T>
AVLTree::Node *AVLTree::Node::getRightChild() {
  return right_child;
}

// Get the node's parent.
template<typename T>
AVLTree::Node *AVLTree::Node::getParent() {
  return parent;
}

// Remove the node's parent.
template<typename T>
void AVLTree::Node::removeParent() {
  parent = nullptr;
}

// Set the left subtree.
template<typename T>
AVLTree::Node *AVLTree::Node::setLeftChild(Node *newLeft<T>)
 {
  // If there is a left node, set it's parent to
  // be us. In any event, make it our left subtree
  // and update the height.
  if (newLeft != nullptr)
	newLeft->parent = this;
  left_child = newLeft;
  updateHeight();
  return left_child;
}

// Set the right subtree.
template<typename T>
AVLTree::Node *AVLTree::Node::setRightChild(Node *newRight<T>) {
  // If there is a right node, set it's parent to
  // be us. In any event, make it our right subtree
  // and update the height.
  if (newRight != nullptr)
	newRight->parent = this;
  right_child = newRight;
  updateHeight();
  return right_child;
}

// update the node's height.
template<typename T>
int AVLTree::Node::updateHeight() {

  // If we don't have a left subtree, check the
  // right.
  if (left_child == nullptr)

	// If we don't have either subtree, the height
	// is zero.
	if (right_child == nullptr)
	  height = 0;

	// Otherwise, we only have the right subtree so
	// our height is one more than it's height.
	else
	  height = right_child->height+1;

  // Otherwise, the left subtree exists so if we
  // don't have a right one, our height is one
  // more than it's height.
  else if (right_child == nullptr)
	height = left_child->height+1;

  // Otherwise, we have both subtree's so if the
  // left's height is greater than the right, our
  // height is one more than it.
  else if (left_child->height > right_child->height)
	height = left_child->height+1;

  // Otherwise, the right subtree's height will be
  // used so our height is one more than it.
  else
	height = right_child->height+1;
  return height;
}

//empty tree constructor
template<typename T>
AVLTree::AVLTree() {
  root = nullptr;
}

// Constructor to populate the tree with one node.
template<typename T>
AVLTree::AVLTree(T t) {
  root = new Node(t);
}

// Balance the subtree.
template<typename T>
void AVLTree::balanceAtNode(Node *n<T>) {

  // Get the current balance
  //determine which rotation is needed RR,LL,RL,LR
  int bal = n->getBalance();
  if (bal > 1) {
    //determine if we are in LR case
	if (n->getLeftChild()->getBalance() < 0)
	  rotateLeft(n->getLeftChild());
	rotateRight(n);
    } 
  // Otherwise, we are right heavy
  // determine if we need RL or RR
  else if (bal < -1) {
	if (n->getRightChild()->getBalance() > 0)
	  rotateRight(n->getRightChild());
	rotateLeft(n);
  }
}