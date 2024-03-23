#include<vector>
#include<string>

using namespace std;

// key : string, two pointer
/*  explain:
    as described in the code.
*/

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Trim spaces and remove extra spaces
        string trimmed;
        for(int i=0; i<s.length(); i++){
            if(s[i] != ' ' || (i > 0 && s[i-1] != ' ')){    // put word and the 1 whitespace after a word into trimmed
                trimmed += s[i];
            }
        }

        // remove last whitespace of the last word
        if(!trimmed.empty() && trimmed.back() == ' ') trimmed.pop_back();

        // Step 2: Reverse the entire string
        reverse(trimmed.begin(), trimmed.end());

        // Step 3: Reverse each word
        int start = 0;
        for(int i=0; i<=trimmed.length(); i++){
            if(i == trimmed.length() || trimmed[i] == ' '){
                reverse(trimmed.begin() + start, trimmed.begin() + i);
                start = i+1;
            }
        }
        
        return trimmed;
    }
};
