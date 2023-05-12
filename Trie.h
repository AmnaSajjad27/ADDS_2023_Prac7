#define TRIE_H
#ifndef TRIE_H

#include <string>
#include <vector>

class Trie
{
    public:
    std::vector<Trie*> childern;
    bool end_of_word;

    Trie();
};

#endif