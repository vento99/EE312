

#ifndef LAB8_HASHTABLE_H
#define LAB8_HASHTABLE_H
#include <string>

using namespace std;
class hashTable{
    private:
        struct HashNode
        {
            int fileIndex;
            HashNode *next;
        };
        static const int SIZE = 1502719;
        HashNode* table[SIZE];
    public:
        hashTable();
        int hashingFunction(string value);
        void put(string word, int fileIndex);
        void determineCollisions(int *matrix[]);
        ~hashTable();

};



#endif //LAB8_HASHTABLE_H
