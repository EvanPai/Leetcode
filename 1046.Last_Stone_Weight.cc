#include<vector>
#include<queue>

using namespace std;

// key : heap(priority queue)
/*  explain:
    use max heap, the problem can be easily solve.
*/


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while(maxHeap.size() > 1){
            int stone1 = maxHeap.top();
            maxHeap.pop();

            int stone2 = maxHeap.top();
            maxHeap.pop();

            if(stone1 != stone2) maxHeap.push(stone1 - stone2);
            else if(stone1 == stone2) maxHeap.push(0);
        }

        return maxHeap.top();
    }
};