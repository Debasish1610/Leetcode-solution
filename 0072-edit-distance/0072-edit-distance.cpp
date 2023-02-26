class Solution {
    int edit[2][1003];
public:
       int editDistance(string s, string t)
        {
            for(int i = 0; i <= s.size(); i++)
            {
                for(int j = 0; j <= t.size(); j++)
                {
                    if(i == 0 || j == 0)
                    {
                        edit[i%2][j] = max(i,j);
                    }
                    else if(s[i-1] == t[j-1])
                    {
                        edit[i%2][j] = edit[(i-1)%2][j-1];
                    }
                    else
                    {
                        edit[i%2][j] = 1+ min(edit[i%2][j-1], min(edit[(i-1)%2][j], edit[(i-1)%2][j-1]));
                    }
                }
            }
            return edit[s.size()%2][t.size()];
        }
        
    int minDistance(string word1, string word2) {
        return editDistance(word1, word2);
    }
};