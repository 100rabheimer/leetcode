class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxending=0, maxsum=0;
        int minending=0, minsum=0;
        for(int x:nums){
            maxending=max(x, maxending+x);
            maxsum=max(maxsum, maxending);
            minending=min(x, minending+x);
            minsum=min(minsum, minending);
        }
        return max(maxsum, -minsum);
    }
};