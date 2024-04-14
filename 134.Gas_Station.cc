#include<vector>

using namespace std;

// key : array, greedy
/*  explain:
    1. the total_gas must >= total_cost in order to finish the circuit.
    2. iterate through the array, and calculate tank = gas[i] - cost[i]
    3. if during the run, tank < 0, it means that the starting station cannot be the current and before current
    4. so start station = i + 1 
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int n = gas.size();
        // int currentGas;

        // int maxStartGas = 0;
        // int maxStartIndex;

        // // Find the max start gas
        // for(int i=0; i<n; i++){
        //     int g = gas[i] - cost[i] + g
        //     if(gas[i] - cost[i] > maxStartGas){
        //         maxStartGas = gas[i] - cost[i];
        //         maxStartIndex = i;
        //     }
        // }
        
        // // From that gas station, traverse through every station, until finish or run out of gas in the middle
        // currentGas = maxStartGas;
        // for(int i=maxStartIndex; i<maxStartIndex + n; i++){
        //     currentGas -= cost[i%n];
        //     currentGas += gas[(i+1)%n];
        //     if(currentGas <= 0) return -1;
        // }

        // return maxStartIndex;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total_gas = 0;
        int total_cost = 0;
        int tank = 0;
        int startIndex = 0;

        for(int i=0; i<n; i++){
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];
            
            if(tank < 0){
                startIndex = i+1;
                tank = 0;
            }
        }

        if(total_gas < total_cost) return -1;
        else return startIndex;
    }
};