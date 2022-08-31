class Solution {
public:
    void checkReachToOcean(vector<vector<bool>> &reachOcean, vector<vector<int>>& heights, queue<pair<int,int>>qu) {
        int fx[] = {0, 0, -1, +1};
        int fy[] = {-1, +1, 0, 0};
        int n = heights.size();
        int m = heights[0].size();
        
        while(!qu.empty()) {
            int r = qu.front().first;
            int c = qu.front().second;
            reachOcean[r][c] = true;
            qu.pop();
        
            for (int i = 0; i < 4; i++) {
                int x = fx[i]+r;
                int y = fy[i]+c;
                if (x >= 0 && x < n && y >= 0 && y < m && heights[x][y] >= heights[r][c] && !reachOcean[x][y]) {
                    reachOcean[x][y] = true;
                    qu.push({x, y});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> output;
        vector<vector<bool>> reachPacific(n, vector<bool>(m, false));
        vector<vector<bool>> reachAtlantic(n, vector<bool>(m, false));
        queue<pair<int,int>>qu;
        
        for(int i = 0; i < n; i++) {
            if (!reachPacific[i][0]) {
                qu.push({i, 0});
                reachPacific[i][0] = true;
            }
        }
        for(int i = 0; i < m; i++) {
            if (!reachPacific[0][i]) {
                qu.push({0, i});
                reachPacific[0][i] = true;
            }
        }
        checkReachToOcean(reachPacific, heights, qu);
        while(!qu.empty()) {
            qu.pop();
        }
        
        for(int i = 0; i < n; i++) {
            if (!reachAtlantic[i][m-1]) {
                qu.push({i, m-1});
                reachAtlantic[i][m-1] = true;
            }
        }
        for(int i = 0; i < m; i++) {
            if (!reachAtlantic[n-1][i]) {
                qu.push({n-1, i});
                reachAtlantic[n-1][i] = true;
            }
        }
        checkReachToOcean(reachAtlantic, heights, qu);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0;  j < m; j++) {
                if (reachAtlantic[i][j] && reachPacific[i][j]) {
                    output.push_back({i, j});
                } 
            }
        }
        
        return output;
    }
};