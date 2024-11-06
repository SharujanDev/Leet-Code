#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find two indices such that the numbers add up to the target
vector<int> twoSum(vector<int>& nums, int target) {

        //BRUTE FORCE
        /*
        for (int i = 0;i < nums.size();i++)
        {
            int diff = target - nums[i];
            for (int j = i + 1;j<nums.size();j++)
            {
                if (nums[j] == diff) return {i,j};
            }
        }
        return {};
        */

       //TWO PASS HASH MAP
        unordered_map<int,int> numHash = {}; 
        
        for (int i = 0; i < nums.size();i++) numHash.insert({nums[i],i});//Add Vector to HAshMap
        for (int j = 0; j < nums.size();j++)
        {
            int diff = target - nums[j];
            if (numHash.contains(diff) && j != numHash[diff]) return {j,numHash[diff]};
        } 
        return {};
    }


// Function to test the twoSum function with various test cases
void testTwoSum() {
    vector<pair<vector<int>, int>> testCases = {
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6},
        {{1, 5, 3, 6, 8}, 11},
        {{0, 4, 3, 0}, 0}
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i].first;
        int target = testCases[i].second;
        vector<int> result = twoSum(nums, target);
        cout << "Test case " << i + 1 << ": ";
        if (!result.empty()) {
            cout << "Indices [" << result[0] << ", " << result[1] << "] sum to " << target << endl;
        } else {
            cout << "No solution found for target " << target << endl;
        }
    }
}

int main() {
    testTwoSum();
    return 0;
}