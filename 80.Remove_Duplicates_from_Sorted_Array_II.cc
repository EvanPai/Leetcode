#include<vector>

using namespace std;
// key : array, two pointer
/*  explain:
    straight forward.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // naive
        int k = 0;
        int prev;
        int prevPrev;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != prev){
                prev = nums[i];
                nums[k] = nums[i];
                k++;
            }
            else if(nums[i] != prevPrev){
                prevPrev = nums[i];
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        
        for(int i = 1; i<nums.size(); i++){
            if(k == 1 || nums[i] != nums[k-2]){
                nums[k++] = nums[i];
                
            }
        }
        return k;
    }
};