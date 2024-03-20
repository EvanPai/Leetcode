#include<iostream>
#include<unordered_map>

using namespace std;


// key : array, matrix

/*  explain:
    transpose and then swap column
    imagine the animation of it.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        int row = matrix.size();
        for(int i=0; i<row; i++){
            for(int j=0; j<=i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // swap column
        for(int i=0; i<row; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};