#include "Trie.h"

#include <vector>
#include <string>

using namespace std;

Trie()
{
    childern = vector<Trie*>(26, nullptr);
    end_of_word = false;
}