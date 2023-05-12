#define AUTOCOMPLETE_H
#ifndef AUTOCOMPLETE_H

#include "Trie.h"

#include <string>
#include <vector>

class Autocomplete
{
    private:
    Trie* rootNode;
    void transverse(Trie *Node, std::string partialWord, std::vector<string>& result);

    public:
    Autocomplete();

    // return the known words that start with partialWord
    vector<string> getSuggestions(std::string partialWord);

    // add a word to the known words
    void insert(std::string word);

};

#endif
