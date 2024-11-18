#include <algorithm>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty array
        
        std::sort(nums.begin(), nums.end()); // Sort the array

        int counter = 1; // Track the current streak length
        int maxStreak = 1; // Track the maximum streak length

        for (int i = 1; i < nums.size(); i++) { // Loop through sorted array
            if (nums[i] == nums[i - 1] + 1) {
                counter++; // Increment streak
            } else if (nums[i] != nums[i - 1]) {
                maxStreak = std::max(maxStreak, counter); // Update max streak
                counter = 1; // Reset streak
            }
        }

        // Update max streak after the loop ends
        return std::max(maxStreak, counter);
    }
};