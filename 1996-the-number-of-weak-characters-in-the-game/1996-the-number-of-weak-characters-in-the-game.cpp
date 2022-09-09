class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), this->compare);
        int weakChars = 0;
        int length = properties.size();
        int lastDifIndex = properties.size();
        for (int i = length-2; i >= 0; i--) {
            if (properties[i][0] != properties[i+1][0]) {
                lastDifIndex = i+1;
            }
            
            if (lastDifIndex < length && properties[lastDifIndex][1] > properties[i][1]) {
                weakChars++;
            }
            
            properties[i][1] = max(properties[i][1], properties[i+1][1]);
        }
        return weakChars;
    }
};