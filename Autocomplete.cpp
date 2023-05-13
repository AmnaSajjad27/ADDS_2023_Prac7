#include "Trie.h"
#include "Autocomplete.h"

#include <string>
#include <vector>

using namespace std;

// constructor
Autocomplete::Autocomplete()
{
    rootNode = new Trie();
}

// destructor
Autocomplete::~Autocomplete()
{
    delete rootNode;
}

// helper function 
// recursively finds all words starting with given partial word
void Autocomplete::helper_transverse(Trie *Node, string partialWord, vector<string>& result)
{
    if (Node->end_of_word)
    {
        // found a match, pushback into vector
        result.push_back(partialWord);
    }
    // 26 alphabets, 26 childern that we iteriate through 
    for (int i = 0; i < 26; i++)
    {
        // base case for recurssion, if we reach a leaf, i.e. a node with no childern 
        if (Node->childern[i] != nullptr)
        {
            // offset 
            char character = 'a' + i;
            // recursively call it again till we are at the end of the trie
            // store all the suggestions in the result vector 
            helper_transverse(Node->childern[i], partialWord + character, result);
        }
    }
}

void Autocomplete::insert(string word)
{
    // initalise root node
    Trie *Node = rootNode;

    //for (int i = 0; i < word.length(); i++)
    //char character = word[i];

    for (char character : word)
    {
        if (Node->childern[character - 'a'] == nullptr)
        {
            Node->childern[character - 'a'] = new Trie();
        }
        Node = Node->childern[character - 'a'];
    }
    // set the end of word to true 
    Node->end_of_word = true;
}

vector<string> Autocomplete::getSuggestions(string partialWord)
{
    // initalise vector of strings to store the result in
    vector<string> result;

    Trie *Node = rootNode;

    for(char character : partialWord)
    {
        // if at the end of the trie leaf, return the suggestions 
        if (Node->childern[character - 'a'] == nullptr)
        {
            return result;
        }
        Node = Node->childern[character - 'a'];
    }
    // call helper function to search and store the results 
    helper_transverse(Node, partialWord, result);
    return result;
}