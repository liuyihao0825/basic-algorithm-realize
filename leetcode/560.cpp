/*****************************************************************
Question:
Given an array of integers and an integer k, you need to find the total number of 
continuous subarrays whose sum equals to k.

Input:nums = [1,1,1], k = 2
Output: 2
*****************************************************************/

// Solution 1: bruce forse
class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();

        int count = 0;

        for (int i = 0; i < len; ++i) {
            int j = i;
            int sum = 0;
            while (j < len) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
                j++;
            }
        }

        return count;
    }
};