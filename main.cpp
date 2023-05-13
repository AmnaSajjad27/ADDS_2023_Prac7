#include <iostream>
#include "Autocomplete.h"
#include "Trie.h"

using namespace std;

int main() {
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
    
    return 0;
}