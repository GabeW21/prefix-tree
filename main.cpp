#include "prefix.h"

int main(){
    Trie test = Trie();
    /*****************Debugging and testing***************************
    test.insertSentence("this project has to be so cool as this project will be my final grade and i want it work and and and");
    test.printTrie();

    test.nodeInfo("an");
    cout << "the word project was found: " << test.search("project") << endl;
    cout << "the prefix this was found: " << test.findPrefix("this") << endl;
    test.mostCommonWord();
    test.remove("and");
    test.mostCommonWord();
    test.removeAll("and");
    cout << "Is it found (0 no, 1 yes): " << test.search("and") << endl;
    test.showPrefixCount("an");
    test.showPrefixCount("pro");
    test.giveRecommendedWord("proj");
    */
    int choice;
    string thing;
    test.mostCommonWords();
    while(true){
        cout << "Trie Main Menu" << endl;
        cout << "1. Insert a word" << endl;
        cout << "2. Check most common word" << endl;
        cout << "3. Remove a word" << endl;
        cout << "4. Insert a sentence (no special chars/uppercase)" << endl;
        cout << "5. Get recommended word (autocorrect)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice){
            case 1:
            cout << "Enter the word you wish to insert: " << endl;
            cin >> thing;
            test.insert(thing);
            break;
            case 2:
            test.mostCommonWord();
            break;
            case 3:
            cout << "Enter the word you wish to remove fully: " << endl;
            cin >> thing;
            test.removeAll(thing);
            break;
            case 4:
            cout << "Enter the sentence you wish to add: " << endl;
            getline(cin,thing);
            test.insertSentence(thing);
            break;
            case 5:
            cout << "Enter incomplete word: " << endl;
            cin >> thing;
            test.giveRecommendedWord(thing);
            break;
            case 6:
            cout << "Terminating program." << endl;
            return 0;
            default:
            cout << "Enter a valid input" << endl;
            break;
        }
    }
}