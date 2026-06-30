class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
           int low = 0;
        int high = arr.size() - 1;

        while(low < high)
        {
            int mid = low + (high - low) / 2;

            // Abhi increasing part me hain
            if(arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
            }
            // Abhi decreasing part me hain
            else
            {
                high = mid;
            }
        }

        return low;
    }
};