#include<vector>
#include<unordered_map>

using namespace std;
// key : naive, Hash table
/*  explain:
    use hash table, unordered_map<int, int> map
    first int stores the value, second int stores the index of that value.

    int complement = target - nums[i];
    if(map.count(complement) && map[complement] != i){  // check whether the complement is in the hash table as a key
        return {map[complement], i};
    }
*/



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // naive solution
        int length = nums.size();
        vector<int> answer;
        for(int i=0; i<length; i++){
            for(int j=i+1; j<length; j++){
                if(nums[i] + nums[j] == target){
                    answer.push_back(i);
                    answer.push_back(j);
                    break;
                }
            }
        }

        return answer;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hash table solution
        unordered_map<int, int> map;
        int length = nums.size();

        // build the hash table
        for(int i=0; i<length; i++){
            map[nums[i]] = i;
        }

        // use the target - number to get complement
        for(int i=0; i<length; i++){
            int complement = target - nums[i];
            if(map.count(complement) && map[complement] != i){  // check whether the complement is in the hash table as a key
                return {map[complement], i};
            }
        }

        return {};
        // time complexity : O(n)
    }
};