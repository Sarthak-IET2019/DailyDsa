// scrambled string

class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        
        int n=s1.length();
        if(s1.length()!=s2.length()) return false;
        
        if(s1.length()==0 and s2.length()==0) return true;
        
        if(s1.compare(s2)==0) return true;
        
        if(s1.length()<=1) return false;
        
        string key= s1 + " " + s2;
        
        if(mp.find(key)!=mp.end()) return mp[key];
        bool flag=false;
        
        for(int i=1;i<n;++i){
            
            if(isScramble(s1.substr(0,i),s2.substr(n-i,i)) and isScramble(s1.substr(i,n-i),s2.substr(0,n-i))){
                flag= true;
                return true;
            }
            
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i,n-i),s2.substr(i,n-i))){
                flag=true;
                return true;
            }
        }
        
        mp[key]=flag;
        
        return false;
        
    }
};