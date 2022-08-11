class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int>output;
        
        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.find(target-nums[i]) != hashmap.end()) {
                output.push_back(i);
                output.push_back(hashmap[target-nums[i]]);
                break;
            }
            hashmap[nums[i]] = i;
        }
        
        return output;
    }
};