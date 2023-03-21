class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int j=0;
        int ans=0;
        
        map<char,int>m;
        // a b c a b c b b
        // 0 1 2 3 4 5 6 7
        // (a,3) (b,4) (c,2)
        
        
        
        for(int i=0;i<s.size();++i){
            if(m.find(s[i])!=m.end()){
                
                j=max(j,m[s[i]]+1);
            }
             
             m[s[i]]=i;   
             ans=max(ans,i-j+1);
        }
                   
          return ans;
               
        
    }
};