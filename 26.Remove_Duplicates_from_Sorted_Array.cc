#include<vector>

using namespace std;
// key : array, two pointer
/*  explain:
    straight forward.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int same;

        for(int i=0; i<nums.size(); i++){
            if(same != nums[i]) {
                same = nums[i];
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};