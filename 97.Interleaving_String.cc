#include<vector>
#include<string>

using namespace std;

// key : dp
/*  explain:
    special solution.

    concept : check the path of using s1 to fill up or using s2 to fill up the s3[i] word.
    inspect the relation between the [i-1] and the [i]th char of s1 and s2.
    for ith char in s3, you can choose a char in s1 or s2 to fill it, use a 2d dp array to track this.

    time complexity : O(n*m) = O(s1.length() * s2.length*())
    space complexity : O(n*m) = O(s1.length() * s2.length*())
*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;

        vector<vector<bool>> dp(s1.length() +1, vector<bool>(s2.length() +1, false));
        dp[0][0] = true;

        // s1
        for(int i=1; i<=s1.length(); i++){
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        // s2
        for(int j=1; j<=s2.length(); j++){
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        for(int i=1; i<=s1.length(); i++){
            for(int j=1; j<=s2.length(); j++){
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i + j -1]) ||
                           (dp[i][j-1] && s2[j-1] == s3[i + j - 1]);
            }
        }

        return dp[s1.length()][s2.length()];
    }
};