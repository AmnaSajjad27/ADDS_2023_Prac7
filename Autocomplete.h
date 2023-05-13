#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "Trie.h"

#include <string>
#include <vector>

class Autocomplete
{
    private:
    Trie* rootNode;
    void transverse(Trie *Node, std::string partialWord, std::vector<std::string>& result);

    public:
    Autocomplete();
    ~Autocomplete();

    // return the known words that start with partialWord
    std::vector<std::string> getSuggestions(std::string partialWord);

    // add a word to the known words
    void insert(std::string word);

};

#endif
