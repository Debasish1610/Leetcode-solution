class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int byte = 0;
        for (int i = 0; i < data.size(); i++) {
            if (!byte) {
                if ((data[i] >> 5) == 6) {
                    byte = 1;
                } else if ((data[i] >> 4) == 14) {
                    byte = 2;
                } else if ((data[i] >> 3) == 30) {
                    byte = 3;
                } else if ((data[i] >> 7) != 0) {
                    return false;
                } 
            } else {
                if ((data[i] >> 6) == 2) {
                    byte--;
                } else {
                    return false;
                }
            }
        }
        
        return byte == 0 ? true : false;
    }
};