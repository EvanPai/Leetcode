#include<string>

using namespace std;

// key : string
/*  explain:
    sum each char of string backward, notice the carry.
    remember to reverse the answer at last.

    time complexity : O(num1.length() + num2.length())
    space complexity : O(num1.length() + num2.length())
*/


class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() -1;
        int j = num2.length() -1;
        int carry = 0;

        string result = "";
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0) sum += num1[i--] - '0'; // convert char to int
            if(j >= 0) sum += num2[j--] - '0';

            result += (sum%10) + '0';   //convert int to char
            carry = sum/10;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};