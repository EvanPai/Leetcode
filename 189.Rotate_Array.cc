#include<vector>

using namespace std;
// key : array
/*  explain:
    just reverse the array three times.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // insure that k is within the range of 0 ~ n-1

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};