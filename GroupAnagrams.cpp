#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

// Function signature for you to implement
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> temp;
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::string order;

    for (int i = 0;i<strs.size();i++) 
    {
        order = strs[i];
        sort(order.begin(),order.end());
        map[order].push_back(strs[i]);
    }

    for (auto vec : map)
    {
        temp.push_back(vec.second);
    }

    return temp;  
}

// Helper function to check if two 2D vectors of strings are the same
bool compareGroups(const std::vector<std::vector<std::string>>& result, const std::vector<std::vector<std::string>>& expected) {
    if (result.size() != expected.size()) return false;

    std::vector<std::string> sortedResult;
    std::vector<std::string> sortedExpected;
    
    for (const auto& group : result) {
        std::vector<std::string> sortedGroup = group;
        std::sort(sortedGroup.begin(), sortedGroup.end());
        sortedResult.push_back("");
        for (const auto& word : sortedGroup) {
            sortedResult.back() += word;
        }
    }
    
    for (const auto& group : expected) {
        std::vector<std::string> sortedGroup = group;
        std::sort(sortedGroup.begin(), sortedGroup.end());
        sortedExpected.push_back("");
        for (const auto& word : sortedGroup) {
            sortedExpected.back() += word;
        }
    }
    
    std::sort(sortedResult.begin(), sortedResult.end());
    std::sort(sortedExpected.begin(), sortedExpected.end());

    return sortedResult == sortedExpected;
}

// Function to run the test cases
void runTests() {
    struct TestCase {
        std::vector<std::string> input;
        std::vector<std::vector<std::string>> expected;
    };

    std::vector<TestCase> testCases = {
        {
            {"eat", "tea", "tan", "ate", "nat", "bat"},
            {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}}
        },
        {
            {""},
            {{""}}
        },
        {
            {"a"},
            {{"a"}}
        },
        {
            {"ab", "ba", "abc", "cba", "bac"},
            {{"ab", "ba"}, {"abc", "cba", "bac"}}
        },
        {
            {"listen", "silent", "enlist", "google", "gogole"},
            {{"listen", "silent", "enlist"}, {"google", "gogole"}}
        }
    };

    bool allPassed = true;
    int testCaseNumber = 1;

    for (const auto& testCase : testCases) {
        std::vector<std::vector<std::string>> result = groupAnagrams(const_cast<std::vector<std::string>&>(testCase.input));
        bool pass = compareGroups(result, testCase.expected);
        if (pass) {
            std::cout << "Test Case " << testCaseNumber << " Passed.\n";
        } else {
            std::cout << "Test Case " << testCaseNumber << " Failed.\n";
            std::cout << "Expected:\n";
            for (const auto& group : testCase.expected) {
                for (const auto& word : group) std::cout << word << " ";
                std::cout << "\n";
            }
            std::cout << "Got:\n";
            for (const auto& group : result) {
                for (const auto& word : group) std::cout << word << " ";
                std::cout << "\n";
            }
            allPassed = false;
        }
        testCaseNumber++;
    }

    if (allPassed) {
        std::cout << "All test cases passed!\n";
    } else {
        std::cout << "Some test cases failed.\n";
    }
}

int main() {
    runTests();
    return 0;
}
