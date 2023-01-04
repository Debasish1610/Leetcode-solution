class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        
        int sameDifficultyCount = 1, ans = 0;
        for (int i = 1; i < tasks.size(); i++) {
            if (tasks[i] != tasks[i-1]) {
                if (sameDifficultyCount == 1) {
                    return -1;
                }
                
                ans = ans + (sameDifficultyCount / 3) + (((sameDifficultyCount % 3) != 0) ? 1 : 0);
                sameDifficultyCount = 1;
            } else {
                sameDifficultyCount++;
            }
        }
        if (sameDifficultyCount == 1) {
            return -1;
        }
        ans = ans + (sameDifficultyCount / 3) + (((sameDifficultyCount % 3) != 0) ? 1 : 0);
        
        return ans;
    }
};