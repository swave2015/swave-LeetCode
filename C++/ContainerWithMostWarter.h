#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // l is left side pointer, r is right side pointer
        int l = 0, r = height.size() - 1;
        int maxArea = 0, area = 0;
        while(l < r) {
            if(height[l] <= height[r]) {
                area = height[l] * (r - l);
                l++;
            } else {
                area = height[r] * (r - l);
                r--;
            }
            if (area > maxArea) {
                 maxArea = area;
            };
        }

        return maxArea;
    }
};