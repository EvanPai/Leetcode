#include<iostream>

using namespace std;

//Key : sliding window
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;

        int product = 1;
        int count = 0;

        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            product *= nums[right];
            while(left <= right && product >= k){
                product /= nums[left];
                left++;
            }
            count += right - left + 1;
        }

        return count;
        
        // Time complexity : 
        // Space complexity :
    }
};