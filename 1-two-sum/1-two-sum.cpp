class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> hashmap;
        vector<int>output;
        
        for (int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]].push_back(i);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.find(target - nums[i]) != hashmap.end()) {
                if (nums[i] == target - nums[i] && hashmap[nums[i]].size() >= 2) {
                    output.push_back(hashmap[nums[i]][0]);
                    output.push_back(hashmap[nums[i]][1]);
                    break;
                } else if (nums[i] != target - nums[i]) {
                    output.push_back(i);
                    output.push_back(hashmap[target - nums[i]][0]);
                    break;
                }
            }
        }
        
        return output;
    }
};