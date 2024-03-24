#include<vector>
#include<unordered_map>

using namespace std;

// key : hash table, prefix sum
/*  explain:
    use hash table and prefix sum concept.
    kinda special solution.

    So, suppose we have an array as arr[]: [1,2,3,4,5] and k = 9

    so, our answer will be '2' i.e (2 + 3 + 4 and 4 + 5)
    so if we store our prefix sum array then it should looks like:
    index :   0, 1, 2, 3,  4
    arr[]:   [1, 2, 3, 4,  5]
    prefix[]:[1, 3, 6, 10, 15]
              ↑         ↑

    prefix[3] - prefix[0] = 10 - 1 = 9 = k
    -> prefix[3] - k = prefix[0] = 1

    if(sumCount.find(1) != sumCount.end()) it means that there are <sumCount> subarray that can sum to k.

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCount;
        int count = 0;
        int sum = 0;

        // Initialize sumCount with 0 sum occurring once to handle the case when a subarray starts from the beginning
        sumCount[0] = 1;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            // If sum - k exists in sumCount, it means there is a subarray that sums up to k ending at the current index
            if(sumCount.find(sum - k) != sumCount.end()) count += sumCount[sum-k];

            sumCount[sum]++;
        }
        return count;
    }
};