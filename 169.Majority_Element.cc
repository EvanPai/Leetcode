#include<vector>

using namespace std;
// key : array, counting
/*  explain:
    using Moore's voting algorithm
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority = 0;

        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                majority = nums[i];
            }

            count += (nums[i] == majority) ? 1 : -1;
        }

        return majority;
    }
};