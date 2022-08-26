class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        st.insert(nums.begin(), nums.end());
        
        return (nums.size() != st.size());
    }
};