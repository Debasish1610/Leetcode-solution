class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), this->compare);
        int weakChars = 0;
        int length = properties.size();
        int maxValue = -1;
        for (int i = length-1; i >= 0; i--) {
            if (properties[i][1] > maxValue) {
                maxValue =  properties[i][1];
            }
            
            if (maxValue > properties[i][1]) {
                weakChars++;
            }
            
            // properties[i][1] = max(properties[i][1], properties[i+1][1]);
        }
        return weakChars;
    }
};