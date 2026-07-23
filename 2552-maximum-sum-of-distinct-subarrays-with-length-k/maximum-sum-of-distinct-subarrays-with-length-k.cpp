class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        long long sum=0;
        long long ans=0;
        for(int i=0;i<k;i++){
sum+=nums[i];
map[nums[i]]++;
        }

    if(map.size()==k){
        ans=sum;
    }
    for(int i=k;i<nums.size();i++){
        sum-=nums[i-k];
        map[nums[i-k]]--;
    

    if(map[nums[i-k]]==0){
        map.erase(nums[i-k]);
    }
sum+=nums[i];
map[nums[i]]++;
if(map.size()==k){
    ans=max(ans,sum);
}

    }
    return ans;
    }
};