class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0, lastIndex = tokens.size()-1;
        
        for(int i = 0; i <= lastIndex; i++) {
            if (tokens[i] <= power) {
                score++;
                power -= tokens[i];
            } else if (i != lastIndex) {
                if (tokens[i] <= tokens[lastIndex]+power && score >= 1) {
                    power = power + tokens[lastIndex] - tokens[i];
                    cout<<power<<endl;
                    lastIndex--;
                } else {
                    break;
                }
            }
        }
        return score;
    }
};