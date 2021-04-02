class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
    vector <vector<int>> dp (m+1, vector<int>(n+1,0));
    for (string & str: strs){
        int zeros = count(str.begin(), str.end(), '0');
        int unos = str.size()-zeros;
        for (int i=m; i>=zeros; i--){
            for (int j=n; j>=unos; j--){
                dp[i][j]=max(dp[i][j], dp[i-zeros][j-unos]+1);
            }
        }
    }
    return dp[m][n];
}   
};