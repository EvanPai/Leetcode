#include<vector>

using namespace std;

// key : DP
/*  explain:
    special solution.

    can also use Divide and conquer    
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Max = nums[0];
        int maxEndingHere = nums[0];

        for(int i=1; i<nums.size(); i++){
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]);

            Max = max(Max, maxEndingHere);
        }

        return Max;
    }
};

// Divied and conquer
#include <limits>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayUtil(nums, 0, nums.size() - 1);
    }

    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int sum = 0;
        int leftSum = numeric_limits<int>::min();
        
        // Traverse left of mid and keep track of max sum
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            if (sum > leftSum)
                leftSum = sum;
        }

        sum = 0;
        int rightSum = numeric_limits<int>::min();
        
        // Traverse right of mid + 1 and keep track of max sum
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            if (sum > rightSum)
                rightSum = sum;
        }

        // Return sum of elements on left and right of mid
        return leftSum + rightSum;
    }

    int maxSubArrayUtil(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];

        int mid = left + (right - left) / 2;

        /* Return maximum of following three possible cases:
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum such that the subarray crosses the midpoint */
        return max({maxSubArrayUtil(nums, left, mid),
                    maxSubArrayUtil(nums, mid + 1, right),
                    maxCrossingSum(nums, left, mid, right)});
    }
};
