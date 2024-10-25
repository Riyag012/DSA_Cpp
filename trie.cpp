#include <iostream>
using namespace std;
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data){
            data = this->data;
            for (int i = 0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }

};