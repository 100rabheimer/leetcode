class Solution {
public:
    int countCommas(int n) {
        if(n>=1000){
            return abs(n-999);
        }else {
            return 0;
        }
    }
};