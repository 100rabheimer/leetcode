class Solution {
public:

long long calculatehours(vector<int>& piles, int speed)
{
    long long totalhours=0;
    for(int pile:piles){
        totalhours += (pile+speed-1)/speed;
    }
    return totalhours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
       int low=1;
       int high=*max_element(piles.begin(), piles.end());
       int ans=high;
       while(low<=high){
       int mid=low+(high-low)/2;
       long long totalhours=calculatehours(piles,mid);
       if(totalhours<=h){
        ans=mid;
        high=mid-1;
       } else{
        low=mid+1;
       }
    }
    return ans;
}
};