#include <iostream>
#include "RoundRobinProcessScheduling.h"

using namespace std;

int main() {
    RoundRobinProcessScheduling roundRobin; //Create instance of round-robin scheduler

    //Load Data
    roundRobin.LoadFromFile("process.txt");

    // Display the loaded execution times and timeslice
    cout << "Loaded process execution times:" << endl;
    roundRobin.displayExecutionTimes();
    cout << "Processor time slice:" << endl;
    cout << roundRobin.getTimeSlice() << endl;

    // Execute the round-robin scheduling
    roundRobin.Process();

    // Display the results (turnaround times and average turnaround time)
    roundRobin.ShowResults();

    return 0;
}
