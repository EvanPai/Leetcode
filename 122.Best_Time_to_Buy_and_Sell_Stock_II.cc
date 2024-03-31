#include<vector>

using namespace std;

// key : array, dp
/*  explain:
    naive
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // naive
        int minPrice = INT_MAX;
        int profit = 0;

        for(int i=0; i<prices.size(); i++){
            if(prices[i] < minPrice) minPrice = prices[i];
            if(prices[i] - minPrice > 0){
                profit += prices[i] - minPrice;
                minPrice = prices[i];
            }
        }
        return profit;
    }
};
// Time complexity : O(n)
// Space complexity : O(1)