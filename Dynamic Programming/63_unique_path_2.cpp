class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m = obstacleGrid.size();
        size_t n = obstacleGrid[0].size();

        int grid[m+1][n+1];

        memset(grid, 0, sizeof(grid));

        grid[1][1] = 1;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(obstacleGrid[i-1][j-1]){
                    grid[i][j] = 0;
                }else{
                    grid[i][j] += grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        return grid[m][n];
    }
};