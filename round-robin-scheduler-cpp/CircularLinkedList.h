#include <iostream>
using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
    int data;
    Node* next;

    //Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* last;

public:
    //Constructor
    CircularLinkedList() : last(nullptr) {}

    //Get node Data
    int getNodeData(int position) const {
        if (!last) { //If list is empty
            cout << "List is Empty" << endl;
            return -1;
        }
        Node* current = last->next; //Start at the first node
        int index = 0;
        while (current != last->next || index == 0) {
            if (index == position) {
                return current->data;
            }
            current = current->next; 
            index++;
        }
        return -1;
    }



    // Insert a new node with data at the end of the circular linked list
    void insert(int data) {
        Node* new_node = new Node(data); 
        if (!last) { 
            last = new_node; 
            last->next = last; 
        } else { 
            new_node->next = last->next; 
            last->next = new_node; 
            last = new_node; 
        }
    }

    // Delete a node with the given data
    void deleteNode(int data) {
        if (!last) //If list is empty terminate
            return;

        Node* current = last->next; 
        Node* previous = nullptr;

        while (current->next != last->next) {//While our current pointer points to to a different location than the beginig of CLL
            if (current->data == data) { //if we found a node with the data we are searching for
                if (current == last->next)
                    last->next = last->next->next;
                if (current == last)
                    last = previous;
                if (previous)
                    previous->next = current->next;
                delete current; 
                return;
            }
            previous = current; 
            current = current->next;
        }

        if (current->data == data) { //If we locate the data at the begining of the list
            if (current == last->next)
                last->next = last->next->next;
            if (current == last)
                last = previous;
            if (previous)
                previous->next = current->next;
            delete current;
        }
    }

    // Search for a node with the given data
    bool search(int data) {
        if (!last)
            return false;

        Node* current = last->next;

        do {
            if (current->data == data)
                return true;
            current = current->next;
        } while (current != last->next);

        return false;
    }

    // Display all elements in the circular linked list
    void display() const {
        if (!last)
            return;

        Node* current = last->next;

        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != last->next);

        cout << endl;
    }

    //Return linked list size
    int size() const {
        if (!last) //If list is empty, return 0
            return 0;

        int count = 0;
        Node* current = last->next;
        
        while (current != last) { //Loop throughout the whole linked list.
            count++; 
            current = current->next;
        }
        count++; 

        return count;
    }


    void update(int position, int newValue) {
        if (!last) { // Check if the list is empty
            cout << "List is empty." << endl;
            return;
        }

        Node* current = last->next; 
        int index = 0; 
        while (current != last->next || index == 0) { //Loop through the list
            if (index == position) { //If we've reached the position
                current->data = newValue; //Update data
                return;
            }
            current = current->next; 
            index++;
            if (current == last->next) { //Break if we completed full cycle
                break;
            }
        }

        cout << "Position out of bounds." << endl; //Print error if invalid index
    }




    //Destructor
    ~CircularLinkedList(){
        //Check if list is empty
        if(!last){
            return;
        }

        Node* current = last->next; //Create node pointer pointing to first node
        Node* next; //Node pointer 

        while(current != last){
            next = current -> next; //Next point to current's next node
            delete current;
            current = next; //Move current to next
        }
        delete last;
        last = nullptr;
    }
};

#endif