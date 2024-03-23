#include<vector>
#include<unordered_map>

using namespace std;

// key : array, hash table
/*  explain:
    1. Find the Degree: First, we need to find the degree of the array, which is the maximum frequency of any element.
    
    2. Track Elements: While finding the degree, 
    we also track the first and last occurrence of each element to know the indices where they appear. 
    This information helps us determine the length of the subarray for each element.

    3. Find Minimum Subarray Length: After knowing the degree, 
    we look for elements that have this frequency and calculate the length of the subarray that 
    includes all occurrences of such elements. 
    The minimum length among these subarrays is the answer.
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> firstOccurance;
        int degree = 0;
        int minLength = nums.size();

        for(int i=0; i<nums.size(); i++){
            // If it's the first occurrence of the number, store its index
            if(firstOccurance.find(nums[i]) == firstOccurance.end()) firstOccurance[nums[i]] = i;

            // Increase the count for the current number
            count[nums[i]]++;

            // Update the degree if necessary
            degree = max(degree, count[nums[i]]);
        }

        // Reset count for the next loop
        count.clear();

        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
            // If the current number's count matches the degree,
            // check if this subarray is the smallest so far
            if(count[nums[i]] == degree) minLength = min(minLength, i - firstOccurance[nums[i]] + 1);
        }

        return minLength;
    }
};