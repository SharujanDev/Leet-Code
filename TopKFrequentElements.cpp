#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;  // Sort by frequency (second) in descending order
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Find frequem
        unordered_map<int,int> frequencyMap = {};// <value,val positionss,>
        for (int num : nums) frequencyMap[num]++;

        //Sorting by Occurence
        vector<pair<int,int>> pair = {};
        for (auto set : frequencyMap) pair.push_back({set.second,set.first});
        sort(pair.begin(),pair.end(),cmp);

        //Return Top K most frequent
        vector<int>ans;
        for (int i = 0; i < k;i++) ans.push_back(pair[i].second);

        return ans;
    }
};

// Function to print the result of test cases
void printTestCaseResult(const vector<int>& result) {
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

// Test cases
int main() {
    Solution solution;

    // Test case 1: Simple case with multiple frequencies
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = solution.topKFrequent(nums1, k1);
    cout << "Test case 1 result: ";
    printTestCaseResult(result1);  // Expected: 1 2

    // Test case 2: Case with all elements having same frequency
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 3;
    vector<int> result2 = solution.topKFrequent(nums2, k2);
    cout << "Test case 2 result: ";
    printTestCaseResult(result2);  // Expected: any 3 numbers, since frequencies are equal

    // Test case 3: Case with repeated elements and large k
    vector<int> nums3 = {4, 4, 4, 3, 3, 2, 2, 2, 1, 1};
    int k3 = 2;
    vector<int> result3 = solution.topKFrequent(nums3, k3);
    cout << "Test case 3 result: ";
    printTestCaseResult(result3);  // Expected: 4 2 (4 has 3 occurrences, 2 has 3)

    // Test case 4: Case with a single element repeated
    vector<int> nums4 = {5, 5, 5, 5};
    int k4 = 1;
    vector<int> result4 = solution.topKFrequent(nums4, k4);
    cout << "Test case 4 result: ";
    printTestCaseResult(result4);  // Expected: 5

    // Test case 5: Case with k equal to the number of unique elements
    vector<int> nums5 = {1, 2, 3};
    int k5 = 3;
    vector<int> result5 = solution.topKFrequent(nums5, k5);
    cout << "Test case 5 result: ";
    printTestCaseResult(result5);  // Expected: 1 2 3 or any permutation

    return 0;
}
