#include <vector>

using namespace std;

class Solution {
public:
    int binarySearchIterative(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        //each iteration find target in [l, r]
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {

                return mid;

            } else if(nums[mid] > target) {

                r = mid -1;

            } else if(nums[mid] < target) {

                l = mid + 1;

            }
        }

        return -1;
    }

public:
   int binarySearchRecursive(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
       return __binarySearchRecursive(nums, 0, nums.size() - 1, target);
   }

public:
    int __binarySearchRecursive(vector<int>& nums, int l, int r, int target) {
        // find target in [l, r]
        if(l > r) {
            return -1;
        }

        int mid = l + (r - l) / 2;

        if(nums[mid] == target) {

            return mid;

        } else if(nums[mid] < target) {

            l = mid + 1;

        } else {

            r = mid - 1;

        }
        return __binarySearchRecursive(nums, l, r, target);
    }
};