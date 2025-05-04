#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SkipList.h"

using namespace std;

int main(){
    srand(time(0));
 
    SkipList lst(3); // skiplist with maximum allowed level index
 
    lst.InsertElement(13);
    lst.InsertElement(7);
    lst.InsertElement(11);
    lst.InsertElement(1);
    lst.InsertElement(5);
    lst.InsertElement(19);

    lst.InsertElement(313);
    lst.InsertElement(37);
    lst.InsertElement(311);
    lst.InsertElement(31);
    lst.InsertElement(35);
    lst.InsertElement(319);

    lst.Show();

    return 0;
}