class Solution {
public:
  // Check karta hai ki mid candies har child ko dekar
    // kam se kam k children bana sakte hain ya nahi
    bool canDistribute(vector<int>& candies, long long k, int mid)
      {
        long long children = 0;

        for(int bag : candies)
        {
            // Is bag se kitne children ko mid candies milengi
            children += bag / mid;

            // Agar already k children ban gaye
            if(children >= k)
                return true;
        }

        return false;
    }

    int maximumCandies(vector<int>& candies, long long k)
    {
        int low = 1;

        int high = *max_element(candies.begin(), candies.end());

        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(canDistribute(candies,k,mid))
            {
                ans = mid;

                // Aur zyada candies try karo
                low = mid+1;
            }
            else
            {
                // Bahut zyada candies de rahe ho
                high = mid-1;
            }
        }

        return ans;
    }
};