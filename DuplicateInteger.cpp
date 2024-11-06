#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class DuplicateInteger {
public:
    // Function to check if there are any duplicates in the vector
    bool hasDuplicate(vector<int>& nums) 
    {
        //BRUTE FORCE
        /*
        for (int i = 0;i<nums.size();i++) 
        {
            for (int j = 0;j<nums.size();j++)
            {
                if ((nums[i] == nums[j]) && (i!=j)) return true;
            }
        }
        return false;*/

        //Sorting Method
        /*
        sort(nums.begin(),nums.end());

        for (int i=1;i<nums.size();i++)
        {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
        */
       
       //HashSet
       unordered_set<int> numSet= {};
       for (int num1: nums)
       {
            if (numSet.count(num1))return true;
            numSet.insert(num1);
       }
        return false;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 3, 4, 2, 2}; // Example with a duplicate

    DuplicateInteger solution; // Create an instance of the DuplicateInteger class

    // Call the hasDuplicate function and print the result
    if (solution.hasDuplicate(nums)) {
        cout << "The array has a duplicate." << endl;
    } else {
        cout << "The array has no duplicates." << endl;
    }

    return 0;
}
