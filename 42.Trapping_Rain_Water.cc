#include<vector>

using namespace std;

// key : array, two pointer
// picture : https://leetcode.com/problems/trapping-rain-water/solutions/3401992/100-detailed-explaination-with-pictures-in-c-java-python-two-pointers/
/*  explain:

    special solution.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // compute leftMax
        leftMax[0] = height[0];
        for(int i=1; i<n; i++) leftMax[i] = max(leftMax[i-1], height[i]);

        // compute rightMax
        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) rightMax[i] = max(rightMax[i+1], height[i]);

        // compute trap water
        int trapWater = 0;
        for(int i=0; i<n; i++) trapWater += min(leftMax[i], rightMax[i]) - height[i];

        return trapWater;
    }
};