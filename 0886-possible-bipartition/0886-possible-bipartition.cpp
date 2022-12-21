class Solution {
    const int mx=2002;
public:
   
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int>graph[mx];
        int flag[2002];
        memset(flag,0,sizeof flag);
        for(int i=0;i<dislikes.size();i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        if(dislikes.size()==0)
            return true;
        
        queue<int>qu;
        for(int j=1;j<2002;j++)
        {
            if(graph[j].size()==0 || flag[j]!=0)
                continue;
            qu.push(dislikes[j][0]);
            flag[dislikes[j][0]]=1;

            while(!qu.empty())
            {
                int f=qu.front();
                qu.pop();
                for(int i=0;i<graph[f].size();i++)
                {
                    if(flag[graph[f][i]]==0)
                    {
                        flag[graph[f][i]]=flag[f]%2+1;
                        qu.push(graph[f][i]);
                    }
                    else if(flag[graph[f][i]]==flag[f])
                    {
                        return false;
                    }
                }
            }
        }
            
        return true;
    }
};