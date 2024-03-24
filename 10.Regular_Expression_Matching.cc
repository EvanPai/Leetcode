#include<vector>
#include<string>

using namespace std;

// key : dp
/*  explain:
    special solution.

    use a 2D dp array.

    To implement regular expression matching with support for '.' and '*', we can use dynamic programming. 
    The idea is to create a 2D table dp where dp[i][j] represents whether the first i characters 
    in the string s match the first j characters in the pattern p.

    Here's the approach:

    1. Initialize a 2D boolean array dp with dimensions [s.length() + 1][p.length() + 1]. 
    dp[0][0] is true because an empty string matches an empty pattern.

    2. Iterate through s and p to fill in dp. For each pair of indices (i, j):
    If p[j-1] == '.', it matches any character, so we take the value from dp[i-1][j-1].
    If p[j-1] == '*', there are two cases:
    The character before * matches 0 times: We take the value from dp[i][j-2] 
    (i.e., we ignore the character before * and the * itself in the pattern).
    The character before * matches 1 or more times: 
    This is true if dp[i-1][j] is true and (s[i-1] == p[j-2] or p[j-2] == '.').


    3. The result is stored in dp[s.length()][p.length()].



*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c* that can match an empty string
        for(int j=1; j<=n; j++){
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                // Current characters match, carry over the result from the previous state
                if(p[j-1] == '.' || p[j-1] == s[i-1]) dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    // Zero occurrences of the character before '*'
                    dp[i][j] = dp[i][j-2];
                    // One or more occurrences of the character before '*'
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};