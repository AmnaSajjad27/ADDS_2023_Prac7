#include "Trie.h"

#include <vector>
#include <string>

using namespace std;

Trie::Trie()
{
    childern = vector<Trie*>(26, nullptr);
    end_of_word = false;
}

Trie::~Trie()
{
    for (auto child : childern)
    {
        if (child != nullptr)
        {
            delete child;
        }
    }
}