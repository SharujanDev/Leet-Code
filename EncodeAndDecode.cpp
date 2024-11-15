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
    /*
        string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        vector<int> sizes;
        string res = "";
        for (string& s : strs) {
            sizes.push_back(s.size());
        }
        for (int sz : sizes) {
            res += to_string(sz) + ',';
        }
        res += '#';
        for (string& s : strs) {
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        vector<string> res;
        int i = 0;
        while (s[i] != '#') {
            string cur = "";
            while (s[i] != ',') {
                cur += s[i];
                i++;
            }
            sizes.push_back(stoi(cur));
            i++;
        }
        i++;
        for (int sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }
        return res;
    }
    */
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
