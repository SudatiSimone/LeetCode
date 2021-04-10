class Solution {
public:
    bool ok (int i, int j, int row, int col){
        if (i<0 or j<0 or i>=row or j>=col) return false;
        else return true;
    }

    void dfs(vector<vector<int>> &dp, vector<vector<int>> &matrix, int i, int j, int row, int col ){
        if (dp[i][j]!=0)return;
        dp[i][j]=1; 
        int upper=0, down=0, left=0, right=0;
        if (ok(i, j+1, row, col) and matrix[i][j+1]>matrix[i][j]){
            dfs(dp, matrix, i, j+1, row, col);
            upper= dp[i][j+1];
        }
        if (ok(i, j-1, row, col) and matrix[i][j-1]>matrix[i][j]){
            dfs(dp, matrix, i, j-1, row, col);
            down= dp[i][j-1];
        }
        if (ok(i-1, j, row, col) and matrix[i-1][j]>matrix[i][j]){
            dfs(dp, matrix, i-1, j, row, col);
            left= dp[i-1][j];
        }   
        if (ok(i+1, j, row, col) and matrix[i+1][j]>matrix[i][j]){
            dfs(dp, matrix, i+1, j, row, col);
            right= dp[i+1][j];
        }
        dp[i][j]+= max(down, max(upper, max(left, right)));
    }
   
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res =0, row=matrix.size(), col=matrix[0].size();
        vector <vector <int>> dp (row, vector<int>(col,0));
        for (int i=0; i<row; ++i){
            for (int j=0; j<col; ++j){
                dfs(dp, matrix,i, j, row, col);
            }
        }
        for (int i=0; i<row; ++i){
            for (int j=0; j<col; ++j){
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};