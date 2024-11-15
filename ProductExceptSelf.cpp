#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    
    //Pre Fix and Suffix Method`
    /*{
        vector<int> left = nums;
        vector<int> right = nums;
        vector<int> answ=nums;

        left[0] = nums[0];
        right[nums.size()-1]=nums[nums.size() - 1];
        
        for (int i = 1;i<nums.size();i++)left[i] = nums[i]*left[i-1];//Find product of values left of index
        for (int i =  nums.size()-2;i >-1;i--) right[i] = right[i+1]*nums[i]; //Find product of values right of index
        for (int i = 0;i<nums.size();i++)
        {
            if (i==0) answ[i] = right[i+1];
            else if (i == nums.size()-1) answ[i] = left[i-1];
            else answ[i] = left[i-1] * right[i+1];

        }
        return answ;
    }*/

    //Improved Prefix and Suffix Method
    {
        vector<int> left = nums;
        vector<int> right = nums;

        for (int i = 0; i < nums.size();i++);
        {

        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    
    vector<int> result = sol.productExceptSelf(nums);
    
    cout << "Product of array except self: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
