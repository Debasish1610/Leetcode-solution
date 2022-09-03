class Solution {
public:
    void findAns(int n, int k, int currNum, int currNumSize, vector<int> &output) {
        if (currNumSize == n) {
            output.push_back(currNum);
            return;
        }
        int value;
        if (k == 0) {
            value = currNum%10 + currNum*10;
            findAns(n, k, value, currNumSize+1, output);
        } else {
            if (currNum%10 + k < 10) {
                value = (currNum%10 + k) + currNum*10;
                findAns(n, k, value, currNumSize+1, output);
            }
            
            if (currNum%10 - k >= 0) {
                value = (currNum%10 - k) + currNum*10;
                findAns(n, k, value, currNumSize+1, output);
            }
        }
        
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>output;
        
        for (int i = 1; i < 10; i++) {
            findAns(n, k, i, 1, output);
        }
        
        return output;
    }
};