#include <vector>
#include <string>
#include <algorithm>

#ifndef TRIE_PREFIX_H
#define TRIE_PREFIX_H

// maximum characters as 2, using binary only 0 or 1

class Trie_prefix
{
    public:
    
    Trie_prefix *childern[2];

    int routerNumber;

    Trie_prefix();
};

#endif