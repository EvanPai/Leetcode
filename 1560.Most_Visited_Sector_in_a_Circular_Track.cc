#include<vector>

using namespace std;
// key : array, simulation
/*  explain:
    trace the code.
*/

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> visit(n+1, 0);

        int current = rounds[0];
        visit[current]++;

        for(int i=1; i<rounds.size(); i++){
            int start = rounds[i-1];
            int end = rounds[i];

            if(start <= end){
                for(int j=start+1; j<=end; j++){
                    visit[j]++;
                }
            }
            else{
                for(int j=start+1; j<=n; j++){
                    visit[j]++;
                }
                for(int j=1; j<=end; j++){
                    visit[j]++;
                }
            }
        }

        int maxNum = *max_element(visit.begin(), visit.end());

        vector<int> ans;
        for(int i=1; i<=n; i++){
            if(visit[i] == maxNum) ans.push_back(i);
        }
        return ans;
    }
};