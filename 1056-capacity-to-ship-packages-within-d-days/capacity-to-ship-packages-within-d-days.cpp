class Solution {
public:
int calculatedays(vector<int>&weights, int capacity){
    int days=1;
    int currentload=0;
    for(int weight: weights){
        if(currentload + weight  > capacity){
            days++;
            currentload = weight;
        }else{
            currentload += weight;
        }  }
    return days;}
    int shipWithinDays(vector<int>& weights, int days) {
      int low=*max_element(weights.begin(),weights.end());
      int high=accumulate(weights.begin(),weights.end(), 0);
      int ans=high;
      while(low<=high){
        int mid=low+(high-low)/2;
        int requireddays=calculatedays(weights,mid);
        if(requireddays<=days){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }}
      return ans;  }
};