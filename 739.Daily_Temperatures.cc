#include<vector>
#include<stack>

using namespace std;

// key : array, stack, monotonic stack(non incresing stack)
/*  explain:
    special answer.
    as described in the code.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0); // Initialize answer vector with 0s
        stack<int> indexStack; // Stack to store indices
        
        for (int i = 0; i < n; ++i) {
            // Check if current day is warmer than the day at the top of the stack
            while (!indexStack.empty() && temperatures[i] > temperatures[indexStack.top()]) {
                int prevIndex = indexStack.top();
                indexStack.pop();
                answer[prevIndex] = i - prevIndex; // Update answer for the day at prevIndex
            }
            indexStack.push(i); // Push current index onto stack
        }
        
        return answer;
    }
};