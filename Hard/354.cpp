class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end()); 
        int n = envelopes.size(); 
        vector<int> dp(n,1); // at least 1, take only that doll 
        
        for(int i=1; i<n; i++){
            
            for(int j=0; j<=i-1; j++){
            if(envelopes[i][0]>envelopes[j][0] and envelopes[i][1]>envelopes[j][1])
                dp[i] = max(dp[i], dp[j]+1); 
            }
            //for (auto c: dp) cout<<c<<"-";
            cout<<endl;
        }
        int res = -1; 
        for(int i=0; i<n; i++)
            if(res<dp[i])
                res = dp[i];
        return res;
        
    }
};