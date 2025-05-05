#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
  int element; // Element contained in the node
  TreeNode* left; // Pointer to the left child
  TreeNode* right; // Pointer to the right child

  TreeNode() // default constructor
  {
    element = 0;
    left = nullptr;
    right = nullptr;
  }

  TreeNode(const int& e) // defined constructor
  {
    this->element = e;
    left = nullptr;
    right = nullptr;
  }
};

class BST
{
public:
  BST() // default constructor
  {
    root = nullptr;
    size = 0;
  }

  BST(int *elements, int arraySize) // defined constructor
  {
    root = nullptr;
    size = 0;

    for (int i = 0; i < arraySize; i++)
    {
      insert(elements[i]);
    }
  }

  /* Copy constructor */
  BST(const BST& tree)
  {
    root = nullptr;
    size = 0;
    copy(tree.root); // Recursively copy nodes to this tree
  }
  /* Deep Copies all elements from the specified tree to this tree */
  void copy(const TreeNode* root)
  {
    // If BST is empty return
    if( root == nullptr){
      return;
    }
    else{
      // Create new TreeNode passing the element of original node
      this->root = new TreeNode(root->element);

      // Deep Copy Subtrees recursively
      subTreeCopy(this->root, root);
    }
  }

  // Recursive helper function copying subtrees
  void subTreeCopy(TreeNode* newNode, const TreeNode* originalNode){

    // Copy left subtree
    if( originalNode->left != nullptr){ // If left node exists
      newNode->left = new TreeNode(originalNode->left->element); // Create newNode on parrents left
      subTreeCopy(newNode->left, originalNode->left); // Call function copy left subtree recursively
    }

    // Copy right subtree
    if(originalNode->right != nullptr){ // If right node exists
      newNode->right = new TreeNode(originalNode->right->element); // Create newNode on parrents right
      subTreeCopy(newNode->right, originalNode->right); // Call function copy right subtree recursively
    }
  }

  /* Destructor */
  ~BST()
  {
    clear();
  }

  /* Return the address of the node if the element is in the tree; returns nullptr otherwise */
  TreeNode* search(const int& e) const
  {
    return searchRecursiveHelper(this->root, e);
  }

  // Helper function returns recurscive search
  TreeNode* searchRecursiveHelper(TreeNode* currentNode, const int &e) const{
    // Base case
    if (currentNode == nullptr){
      return nullptr;
    }
    // If element found return node
    if(currentNode->element == e){
      return currentNode;
    }
    else if(e < currentNode->element){ // If element < currentNode element
      return searchRecursiveHelper(currentNode->left, e); // Search left subtree
    }
    else{ // Else e > current node
      return searchRecursiveHelper(currentNode->right, e); // Search right subtree
    }
  }

  TreeNode* createNewNode(const int& e)
  {
    return new TreeNode(e);
  }

  // Insert element e into the binary tree
  // Return true if the element is inserted successfully
  // Return false if the element is already in the list
  bool insert(const int& e)
  {
    if (root == nullptr)
      root = createNewNode(e); // Create a new root
    else
    {
      // Locate the parent node
      TreeNode* parent = nullptr;
      TreeNode* current = root;
      while (current != nullptr)
        if (e < current->element)
        {
          parent = current;
          current = current->left;
        }
        else if (e > current->element)
        {
          parent = current;
          current = current->right;
        }
        else
          return false; // Duplicate node not inserted

      // Create the new node and attach it to the parent node
      if (e < parent->element)
        parent->left = createNewNode(e);
      else
        parent->right = createNewNode(e);
    }

    size++;
    return true; // Element inserted
  }

  /* Inorder traversal */
  void inorder() const
  {
    inorder(root);
  }

  /* Inorder traversal from a subtree */
  void inorder(const TreeNode* someNode) const
  {
    if (someNode == nullptr) return;

    inorder(someNode->left); // process all nodes in left sub-tree of someNode
    cout << someNode->element << " "; // process someNode
    inorder(someNode->right); // process all nodes in right sub-tree of someNode
  }

  /* Get the number of nodes in the tree */
  int getSize() const
  {
    return size;
  }

  /* Remove all nodes from the tree */
  void clear()
  {
    //Base case, If tree is empty return
    if(this->root == nullptr){
      return;
    }
    clearRecursiveHelper(this->root);

    this->root = nullptr;
  }

  // Clear recusrive helper
  void clearRecursiveHelper(TreeNode* currentNode){
    // Base case, If tree is empty
   if (currentNode == nullptr){
      return;
    }
    // Clear left subtree
    clearRecursiveHelper(currentNode->left);

    // Clear right subtree
    clearRecursiveHelper(currentNode->right);

    delete currentNode;
  }
  

/////EXERCISE
  /* Return a path from the root leading to the specified element (i.e. store the node addresses along the path).
  If specified element does not exist in the tree then add a nullptr to the vector and return it. */
  vector<TreeNode*>* path(const int& e) const
  {
    vector<TreeNode*>* pathCoordinates = new vector<TreeNode*>; // Initialize a pointer for TreeNode pointer vector

    // If elemenet doesnt exist return nullptr
    if(searchAndMapPath(root, e, *pathCoordinates)){
      return pathCoordinates;
    }
    else{
      pathCoordinates->push_back(nullptr);
    }
    return pathCoordinates;
  }

  // Helper function searches element and records path
  // Return false when element not found
  bool searchAndMapPath(TreeNode* current, const int& e, vector<TreeNode*>& pathCoordinates) const{
    
    // Base case, If element not found return false
    if(current == nullptr){
      return false;
    }
    pathCoordinates.push_back(current); // Store pointer pointing at root

    if(current->element == e){ // If element found return true
      return true;
    }

    // If e < current element move left
    if(e < current->element){
      // If element found return true
      if(searchAndMapPath(current->left, e, pathCoordinates)){
        return true;
      }
    }
    // If e > current element move right
    if(e > current->element){
      // If element found return true
      if(searchAndMapPath(current->right, e, pathCoordinates)){
        return true;
      }
    }

    // Remove path direction if element not found
    pathCoordinates.pop_back();
    return false;
  }

  /* Delete an element e from the binary tree.
   * Return true if the element is deleted successfully
   * Return false if the element is not in the tree */
  bool remove(const int &e)
  {
    // Locate the node to be deleted and also locate its parent node
    TreeNode *parent = nullptr;
    TreeNode *current = root;
    while (current != nullptr)
    {
      if (e < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (e > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        break; // Element e is in the tree pointed by current
    }

    if (current == nullptr)
      return false; // Element e is not in the tree

    // Case 0: current is a leaf
    if(current->left == nullptr && current->right == nullptr){
      if (parent == nullptr)
      {
        root = nullptr;
      }
      else
      {
        if (e < parent->element)
          parent->left = nullptr;
        else
          parent->right = nullptr;
      }

      delete current; // Delete current
    }
    // Case 1: current has no left children
    else if (current->left == nullptr)
    {
      // Connect the parent with the right child of the current node
      if (parent == nullptr)
      {
        root = current->right;
      }
      else
      {
        if (e < parent->element)
          parent->left = current->right;
        else
          parent->right = current->right;
      }

      delete current; // Delete current
    }
    else
    {
      // Case 2: The current node has a left child
      // Locate the rightmost node in the left subtree of
      // the current node and also its parent
      TreeNode *parentOfRightMost = current;
      TreeNode *rightMost = current->left;

      while (rightMost->right != nullptr)
      {
        parentOfRightMost = rightMost;
        rightMost = rightMost->right; // Keep going to the right
      }

      // Replace the element in current by the element in rightMost
      current->element = rightMost->element;

      // Eliminate rightmost node
      if (parentOfRightMost->right == rightMost)
        parentOfRightMost->right = rightMost->left;
      else
        // Special case: parentOfRightMost->right == current
        parentOfRightMost->left = rightMost->left;

      delete rightMost; // Delete rightMost
    }

    size--;
    return true; // Element inserted
  }

      // Base case, node left or right = nullptr, return -1
      if(someNode == nullptr){
        return -1;
      }

      // Calculate hight of both subtrees
      int leftHeight = GetHeight(someNode->left);
      int rightHeight = GetHeight(someNode->right);

      // Return 1 + max(left or right height) 
      // We can also use std:max from std for comparison, not sure if it is allowed.  
      if (leftHeight > rightHeight){
        return 1 + leftHeight;
      }
      else{
        return 1 + rightHeight;
      }
    }
/////EXERCISE
    // returns the maximum value in the tree
    int Max(){
      if(root == nullptr){
        cout << "The tree is empty, no MAX found." << endl;
        return -1; // If tree includes negative numbers, we could throw error here instead.
      }

      TreeNode* current = root;
      while(current->right != nullptr){ // Traverse to the most right node of the tree.
        current = current->right;
      }
      return current->element; // Return right most node's int element
    }

    // returns the minimum value in the tree
    int Min(){
            if(root == nullptr){
        cout << "The tree is empty, no MIN found." << endl;
        return -1; // Throw error here too.
      }

      TreeNode* current = root;
      while(current->left != nullptr){ // Traverse to the most right node of the tree.
        current = current->left;
      }
      return current->element; // Return right most node's int element
    }

    // returns true if the tree is a binary search tree; false otherwise
    bool IsBST(){
      return IsBSTHelper(root, -2147483648, 2147483647); // Root should be within max and min value an integer can have
    }

    // Check if tree is BST
    bool IsBSTHelper(TreeNode* node, int min, int max){
      // Base case, empty node
      if(node == nullptr){
        return true;
      }

      // If element is not within bounds return false.
      // Checks if right child's value < parrent or left child's value is > than parent's value 
      if(node->element < min || node->element > max){
        return false;
      }
      

      return IsBSTHelper(node->left, min, node->element) && // Left subtree
             IsBSTHelper(node->right, node->element, max); // Right subtree

    }

  // level order display
    void LevelOrderDisplay(){
        LevelOrderDisplay(root);
    }

/////EXERCISE
    // level order display of the tree rooted at someNode
    void LevelOrderDisplay(TreeNode* someNode){

      // If node is empty, return
      if(someNode == nullptr){
        return;
      }
      // Initialize a queue of TreeNode pointers to keep track
      queue<TreeNode*> aQueue;

      aQueue.push(someNode); // Push root of BST

      // While 
      while(!aQueue.empty()){
        TreeNode* current = aQueue.front(); 
        aQueue.pop();

        cout << current-> element << " ";

        if(current->left!= nullptr){ // If there is left child
          aQueue.push(current->left); // Enqueu left sub tree
        }
        if(current->right != nullptr){
          aQueue.push(current->right);
        }
        cout << endl;
      }
    }

    // display tree like a tree horizontally
    void DisplayTreeHorizontally(){
        DisplayTreeHorizontally(root, 0);
    }

    // display the tree rooted at someNode like a tree, horizontally
    void DisplayTreeHorizontally(TreeNode* someNode, int space){
        if(someNode == nullptr){
            return;
        }
        else{
            space += 10;

            DisplayTreeHorizontally(someNode->right, space);

            cout << endl;
            for(int i = 10; i < space; i++){
                cout << " ";
            }
            cout << someNode->element << endl;

            DisplayTreeHorizontally(someNode->left, space);
        }
    }

    // returns the nodes at distance k from the root
    // the distance from the root to the root is 0
    // the distance from the root to its children is 1
    // if k is negative, return an empty vector
    vector<TreeNode> NodesAtDistance(int k){
      vector<TreeNode> nodes; // Vector of TreeNode objects
      NodesAtDistance(*root, k, nodes); // Call helper
      return nodes;
    }

    // Collect nodes at distance K helper function overloading
    void NodesAtDistance(TreeNode& node, int k, vector<TreeNode>& nodes){
      // if node is empty or K negative return
      if(&node == nullptr || k < 0){
        return;
      }
      // If we reached to root
      if(k == 0){
        nodes.push_back(node);
      }
      // Else, search left and right subtrees while reducing the distance to the node
      else{
        if(node.left != nullptr){ // Left child
          NodesAtDistance(*node.left, k-1, nodes);
        }
        if(node.right != nullptr){ // Right child
          NodesAtDistance(*node.right, k-1, nodes);
        }
      }
    }

    // Find the closest common ancestor of 2 nodes
    TreeNode* ClosestCommonAncestor(TreeNode* other){
    //Compaire values with Root moving forward
    return ClosestCommonAncestor(root, other->element, root->element);
    }

    // Find closest common ancestor overloading
    TreeNode* ClosestCommonAncestor(TreeNode* node, int element1, int element2){
      // Base case, if node is nullptr return, least common ancestor not found
      if( node == nullptr){
        return nullptr;
      }
      // If both node's values are less that current
      if(element1 < node->element && element2 < node->element){
        return ClosestCommonAncestor(node->left, element1,element2);
      }
      // If both node's values are more than current.
      if(element1 > node->element && element2 > node->element){
        return ClosestCommonAncestor(node->right, element1,element2);
      }

      //Else current node is the least common ancestor.
      return node;
    }

private:
  TreeNode* root;
  int size;
};

#endif
