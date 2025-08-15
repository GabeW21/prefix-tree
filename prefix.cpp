#ifndef PREFIX_CPP
#define PREFIX_CPP
#include "prefix.h"

Trie::Trie(){//Using to construct the root with a defined TrieNode and setting all variables
    root = new TrieNode();
    root->isEndOfWord = false;
    root->useCount = 0;

    for (int i = 0; i < 26; i ++){
        root->letters[i] = NULL;
    }
} 

Trie::~Trie(){}

void Trie::printTrie(){//Debugging essentially
    printHelper(root);
}


void Trie::printHelper(TrieNode* node){//Helper function for printTrie
    cout << node->letter << endl;
    for (int i = 0; i < 26; i++){
        if (node->letters[i] != NULL)
            printHelper(node->letters[i]);
    }
}


void Trie::nodeInfo(string prefix){
    TrieNode* node = new TrieNode();
    node = root;
    for (char& n:prefix){
        if (node->letters[n-'a'] == NULL){
            cout << "Does not exist" << endl;
            return;
        }
        node = node->letters[n-'a'];
    }
    nodeCheck(node);
}


void Trie::nodeCheck(TrieNode* node){
    cout << "This is the node's isEndOfWord:" << node->isEndOfWord << endl;
    cout << "This is the node's letter:" << node->letter << endl;
    cout << "This is the node's useCount:" << node->useCount << endl;
}

 
void Trie::insert(string word){//Standard Trie insert for word

    TrieNode* curr = root;
    for (char& n:word){
        if (curr->letters[n-'a'] == NULL){
            TrieNode* newNode = new TrieNode();
            newNode->letter = n;
            curr->letters[n-'a'] = newNode; 
        }
        curr->letters[n-'a']->useCount++;
        curr = curr->letters[n-'a'];
    }
    curr->isEndOfWord = true;
}          


bool Trie::search(string word){//Search method for finding a word starting from the root
    TrieNode* node = new TrieNode();
    node = root;
    for (char& n:word){
        if (node->letters[n-'a'] == NULL){return false;}
        node = node->letters[n-'a'];
    }
    if (node->isEndOfWord == true){return true;}
    return false;
}          


bool Trie::findPrefix(string prefix){//Method to find if a prefix exists that is not the full word. So ensure isEndOfWord is false as well
    TrieNode* node = new TrieNode();
    node = root;
    for (char& n:prefix){
        if (node->letters[n-'a'] == NULL){return false;}
        node = node->letters[n-'a'];
    }
    if (node->isEndOfWord == false){return true;}
    return false;
}    

void Trie::remove(string word){//Standard remove function with associated helper
    if (!search(word)){
        cout << "Word is not in the trie" << endl;
        return;
    }
    removeHelp(word, root);
}          


void Trie::removeHelp(string word, TrieNode* node){
    if (!node){return;}
    char removal = word[0];
    node = node->letters[word[0]-'a'];
    if (!node){return;}
    if (word.length() > 1){
        word = word.substr(1);
        removeHelp(word,node);
    }
    node->useCount--;
    if (node->useCount == 0){
        delete node;
        node->letters[removal-'a'] = NULL;
    }
}




void Trie::removeAll(string word){
    while (search(word)){
        remove(word);
    }
}


void Trie::showPrefixCount(string prefix){//Show the count of how many times this prefix has been used in the trie
    TrieNode* node = new TrieNode();
    node = root;
    for (char& n:prefix){
        if (node->letters[n-'a'] == NULL){return;}
        node = node->letters[n-'a'];
    }
    cout << "The prefix '" << prefix << "' was used " << node->useCount << " times" << endl;
}   


void Trie::insertSentence(string sentence){//Take in a full sentence and insert in the trie
    stringstream ss(sentence);
    string word;
    vector<string> words;

    while (ss >> word){
        words.push_back(word);
    }

    for (auto& word:words){
        insert(word);
    }
}  


void Trie::giveRecommendedWord(string prefix){//Taking in an incomplete word give a recommendation for what word can be shown (to demonstrate autocorrect possibilities)
    TrieNode* node = new TrieNode();
    node = root;
    string word = prefix;
    for (char& n:prefix){
        if (node->letters[n-'a'] == NULL){return;}
        node = node->letters[n-'a'];
    }
    int index = 0;
    int max = 0;
    while(true){
        if (node->isEndOfWord){
            cout << "Recommended word to use is: " << word << endl;
            return;
        }
        max = 0;
        for (int j = 0; j < 26; j++){
            if (node->letters[j] == NULL){
                continue;
            }
            if (node->letters[j]->useCount > max){
                max = node->letters[j]->useCount;
                index = j;
            }
        }
        word += node->letters[index]->letter;
        node = node->letters[index];
    }
}   




void Trie::mostCommonWord(){//Take look through the root and see what the most common letter combination is
    TrieNode* node = root;
    int max = 0;
    int index = 0;
    string word = "";
    while(true){
        if (node->isEndOfWord){
            cout << "Most common word is: " << word << endl;
            cout << "Used " << max << " times" << endl;
            return;
        }
        max = 0;
        for (int j = 0; j < 26; j++){
            if (node->letters[j] == NULL){
                continue;
            }
            if (node->letters[j]->useCount > max){
                max = node->letters[j]->useCount;
                index = j;
            }
        }
        word += node->letters[index]->letter;
        node = node->letters[index];
    }
} 

void Trie::mostCommonWords(){
    TrieNode* node = root;
    int max = 0;
    mostCommonWordHelper(max,node);

}

void Trie::mostCommonWordHelper(int& max, TrieNode* node){

}

#endif