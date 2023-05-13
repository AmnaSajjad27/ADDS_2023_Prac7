#include <iostream>

#include "Autocomplete.h"
#include "Trie.h"

#include "PrefixMatcher.h"
#include "Trie_prefix.h"

using namespace std;

int main() {

    // Part 1:

    Autocomplete ac;
    ac.insert("ant");
    ac.insert("anthoney");
    ac.insert("amna");
    ac.insert("amalga");
    ac.insert("olga");
    ac.insert("orange");
    
    vector<string> res;
    res = ac.getSuggestions("am");
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
    
    res = ac.getSuggestions("an");
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
    
    res = ac.getSuggestions("o");
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
    
    res = ac.getSuggestions("a");
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
    
// Part 2:

    PrefixMatcher prefixMatcher;

    prefixMatcher.insert("110", 1);
    prefixMatcher.insert("110011011", 2);
    prefixMatcher.insert("11001101", 3);

    string networkAddress = "11001";
    int routerNumber = prefixMatcher.selectRouter(networkAddress);
    cout << "Address " << networkAddress << " best matches router " << routerNumber << endl;

    return 0;

}