#include<vector>

using namespace std;

// key : array, sliding window
/*  explain:
    1. Initialize two pointers: Start both at the beginning of the array. These pointers define the current window of elements.
    2. Expand the right pointer to include more elements in the window until the sum within the window is at least the target.
    3. Once the sum meets or exceeds the target, record the length of the window if it's the smallest found so far. Then, increment the left pointer to try and find a smaller valid window.
    4. Repeat the process until the right pointer has traversed the entire array.
    5. Return the minimum length found. If no such subarray is found, return 0.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;
        int len = 0;

        for(int right=0; right<nums.size(); right++){
            sum += nums[right];
            len++;
            while(left <= right && sum >= target){
                minLen = min(minLen, len);
                sum -= nums[left];
                left++;
                len--;
            }

        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
