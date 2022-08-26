class Solution {
public:
    void digitFrequency(int n, vector<int> &flag) {
        while (n != 0) {
            flag[n%10]++;
            n = n/10;
        }
    }
    
    bool checkSameFrequency(vector<int>&firstNumber, vector<int>&secondNumber) {
        bool sameFrequency = true;
        for (int i = 0; i < firstNumber.size(); i++) {
            if (firstNumber[i] != secondNumber[i]) {
                sameFrequency = false;
            }
        }
        
        return sameFrequency;
    }
    
    
    bool reorderedPowerOf2(int n) {
        vector<int> digitFrequencyOfN(10, 0);
        vector<int> digitFrequencyOfPowerOf2(10, 0);
        digitFrequency(n, digitFrequencyOfN);
        
        for (int i = 0; (int)pow(2, i) <= 1000000000; i++) {
            digitFrequencyOfPowerOf2.assign(10, 0);
            digitFrequency(pow(2, i), digitFrequencyOfPowerOf2);
            
            if (checkSameFrequency(digitFrequencyOfN, digitFrequencyOfPowerOf2)) {
                return true;
            }
        }
        
        return false;
    }
};