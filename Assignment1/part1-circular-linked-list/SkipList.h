#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include "Node.h"


#ifndef SKIPLIST_H
#define SKIPLIST_H

using namespace std;

class SkipList{
public:
    // Maximum allowed level index
    int MAXIMUM_ALLOWED_LEVEL_INDEX; //The maxium level of skipped list wont change after construction of each list
 
    // current maximum level amongst the inserted nodes
    int currentHighestLevelIndex;
    
    // the head node's next links are connected to the first node at every level
    Node *head;

    SkipList(int maxLevels){
        MAXIMUM_ALLOWED_LEVEL_INDEX = maxLevels;

        // initially we have the bottom-most level only
        currentHighestLevelIndex = 0;
    
        // create the header node, value is irrelevant (as long as it doesn't match an inserted value - NO REPEATS), number of next links is important (initially this node is the first node at every level)
        head = new Node(INT_MIN, MAXIMUM_ALLOWED_LEVEL_INDEX); //Doesnt contain any value
    }

    int RandomLevel(){
        float probablity = (float)rand()/RAND_MAX; // flip a coin
        int lvl = 0;
        while (probablity < 0.5 && lvl < MAXIMUM_ALLOWED_LEVEL_INDEX){
            lvl++; // landed heads so increase level by 1
            probablity = (float)rand()/RAND_MAX; // flip a coin again
        }
        return lvl;        
    }

    Node* CreateNode(int value, int level){
        // create a new node with next links for every level that this node will be part of
        // it will use these links to connect to the next node at each level  
        return new Node(value, level);
    }

    void InsertElement(int value){
        Node *current = head; // start at head node
        vector<Node*> update(MAXIMUM_ALLOWED_LEVEL_INDEX+1, nullptr); // this will hold the nodes that need updating at every level after the insert takes place
        for (int i = currentHighestLevelIndex; i >= 0; i--){ // start at the highest level and move down so that more nodes may be skipped
            // for level i, if value is to be inserted here then find out where (i.e. after which node)
            while (current->next[i] != nullptr && current->next[i]->value < value){
                current = current->next[i]; //We have an array of next links, its next link at level i
            }
            // found the node after which the value is to be placed at level i, move down a level, if possible 
            update[i] = current;
        }    
        
        // at level 0, where current is pointing to by the end of the preceding loop, move over one node to where the value is to be inserted to see if the value already exists there (NO REPEATS allowed)
        current = current->next[0];
    
        if (current == nullptr || current->value != value){
            int ranLevel = RandomLevel(); // choose a random level upto where the new node will be placed
    
            if (ranLevel > currentHighestLevelIndex){
                // if random level for current node is higher than the current maximum level for existing nodes; then set head as the node after which the new value is to be inserted for each level over current maximum to the level chosen for new value to be inserted (update currently contains nulls for these level(s)).
                for (int i = currentHighestLevelIndex+1; i <= ranLevel; i++){
                    update[i] = head;
                }
    
                // also change the current maximum level for the existing nodes
                currentHighestLevelIndex = ranLevel;
            }
    
            // create new node with next links for every level from ranLevel to zero
            Node* n = CreateNode(value, ranLevel);
    
            // placing new node in the correct place at every level
            for (int i = 0; i<=ranLevel; i++){
                n->next[i] = update[i]->next[i]; //Connect new node pointing it where the node before was pointing
                update[i]->next[i] = n; //Connect previous node with current new node.
            }
        }
           
    }

    void Delete(int value){
        // TO BE COMPLETED
        // remove value from skip list (all levels) if it exists (output a message if it does not exist)
    }

    bool Search(int value){
        // TO BE COMPLETED
        // search for value in skip list and return true if it exists; false otherwise
    }

    void Show(){
        for (int i=0;i<=currentHighestLevelIndex;i++){
            Node *node = head->next[i];
            cout << "Level " << i << ": ";
            while (node != nullptr && node->next[i] != nullptr){
                cout << node->value << " -> ";
                node = node->next[i];
            }
            cout << node->value << " .\n";
        }
    }
};

#endif