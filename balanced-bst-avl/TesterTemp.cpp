#include <iostream>
#include "AVLTree.h"
using namespace std;

int main() {
    // Create AVL Tree
    AVLTree tree;

    // Insertion and Balancing
    cout << "Inserting elements." << endl;
    int elements[] = {13, 22, 42, 11, 25, 37, 52, 5, 13};
    for(int el : elements){
        tree.insert(el);
        cout << "Inserting " << el << endl;
        tree.LevelOrderDisplay();
    }

    // Search
    cout << "\n Testing Search function" << endl;
    for(int el : elements){
        if(tree.search(el) != nullptr){
            cout << "Found " << el << endl;
        }
        else{
            cout << el << " not found" << endl;
        }
    }

    // Delete and Balancing
    cout << "\nDeleting elements" << endl;
    int elementsToDelete[] = {11, 25, 37};
    for(int el : elementsToDelete){
        if(tree.remove(el)) {
            cout << "Deleting " << el << endl;
            tree.LevelOrderDisplay();
        }
        else{
            cout << "Element " << el << " not found to delete" << endl;
        }
    }

    // Display Functions
    cout << "\nAVL Tree Horizontally:" <<endl;
    tree.DisplayTreeHorizontally();

    cout << "\nLevel Order Display:" << endl;
    tree.LevelOrderDisplay();

    // Count and CountNodesAtLevel
    cout << "\nCount of nodes between 15 and 40: " << tree.Count(15, 40) << endl;
    cout << "Nodes at level 2: " << tree.CountNodesAtLevel(2) << endl;

    // Diameter of AVL Tree
    cout << "\n The diameter of the AVL Tree is: " << tree.Diameter() << endl;

    return 0;
}
