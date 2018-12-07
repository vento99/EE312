/* hashTable.h
Anthony Vento

 Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Anthony Vento, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Anthony Vento
 * email address: anthony.vento@utexas.edu
 * UTEID: amv2987
 * Section 5 digit ID: 16235
 *
 */

// This file is the header that defines methods relating for hashTable class
// Date: December 7, 2018

#ifndef LAB8_HASHTABLE_H
#define LAB8_HASHTABLE_H
#include <string>

using namespace std;
class hashTable{
    private:
        struct HashNode  //struct for each linkedlist node within the table
        {
            int fileIndex;
            HashNode *next;
        };
        static const int SIZE = 1502719;
        HashNode* table[SIZE];

    public:
        //Default constructor
        //Initializes all indicies of the table to NULL
        hashTable();

        //hashingFunction
        //inputs: string which will be hashed
        //outputs: output of hash function
        //implements the hashingFunction
        int hashingFunction(string value);

        //put
        //inputs: a sequence of N words, and a file index
        //outputs: N/A
        //puts the fileIndex into the appropriate position in the table
        void put(string sequence, int fileIndex);

        //determineCollisions
        //inputs: an array of ints, and the number of files
        //outputs: N/A
        //inititializes and populates the collision matrix
        void determineCollisions(int *matrix[], int numFiles);

        //Destructor
        //Goes through and deletes the dynamically allocated memroy
        ~hashTable();
};



#endif //LAB8_HASHTABLE_H
