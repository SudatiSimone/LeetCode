class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map <int, int> edge; // position + occurrence
        int max = 0,count=0;
        for (int i=0; i<wall.size(); ++i){
            count=0;
            for (int j=0; j<wall[i].size(); ++j){
                count+=wall[i][j];
                if (j!=wall[i].size()-1){
                    if ( edge.find(count) == edge.end() ) {
                      edge[count]=1;
                    } else {
                      edge[count]++;
                    }
                    if (max<edge[count]) {
                        max= edge[count];
                    }
                }
            }
        }
        return wall.size()-max;
    }
};