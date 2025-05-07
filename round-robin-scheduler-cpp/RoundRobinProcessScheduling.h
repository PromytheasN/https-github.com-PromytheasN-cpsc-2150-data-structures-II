/*
 * Author: Alexander Kemos
 * Date: 10/4/2024
 * Implements round-robin scheduling process,
 * handling process execution times,
 * and calculating turnound times for each process.
*/

#include <iostream>
#include <fstream> 
#include <sstream> 
#include "CircularLinkedList.h"

using namespace std;

#ifndef ROUNDROBINPROCESSSCHEDULING_H
#define ROUNDROBINPROCESSSCHEDULING_H

class RoundRobinProcessScheduling{
    private:
        int timeSlice; //Where time slice is kept
        CircularLinkedList executionTimes;//Process execution times kept here (in CLL)
        CircularLinkedList turnaroundTimes;//Store turn around times

    public:

    //Getter
    int getTimeSlice() const {
        return timeSlice; 
    }

    void displayExecutionTimes() const {
        executionTimes.display(); // Call the display method from CircularLinkedList
    }



    void LoadFromFile(string fileName){
        ifstream input(fileName); //Create an input stream instance of inserted file

        //Check if file is open
        if(!input.is_open()){
            cout << "Error." << endl;
            return;
        }

        string lineInput; //To hold information from input stream as a string

        //take input of first line (time slice)
        getline(input, lineInput);
        timeSlice = stoi(lineInput);

        //Take input of second line
        if (getline(input, lineInput)) {
            stringstream inputStream(lineInput);
            int processTime;
            
            while (inputStream >> processTime) { //Extract each process time
                executionTimes.insert(processTime); //Insert each process time as a node in the circular linked list
                if (inputStream.peek() == ',') { //Check if the next character is a comma
                    inputStream.ignore(); //Skip the comma to move to the next value
                }
            }
        }   
        input.close(); //Close input stream
    }

    //Round-robin stimulator
    void Process() {
        CircularLinkedList timesLeft = executionTimes; //Copy original times CLL
        int clock = 0;
        bool completed = false; 

        //Initialize turnaroundTimes with zeros for all processes
        for (int i = 0; i < executionTimes.size(); i++) {
            turnaroundTimes.insert(0);
        }

        while (!completed) {
            completed = true;

            //Loop through each process
            for (int i = 0; i < executionTimes.size(); i++) {
                int remainingTime = timesLeft.getNodeData(i);

                if (remainingTime > 0) { //If process needs more time to complete
                    completed = false; //At least one process hasn't completed
                    if (remainingTime > timeSlice) {
                        clock += timeSlice; 
                        timesLeft.update(i, remainingTime - timeSlice); //Reduce remaining time
                    } else {
                        //Process completes in this round
                        clock += remainingTime;
                        timesLeft.update(i, 0); //Mark the process as complete
                        turnaroundTimes.update(i, clock); //Save turnaround time remeinder for each process
                    }
                }
            }
        }
    }

    //Display turn-around times
    void ShowResults() {
        int numProcesses = executionTimes.size(); //Get total processes number
        int clock = 0; //Track time

        cout << "Turnaround times for each process:" << endl;

        //Loop through processes list and rint turnaround times
        for (int i = 0; i < numProcesses; i++) {
            int turnaroundTime = turnaroundTimes.getNodeData(i);
            cout << "Process " << i + 1 << ": " << turnaroundTime << endl;
            clock += turnaroundTime;
        }

        // Calculate and display the average turnaround time
        double averageTurnaroundTime = static_cast<double>(clock) / numProcesses;
        cout << "Average turnaround time: " << averageTurnaroundTime << endl;
    }

    

    //Destructor
    ~RoundRobinProcessScheduling() = default; 
};


#endif