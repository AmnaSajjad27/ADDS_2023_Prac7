#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <vector>
#include "Trie_prefix.h"

class PrefixMatcher
{
    public:
    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);

    PrefixMatcher();
    void free_Node(Trie_prefix *Node);

    //private:
    Trie_prefix *rootNode;

};

#endif