#include<vector>
#include<string>

using namespace std;

// key : string, back track
/*  explain:
    if the '(' is less than n, then put '('
    if the ')' is less than '(', then put ')'

    time complexity : O(2n) = O(n)
    space complexity : O(2n) = O(n)
*/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backTrack(n, 0, 0, "", result);
        return result;
    }

    void backTrack(int n, int open, int close, string current, vector<string>& result){
        // if it is a valid combination, add to the result
        if(current.length() == 2*n){
            result.push_back(current);
            return;
        }

        if(open < n) backTrack(n, open+1, close, current + '(', result);  
        if(close < open) backTrack(n, open, close+1, current + ')', result);
    }
};