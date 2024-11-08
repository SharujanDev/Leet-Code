#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class ValidAnagram {
public:
    bool isAnagram(string s, string t) {

        //SORTING METHOD
        /*
        if (s.size() != t.size()) return false;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if (s == t) return true;
        return false;
        */

       //HASHMAP METHOD
        if (s.size() != t.size()) return false;//String must be the same size

        unordered_map<char,int> hs={};

        for (char x: s) hs[x]++;

        for (char c : t) {
            if (hs.find(c) != hs.end()) {
                hs[c]--;
                // Remove the character from map if count becomes zero
                if (hs[c] == 0) {
                    hs.erase(c);
                }
            }
        }
        if (hs.empty()) return true;
        return false;
    }     
};

int main() {
    ValidAnagram validAnagram;
    
    // Test cases
    string s1 = "anagram";
    string t1 = "nagaram";
    
    string s2 = "rat";
    string t2 = "car";
    
    // Running test cases
    cout << (validAnagram.isAnagram(s1, t1) ? "True" : "False") << endl;  // Output: True
    cout << (validAnagram.isAnagram(s2, t2) ? "True" : "False") << endl;  // Output: False
    
    return 0;
}
