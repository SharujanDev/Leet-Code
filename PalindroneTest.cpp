
#include <iostream>
#include <vector>
#include <string>

// Function signature for you to implement
bool isPalindrome(int x) {
    //String Conversion Aproach
    /*
    std::string StringX = std::to_string(x);
    int n = StringX.size();
    if ((x<0) || (x=0) || n<1) return false;

    for (int i = 0;i<n/2;i++)
    {
        if (StringX[i] != StringX[n-i-1]) return false;}

    return true; 
    */

   //Checking All Digits IN Integer Form APPROACH
   /*
   if (x<0) return false;

   int reverse = 0;
   int temp = x;

   while (temp !=0)
   {
        int val = temp%10;
        reverse = (reverse*10)+val;
        temp = temp/10;
        //std::cout << reverse << "\n";
   }

    if (reverse == x) return true;
    return false;
    */
   if (x<0 || (x != 0 && x % 10 == 0)) return false;

   int reverse = 0;
   int temp = x;

   while (temp > reverse)
   {
        int val = temp%10;
        reverse = (int)(reverse*10)+val;
        temp = temp/10;
        //std::cout << temp << " " << reverse << "\n"; 
   }

    return (temp==reverse) || (temp == reverse/10);

}

// Function to test the isPalindrome function
void runTests() {
    // Test cases: pairs of (input, expected output)
    std::vector<std::pair<int, bool>> testCases = {
        {121, true},
        {-121, false},
        {10, false},
        {0, true},
        {12321, true},
        {1234321, true},
        {-101, false},
        {1001, true},
        {123, false}
    };

    bool allPassed = true;
    for (const auto& testCase : testCases) {
        int input = testCase.first;
        bool expected = testCase.second;
        bool result = isPalindrome(input);

        if (result == expected) {
            std::cout << "Test passed for input " << input << ": " << result << std::endl;
        } else {
            std::cout << "Test failed for input " << input << ". Expected " << expected << " but got " << result << std::endl;
            allPassed = false;
        }

    }

    if (allPassed) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}
