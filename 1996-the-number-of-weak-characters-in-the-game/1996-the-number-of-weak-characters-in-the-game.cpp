class Solution {
public:
    static bool compare(pair<int,int>a, pair<int,int>b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<pair<int,int>>prop;
        for (int i = 0; i < properties.size(); i++) {
            prop.push_back({properties[i][0], properties[i][1]});
        }
        sort(prop.begin(), prop.end(), this->compare);
        int weakChars = 0;
        int length = properties.size();
        int lastDifIndex = properties.size();
        for (int i = length-2; i >= 0; i--) {
            if (prop[i].first != prop[i+1].first) {
                lastDifIndex = i+1;
            }
            
            if (lastDifIndex < length && prop[lastDifIndex].second > prop[i].second) {
                weakChars++;
            }
            
            prop[i].second = max(prop[i].second, prop[i+1].second);
        }
        return weakChars;
    }
};