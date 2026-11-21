class Solution {
public:
bool caneat(vector<int>& piles, int mid, int h)
{
long long totalhours=0;
for(int i=0;i<piles.size();i++){
    int hr=ceil((double)piles[i]/mid);

 totalhours+=hr;
}
return totalhours<=h;
}  
  int minEatingSpeed(vector<int>& piles, int h) {
        int low=1; 
       int high=0;
       for(int i=0;i<piles.size();i++){
high=max(high, piles[i]);
       }
int ans=-1;
        while(low<=high){
            long long  mid=low+(high-low)/2;
            if(caneat(piles, mid, h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
};