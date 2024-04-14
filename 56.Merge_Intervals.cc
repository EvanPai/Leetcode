#include<vector>

using namespace std;

// key : array, sorting
/*  explain:
    sort the intervals first, using lambda function.

    1. Sort the intervals: First, sort the array of intervals based on their starting values. Sorting makes it easier to merge intervals in a single pass because once an interval is found not to overlap with the current one, no further intervals can overlap with it.
    2. Initialize a result container: This will store the merged intervals.
    3. Iterate and merge intervals: Traverse the sorted intervals and merge them if they overlap. You determine overlap by checking if the start of the current interval is less than or equal to the end of the last interval in the result. If they overlap, update the end of the last interval in the result to be the maximum of its own end and the end of the current interval.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};

        // Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){return a[0] < b[0];});


        vector<vector<int>> merged;
        for(int i=0; i<intervals.size(); i++){
            if(merged.empty() || merged.back()[1] < intervals[i][0]){
                // not overlaping
                merged.push_back(intervals[i]);
            }
            else{
                // overlaping
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }
        return merged;
    }
};