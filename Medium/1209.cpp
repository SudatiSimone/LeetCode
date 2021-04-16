class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char, int>> score;
        string res;
        int len= s.size();
        for (char c: s){
            if (score.empty() or score.top().first!=c){
                score.push({c,1});
            } else if (score.top().first==c){
                score.top().second++;
                if (score.top().second==k){ 
                    score.pop();
                }
            }
        }
        while(!score.empty()){
            for (int i=0; i<score.top().second; ++i){
                res.push_back(score.top().first);
            }
            score.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        }
};