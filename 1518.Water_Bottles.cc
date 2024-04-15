#include<vector>

using namespace std;
// key : math, simulation
/*  explain:
    just simulate the process.
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = 0;
        int ans = 0;

        while(full > 0){
            empty += full; // drink
            ans += full;    
            full = 0;   

            full += empty / numExchange;
            empty = empty % numExchange;
            
        }
        return ans;
    }
};