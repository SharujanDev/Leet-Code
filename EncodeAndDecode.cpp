#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encodedString = "";
        for (string str: strs) encodedString.append(str + "\n");
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decodedVal;
        string word;
        for (int i = 0;i<s.size();i++)
        {

        if (s[i] != '\n') {word.append(1, s[i]);  // Append the character to word
        } 
        else 
        {
            decodedVal.push_back(word);  // Add the word to decodedVal
            word = "";  // Reset word
        }
        }
        return decodedVal;
    }
};


// Function to test the encode and decode methods
void test() {
    Solution solution;

    vector<string> testStrings = {"hello", "world", "this", "is", "LeetCode"};
    
    // Encoding the list of strings
    string encoded = solution.encode(testStrings);
    cout << "Encoded: " << encoded << endl;
    
    // Decoding the encoded string back to the list of strings
    vector<string> decoded = solution.decode(encoded);
    cout << "Decoded: ";
    for (const string& str : decoded) {
        cout << str << " ";
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}
