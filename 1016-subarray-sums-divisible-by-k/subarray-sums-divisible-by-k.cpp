class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        vector<int> freq(k, 0);

        int prefixSum = 0;
        int count = 0;

        freq[0] = 1;

        for(int num : nums) {

            prefixSum += num;

            int rem = prefixSum % k;

            if(rem < 0) {
                rem += k;
            }

            count += freq[rem];

            freq[rem]++;
        }

        return count;
    }
};