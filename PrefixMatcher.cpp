#include "PrefixMatcher.h"
#include "Trie_prefix.h"

#include <string>
#include <vector>

// constructor 
PrefixMatcher::PrefixMatcher()
{
    rootNode = new Trie_prefix();
}

// Need to destroy each node 
// PrefixMatcher::~PrefixMatcher()
// {
//     // destroy the Trie 
//     delete rootNode;
// }

// insert function, same as before
// probably can implement in trie class for both part 1 and 2 and use from there as a method 
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

// select router that matches the longest prefix  
int PrefixMatcher::selectRouter(std::string networkAddress)
{
    // iniialise root Node 
    Trie_prefix *temp = rootNode;

    // set last found to -1, will change if we find, if not use to return 
    int last_found = -1;
    
    // character will be assigned the next character in networkAddress, until we exhaust all characters 
    // i.e. all numbers of the netword address 
    for (char character : networkAddress)
    {
        int i = character - '0';
        if (!temp->childern[i])
        {
            // if found the longest, break and return 
            break;
        }
        temp = temp->childern[i];
        // if matched, i.e. -1 as initlasied on line 49, we store it in last_found 
        if(temp->routerNumber != -1)
        {
            // Return outside the loop
            last_found = temp->routerNumber;
        }
    }
    return last_found;
}

// destructor 
void PrefixMatcher::free_Node(Trie_prefix *Node)
{
    if (!Node)
    {
        // nothing to delete
        return;
    }
    // delete each childern of each node 
    for (int i = 0; i < 2; i++)
    {
        free_Node(Node->childern[i]);
    }
    // delete each node after all childern have been deleted 
    delete Node;
}