#include<string>

using namespace std;

// key : string
/*  explain:
    follow the problem instruction.
*/


class Solution {
public:
    int myAtoi(string s) {
        int i=0; 
        int n = s.length();

        long long result = 0;
        bool isNegative = false;

        // skip white space
        while(i < n && s[i] == ' ') i++;
        
        // check for + or -
        if(i < n && (s[i] == '+' || s[i] == '-') ) {
            isNegative = (s[i] == '-');
            i++;
        }
        
        // read in the digit
        while(i<n && isdigit(s[i])){
            result = (result*10) + (s[i] - '0');    //convert char to int

            if(result > INT_MAX) return (isNegative) ? INT_MIN : INT_MAX;
            i++;
        }

        result = (isNegative) ? -result : result;

        // clamping
        if(result > INT_MAX) result = INT_MAX;
        if(result < INT_MIN) result = INT_MIN;

        return (int)result;

    }
};