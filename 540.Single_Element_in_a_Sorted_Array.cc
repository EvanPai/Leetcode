#include<vector>

using namespace std;

// key : binary search modification
/*  explain:
    Before the single element, pairs start at even indices (0-based indexing). 
    After the single element, pairs start at odd indices.

    1. Initialize the left and right pointers for binary search. The left pointer starts at 0, and the right pointer starts at the last index of the array.

    2. Binary Search: While the left pointer is less than the right pointer:
    Find the middle index.
    Check the pairing of the middle index. If the middle index is even, 
    then its pair should be at mid + 1. If it's odd, its pair should be at mid - 1.
    If the pair does not match as expected, it means the single element is on the left side of the 
    middle element (including the middle). Otherwise, it's on the right side.
    Adjust the left or right pointer accordingly.

    3. Result: The left pointer will eventually converge to the index of the single element.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0; 
        int right = nums.size() - 1;

        int mid;
        bool isEven;

        while(left < right){
            mid = left + (right - left) /2;

            // Check if mid is even or odd to decide the pairing direction
            isEven = (mid%2 == 0);

            // Adjust search boundary based on the comparison with the next or previous element
            if( nums[mid] == nums[mid + (isEven ? 1 : -1) ] ){
                // The single element is in the other half
                left = (isEven ? mid+2 : mid+1);
            }
            else{
                right = mid;
            }
        }
        // Left and right converge to the index of the single element
        return nums[left];
    }
};