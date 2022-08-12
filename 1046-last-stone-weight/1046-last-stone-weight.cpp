class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int, greater<int>> st;
        // multiset<int>::reverse_iterator itr1, itr2;
        
        for (int i = 0; i < stones.size(); i++) {
            st.insert(stones[i]);
        }
        
        while(st.size() > 1) {
            auto itr1 = st.begin();
            auto itr2 = ++st.begin();
            
            if (*itr1 - *itr2 > 0) {
                st.insert(*itr1 - *itr2);
            }
            st.erase(itr1);
            st.erase(itr2);
        }
        
        return st.empty() ? 0 : *st.begin();
    }
};