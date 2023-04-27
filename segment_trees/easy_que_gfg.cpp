class Solution{
public:
  
    vector<vector<int>>seg;
    
    void build(int l,int r,int ind,string &s){
        
        if(l==r){
            vector<int>temp(26,0);
            temp[s[l]-'a']++;
            seg[ind]=temp;
            return;
        }
        
        int mid = l+(r-l)/2;
        build(l,mid,2*ind+1,s);
        build(mid+1,r,2*ind+2,s);
        
        for(int i=0;i<26;++i){
            seg[ind][i] = seg[2*ind+1][i]+seg[2*ind+2][i];
        }
        
    }
    
    void point_update(int l,int r,int pos,char ch,int ind,string &s){
        
        if(l==r){
            vector<int>temp(26,0);
            temp[ch-'a']=1;
            seg[ind]= temp;
            return;
        }
        
        int mid = l+(r-l)/2;
        if(mid>=pos) point_update(l,mid,pos,ch,2*ind+1,s);
        else point_update(mid+1,r,pos,ch,2*ind+2,s);
        
        for(int i=0;i<26;++i)
        seg[ind][i]=seg[2*ind+1][i]+seg[2*ind+2][i];
    }
    
    // void update(int ql,int qr,int l,int r,int ind,char ch,string &s){
        
    //     if(ql>r or qr<l) return;
    //     if(l>=ql and r<=qr){
            
    //         vector<int>temp(26,0);
    //         temp[ch-'a']++;
    //         seg[ind]=temp;
    //         return;
    //     } 
        
        
    //     int mid = l + (r-l)/2;
        
    //     update(ql,qr,l,mid,2*ind+1,ch,s);
    //     update(ql,qr,mid+1,r,2*ind+2,ch,s);
        
    //     for(int i=0;i<26;++i){
    //         seg[ind][i] = seg[2*ind+1][i]+seg[2*ind+2][i];
    //     }
        
    // }
    
    
    void query(int ql,int qr,int l,int r,int ind,string &s,vector<int>&aux){
        
        if(l>=ql and r<=qr){
            
            for(int i=0;i<26;++i) aux[i]+=seg[ind][i];
            return;
        }
        
        if(ql>r or qr<l) return;
        
        int mid = l + (r-l)/2;
        
        query(ql,qr,l,mid,2*ind+1,s,aux);
        query(ql,qr,mid+1,r,2*ind+2,s,aux);
    }
    
    // auto query(int ql,int qr,int l,int r,int ind,string &s){
    //     vector<int>aux(26,0);
        
    //     if(ql>r or qr<l) return aux;
    //     if(l>=ql and r<=qr) return seg[ind];
        
        
    //     int mid = l + (r-l)/2;
        
    //     auto x=query(ql,qr,l,mid,2*ind+1,s);
    //     auto y=query(ql,qr,mid+1,r,2*ind+2,s);
        
    //     for(int i=0;i<26;++i) aux[i]=x[i]+y[i];
    //     return aux;
    // }

    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        // Code here
        vector<char>ans;
        seg.resize(4*n);
        for(int i=0;i<4*n;++i) seg[i].resize(26);
        build(0,n-1,0,s);
        
       for(int i=0;i<q;++i){
           char a = queries[i][0][0];
           if(a == '1'){
           
               int pos = stoi(queries[i][1]);
               char ch = queries[i][2][0];
               point_update(0,n-1,pos,ch,0,s);
            
           }
           
           else{
           
               int ql = stoi(queries[i][1]);
               int qr = stoi(queries[i][2]);
               int k =  stoi(queries[i][3]);
               
               vector<int>aux(26,0);
               query(ql,qr,0,n-1,0,s,aux);
            
               int count=0;
               
               for(int i=25;~i;--i){
                   count+=aux[i];
                   if(count>=k){
                        ans.push_back((char)(i+'a'));
                        break;
                   }
               }
               
               
           }
       }
        
        
        
        return ans;
    }
};