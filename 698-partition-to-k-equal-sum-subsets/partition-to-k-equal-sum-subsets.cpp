class Solution {
public:
    vector<int> nums;
    int n;
    int target; 
    vector<bool> used;

    bool solve(int k,int idx,int currSum) {
        if(k==1) return true;
        if(currSum == target){
            return solve(k-1,0,0);
        }

        if(idx >= n || currSum > target) {
            return false;
        }

        if(!used[idx]) {
            used[idx] = true;
            if(solve(k,idx+1,currSum+nums[idx])) {
                return true;
            };
            used[idx] = false;
        }
 
        return solve(k,idx+1,currSum);
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->nums = nums;
        n = nums.size();
        used.assign(n,false);

        int total = accumulate(nums.begin(),nums.end(),0);

        if(total % k != 0) {
            return false;
        }

        target = total / k;

        sort(nums.rbegin(),nums.rend());
        if(nums[0]>target) {
            return false;
        }

        return solve(k,0,0);
    }
};