/* main.cpp
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

// This file is the main driver for the Cheaters assignment
// Date: December 7, 2018

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>
#include <queue>
#include "hashTable.h"

using namespace std;

//Function prototypes. For documentation, scroll down to the functon.
int getdir (string dir, vector<string> &files);
void initializeOutput(vector<vector<int> > &output, int cutoff, int numFiles, int *fileCollisions[]);
void sortOutput(vector<vector<int> > &output);
void putNWords(const string &path, int n, hashTable &table, const vector<string> &files);

int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "Please run again with correct format of input" << endl;
        return 0;
    }
    string path = string(argv[1]);
    int n = atoi(argv[2]);
    int cutoff = atoi(argv[3]);

    vector<string> files = vector<string>();
    getdir(path, files);

    int numFiles = files.size() - 2;
    int *fileCollisions[numFiles];
    hashTable table;

    putNWords(path, n, table, files);
    table.determineCollisions(fileCollisions, numFiles);

    vector<vector<int> > output;
    initializeOutput(output, cutoff, numFiles, fileCollisions);
    if(output.empty()){
        cout << "No plagiarism detected for the given inputs!" << endl;
        return 0;
    }
    sortOutput(output);
    for(int i = 0; i < output.size(); i++){
        cout << output[i][0] << " collisions between " << files[output[i][1]] << " and " << files[output[i][2]] << endl;
    }

    for(int i = 0; i < numFiles; i++){
        delete[] fileCollisions[i];  //prevent leaks
    }
    return 0;
}
//getdir
//inputs: string which holds directory, and reference to vector
//outputs: int: 0 if successful, errno if not
//populates the files vector with a list of all the file names in the directory
int getdir (string dir, vector<string> &files) {
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

//initiatlizeOutput
//inputs:  reference to the vector of vectors which will hold the # of collision, and two file indicies,
//         cutoff specified by user, the number of files, and the collision matrix
//outputs: N/A
//populates the output vector of vector with the # of collisions, and the two files indicies
void initializeOutput(vector<vector<int> > &output, int cutoff, int numFiles, int *fileCollisions[]){
    for(int i = 0; i < numFiles; i++){
        for(int j = i+1; j < numFiles; j++){
            if(fileCollisions[i][j] >= cutoff){
                vector <int> currCollision;
                currCollision.push_back(fileCollisions[i][j]);
                currCollision.push_back(i+2);
                currCollision.push_back(j+2);
                output.push_back(currCollision);
            }
        }
    }
}

//sortOutput
//inputs: reference to output vector of vectors
//outputs: N/A
//sorts the output in descending order by the number of collisions
void sortOutput(vector<vector<int> > &output){
    for(int i = 0; i < output.size()-1; i++){
        for(int j = 0; j < output.size()-1; j++){
            if(output[j][0] < output[j+1][0]){
                vector<int> temp = output[j];
                output[j] = output[j+1];
                output[j+1] = temp;
            }
        }
    }
}

//putNWords
//inputs: reference to path, the number of words, the hashTable, and the vector of files
//outputs: none
//iterates through files and adds each sequence of n words to the hashTable
void putNWords(const string &path, int n, hashTable &table, const vector<string> &files){
    for (unsigned int i = 2; i < files.size(); i++) {
        string filePath = path + "/" + files[i];
        ifstream currentFile(filePath.c_str());
        string word;
        queue<string> nWords;
        string currentSet;
        string removeWord;
        while(currentFile >> word){
            currentSet += word + " ";
            nWords.push(word);
            if(nWords.size() == n){
                string outputWord = currentSet.substr(0, currentSet.length() - 1);
                table.put(outputWord, i-2);
                //cout << outputWord;
                removeWord = nWords.front();
                nWords.pop();
                currentSet.erase(currentSet.begin(), currentSet.begin() + removeWord.length() + 1);
            }
        }
        currentFile.close();
    }
}