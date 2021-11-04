/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0; 
        int index;
        std::multimap<int, int> temp; // multimap so that 2 same keys can exist without being overwritten
        vector<int> returnArr{0, 0};
        

        for (i = 0; i < nums.size(); i++) {
            temp.insert(make_pair(nums[i], i));
            auto index = temp.find(target - nums[i]);
            if (index != temp.end() && index->second != i) {
                returnArr[0] = i;
                returnArr[1] = index->second;
            }
        }
        
        return returnArr;
        
    }
    
};
