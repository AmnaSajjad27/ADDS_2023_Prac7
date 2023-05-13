#include "Trie.h"
#include "Autocomplete.h"

#include <string>
#include <vector>

using namespace std;

Autocomplete::Autocomplete()
{
    rootNode = new Trie();
}

Autocomplete::~Autocomplete()
{
    delete rootNode;
}

void Autocomplete::transverse(Trie *Node, string partialWord, vector<string>& result)
{
    if (Node->end_of_word)
    {
        result.push_back(partialWord);
    }
    for (int i = 0; i < 26; i++)
    {
        if (Node->childern[i] != nullptr)
        {
            // offset 
            char character = 'a' + i;
            // recursively call it again till we are at the end of the trie
            transverse(Node->childern[i], partialWord + character, result);
        }
    }
}

void Autocomplete::insert(string word)
{
    Trie *Node = rootNode;

    for (char character : word)
    {
        if (Node->childern[character - 'a'] == nullptr)
        {
            Node->childern[character - 'a'] = new Trie();
        }
        Node = Node->childern[character - 'a'];
    }
    Node->end_of_word = true;
}

vector<string> Autocomplete::getSuggestions(string partialWord)
{
    vector<string> result;

    Trie *Node = rootNode;

    for(char character : partialWord)
    {
        if (Node->childern[character - 'a'] == nullptr)
        {
            return result;
        }
        Node = Node->childern[character - 'a'];
    }
    transverse(Node, partialWord, result);
    return result;
}