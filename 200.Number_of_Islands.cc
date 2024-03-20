#include<vector>

using namespace std;
// key : DFS

/*  explain:
    apply DFS.
    DFS : 
        1. check for invalid index, if invalid, return
        2. mark the cell as visited
        3. dfs up, right, down, left
*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y){
        int length = grid.size();
        int width = grid[0].size();

        // Check for invalid indices and water
        if(x < 0 || y < 0 || x>= length || y >= width || grid[x][y] == '0') return;

        // Mark the visited cell as '0'
        grid[x][y] = '0';

        dfs(grid, x-1, y);      // left
        dfs(grid, x, y-1);      // up
        dfs(grid, x+1, y);      // right 
        dfs(grid, x, y+1);      // down
        
    }      


    int numIslands(vector<vector<char>>& grid) {
        int legnth = grid.size();
        int width = grid[0].size();
        int count = 0;

        for(int x=0; x<legnth; x++){
            for(int y=0; y<width; y++){
                if(grid[x][y] == '1'){
                    count++;
                    dfs(grid, x, y);
                }
            }
        }

        return count;
    }
};