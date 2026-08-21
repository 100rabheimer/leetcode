class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>ans(nums.size(),0);
       int leftproduct=1;
       for(int i=0;i<nums.size();i++){
    
        ans[i]=leftproduct;
                leftproduct*=nums[i];

       }

       int rightproduct=1;
       for(int i=nums.size()-1;i>=0;i--){
ans[i] *= rightproduct;
rightproduct *= nums[i];
       }

       return ans; 
    }
};