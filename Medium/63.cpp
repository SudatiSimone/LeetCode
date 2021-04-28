class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(),  col=obstacleGrid[0].size();
        vector < vector <int>> dp (row, vector<int>(col,0));
        for (int i=0; i<row; ++i){
            for (int j=0; j<col; ++j){
                if (i==0 and j==0 and obstacleGrid[0][0]!=1) dp[0][0]=1;
                if (j>=1 and obstacleGrid[i][j]!=1){
                    dp[i][j]+=dp[i][j-1]; 
                }
                if (i>=1 and obstacleGrid[i][j]!=1){
                    dp[i][j]+=dp[i-1][j]; 
                }
                    
            }
        }
        return dp[row-1][col-1];
    }
};