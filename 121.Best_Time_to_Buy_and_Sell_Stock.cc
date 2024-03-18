#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 100001;
        int maxProfit = 0;

        // iterate through the vector
        // method 1
        // for(int i=0; i<prices.size(); i++){
        //     if(prices[i] < minPrice) minPrice = prices[i];
        //     maxProfit = max(maxProfit, prices[i] - minPrice);
            
        // }

        // method 2 : element wise for loop
        for(int i: prices){
            if(i < minPrice) minPrice = i;
            maxProfit = max(maxProfit, i - minPrice);
        }

        return maxProfit;
    }

};
// Time complexity : O(n)
// Space complexity : O(1)