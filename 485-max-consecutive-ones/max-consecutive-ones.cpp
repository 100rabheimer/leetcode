class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxcount=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
            maxcount=max(count,maxcount);
        }else if(nums[i]==0){
            count=0;
        }
       } 
       return maxcount;
    }
};