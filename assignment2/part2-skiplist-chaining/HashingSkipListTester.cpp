#include <iostream>
#include "HashingSkipList.h"

using namespace std;


int main() {
    //Initialize hash table size = 5 and load factor threshold = 0.65
    HashingSkipList hashTable(5, 0.65);
    
    //Insert values into the hash table
    cout << "Inserting values: 3, 23, 11, 15, 9" << endl;
    hashTable.Insert(3);
    hashTable.Insert(23);
    hashTable.Insert(11);
    hashTable.Insert(15);
    hashTable.Insert(9);

    //Display hash table
    cout << "\n Current Hash table: " << endl;
    hashTable.Display();

    //Insert additional values exceeding threshold and activating rehashing
    cout << "\nInserting values to activating rehashing: 35, 44" << endl;
    hashTable.Insert(35);
    hashTable.Insert(44);

    //Display hash table
    cout << "\nHash table after rehashing: " <<endl;
    hashTable.Display();

    //Search for values
   cout << "\nSearching values: " << endl;
    int searchValues[] = {23, 70, 44};
    for (int value : searchValues) {
        bool found = hashTable.Search(value);
        cout << "Value " << value << (found ? " found." : " not found.") << endl; //Print whether value found or not
    }

    //Delete existing or not values
    cout << "\nDeleting values: " << endl;
    int deleteValues[] = {23, 70, 44};
    for (int value : deleteValues) {
        hashTable.Delete(value);
    }

    // Display hash table after deletions
    cout << "\nHash table after deletions: " << endl;
    hashTable.Display();

    return 0;
}
