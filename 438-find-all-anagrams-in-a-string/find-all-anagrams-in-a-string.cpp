class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int>ans;
       vector<int>freq(26,0);//pattern ki frequency count
       vector<int>windowfreq(26,0);//window ki frequency count
       for(int i=0;i<p.size();i++){
        freq[p[i]-'a']++;//patternke us alphabet ki freq count bdha do
       }

    int left=0;
    //sliding window hai yeh
    for(int right=0;right<s.size();right++){
        windowfreq[s[right]-'a']++;//current character window mein add
        //jab window ka size p ke equal ho
        if(right-left+1==p.size()){
            if(windowfreq==freq){
                //anagram mila
                ans.push_back(left);
            }

            //window slide krne se pehle left character move
            windowfreq[s[left]-'a']--;
            left++;

        }
    }
    return ans;
}
};