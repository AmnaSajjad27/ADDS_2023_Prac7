#include "Trie_prefix.h"

#include <string>
#include <vector>
// for memset
#include <cstring>

Trie_prefix::Trie_prefix()
{
    routerNumber = -1;
    // Allocate memeory 
    memset(childern, 0, sizeof(childern));
}
