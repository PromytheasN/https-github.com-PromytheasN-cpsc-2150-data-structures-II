#include <iostream>
#include "theBST.h"

using namespace std;

int main(){
    BST tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    // tree.insert(3);
    // tree.insert(8);


    cout << "Horizontal desplay of tree" << endl;
    tree.DisplayTreeHorizontally();

    tree.insert(12);
    tree.insert(22);
    tree.insert(33);

    cout << "Horizontal desplay of tree after insertion: 12, 22, 33" << endl;
    tree.DisplayTreeHorizontally();

    // Test inorder
    cout << "In order travesal" << endl;
    tree.inorder();
    cout << endl;

    // Test search
    TreeNode* result = tree.search(12);
    if(result != nullptr){ // If found
        cout << "Element 12 found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    result = tree.search(18);
    if(result != nullptr){ // If found
        cout << "Element 12 found" << endl;     
    }
    else{
        cout << "Not found" << endl;
    }

    // Test getSize
    cout << "The size of the tree is: " << tree.getSize() << endl;

    // Test GetHeight 
    int height = tree.GetHeight(tree.search(20)); // Get height from root
    cout << "Height of the tree: " << height << endl;

    // Test Max and Min 
    cout << "Maximum value in the tree: " << tree.Max() << endl;
    cout << "Minimum value in the tree: " << tree.Min() << endl; 

    // Test Max and Min 
    cout << "Maximum value in the tree: " << tree.Max() << endl;
    cout << "Minimum value in the tree: " << tree.Min() << endl;

     // Test IsBST 
    bool isBST = tree.IsBST();
    cout << "The tree is " << (isBST ? "a BST." : "not a BST.") << endl;

    // Test LevelOrderDisplay 
    cout << "Level order display of the tree:" << endl;
    tree.LevelOrderDisplay();

    // Test NodesAtDistance 
    int k = 2;
    vector<TreeNode> nodesAtDistance = tree.NodesAtDistance(k);
    cout << "Nodes at distance " << k << " from the root: ";
    for (const auto& node : nodesAtDistance) {
        cout << node.element << " ";
    }
    cout << endl;

    // Test ClosestCommonAncestor
    int el1 = 5, el2 = 10;
    TreeNode* lca = tree.ClosestCommonAncestor(tree.search(el1));
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << el1 << " and " << el2 << " is: " << lca->element << endl;
    } else {
        cout << "There is no Common Ancestor." << endl;
    }

    // Test remove function
    int removeValue = 10;
    cout << "Removing element " << removeValue << " from the tree. " << endl;
    bool removed = tree.remove(removeValue);
    cout << "Element " << removeValue << (removed ? " removed successfully." : " not found in the tree.") << endl;

    // Display the tree after removal
    cout << "Tree after removal: "<< endl;
    tree.DisplayTreeHorizontally();

    // Test clear
    tree.clear();
    cout << "Tree after clearing:"<< endl;
    tree.DisplayTreeHorizontally();
    
    return 0;
}