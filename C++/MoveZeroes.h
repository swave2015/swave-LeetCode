/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * Example:
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 * Note:
 * 1.You must do this in-place without making a copy of the array.
 * 2.Minimize the total number of operations.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // make sure that non zero values are in place [0, k)
        // k is slow runner point to index need to swap
        // i is fast runner iterrate each element value if non zero then swap to k
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) {
                if(i != k) {
                    swap(nums[i], nums[k++]);
                } else {
                    k++;
                }
            }
        } 
    }
};