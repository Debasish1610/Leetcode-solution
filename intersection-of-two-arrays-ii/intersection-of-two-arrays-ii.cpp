class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        map<int, int>frequencyCountOfNums1;
        
        for (int i = 0; i < nums1.size(); i++) {
            frequencyCountOfNums1[nums1[i]]++;
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            if (frequencyCountOfNums1[nums2[i]] != 0) {
                frequencyCountOfNums1[nums2[i]]--;
                output.push_back(nums2[i]);
            }
        }
        
        return output;
    }
};