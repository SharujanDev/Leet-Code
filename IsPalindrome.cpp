#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(std::string s) 

    //Pointer Aproach
    /*
    {
        int left = 0;
        std::string result = "";
        for (char ch : s)if (std::isalnum(ch)) result += std::tolower(ch);
        int right = result.size() - 1;
        while (left < right)
        {
            if (result[left] != result[right]) return false;
            left++;right--;
        }
        return true;
    }
    */
   //Improved Memory Aproach + Bad Timing
   /*
    {
        int left = 0;
        
        //for (char ch : s)if (std::isalnum(ch)) result += std::tolower(ch);
        for (int i = 0;i < s.size();i++)
        {
            if (!std::isalnum(s[i])){ s.erase(i,1); i--;} 
        }

        std::transform(s.begin(), s.end(), s.begin(),tolower);
        
        int right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right]) return false;
            left++;right--;
        }
        return true;
    }
    */

   //One Loop 
   {
        int left = 0; int right = s.size()-1;

        while (left < right)
        {
            int left = 0;
            
        }

   }
};


int main() {
    Solution solution;

    // Test case 1
    std::string test1 = "A man, a plan, a canal, Panama";
    std::cout << (solution.isPalindrome(test1) ? "True" : "False") << std::endl; // Should print True

    // Test case 2
    std::string test2 = "race a car";
    std::cout << (solution.isPalindrome(test2) ? "True" : "False") << std::endl; // Should print False

    // Test case 3
    std::string test3 = " ";
    std::cout << (solution.isPalindrome(test3) ? "True" : "False") << std::endl; // Should print True

    // Test case 4
    std::string test4 = "abccba";
    std::cout << (solution.isPalindrome(test4) ? "True" : "False") << std::endl; // Should print True

    // Test case 5
    std::string test5 = "A";
    std::cout << (solution.isPalindrome(test5) ? "True" : "False") << std::endl; // Should print True

    return 0;
}
