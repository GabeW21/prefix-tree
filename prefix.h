#ifndef PREFIX_H
#define PREFIX_H

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


struct TrieNode {
    bool isEndOfWord;       //Boolean if it is the end of the word. Used to check if end of word or if still a prefix for another word, explained more in implemented functions
    TrieNode* letters[26];  //Storage of the Trie Nodes that a word leads to. Will be initialized to NULL for each position
    char letter;            //The stored letter at the node in the chain of prefixes
    int useCount;           //How many words used this node in its prefix. Can be the starting letter or even multiple characters in
    TrieNode* previous;
};

// Trie data structure
class Trie {
private:
    TrieNode* root;

public:
    Trie(); //Using to construct the root with a defined TrieNode and setting all variables
    ~Trie(); //Don't plan on using, but kept for best practice      
    void printTrie();                   //Using to print the trie and see if the structure is as expected
    void printHelper(TrieNode* node);   //Using recursion to search through the tree and print the words  
    void nodeInfo(string prefix);       //Print node info of where prefix is (last node in the prefix)
    void nodeCheck(TrieNode* node);     //Print out the node info
    void insert(string word);           //Standard Trie insert for word
    bool search(string word) ;         //Search method for finding a word starting from the root
    bool findPrefix(string prefix) ;   //Method to find if a prefix exists that is not the full word. So ensure isEndOfWord is false as well
    void remove(string word);          //Standard remove function with associated helper
    void removeHelp(string word, TrieNode* node);
    void removeAll(string word);        //Remove every instance of the word rather than a single instance
    void showPrefixCount(string prefix);   //Show the count of how many times this prefix has been used in the trie
    void insertSentence(string sentence);  //Take in a full sentence and insert in the trie
    void giveRecommendedWord(string prefix);   //Taking in an incomplete word give a recommendation for what word can be shown (to demonstrate autocorrect possibilities)
    void mostCommonWords();  //Take look through the root and see what the most common word is at that point in time
    TrieNode* mostCommonWordHelper(int& max, TrieNode* node);
    void mostCommonWord();  //Take look through the root and see what the most common letter combination is
    void reverseTraversal(TrieNode* node);  //Print out the word that comes from this node, used with end of tree node
};

#endif
