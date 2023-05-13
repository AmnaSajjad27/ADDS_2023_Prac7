#include "PrefixMatcher.h"
#include "Trie_prefix.h"

#include <string>
#include <vector>

PrefixMatcher::PrefixMatcher()
{
    rootNode = new Trie_prefix();
}

// PrefixMatcher::~PrefixMatcher()
// {
//     // destroy the Trie 
//     delete rootNode;
// }

void PrefixMatcher::insert(std::string address, int routerNumber)
{
    Trie_prefix *temp = rootNode;
    
    // same for loop as getSuggestions 
    // but now we offset by '0' becuase binary 
    for (char character : address)
    {
        int i = character - '0';
        if (!temp->childern[i])
        {
            // check if not, if not then insert 
            temp->childern[i] = new Trie_prefix();
        }
        // update the current temporary leaf
        temp = temp->childern[i];
    }
    temp->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress)
{
    Trie_prefix *temp = rootNode;

    int last_found = -1;
    
    for (char character : networkAddress)
    {
        int i = character - '0';
        if (!temp->childern[i])
        {
            // if found the longest, break and return 
            break;
        }
        temp = temp->childern[i];
        // if matched, we initlised to -1
        if(temp->routerNumber != -1)
        {
            // store it in last_found and return 
            last_found = temp->routerNumber;
        }
    }
    return last_found;
}

void PrefixMatcher::free_Node(Trie_prefix *Node)
{
    if (!Node)
    {
        // nothing to delete
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        free_Node(Node->childern[i]);
    }
    delete Node;
}