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
int getdir (string dir, vector<string> &files);


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
                //cout << outputWord << endl;
                removeWord = nWords.front();
                nWords.pop();
                currentSet.erase(currentSet.begin(), currentSet.begin() + removeWord.length() + 1);
            }
        }
        currentFile.close();
    }
    for(int i = 0; i < numFiles; i++){
        fileCollisions[i] = new int[numFiles];
    }

    for(int i = 0; i < numFiles; i++){
        for(int j = 0; j < numFiles; j++){
            fileCollisions[i][j] = 0;
        }
    }

    table.determineCollisions(fileCollisions);
    int numOverlaps = 0;
    for(int i = 0; i < numFiles; i++){
        for(int j = i+1; j < numFiles; j++){
            if(fileCollisions[i][j] >= cutoff){
                numOverlaps++;
                cout << fileCollisions[i][j] << " collisions between " << files[i+2] << "and " << files[j+2] << endl;
            }
        }
    }
    cout << numOverlaps << endl;
    for(int i = 0; i < numFiles; i++){
        delete[] fileCollisions[i];
    }

    return 0;
}

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