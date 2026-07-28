class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
     int left=0;
     int product=1;
     int ans=0;
     if(k<=1){
     return 0;}

     for(int r=0;r<nums.size();r++){
        product=product*nums[r];
        while(product>=k){
            product/=nums[left];
            left++;
        }
        ans=ans+(r-left+1);
     }   
     return ans;
    }
};