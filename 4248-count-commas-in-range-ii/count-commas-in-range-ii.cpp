class Solution {
public:
    long long countCommas(long long n) {
        long long cnt = 1;
        long long total = 0;
        for(long long i = 1000; i <= n; i*=1000) {
            if(n>=i*1000) {
                total += (i * 1000 - i) * cnt;
            } else {
                total += (n - i + 1) * cnt;
            }
            cnt++;
        }
       return total;
    }
};