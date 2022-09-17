class Solution {
public:
    map<string, int>palindromeMap;
    bool isPalindrome(string &s) {
        // if (palindromeMap.find(s) != palindromeMap.end()) {
        //     return palindromeMap[s];
        // }
        
        int left=0, right = s.size()-1;
        while(left < right && s[left] == s[right]) {
            left++;
            right--;
        }
        // palindromeMap[s] = (left >= right) ? 1:0;
        return left >= right;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>output;
        unordered_map<string, int>wordMapWithIndex;
        string s, left, right;
        int index;
        for(int i = 0; i < words.size(); i++) {
            s = words[i];
            reverse(s.begin(), s.end());
            wordMapWithIndex[s] = i;
        }
        
        if (wordMapWithIndex.find("") != wordMapWithIndex.end()) {
            for (int i = 0; i < words.size(); i++) {
                if (words[i] != "" && isPalindrome(words[i])) {
                    output.push_back({i, wordMapWithIndex[""]});
                }
            }
        }
        
        for (int i = 0; i < words.size(); i++) {
            int len = words[i].size();
                
            left = "";
            right = words[i];

            for (int j = 0; j < len; j++) {
                left.push_back(words[i][j]);
                right.erase(0, 1); 

                if ( wordMapWithIndex.find(right) != wordMapWithIndex.end() && isPalindrome(left) && wordMapWithIndex[right] != i) {
                    output.push_back({wordMapWithIndex[right], i});
                    
                }

                if (wordMapWithIndex.find(left) != wordMapWithIndex.end() && isPalindrome(right) && wordMapWithIndex[left] != i) {
                    output.push_back({i, wordMapWithIndex[left]});
                }
            }
        }
        return output;
    }
};