class Solution {
public:
vector<int>nums;
int k;
int target;

bool solve(int index, vector<int>& buckets){
    if(index==nums.size()){
        return true;
    }
    int current=nums[index];
    for(int i=0;i<k;i++){
        if(buckets[i]+current>target){
            continue;
        }

        buckets[i]+=current;
        if(solve(index+1, buckets)){
            return true;
        }
        buckets[i]-=current;

if(buckets[i] == 0) {
    break;
}
    }
    return false;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
     this->nums=nums;
     this->k=k;
     int total=0;
     for(int i=0;i<nums.size();i++){
total+=nums[i];
     }   
// Equal partition impossible
     if(total%k!=0){
     return false;
     }

     target=total/k;
       sort(this->nums.begin(), this->nums.end(), greater<int>());
         if(this->nums[0] > target) {
        return false;
    }
     vector<int>buckets(k,0);
     return solve(0,buckets);
     


    }
};