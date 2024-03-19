#include<iostream>

using namespace std;


// key : binary search modification

/*
    the key of this task is that the right or left portion of array will always be sorted
    so we can utilize this property to modify the binary search
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // n-1

        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;

            if(nums[left] <= nums[mid]){ // the left half of array is sorted
                if(target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else{ // the right half of array is sorted
                if(target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid -1;
            }
        }   

        // no target found
        return -1;

        // time complexity : O(logn)
        // space complexity : O(1)
    }
};