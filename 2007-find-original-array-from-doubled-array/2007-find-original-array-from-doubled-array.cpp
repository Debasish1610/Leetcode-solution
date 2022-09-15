class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int maxValue = 200002, oddCount = 0;
        vector<int>flag(maxValue, 0), output;
        for(int i = 0; i < changed.size(); i++) {
            flag[changed[i]]++;
        }
        sort(changed.begin(), changed.end());
        for(int i = 0; i < changed.size(); i++) {
            if (changed[i] == 0 && flag[changed[i]] > 1) {
                output.push_back(0);
                flag[changed[i]] -=2;
            } else if (changed[i] != 0 && changed[i]%2==0 && flag[changed[i]] != 0) {
                if (flag[changed[i]*2] != 0) {
                    output.push_back(changed[i]);
                    flag[changed[i]*2]--;
                    flag[changed[i]]--;
                }
            } else if (changed[i] != 0 && changed[i]%2 == 1 && flag[changed[i]] != 0) {
                if (flag[changed[i]*2] != 0) {
                    output.push_back(changed[i]);
                    flag[changed[i]*2]--;
                    flag[changed[i]]--;
                }
            }
        }
        for(int i = 0; i < changed.size(); i++) {
            if(flag[changed[i]]!=0) {
                oddCount++;
            }
        }
        if (oddCount) {
            output.clear();
        }
        
        return output;
    }
};