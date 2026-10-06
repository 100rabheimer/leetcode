class Solution {
public:

struct compare{
    bool operator() (const pair<int ,string>& a, const pair<int , string> &b) const{
 // Same frequency:
            // Alphabetically bada word = worse
            if(a.first== b.first){
                return a.second<b.second;
            }


             // Different frequency:
            // Chhoti frequency = worse
            return a.first>b.first;
    }
};



    vector<string> topKFrequent(vector<string>& words, int k) {

         // Step 1: Frequency count
      unordered_map<string , int> freq;
      for(string word : words) {
        freq[word]++;
      } 
      

          // Step 2: Min Heap
        // pair = {frequency, word}
   priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
        compare
        > pq;  
     
      // Step 3: Har unique word ko heap mein daalo
        for (auto &[word, f] : freq) {

            pq.push({f, word});

            // Sirf K best words rakhne hain
            if (pq.size() > k) {
                // Top = worst candidate
                pq.pop();
            }
        }
       

        // Step 4: Heap se answer nikalo
        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Heap se worst -> best mila tha
        // Hume best -> worst chahiye
        reverse(ans.begin(), ans.end());

        return ans;

          }
};