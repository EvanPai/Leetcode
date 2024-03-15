#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            // primary
            sum += mat[i][i];

            // secondary
            sum += mat[(n-1)-i][i];
        }

        if(n%2 == 1){
            sum -= mat[n/2][n/2];
        }

        return sum;
    }
};

int main(){
    Solution a;

    vector<vector<int>> mat;
    a.diagonalSum(mat);

    

    return 0;
}